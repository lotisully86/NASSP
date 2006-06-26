/***************************************************************************
  This file is part of Project Apollo - NASSP
  Copyright 2004-2005 Jean-Luc Rocca-Serra, Mark Grant

  ORBITER vessel module: Service Module class

  Project Apollo is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  Project Apollo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Project Apollo; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  See http://nassp.sourceforge.net/license/ for more details.

  **************************** Revision History ****************************
  *	$Log$
  *	Revision 1.9  2006/06/10 13:27:41  movieman523
  *	Fixed a bunch of SM bugs.
  *	
  *	Revision 1.8  2006/05/30 22:34:33  movieman523
  *	Various changes. Panel switches now need power, APO and PER correctly placed in scenario fle, disabled some warnings, moved 'window' sound message to the correct place, added heat measurement to SM DLL for re-entry.
  *	
  *	Revision 1.7  2006/05/04 20:46:50  movieman523
  *	Added re-entry texture and started heat tracking.
  *	
  *	Revision 1.6  2006/04/25 13:45:06  tschachim
  *	Fixed RCS.
  *	
  *	Revision 1.5  2006/04/05 19:33:49  movieman523
  *	Support low-res RCS mesh, saved umbilical animation state so it only happens once, revised Apollo 13 support.
  *	
  *	Revision 1.4  2006/04/04 22:00:54  jasonims
  *	Apollo Spacecraft Mesh offset corrections and SM Umbilical Animation.
  *	
  *	Revision 1.3  2006/03/30 01:59:37  movieman523
  *	Added RCS to SM DLL.
  *	
  *	Revision 1.2  2006/03/30 00:31:22  movieman523
  *	Set up RCS thruster propellant.
  *	
  *	Revision 1.1  2006/03/30 00:21:37  movieman523
  *	Pass empty mass correctly and remember to check in SM files :).
  *	
  *	
  **************************************************************************/

#include "orbiterSDK.h"

#include "nasspdefs.h"
#include "sm.h"

#include <stdio.h>
#include <string.h>

//
// Meshes are globally loaded. Only HiRes for time being
//

MESHHANDLE hSM;
MESHHANDLE hSMRCS;
MESHHANDLE hSMRCSLow;
MESHHANDLE hSMSPS;
MESHHANDLE hSMPanel1;
MESHHANDLE hSMPanel2;
MESHHANDLE hSMPanel3;
MESHHANDLE hSMPanel4;
MESHHANDLE hSMPanel5;
MESHHANDLE hSMPanel6;
MESHHANDLE hSMhga;
MESHHANDLE hSMCRYO;


#define LOAD_MESH(var, name) var = oapiLoadMeshGlobal(name);

void SMLoadMeshes()

{
	//
	// SM meshes
	//

	LOAD_MESH(hSM, "ProjectApollo/SM-core");
    LOAD_MESH(hSMRCS, "ProjectApollo/SM-RCSHI");
	LOAD_MESH(hSMRCSLow, "ProjectApollo/SM-RCSLO");
	LOAD_MESH(hSMSPS, "ProjectApollo/SM-SPS");
	LOAD_MESH(hSMPanel1, "ProjectApollo/SM-Panel1");
	LOAD_MESH(hSMPanel2, "ProjectApollo/SM-Panel2");
	LOAD_MESH(hSMPanel3, "ProjectApollo/SM-Panel3");
	LOAD_MESH(hSMPanel4, "ProjectApollo/SM-Panel4");
	LOAD_MESH(hSMPanel5, "ProjectApollo/SM-Panel5");
	LOAD_MESH(hSMPanel6, "ProjectApollo/SM-Panel6");
	LOAD_MESH(hSMhga, "ProjectApollo/SM-HGA");
	LOAD_MESH(hSMCRYO, "ProjectApollo/SM-CRYO");

}

SM::SM (OBJHANDLE hObj, int fmodel) : VESSEL2(hObj, fmodel)

{
	InitSM();
	DefineAnimations();
}

SM::~SM()

{
	// Nothing for now.
}

void SM::InitSM()

{
	State = SM_STATE_SETUP;

	EmptyMass = 6100.0;
	MainFuel = 5000.0;
	Realism = REALISM_DEFAULT;

	RetrosFired = false;
	LowRes = false;

	MissionTime = MINUS_INFINITY;
	NextMissionEventTime = MINUS_INFINITY;
	LastMissionEventTime = MINUS_INFINITY;

	ph_rcsa = 0;
	ph_rcsb = 0;
	ph_rcsc = 0;
	ph_rcsd = 0;

	showSPS = true;
	showHGA = true;
	showCRYO = true;
	showRCS = true;

	showPanel1 = true;
	showPanel2 = true;
	showPanel3 = true;
	showPanel4 = true;
	showPanel5 = true;
	showPanel6 = true;

	CMTex = oapiRegisterReentryTexture("reentry");

	Temperature = 250.0;

	umbilical_proc = 0;
}

const double SMVO = 0.0;//-0.14;

void SM::SetSM()

{
	ClearMeshes();

	double mass = EmptyMass + MainFuel;
	
	SetSize (5);

	SetPMI (_V(12,12,7));
	SetCrossSections (_V(40,40,14));
	SetCW (0.1, 0.3, 1.4, 1.4);
	SetRotDrag (_V(0.7,0.7,0.3));
	SetPitchMomentScale (0);
	SetBankMomentScale (0);
	SetLiftCoeffFunc (0);

    ClearExhaustRefs();
    ClearAttExhaustRefs();

	VECTOR3 mesh_dir=_V(0, 0, 0);

	AddMesh (hSM, &mesh_dir);

	if (LowRes)
		AddMesh (hSMRCSLow, &mesh_dir);
	else
		AddMesh (hSMRCS, &mesh_dir);

	if (showPanel1)
		AddMesh (hSMPanel1, &mesh_dir);

	if (showPanel2)
		AddMesh (hSMPanel2, &mesh_dir);

	if (showPanel3)
		AddMesh (hSMPanel3, &mesh_dir);

	if (showPanel4)
		AddMesh (hSMPanel4, &mesh_dir);

	if (showPanel5)
		AddMesh (hSMPanel5, &mesh_dir);

	if (showPanel6)
		AddMesh (hSMPanel6, &mesh_dir);

	if (showCRYO)
		AddMesh (hSMCRYO, &mesh_dir);

	if (showSPS) 
	{
		mesh_dir = _V(0, SMVO, -1.654);
		AddMesh(hSMSPS, &mesh_dir);
	}

	if (showHGA) 
	{
		mesh_dir=_V(-1.308,-1.18,-1.258);
		AddMesh (hSMhga, &mesh_dir);
	}

	SetEmptyMass (mass);

	AddEngines ();

	if (CMTex)
		SetReentryTexture(CMTex,1e6,5,0.7);
}

void SM::clbkPreStep(double simt, double simdt, double mjd)

{
	MissionTime += simdt;

	double da = simdt * UMBILICAL_SPEED;
	if (umbilical_proc < 1.0)
	{
		umbilical_proc = min (1.0, umbilical_proc+da);
	}
    SetAnimation (anim_umbilical, umbilical_proc);

	//
	// See section 2.9.4.13.2 of the Apollo Operations Handbook Seq Sys section for
	// details on RCS operation after SM sep.
	//
	// -X engines start at seperation. +R engines fire 2.0 seconds later, and stop
	// 5.5 seconds after that. -X engines continue to fire until the fuel depletes
	// or the fuel cells stop providing power.
	//

	switch (State) 
	{

	case SM_UMBILICALDETACH_PAUSE:
		//Someone who knows how, please add a small Particle stream going from detach Point.
		NextMissionEventTime = MissionTime + 1.0;
		State = SM_STATE_RCS_START;

	case SM_STATE_RCS_START:
		if (MissionTime >=NextMissionEventTime) 
		{
			SetThrusterLevel(th_rcs_a[3], 1.0);
			SetThrusterLevel(th_rcs_b[3], 1.0);
			SetThrusterLevel(th_rcs_c[4], 1.0);
			SetThrusterLevel(th_rcs_d[4], 1.0);
			NextMissionEventTime = MissionTime + 2.0;
			State = SM_STATE_RCS_ROLL_START;
		}
		break;

	//
	// Start rolling after two seconds.
	//

	case SM_STATE_RCS_ROLL_START:
		if (MissionTime >= NextMissionEventTime) 
		{
			SetThrusterLevel(th_rcs_a[1], 1.0);
			SetThrusterLevel(th_rcs_b[1], 1.0);
			SetThrusterLevel(th_rcs_c[1], 1.0);
			SetThrusterLevel(th_rcs_d[1], 1.0);
			NextMissionEventTime = MissionTime + 5.5;
			State = SM_STATE_RCS_ROLL_STOP;
		}
		break;

	//
	// Stop the roll.
	//

	case SM_STATE_RCS_ROLL_STOP:
		if (MissionTime >= NextMissionEventTime)
		{
			SetThrusterLevel(th_rcs_a[1], 0.0);
			SetThrusterLevel(th_rcs_b[1], 0.0);
			SetThrusterLevel(th_rcs_c[1], 0.0);
			SetThrusterLevel(th_rcs_d[1], 0.0);
			State = SM_STATE_WAITING;
		}
		break;

	//
	// Wait until destroyed. Break up the SM as it burns up in
	// the atmosphere.
	//

	case SM_STATE_WAITING:
		if (MissionTime >= NextMissionEventTime)
		{
			NextMissionEventTime = MissionTime + 1.0;

			//
			// Do heating calculations and break up when we get too hot. These
			// only need to be approximate, since we just want to time breakup
			// based on how tough the re-entry is.
			//

			//
			// approximate SM area:
			// total: 116
			// front: 12.5
			//
			// So we can assume it radiates away from 116 and absorbs from 12.5
			// for a simple measure.
			//

			//
			// This should be the heat flux in watts per square meter.
			//

			double heatflux = GetDynPressure() * GetAirspeed();
			double heatinput = heatflux * 12.5;

			double heatrad = 5.67e-8 * 116 * pow(Temperature, 4);
			double Heat = (heatinput - heatrad) * simdt;

			//
			// Adjust temperature.
			//

			Temperature += Heat / 3000.0; // Need thermal capacity

			//
			// Set a sane lowest temperature.
			//

			if (Temperature < 200.0)
			{
				Temperature = 200.0;
			}
	
			//
			// Initial breakup code.
			//
			if (showHGA && Temperature > 1000.0)
			{
				showHGA = false;
				SetSM();

				//
				// We now need to create an HGA 'vessel' falling away from the SM.
				//
			}
			else if (showPanel1 && Temperature > 1400.0)
			{
				showPanel1 = false;
				showCRYO = true;

				SetSM();

				//
				// We now need to create a panel 'vessel' falling away from the SM.
				//
			}
			else if (showPanel2 && Temperature > 1500.0)
			{
				showPanel2 = false;
				SetSM();

				//
				// We now need to create a panel 'vessel' falling away from the SM.
				//
			}
			else if (showPanel3 && Temperature > 1600.0)
			{
				showPanel3 = false;
				SetSM();

				//
				// We now need to create a panel 'vessel' falling away from the SM.
				//
			}
			else if (showPanel4 && Temperature > 1700.0)
			{
				showPanel4 = false;
				SetSM();

				//
				// We now need to create a panel 'vessel' falling away from the SM.
				//
			}
			else if (showPanel5 && Temperature > 1800.0)
			{
				showPanel5 = false;
				SetSM();

				//
				// We now need to create a panel 'vessel' falling away from the SM.
				//
			}
			else if (showPanel6 && Temperature > 1900.0)
			{
				showPanel6 = false;
				SetSM();

				//
				// We now need to create a panel 'vessel' falling away from the SM.
				//
			}
			else if (showSPS && Temperature > 2000.0)
			{
				showSPS = false;
				SetSM();

				//
				// We now need to create an SPS 'vessel' falling away from the SM.
				//
			}
		}
		break;

	default:
		break;
	}
}

void SM::clbkSaveState (FILEHANDLE scn)

{
	VESSEL2::clbkSaveState (scn);

	oapiWriteScenario_int (scn, "MAINSTATE", GetMainState());
	oapiWriteScenario_int (scn, "VECHNO", VehicleNo);
	oapiWriteScenario_int (scn, "STATE", State);
	oapiWriteScenario_int (scn, "REALISM", Realism);
	oapiWriteScenario_float (scn, "EMASS", EmptyMass);
	oapiWriteScenario_float (scn, "FMASS", MainFuel);
	oapiWriteScenario_float (scn, "HEAT", Temperature);
	oapiWriteScenario_float (scn, "MISSNTIME", MissionTime);
	oapiWriteScenario_float (scn, "NMISSNTIME", NextMissionEventTime);
	oapiWriteScenario_float (scn, "LMISSNTIME", LastMissionEventTime);
	oapiWriteScenario_float (scn, "UPRC", umbilical_proc);
}

typedef union {
	struct {
		unsigned int showSPS:1;
		unsigned int showHGA:1;
		unsigned int showCRYO:1;
		unsigned int showRCS:1;
		unsigned int showPanel1:1;
		unsigned int showPanel2:1;
		unsigned int showPanel3:1;
		unsigned int showPanel4:1;
		unsigned int showPanel5:1;
		unsigned int showPanel6:1;
		unsigned int LowRes:1;
		unsigned int A13Exploded:1;
	} u;
	unsigned long word;
} MainState;

int SM::GetMainState()

{
	MainState state;

	state.word = 0;
	state.u.showSPS = showSPS;
	state.u.showHGA = showHGA;
	state.u.showCRYO = showCRYO;
	state.u.showRCS = showRCS;
	state.u.showPanel1 = showPanel1;
	state.u.showPanel2 = showPanel2;
	state.u.showPanel3 = showPanel3;
	state.u.showPanel4 = showPanel4;
	state.u.showPanel5 = showPanel5;
	state.u.showPanel6 = showPanel6;
	state.u.LowRes = LowRes;
	state.u.A13Exploded = A13Exploded;

	return state.word;
}

void SM::AddEngines()

{
	ClearThrusterDefinitions();

	//
	// Add the RCS. SPS won't fire with SM seperated.
	//

	//
	// TODO: For now, we just don't create propellant tanks for the Apollo 13 SM. We should do something
	// more sensible eventually.
	//

	if (!A13Exploded)
	{
		if (!ph_rcsa)
			ph_rcsa = CreatePropellantResource(RCS_FUEL_PER_QUAD);
		if (!ph_rcsb)
			ph_rcsb = CreatePropellantResource(RCS_FUEL_PER_QUAD);
		if (!ph_rcsc)
			ph_rcsc = CreatePropellantResource(RCS_FUEL_PER_QUAD);
		if (!ph_rcsd)
			ph_rcsd = CreatePropellantResource(RCS_FUEL_PER_QUAD);
	}

	double TRANZ = 1.9;

	int i;
	const double ATTCOOR = 0;
	const double ATTCOOR2 = 2.05;
	const double ATTZ = 2.85;
	const double TRANCOOR = 0;
	const double TRANCOOR2 = 0.1;
	const double ATTWIDTH=.2;
	const double ATTHEIGHT=.5;
	const double TRANWIDTH=.2;
	const double TRANHEIGHT=1;
	const double RCSOFFSET=0.25;
	const double RCSOFFSET2=-0.25;
	const double RCSOFFSETM=-0.05;
	const double RCSOFFSETM2=0.05;

	//
	// Clear any old thrusters.
	//

	for (i = 0; i < 24; i++)
	{
		th_att_lin[i] = 0;
		th_att_rot[i] = 0;
	}

	//
	// Adjust ISP and thrust based on realism level.
	// -> Disabled for now, wrong thrust and ISP causes weired behavior of the DAP
	//
	double RCS_ISP = SM_RCS_ISP;		// (SM_RCS_ISP * (15.0 - Realism)) / 5.0;
	double RCS_Thrust = SM_RCS_THRUST;	// (SM_RCS_THRUST * (15.0 - Realism)) / 5.0;

	const double CENTEROFFS = 0.25;

	th_att_lin[0]=th_att_rot[0]=CreateThruster (_V(-CENTEROFFS,ATTCOOR2,TRANZ+RCSOFFSET2), _V(0,-0.1,1), RCS_Thrust, ph_rcsa, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[1]=th_att_rot[3]=CreateThruster (_V(CENTEROFFS,-ATTCOOR2,TRANZ+RCSOFFSET2), _V(0,0.1,1), RCS_Thrust, ph_rcsc, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[2]=th_att_rot[4]=CreateThruster (_V(-ATTCOOR2,-CENTEROFFS,TRANZ+RCSOFFSET2), _V(0.1,0,1), RCS_Thrust, ph_rcsd, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[3]=th_att_rot[7]=CreateThruster (_V(ATTCOOR2,CENTEROFFS,TRANZ+RCSOFFSET2), _V(-0.1,0,1), RCS_Thrust, ph_rcsb, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[4]=th_att_rot[2]=CreateThruster (_V(-CENTEROFFS,ATTCOOR2,TRANZ+RCSOFFSET), _V(0,-0.1,-1), RCS_Thrust, ph_rcsa, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[5]=th_att_rot[1]=CreateThruster (_V(CENTEROFFS,-ATTCOOR2,TRANZ+RCSOFFSET), _V(0,0.1,-1), RCS_Thrust, ph_rcsc, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[6]=th_att_rot[6]=CreateThruster (_V(-ATTCOOR2,-CENTEROFFS,TRANZ+RCSOFFSET), _V(0.1,0,-1), RCS_Thrust, ph_rcsd, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[7]=th_att_rot[5]=CreateThruster (_V(ATTCOOR2,CENTEROFFS,TRANZ+RCSOFFSET), _V(-0.1,0,-1), RCS_Thrust, ph_rcsb, RCS_ISP, SM_RCS_ISP_SL);

	th_att_lin[8]=th_att_rot[16]=th_att_rot[17]=CreateThruster (_V(-CENTEROFFS - 0.2,ATTCOOR2,TRANZ+RCSOFFSETM), _V(1,-0.1,0), RCS_Thrust, ph_rcsa, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[9]=th_att_rot[8]=th_att_rot[9]=CreateThruster (_V(CENTEROFFS -0.2,-ATTCOOR2,TRANZ+RCSOFFSETM2), _V(1,0.1,0), RCS_Thrust, ph_rcsc, RCS_ISP, SM_RCS_ISP_SL);

	th_att_lin[12]=th_att_rot[10]=th_att_rot[11]=CreateThruster (_V(-CENTEROFFS + 0.2,ATTCOOR2,TRANZ+RCSOFFSETM2), _V(-1,-0.1,0), RCS_Thrust, ph_rcsa, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[13]=th_att_rot[18]=th_att_rot[19]=CreateThruster (_V(CENTEROFFS + 0.2,-ATTCOOR2,TRANZ+RCSOFFSETM), _V(-1,0.1,0), RCS_Thrust, ph_rcsc, RCS_ISP, SM_RCS_ISP_SL);

	th_att_lin[16]=th_att_rot[14]=th_att_rot[15]=CreateThruster (_V(ATTCOOR2,CENTEROFFS -0.2,TRANZ+RCSOFFSETM2), _V(-0.1,1,0), RCS_Thrust, ph_rcsb, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[17]=th_att_rot[22]=th_att_rot[23]=CreateThruster (_V(-ATTCOOR2,-CENTEROFFS -0.2,TRANZ+RCSOFFSETM), _V(-0.1,1,0), RCS_Thrust, ph_rcsd, RCS_ISP, SM_RCS_ISP_SL);

	th_att_lin[20]=th_att_rot[20]=th_att_rot[21]=CreateThruster (_V(ATTCOOR2,CENTEROFFS + 0.2,TRANZ+RCSOFFSETM), _V(-0.1,-1,0), RCS_Thrust, ph_rcsb, RCS_ISP, SM_RCS_ISP_SL);
	th_att_lin[21]=th_att_rot[12]=th_att_rot[13]=CreateThruster (_V(-ATTCOOR2,-CENTEROFFS + 0.2,TRANZ+RCSOFFSETM2), _V(0.1,-1,0), RCS_Thrust, ph_rcsd, RCS_ISP, SM_RCS_ISP_SL);

	CreateThrusterGroup (th_att_lin,   4, THGROUP_ATT_FORWARD);
	CreateThrusterGroup (th_att_lin+4, 4, THGROUP_ATT_BACK);
	CreateThrusterGroup (th_att_lin+8,   2, THGROUP_ATT_RIGHT);
	CreateThrusterGroup (th_att_lin+12, 2, THGROUP_ATT_LEFT);
	CreateThrusterGroup (th_att_lin+16,   2, THGROUP_ATT_UP);
	CreateThrusterGroup (th_att_lin+20,   2, THGROUP_ATT_DOWN);

	CreateThrusterGroup (th_att_rot,   2, THGROUP_ATT_PITCHDOWN);
	CreateThrusterGroup (th_att_rot+2,   2, THGROUP_ATT_PITCHUP);
	CreateThrusterGroup (th_att_rot+4,   2, THGROUP_ATT_YAWRIGHT);
	CreateThrusterGroup (th_att_rot+6,   2, THGROUP_ATT_YAWLEFT);
	CreateThrusterGroup (th_att_rot+8,   8, THGROUP_ATT_BANKLEFT);
	CreateThrusterGroup (th_att_rot+16,   8, THGROUP_ATT_BANKRIGHT);

	SURFHANDLE SMExhaustTex = oapiRegisterExhaustTexture ("Exhaust_atrcs");

	for (i = 0; i < 24; i++)
	{
		if (th_att_lin[i])
			AddExhaust (th_att_lin[i], 1.2, 0.18, SMExhaustTex);
	}

	//
	// Map thrusters to RCS quads. Note that we don't use entry zero, we're matching the array to
	// Apollo numbering for simplicity... we also have to include the fake thrusters here so we
	// can enable and disable them.
	//

	th_rcs_a[1] = th_att_rot[16];
	th_rcs_a[2] = th_att_rot[10];
	th_rcs_a[3] = th_att_rot[2];
	th_rcs_a[4] = th_att_rot[0];

	th_rcs_b[1] = th_att_rot[20];
	th_rcs_b[2] = th_att_rot[14];
	th_rcs_b[3] = th_att_rot[5];
	th_rcs_b[4] = th_att_rot[7];

	th_rcs_c[1] = th_att_rot[18];
	th_rcs_c[2] = th_att_rot[8];
	th_rcs_c[3] = th_att_rot[3];
	th_rcs_c[4] = th_att_rot[1];

	th_rcs_d[1] = th_att_rot[22];
	th_rcs_d[2] = th_att_rot[12];
	th_rcs_d[3] = th_att_rot[4];
	th_rcs_d[4] = th_att_rot[6];
}

void SM::DefineAnimations()
{

	static UINT umbilical_group[1] = {2}; // participating groups
	static MGROUP_ROTATE umbilical
	(
		0,				// mesh index
		umbilical_group, 1,		// group list and # groups
		_V(0,-1.9540,3.168), // rotation reference point
		_V(1,0,0),		// rotation axis
		(float)(50*PI/180) // angular rotation range
	);
	anim_umbilical = CreateAnimation (0.0);
	AddAnimationComponent (anim_umbilical, 0, 1, &umbilical);

}

void SM::SetMainState(int s)

{
	MainState state;

	state.word = s;

	showSPS = (state.u.showSPS != 0);
	showHGA = (state.u.showHGA != 0);
	showCRYO = (state.u.showCRYO != 0);
	showRCS = (state.u.showRCS != 0);
	showPanel1 = (state.u.showPanel1 != 0);
	showPanel2 = (state.u.showPanel2 != 0);
	showPanel3 = (state.u.showPanel3 != 0);
	showPanel4 = (state.u.showPanel4 != 0);
	showPanel5 = (state.u.showPanel5 != 0);
	showPanel6 = (state.u.showPanel6 != 0);
	LowRes = (state.u.LowRes != 0);
	A13Exploded = (state.u.A13Exploded != 0);
}

void SM::clbkLoadStateEx (FILEHANDLE scn, void *vstatus)

{
	char *line;
	float flt;

	while (oapiReadScenario_nextline (scn, line))
	{
		if (!strnicmp (line, "MAINSTATE", 9))
		{
            int MainState = 0;;
			sscanf (line+9, "%d", &MainState);
			SetMainState(MainState);
		}
		else if (!strnicmp (line, "VECHNO", 6))
		{
			sscanf (line+6, "%d", &VehicleNo);
		}
		else if (!strnicmp (line, "EMASS", 5))
		{
			sscanf (line+5, "%g", &flt);
			EmptyMass = flt;
		}
		else if (!strnicmp (line, "FMASS", 5))
		{
			sscanf (line+5, "%g", &flt);
			MainFuel = flt;
		}
		else if (!strnicmp (line, "HEAT", 4))
		{
			sscanf (line + 4, "%g", &flt);
			Temperature = flt;
		}
		else if (!strnicmp(line, "MISSNTIME", 9))
		{
            sscanf (line+9, "%f", &flt);
			MissionTime = flt;
		}
		else if (!strnicmp(line, "NMISSNTIME", 10))
		{
            sscanf (line + 10, "%f", &flt);
			NextMissionEventTime = flt;
		}
		else if (!strnicmp(line, "LMISSNTIME", 10))
		{
            sscanf (line + 10, "%f", &flt);
			LastMissionEventTime = flt;
		}
		else if (!strnicmp (line, "STATE", 5))
		{
			int i;
			sscanf (line + 5, "%d", &i);
			State = (SMState) i;
		}
		else if (!strnicmp (line, "REALISM", 7))
		{
			sscanf (line + 7, "%d", &Realism);
		}
		else if (!strnicmp (line, "UPRC", 4))
		{
			sscanf (line + 4, "%g", &flt);
			umbilical_proc = flt;
		}
		else
		{
			ParseScenarioLineEx (line, vstatus);
        }
	}

	SetSM();
}

void SM::clbkSetClassCaps (FILEHANDLE cfg)

{
	VESSEL2::clbkSetClassCaps (cfg);
	InitSM();
}

void SM::clbkDockEvent(int dock, OBJHANDLE connected)

{
}

void SM::SetState(SMSettings &state)

{
	if (state.SettingsType.SM_SETTINGS_GENERAL)
	{
		MissionTime = state.MissionTime;
		VehicleNo = state.VehicleNo;
		Realism = state.Realism;
		showHGA = state.showHGA;
		A13Exploded = state.A13Exploded;

		//
		// If the SM exploded, panel 4 was blown off earlier.
		//

		if (A13Exploded)
		{
			showPanel4 = false;
		}
	}

	if (state.SettingsType.SM_SETTINGS_MASS)
	{
		EmptyMass = state.EmptyMass;
	}

	if (state.SettingsType.SM_SETTINGS_FUEL)
	{
		MainFuel = state.MainFuelKg;
	}

	if (state.SettingsType.SM_SETTINGS_ENGINES)
	{
		//
		// Nothing for now. Later we can enable or disable RCS as
		// appropriate based on seperation state.
		//
	}

	SetSM();

	//
	// Now the RCS propellant resource has been created, set the
	// fuel levels.
	//
	// TODO: for now we don't create RCS propellant for Apollo 13.
	// We should do something more sensible later.
	//

	if (state.SettingsType.SM_SETTINGS_FUEL && !A13Exploded)
	{
		SetPropellantMass(ph_rcsa, state.RCSAFuelKg);
		SetPropellantMass(ph_rcsb, state.RCSBFuelKg);
		SetPropellantMass(ph_rcsc, state.RCSCFuelKg);
		SetPropellantMass(ph_rcsd, state.RCSDFuelKg);
	}

	State = SM_UMBILICALDETACH_PAUSE;
}

static int refcount = 0;

DLLCLBK VESSEL *ovcInit (OBJHANDLE hvessel, int flightmodel)

{
	VESSEL *v;

	if (!refcount++)
	{
		SMLoadMeshes();
	}

	v = new SM (hvessel, flightmodel);
	return v;
}


DLLCLBK void ovcExit (VESSEL *vessel)

{
	--refcount;

	if (!refcount)
	{

		//
		// This code could tidy up allocations when refcount == 0
		//

	}

	if (vessel) 
		delete (SM *)vessel;
}
