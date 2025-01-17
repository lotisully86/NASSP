/***************************************************************************
  This file is part of Project Apollo - NASSP
  Copyright 2004-2005

  Launch Vehicle Digital Computer (C++ Implementation)

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

  **************************************************************************/

#pragma once
#include "OrbiterAPI.h"
#include "Orbitersdk.h"
#include "stdio.h"
#include "math.h"
#include "resource.h"

#include "nasspdefs.h"
#include "nasspsound.h"

#include "soundlib.h"
#include "toggleswitch.h"

#include "apolloguidance.h"
#include "csmcomputer.h"
#include "ioChannels.h"
#include "dsky.h"
#include "IMU.h"
#include "papi.h"
#include "saturn.h"
#include "saturn1b.h"
#include "s1b.h"
#include "../src_rtccmfd/OrbMech.h"
#include "LVDC.h"

//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

// Constructor
LVDC1B::LVDC1B(){
	int x=0;
	Initialized = false;					// Reset cloberness flag
	// Zeroize
	// bool
	alpha_D_op = false;
	BOOST = false;
	CountPIPA = false;
	GATE = false;
	GATE5 = false;
	GRR_init = false;
	HSL = false;
	INH = false;
	INH1 = false;
	INH2 = false;
	i_op = false;
	liftoff = false;
	LVDC_EI_On = false;
	LVDC_GRR = false;
	LVDC_Stop = false;
	MRS = false;
	poweredflight = false;
	S1B_Engine_Out = false;
	S4B_IGN = false;
	theta_N_op = false;
	TerminalConditions = false;
	// int
	IGMCycle = 0;
	LVDC_Timebase = 0;
	T_EO1 = 0;
	T_EO2 = 0;
	UP = 0;
	// double
	a = 0;
	a_0p = 0;
	a_0r = 0;
	a_0y = 0;
	a_1 = 0;
	a_2 = 0;
	A1 = 0;
	A2 = 0;
	A3 = 0;
	A4 = 0;
	A5 = 0;
	a_1p = 0;
	a_1r = 0;
	a_1y = 0;
	alpha_1 = 0;
	alpha_2 = 0;
	alpha_D = 0;
	Azimuth = 0;
	Azo = 0;
	Azs = 0;
	B_11 = 0;
	B_21 = 0;
	B_12 = 0;
	B_22 = 0;
	beta_p1c = 0;
	beta_p2c = 0;
	beta_p3c = 0;
	beta_p4c = 0;
	beta_pc = 0;
	beta_rc = 0;
	beta_y1c = 0;
	beta_y2c = 0;
	beta_y3c = 0;
	beta_y4c = 0;
	beta_yc = 0;
	C_2 = 0;
	C_4 = 0;
	C_3 = 0;
	CG = 0;
	cos_chi_Yit = 0;
	cos_chi_Zit = 0;
	cos_phi_L = 0;
	d2 = 0;
	ddot_xi_G = 0;
	ddot_eta_G = 0;
	ddot_zeta_G = 0;
	ddot_zeta_GT = 0;
	ddot_xi_GT = 0;
	DescNodeAngle = 0;
	deta = 0;
	dxi = 0;
	dot_dxi = 0;
	dot_deta = 0;
	dot_dzeta = 0;
	dot_dxit = 0;
	dot_detat = 0;
	dot_dzetat = 0;
	dotM_1 = 0;
	dotM_2 = 0;
	dot_phi_1 = 0;
	dot_phi_T = 0;
	dot_zeta_T = 0;
	dot_xi_T = 0;
	dot_eta_T = 0;
	dt = 0;
	dT_2 = 0;
	dt_c = 0;
	dT_F = 0;
	dt_LET = 0;
	dtt_1 = 0;
	dtt_2 = 0;
	dV = 0;
	dV_B = 0;
	e = 0;
	eps_2 = 0;
	eps_3 = 0;
	eps_4 = 0;
	eps_p = 0;
	eps_ymr = 0;
	eps_ypr = 0;
	f = 0;
	F = 0;
	Fm = 0;
	for(x=0; x < 5; x++){
		int y=0;
		for(y=0; y < 5; y++){
			Fx[x][y] = 0;
		}
	}
	for(x=0; x < 7; x++){
		fx[x] = 0;
		gx[x] = 0;
	}
	G_T = 0;
	IGMInterval = 0;
	Inclination = 0;
	J = 0;
	J_1 = 0;
	J_2 = 0;
	Jt_2 = 0;
	J_Y = 0;
	J_P = 0;
	K_1 = 0;
	K_2 = 0;
	K_3 = 0;
	K_4 = 0;
	K_5 = 0;
	K_P1 = 0;
	K_P2 = 0;
	K_p = 0;
	K_y = 0;
	K_r = 0;
	K_Y1 = 0;
	K_Y2 = 0;
	K_Y = 0;
	K_P = 0;
	D_P = 0;
	D_Y = 0;
	L_1 = 0;
	L_2 = 0;
	dL_2 = 0;
	Lt_2 = 0;
	L_P = 0;
	L_Y = 0;
	Lt_Y = 0;
	LVDC_TB_ETime = 0;
	mu = 0;
	p = 0;
	P_1 = 0;
	P_2 = 0;
	phi_lat = 0;
	phi_lng = 0;
	phi_T = 0;
	Q_1 = 0;
	Q_2 = 0;
	Q_Y = 0;
	Q_P = 0;
	R = 0;
	ROV = 0;
	ROVs = 0;
	R_T = 0;
	S1B_Sep_Time = 0;
	S_1 = 0;
	S_2 = 0;
	S_P = 0;
	S_Y = 0;
	sinceLastIGM = 0;
	sin_chi_Yit = 0;
	sin_chi_Zit = 0;
	sin_phi_L = 0;
	sin_ups = 0;
	cos_ups = 0;
	SMCG = 0;
	S = 0;
	P = 0;
	t = 0;
	t_1 = 0;
	T_1 = 0;
	t_2 = 0;
	T_2 = 0;
	t_3 = 0;
	t_3i = 0;
	t_4 = 0;
	t_5 = 0;
	t_6 = 0;
	TA1 = 0;
	TA2 = 0;
	TA3 = 0;
	T_ar = 0;
	TAS = 0;
	tau1 = 0;
	tau2 = 0;
	t_B1 = 0;
	t_B3 = 0;
	tchi_y_last = 0;
	tchi_p_last = 0;
	tchi_y = 0;
	tchi_p = 0;
	t_clock = 0;
	T_CO = 0;
	t_fail = 0;
	T_GO = 0;
	TI5F2 = 0;
	T_LET = 0;
	T_S1 = 0;
	T_S2 = 0;
	T_S3 = 0;
	TSMC1 = 0;
	TSMC2 = 0;
	T_T = 0;
	Tt_2 = 0;
	Tt_T = 0;
	U_1 = 0;
	U_2 = 0;
	gamma_T = 0;
	V = 0;
	V_ex1 = 0;
	V_ex2 = 0;
	V_i = 0;
	V_0 = 0;
	V_1 = 0;
	V_2 = 0;
	V_T = 0;
	V_TC = 0;
	xi_T = 0;
	eta_T = 0;
	zeta_T = 0;
	X_S1 = 0;
	X_S2 = 0;
	X_S3 = 0;
	Xtt_y = 0;
	Xtt_p = 0;
	X_Zi = 0;
	X_Yi = 0;
	Y_u = 0;
	// VECTOR3 
	ACommandedAttitude = _V(0,0,0);
	AttitudeError = _V(0,0,0);
	AttRate = _V(0,0,0);
	CommandedAttitude = _V(0,0,0);
	CommandRateLimits = _V(0,0,0);
	CurrentAttitude = _V(0,0,0);
	ddotG_act = _V(0,0,0);
	ddotG_last = _V(0,0,0);
	ddotM_act = _V(0,0,0);
	ddotM_last = _V(0,0,0);
	DDotXEZ_G = _V(0,0,0);
	DeltaAtt = _V(0,0,0);
	Dot0 = _V(0,0,0);
	DotG_act = _V(0,0,0);
	DotG_last = _V(0,0,0);
	DotM_act = _V(0,0,0);
	DotM_last = _V(0,0,0);
	DotS = _V(0,0,0);
	DotXEZ = _V(0,0,0);
	PCommandedAttitude = _V(0,0,0);
	Pos4 = _V(0,0,0);
	PosS = _V(0,0,0);
	PosXEZ = _V(0,0,0);
	// MATRIX3
	MX_A = _M(0,0,0,0,0,0,0,0,0);
	MX_B = _M(0,0,0,0,0,0,0,0,0);
	MX_G = _M(0,0,0,0,0,0,0,0,0);
	MX_K = _M(0,0,0,0,0,0,0,0,0);
	MX_phi_T = _M(0,0,0,0,0,0,0,0,0);
}

void LVDC1B::init(Saturn* own){
	if(Initialized == true){ 
		if(owner == own){
			fprintf(lvlog,"init called after init, ignored\r\n");
			fflush(lvlog);
			return;
		}else{
			fprintf(lvlog,"init called after init with new owner, proceeding\r\n");
			fflush(lvlog);
		}
	}
	owner = own;
	lvimu.Init();							// Initialize IMU
	lvrg.Init(owner);						// LV Rate Gyro Package
	lvimu.SetVessel(owner);					// set vessel pointer
	lvimu.CoarseAlignEnableFlag = false;	// Clobber this
	//presettings in order of boeing listing for easier maintainece
	//GENERAL
	e = 0.00417135950879776;
	f = 359.611584444894;
	C_3 = -60139891.8062616; // Stored as twice the etc etc.
	Inclination = 31.6050041807581;
	DescNodeAngle = 118.998976688105;
	Azimuth = 72.06;
	GATE = false;							// 'chi-freeze-gate': freezes steering commands when true
	GATE5 = false;							// allows single pass through HSL initialization when false
	INH = false;							// inhibits restart preparations; set by x-lunar inject/inhibit switch
	INH1 = false;							// inhibits first EPO roll/pitch maneuver
	INH2 = false;							// inhibits second EPO roll/pitch maneuver
	TA1 = 9780;								// time to start pitchdown maneuver
	TA2 = 10275;							// time for attitude hold
	TA3 = 11820;							// time for final attitude
	T_LET = 25;								// LET Jettison Time, i.e. the time IGM starts after start of TB3
	UP = 0;									// switching variable for Tt_t parameter update
	//alpha _d_op?
	i_op = true;							// flag for selecting method of EPO inclination calculation
	theta_N_op = true;						// flag for selecting method of EPO descending node calculation
	TerminalConditions = true;
	//PRE_IGM GUIDANCE
	B_11 = -0.62;							// Coefficients for determining freeze time after S1C engine failure
	B_12 = 40.9;							// dto.
	B_21 = -0.3611;							// dto.
	B_22 = 29.25;							// dto.
	// PITCH POLYNOMIAL (AS-205)
	Fx[1][0] = -0.8014017976;
	Fx[1][1] = 0.1834943176;
	Fx[1][2] = -0.0127672185;
	Fx[1][3] = 0.000065735448;
	Fx[1][4] = 0.0;
	Fx[2][0] = 19.31641263;
	Fx[2][1] = -0.6190923568;
	Fx[2][2] = -0.0022020716;
	Fx[2][3] = 0.000020108813;
	Fx[2][4] = 0.0;
	Fx[3][0] = 12.08184643;
	Fx[3][1] = -0.5606283163;
	Fx[3][2] = -0.0005797187;
	Fx[3][3] = 0.00000592461278;
	Fx[3][4] = 0.0;
	Fx[4][0] = -59.31545;
	Fx[4][1] = 0.0;
	Fx[4][2] = 0.0;
	Fx[4][3] = 0.0;
	Fx[4][4] = 0.0;
	t_1 = 10;								// Backup timer for Pre-IGM pitch maneuver
	t_2 = 25;								// Time to initiate pitch freeze for S1C engine failure
	t_3 = 36;								// Constant pitch freeze for S1C engine failure prior to t_2
	t_3i=0;									// Clock time at S4B ignition
	t_4 = 45;								// Upper bound of validity for first segment of pitch freeze
	t_5 = 81;								// Upper bound of validity for second segment of pitch freeze
	t_6 = 0;								// Time to terminate pitch freeze after S1C engine failure
	T_ar = 134.3;							// S1C Tilt Arrest Time	   
	T_S1 = 63.8;							// Pitch Polynomial Segment Times
	T_S2 = 109.8;							// dto.
	T_S3 = 134.3;							// dto.
	T_EO1 = 0;								// switching constant for SIC engine-out handling
	T_EO2 = 0;								// allows single pass through IGM engine-out presettings when 0
	dt = 1.7;								// Nominal powered-flight or coast-guidance computation-cycle interval
	dT_F=0;									// Period of frozen pitch in S1C
	dt_LET = 25;							// Nominal time between SII ign and LET jet
	t_fail =0;								// S1C Engine Failure time
	TI5F2 = 20.0;
	CommandRateLimits=_V(1*RAD,1*RAD,1*RAD);// Radians per second
	//IGM BOOST TO ORBIT
	cos_phi_L = 0.878635524;					// cos of the Geodetic Launch site latitude
	// Inclination from azimuth polynomial
	fx[0] = 32.55754;  fx[1] = -15.84615; fx[2] = 11.64780; fx[3] = 9.890970;
	fx[4] = -5.111430; fx[5] = 0;         fx[6] = 0;
	// Descending Node Angle from azimuth polynomial
	gx[0] = 123.1935; gx[1] = -55.06485; gx[2] = -35.26208; gx[3] = 26.01324;
	gx[4] = -1.47591; gx[5] = 0;         gx[6] = 0;			
	MRS = false;							// MR Shift
	dotM_1 = 242.7976615;						// Mass flowrate of SIVB from approximately LET jettison to second MRS
	dotM_2 = 183.3909139;						// Mass flowrate of SIVB after second MRS
	dV_B = 6.22; // AP11// dV_B = 2.0275; // AP9// Velocity cutoff bias for orbital insertion
	ROV = 1.11706196363037;
	ROVs = 1.5;
	sin_phi_L = 0.477493054;					// sin of the Geodetic Launch site latitude
	SMCG = 0.05*RAD;
	TSMC1 = 20; TSMC2 = 5; // AP9
	// TSMC1 = 60.6 TSMC2 = 15 // AP11
	T_1 = 286;								// Time left in first-stage IGM
	T_2 = 0;								// Time left in second and fourth stage IGM
	Tt_2 = 150;								// Estimated third or fifth stage burn time
	Tt_T = T_1 + Tt_2;						// Time-To-Go computed using Tt_3
	t = 0;									// Time from accelerometer reading to next steering command
	t_B1 = 2;								// Transition time for the S2 mixture ratio to shift from 5.5 to 4.7
	t_B3 = 0;								// Time from second S2 MRS signal
	//dt: not set; dependend on cycle time
	V_ex1 = 4145.76977;
	V_ex2 = 4178.68462;
	V_TC = 300;
	
	eps_2 = 35;								// Time to begin chi bar steering
	eps_3 = 10000;							// Terminal condition freeze time
	eps_4 = 3;								// Time to enable HSL loop & chi freeze
	mu =398603200000000;					// Product of G and Earth's mass
	tau2 = 324; //tau2 = 722.67;		// Time to consume all fuel between MRS and S2 Cutoff
	//rate limits: set in pre-igm
	alpha_1 = 0;									//orbital guidance pitch
	alpha_2 = 0;									//orbital guidance yaw
	K_P1 = 4.3 * RAD;							// restart attitude coefficients
	K_P2 = 0;
	K_Y1 = 0;
	K_Y2 = 0;

	//Not in boeing doc, but needed for nav:
	a = 6378137;							//earth's equatorial radius
	J = 1.62345e-3;							//first coefficient of earth's gravity

	//'real' software variable, i.e. those are computed at runtime
	// Software flags
	GRR_init = false;
	liftoff = false;
	poweredflight = false;
	HSL=false;								// High-Speed Loop flag
	BOOST=false;							// Boost To Orbit
	S4B_IGN=false;							// SIVB Ignition
	LVDC_GRR = false;
	tau1=0;									// Time to consume all fuel before S2 MRS
	Fm=0;									// sensed total accel
	//Azimuth = 72.124;
	//Inclination=0;							// Inclination
	//DescNodeAngle=0;						// Descending Node Angle -- THETA_N
	Azo=0; Azs=0;							// Variables for scaling the -from-azimuth polynomials
	CommandedAttitude=_V(0,0,0);			// Commanded Attitude (RADIANS)
	PCommandedAttitude=_V(0,0,0);			// Previous Commanded Attitude (RADIANS)
	CurrentAttitude=_V(0,0,0);				// Current Attitude   (RADIANS)
	F=0;									// Force in Newtons, I assume.	
	K_Y=0; K_P=0; D_P=0; D_Y=0;				// Intermediate variables in IGM
	P_1=0; P_2=0; 
	L_1=0; L_2=0; L_P=0; L_Y=0; Lt_Y=0;
	J_1=0; J_2=0; J_Y=0; J_P=0; 
	S_1=0; S_2=0; S_P=0; S_Y=0; 
	U_1=0; U_2=0;  
	Q_1=0; Q_2=0; Q_Y=0; Q_P=0; 
	d2=0;
	//f=0;									// True anomaly of the predicted cutoff radius vector
	//e=0;									// Eccentricity of the transfer ellipse
	C_2=0; C_4=0;							// IGM coupling terms for pitch steering
	p=0;									// semilatus rectum of terminal ellipse
	K_1=0; K_2=0; K_3=0; K_4=0;				// Correction to chi-tilde steering angles, K_i
	K_5=0;									// IGM terminal velocity constant
	R=0;									// Instantaneous Radius Magnitude
	R_T = 6563366.0;						// Desired terminal radius
	V = 0;									// Instantaneous vehicle velocity
	V_T = 7793.0429;						// Desired terminal velocity
	V_i=0; V_0=0; V_1=0; V_2=0;				// Parameters for cutoff velocity computation
	gamma_T=0;								// Desired terminal flight-path angle
	MX_A=_M(0,0,0,0,0,0,0,0,0);				// Transform matrix from earth-centered plumbline to equatorial
	MX_B=_M(0,0,0,0,0,0,0,0,0);				// Transform matrix from equatorial to orbital coordinates
	MX_G=_M(0,0,0,0,0,0,0,0,0);				// Transform matrix from earth-centered plumbline to orbital
	MX_K=_M(0,0,0,0,0,0,0,0,0);				// Transform matrix from earth-centered plumbline to terminal
	MX_phi_T=_M(0,0,0,0,0,0,0,0,0);			// Matrix made from phi_T
	phi_T=0;								// Angle used to estimate location of terminal radius in orbital plane
	Pos4=_V(0,0,0);							// Position in the orbital reference system
	PosS=_V(0,0,0);							// Position in the earth-centered plumbline system. SPACE-FIXED.
	DotS=_V(0,0,0);							// VELOCITY in the earth-centered plumbline system
	DotM_act=_V(0,0,0);						// actual sensed velocity from platform
	ddotM_act =_V(0,0,0);
	ddotM_last =_V(0,0,0);
	ddotG_act=_V(0,0,0);					// actual computed acceleration from gravity
	DotG_act=_V(0,0,0);						// actual computed velocity from gravity
	DotM_last=_V(0,0,0);					// last sensed velocity from platform
	ddotG_last=_V(0,0,0);					// last computed acceleration from gravity
	DotG_last=_V(0,0,0);					// last computed velocity from gravity
	alpha_D=0;								// Angle from perigee to DN vector
	alpha_D_op=true;						// Option to determine alpha_D or load it
	G_T= -9.255;							// Magnitude of desired terminal gravitational acceleration
	xi_T=0; eta_T=0; zeta_T=0;				// Desired position components in the terminal reference system
	PosXEZ=_V(0,0,0);						// Position components in the terminal reference system
	DotXEZ=_V(0,0,0);						// Instantaneous something
	deta=0; dxi=0;							// Position components to be gained in this axis
	T_T=0;									// Time-To-Go computed using T_2
	tchi_y=0; tchi_p=0;						// Angles to null velocity deficiencies without regard to terminal data
	dot_zeta_T=0; dot_xi_T=0; dot_eta_T=0;	// I don't know.
	ddot_zeta_GT=0; ddot_xi_GT=0;
	DDotXEZ_G=_V(0,0,0);					// ???
	ddot_xi_G=0; ddot_eta_G=0; ddot_zeta_G=0;								
	dot_dxit=0; dot_detat=0; dot_dzetat=0; 	// Intermediate velocity deficiency used in time-to-go computation
	dot_dxi=0; dot_deta=0; dot_dzeta=0; 	// More Deltas
	Xtt_y=0; Xtt_p=0; 						// IGM computed steering angles in terminal system
	X_S1=0; X_S2=0; X_S3=0; 				// Direction cosines of the thrust vector
	sin_ups=0; cos_ups=0;					// Sine and cosine of upsilon (flight-path angle)
	dot_phi_1=0; dot_phi_T=0; 				// ???
	dtt_1=0; dtt_2=0;						// Used in TGO determination
	dt = 1.7;								// Nominal powered-flight or coast-guidance computation-cycle interval
	a_1=0; a_2=0;							// Acceleration terms used to determine TGO
	T_GO=0;									// Time before S4B shutdown
	T_CO=0;									// Predicted time of S4B shutdown, from GRR
	dV=0;
	TAS=0;
	t_clock = 0;


	// Set up remainder
	LVDC_Timebase = -1;										// Start up halted in pre-PTL wait
	LVDC_TB_ETime = 0;
	LVDC_Stop = false;
	IGMCycle = 0;
	sinceLastIGM = 0;
	// INTERNAL (NON-REAL-LVDC) FLAGS
	LVDC_EI_On = false;
	S1B_Sep_Time = 0;
	CountPIPA = false;
	if(!Initialized){ lvlog = fopen("lvlog1b.txt","w+"); } // Don't reopen the log if it's already open
	fprintf(lvlog,"init complete\r\n");
	fflush(lvlog);
	Initialized = true;
}
	
// DS20070205 LVDC++ EXECUTION
void LVDC1B::timestep(double simt, double simdt) {
	// Bail if uninitialized
	if(owner == NULL){ return; }
	// Update timebase ET
	LVDC_TB_ETime += simdt;
	
	// Note that GenericTimestep will update MissionTime.
	if(LVDC_Stop == false){
		/* **** LVDC GUIDANCE PROGRAM **** */
		switch(LVDC_Timebase){
			case -1: // LOOP WAITING FOR PTL
				// Lock time accel to 100x
				if (oapiGetTimeAcceleration() > 100){ oapiSetTimeAcceleration(100); } 

				// Prelaunch tank venting between -3:00h and engine ignition
				// No clue if the venting start time is correct
				if (owner->MissionTime < -10800){
					owner->DeactivatePrelaunchVenting();
				}else{
					owner->ActivatePrelaunchVenting();
				}

				// BEFORE PTL COMMAND (T-00:20:00) STOPS HERE
				{
					double Source  = fabs(owner->MissionTime);
					double Minutes = Source/60;
					double Hours   = (int)Minutes/60;				
					double Seconds = Source - ((int)Minutes*60);
					Minutes       -= Hours*60;
					if (owner->MissionTime < -1200){
						sprintf(oapiDebugString(),"LVDC: T - %d:%d:%.2f | AWAITING PTL INTERRUPT",(int)Hours,(int)Minutes,Seconds);
						lvimu.ZeroIMUCDUFlag = true;					// Zero IMU CDUs
						break;
					}else{
						sprintf(oapiDebugString(),"LVDC: T - %d:%d:%.2f | AWAITING GRR",(int)Hours,(int)Minutes,Seconds);
					}
				}
			
				// WAIT FOR GRR
				// Engine lights on at T-00:04:10
				if (owner->MissionTime >= -250 && LVDC_EI_On == false) { LVDC_EI_On = true; }

				// Between PTL signal and GRR, we monitor the IMU for any failure signals and do vehicle self-tests.
				// At GRR we transfer control to the flight program and start TB0.

				// BEFORE GRR (T-00:00:17) STOPS HERE
				if (owner->MissionTime >= -17){
					lvimu.ZeroIMUCDUFlag = false;					// Release IMU CDUs
					if (owner->ApolloNo == 5)
					{
						lvimu.DriveGimbals((Azimuth - 90)*RAD, 0, 0);	// Now bring to alignment 
					}
					else
					{
						lvimu.DriveGimbals((Azimuth - 100)*RAD, 0, 0);	// Now bring to alignment 
					}
					lvimu.SetCaged(false);							// Release IMU
					CountPIPA = true;								// Enable PIPA storage			
					BOOST = true;
					LVDC_GRR = true;								// Mark event
					poweredflight = true;
					oapiSetTimeAcceleration (1);					// Set time acceleration to 1
					owner->SetThrusterGroupLevel(owner->thg_main, 0);	// Ensure off
					{
						int i;
						for (i = 0; i < 5; i++) {					// Reconnect fuel to S1C engines						
							owner->SetThrusterResource(owner->th_main[i], owner->ph_1st);
						}
					}
					owner->CreateStageOne();						// Create hidden stage one, for later use in staging
					LVDC_Timebase = 0;								// Start TB0
					LVDC_TB_ETime = 0;
				}
				break;
			case 0: // MORE TB0
				double thrst[4];	// Thrust Settings for 2-2-2-2 start (see below)

				// At 10 seconds, play the countdown sound.
				if (owner->MissionTime >= -10.3) { // Was -10.9
					if (!owner->UseATC && owner->Scount.isValid()) {
						owner->Scount.play();
						owner->Scount.done();
					}
				}

				// Shut down venting at T - 9
				if(owner->MissionTime > -9 && owner->prelaunchvent[0] != NULL) { owner->DeactivatePrelaunchVenting(); }

				// Engine startup was staggered 2-2-2-2, with engine 7+5 starting first, then 6+8, then 2+4, then 3+1
			
				// Engine 7+5 combustion chamber ignition was at T-2.998,  6+8 at T-2.898, 2+4 at T-2.798, 1+3 at T-2.698
				// The engines idled in low-range thrust (about 2.5% thrust) for about 0.3 seconds
				// and then rose to 93% thrust in 0.085 seconds.
				// The rise from 93 to 100 percent thrust took 0.75 second.
				// Total engine startup time was 1.9 seconds.

				// Source: Apollo 7 LV Flight Evaluation

				// Transition from seperate throttles to single throttle
				if(owner->MissionTime < -0.715){ 
					int x=0; // Start Sequence Index
					double tm_1,tm_2,tm_3,tm_4; // CC light, 1st rise start, and 2nd rise start, and 100% thrust times.
					double SumThrust=0;

					while(x < 4){
						thrst[x] = 0;
						switch(x){
							case 0: // Engine 7+5
								tm_1 = -2.998; break;
							case 1: // Engine 6+8
								tm_1 = -2.898; break;
							case 2: // Engine 2+4
								tm_1 = -2.798; break;
							case 3: // Engine 1+3
								tm_1 = -2.698; break;
						}
						tm_2 = tm_1 + 0.3;  // Start of 1st rise
						tm_3 = tm_2 + 0.085; // Start of 2nd rise
						tm_4 = tm_3 + 0.75; // End of 2nd rise
						if(owner->MissionTime >= tm_1){
							// Light CC
							if(owner->MissionTime < tm_2){
								// Idle at 2.5% thrust
								thrst[x] = 0.025;
							}else{
								if(owner->MissionTime < tm_3){
									// the actual rise is so fast that any 'smoothing' is pointless
									thrst[x] = 0.93;
								}else{
									if(owner->MissionTime < tm_4){
										// Rise to 100% at a rate of 9 percent per second.
										thrst[x] = 0.93+(0.09*(owner->MissionTime-tm_3));
									}else{
										// Hold 100%
										thrst[x] = 1;
									}
								}
							}
						}
						x++; // Do next
					}
					SumThrust = (thrst[0]*2)+(thrst[1]*2)+(thrst[2]*2)+(thrst[3]*2);
	//				sprintf(oapiDebugString(),"LVDC: T %f | TB0 + %f | TH 0/1/2 = %f %f %f Sum %f",
	//					MissionTime,LVDC_TB_ETime,thrst[0],thrst[1],thrst[2],SumThrust);
					if(SumThrust > 0){ //let's hope that those numberings are right...
						owner->SetThrusterLevel(owner->th_main[0],thrst[3]); // Engine 1
						owner->SetThrusterLevel(owner->th_main[1],thrst[2]); // Engine 2
						owner->SetThrusterLevel(owner->th_main[2],thrst[3]); // Engine 3
						owner->SetThrusterLevel(owner->th_main[3],thrst[2]); // Engine 4
						owner->SetThrusterLevel(owner->th_main[4],thrst[0]); // Engine 5
						owner->SetThrusterLevel(owner->th_main[5],thrst[1]); // Engine 6
						owner->SetThrusterLevel(owner->th_main[6],thrst[0]); // Engine 7
						owner->SetThrusterLevel(owner->th_main[7],thrst[1]); // Engine 8

						owner->contrailLevel = SumThrust/8;
						owner->AddForce(_V(0, 0, -10. * owner->THRUST_FIRST_VAC), _V(0, 0, 0)); // Maintain hold-down lock
					}
				}else{
					// Get 100% thrust on all engines.
					sprintf(oapiDebugString(),"LVDC: T %f | TB0 + %f | TH = 100%%",owner->MissionTime,LVDC_TB_ETime);
					owner->SetThrusterGroupLevel(owner->thg_main,1);
					owner->contrailLevel = 1;				
					owner->AddForce(_V(0, 0, -10. * owner->THRUST_FIRST_VAC), _V(0, 0, 0));
				}

				if(owner->MissionTime >= 0){
					LVDC_Timebase = 1;
					LVDC_TB_ETime = 0;	
				}
				break;

			case 1: // LIFTOFF TIME
				if(liftoff == false){
					liftoff = true;
					owner->SetLiftoffLight();										// And light liftoff lamp
					owner->SetStage(LAUNCH_STAGE_ONE);								// Switch to stage one
					// Start mission and event timers
					owner->MissionTimerDisplay.Reset();
					owner->MissionTimerDisplay.SetEnabled(true);
					owner->EventTimerDisplay.Reset();
					owner->EventTimerDisplay.SetEnabled(true);
					owner->EventTimerDisplay.SetRunning(true);
					owner->agc.SetInputChannelBit(030, LiftOff, true);					// Inform AGC of liftoff
					owner->SetThrusterGroupLevel(owner->thg_main, 1.0);				// Set full thrust, just in case
					owner->contrailLevel = 1.0;
					if (owner->LaunchS.isValid() && !owner->LaunchS.isPlaying()){	// And play launch sound
						owner->LaunchS.play(NOLOOP,255);
						owner->LaunchS.done();
					}			
					sinceLastIGM = 1.7-simdt; // Rig to pass on fall-in
				}

				// Soft-Release Pin Dragging
				if(owner->MissionTime < 0.5){
					double PinDragFactor = 1 - (owner->MissionTime*2);
					owner->AddForce(_V(0, 0, -(owner->THRUST_FIRST_VAC * PinDragFactor)), _V(0, 0, 0));
				}

				// Below here are timed events that must not be dependent on the iteration delay.

				/*
				// ENGINE FAIL TEST:
				if(MissionTime > 22.5 && S1C_Engine_Out == false){
					SetThrusterResource(th_main[1], NULL); // Should stop the engine
					S1C_Engine_Out = true;
				}
				*/

				// S1B CECO TRIGGER:
				if(owner->MissionTime > 140.86){ // Apollo 7
					owner->SetThrusterResource(owner->th_main[4], NULL);
					owner->SetThrusterResource(owner->th_main[5], NULL);
					owner->SetThrusterResource(owner->th_main[6], NULL);
					owner->SetThrusterResource(owner->th_main[7], NULL);
					owner->SShutS.play(NOLOOP,235);
					owner->SShutS.done();
					// Clear liftoff light now - Apollo 15 checklist item
					owner->ClearLiftoffLight();
					S1B_Engine_Out = true;
					// Begin timebase 2
					LVDC_Timebase = 2;
					LVDC_TB_ETime = 0;
				}
				break;

			case 2:
				// S1B OECO TRIGGER
				// Done by low-level sensor.
				if (owner->stage == LAUNCH_STAGE_ONE && owner->GetFuelMass() <= 0){
					// For S1C thruster calibration
					fprintf(lvlog,"[T+%f] S1C OECO - Thrust %f N @ Alt %f\r\n\r\n",
						owner->MissionTime,owner->GetThrusterMax(owner->th_main[0]),owner->GetAltitude());

					// Move hidden S1B
					if (owner->hstg1) {
						VESSELSTATUS vs;
						owner->GetStatus(vs);
						S1B *stage1 = (S1B *) oapiGetVesselInterface(owner->hstg1);
						stage1->DefSetState(&vs);
					}				
					// Set timer
					S1B_Sep_Time = owner->MissionTime;
					// Engine Shutdown
					int i;
					for (i = 0; i < 5; i++){
						owner->SetThrusterResource(owner->th_main[i], NULL);
					}
					// Begin timebase 3
					LVDC_Timebase = 3;
					LVDC_TB_ETime = 0;
				}
				break;

			case 3:
				// S1B SEPARATION TRIGGER
				if(owner->stage == LAUNCH_STAGE_ONE && LVDC_TB_ETime >= 0.5){
					// Drop old stage
					owner->SwitchSelector(18);
				}
						
				if(LVDC_TB_ETime >= 2 && LVDC_TB_ETime < 6.8 && owner->stage == LAUNCH_STAGE_SIVB){
					owner->SetThrusterGroupLevel(owner->thg_main, ((LVDC_TB_ETime-4)*0.36));
					if(LVDC_TB_ETime >= 5){ owner->SetThrusterGroupLevel(owner->thg_ver,0); }
				}
				if(LVDC_TB_ETime >= 8.6 && S4B_IGN == false && owner->stage == LAUNCH_STAGE_SIVB){
					owner->SetThrusterGroupLevel(owner->thg_main, 1.0);
					S4B_IGN=true;
				}
				if(LVDC_TB_ETime > 20 && owner->LESAttached){
					T_LET = LVDC_TB_ETime;	// Update this. If the LET jettison never happens, the placeholder value
											// will start IGM anyway.
					owner->JettisonLET();				
				}
				if(LVDC_TB_ETime > 311.5 && MRS == false){
					// MR Shift
					fprintf(lvlog,"[TB%d+%f] MR Shift\r\n",LVDC_Timebase,LVDC_TB_ETime);
					// sprintf(oapiDebugString(),"LVDC: EMR SHIFT"); LVDC_GP_PC = 30; break;
					owner->SwitchSelector(23);
					MRS = true;
				}
				break;

			case 4:
				// TB4 timed events
				// Cutoff transient thrust
				if(LVDC_TB_ETime < 2){
					if(LVDC_TB_ETime < 0.25){
						// 95% of thrust dies in the first .25 second
						owner->SetThrusterLevel(owner->th_main[0], 1-(LVDC_TB_ETime*3.3048));
					}else{
						if(LVDC_TB_ETime < 1.5){
							// The remainder dies over the next 1.25 second
							owner->SetThrusterLevel(owner->th_main[0], 0.1738-((LVDC_TB_ETime-0.25)*0.1390));
						}else{
							// Engine is completely shut down at 1.5 second
							owner->SetThrusterLevel(owner->th_main[0], 0);
						}
					}
					fprintf(lvlog,"S4B CUTOFF: Time %f Thrust %f\r\n",LVDC_TB_ETime,owner->GetThrusterLevel(owner->th_main[0]));
				}
				if (LVDC_TB_ETime >= 10 && LVDC_EI_On == true){
					owner->SetStage(STAGE_ORBIT_SIVB);
					fprintf(lvlog,"[TB%d+%f] Set STAGE_ORBIT_SIVB\r\n",LVDC_Timebase,LVDC_TB_ETime);
					LVDC_EI_On = false;
				}
				if(LVDC_TB_ETime > 100){
					poweredflight = false; //powered flight nav off
				}
				// Orbital stage timed events
				if(owner->stage != STAGE_ORBIT_SIVB){ break; } // Stop here until enabled			
				// Venting			
				if (LVDC_TB_ETime >= 5773) {				
					if (owner->GetThrusterLevel(owner->th_main[0]) > 0) {
						owner->SetJ2ThrustLevel(0);
						if (owner->Realism){ owner->EnableDisableJ2(false); }
					}
				}else{
					if (LVDC_TB_ETime >= 5052) {					
						if (owner->GetThrusterLevel(owner->th_main[0]) == 0) {
							owner->EnableDisableJ2(true);
							owner->SetJ2ThrustLevel(1);
						}
					}
				}
				// Fuel boiloff every ten seconds.
				if (owner->MissionTime >= owner->NextMissionEventTime){
					if (owner->GetThrusterLevel(owner->th_main[0]) < 0.5){
						owner->SIVBBoiloff();					
					}
					owner->NextMissionEventTime = owner->MissionTime+10.0;				
				}
				// CSM/LV separation
				if(owner->CSMLVPyros.Blown()){
					owner->SeparateStage(CSM_LEM_STAGE);
					owner->SetStage(CSM_LEM_STAGE);
					LVDC_Stop = true;
					return; // Stop here
				}

				if (owner->ApolloNo == 5)
				{
					//
					// Separate nosecap
					//

					if (!owner->Crewed && owner->NosecapAttached && !owner->hNosecapVessel && LVDC_TB_ETime >= 45.0)
					{
						owner->SlowIfDesired();
						owner->NosecapAttached = false;
						owner->SetNosecapMesh();
						owner->JettisonNosecap();
					}

					//
					// For unmanned launches, seperate the payload on timer.
					//

					bool PayloadDeployed = false;

					if (!owner->Crewed && (LVDC_TB_ETime >= 600.0 - 20.))
					{
						owner->SlowIfDesired();
					}

					if (!owner->Crewed && (LVDC_TB_ETime >= 600.0))
					{
						owner->SlowIfDesired();
						PayloadDeployed = true;
						// Payload deploy
						owner->SeparateStage(CSM_LEM_STAGE);
						owner->SetStage(CSM_LEM_STAGE);
					}

					//
					// If the payload was deployed, delete us. Note that this just means that the SLA panels have
					// been blown off of the SIVB; the SIVB will have to do the actual payload deployment.
					//
					if (PayloadDeployed && owner->hs4bM)
					{
						oapiSetFocusObject(owner->hs4bM);
						oapiDeleteVessel(owner->GetHandle(), owner->hs4bM);
					}
				}

				break;
		}
		lvimu.Timestep(simt);								// Give a timestep to the LV IMU
		lvrg.Timestep(simdt);								// and RG
		CurrentAttitude = lvimu.GetTotalAttitude();			// Get current attitude
		/*
		if (lvimu.Operate) { fprintf(lvlog, "IMU: Operate\r\n"); }else{ fprintf(lvlog, "ERROR: IMU: NO-Operate\r\n"); }
		if (lvimu.TurnedOn) { fprintf(lvlog, "IMU: Turned On\r\n"); }else{ fprintf(lvlog, "ERROR: IMU: Turned OFF\r\n"); }
		if (lvimu.ZeroIMUCDUFlag) { fprintf(lvlog, "IMU: ERROR: Zero-IMU-CDU-Flag\r\n"); }
		if (lvimu.CoarseAlignEnableFlag) { fprintf(lvlog, "IMU: ERROR: Coarse-Align-Enable-Flag\r\n"); }
		if (lvimu.Caged) { fprintf(lvlog, "IMU: ERROR: Caged\r\n"); }
		*/
		AttRate = lvrg.GetRates();							// Get rates	
		//This is the actual LVDC code & logic; has to be independent from any of the above events
		if(LVDC_GRR && GRR_init == false){			
			fprintf(lvlog,"[T%f] GRR received!\r\n",owner->MissionTime);

			// Initial Position & Velocity
			MATRIX3 rot;
			owner->GetRelativePos(oapiGetGbodyByName ("Earth"), PosS);
			owner->GetRelativeVel(oapiGetGbodyByName ("Earth"), Dot0);
			
			oapiGetPlanetObliquityMatrix(oapiGetGbodyByName("Earth"),&rot);
			PosS = tmul(rot,PosS);
			Dot0 = tmul(rot,Dot0);
			fprintf(lvlog,"EarthRel Position: %f %f %f \r\n",PosS.x,PosS.y,PosS.z);
			fprintf(lvlog,"EarthRel Velocity: %f %f %f \r\n",Dot0.x,Dot0.y,Dot0.z);
			double rad      = sqrt  (PosS.x*PosS.x + PosS.y*PosS.y + PosS.z*PosS.z);
			phi_lng    = atan2 (PosS.z, PosS.x);
			phi_lat    = asin  (PosS.y/rad);
			cos_phi_L = cos(phi_lat);
			sin_phi_L = sin(phi_lat);
			fprintf(lvlog, "Latitude = %f, Longitude = %f\r\n", phi_lat*DEG, phi_lng*DEG);
			fprintf(lvlog, "cos_phi_l = %f, sin_phi_l = %f\r\n", cos_phi_L, sin_phi_L);
			rot.m11 = cos(phi_lng); rot.m12 = 0; rot.m13 = sin(phi_lng);
			rot.m21 = 0; rot.m22 = 1; rot.m23 = 0;
			rot.m31 = -sin(phi_lng); rot.m32 = 0; rot.m33 = cos(phi_lng);
			PosS = mul(rot,PosS);
			Dot0 = mul(rot,Dot0);
			fprintf(lvlog,"Rot:longitude\r\n");
			fprintf(lvlog,"EarthRel Position: %f %f %f \r\n",PosS.x,PosS.y,PosS.z);
			fprintf(lvlog,"EarthRel Velocity: %f %f %f \r\n",Dot0.x,Dot0.y,Dot0.z);
			rot.m11 = cos(-phi_lat); rot.m12 = -sin(-phi_lat); rot.m13 = 0;
			rot.m21 = sin(-phi_lat); rot.m22 = cos(-phi_lat); rot.m23 = 0;
			rot.m31 = 0; rot.m32 = 0; rot.m33 = 1;
			PosS = mul(rot,PosS);
			Dot0 = mul(rot,Dot0);
			fprintf(lvlog,"Rot:latitude\r\n");
			fprintf(lvlog,"EarthRel Position: %f %f %f \r\n",PosS.x,PosS.y,PosS.z);
			fprintf(lvlog,"EarthRel Velocity: %f %f %f \r\n",Dot0.x,Dot0.y,Dot0.z);
			
			// Time into launch window = launch time from midnight - reference time of launch from midnight
			// azimuth = coeff. of azimuth polynomial * time into launch window

			// preset to fixed value to be independent from any external stuff
			Azimuth = 72.0;
			fprintf(lvlog,"Azimuth = %f\r\n",Azimuth);
			rot.m11 = 1; rot.m12 = 0; rot.m13 = 0;
			rot.m21 = 0; rot.m22 = cos((90-Azimuth)*RAD); rot.m23 = -sin((90-Azimuth)*RAD);
			rot.m31 = 0; rot.m32 = sin((90-Azimuth)*RAD); rot.m33 = cos((90-Azimuth)*RAD);
			PosS = mul(rot,PosS);
			Dot0 = mul(rot,Dot0);
			fprintf(lvlog,"Rot:azimuth\r\n");
			fprintf(lvlog,"EarthRel Position: %f %f %f \r\n",PosS.x,PosS.y,PosS.z);
			fprintf(lvlog,"EarthRel Velocity: %f %f %f \r\n",Dot0.x,Dot0.y,Dot0.z);
			PosS.y = -PosS.y;
			Dot0.y = -Dot0.y;
			// Azo and Azs are used to scale the polys below. These numbers are from Apollo 11.
			// Dunno if this actually works. The numbers are in "PIRADS", whatever that is.
			Azo = 4; 
			Azs = 2;

			if(i_op == true){
				// CALCULATE INCLINATION FROM AZIMUTH
				Inclination = 0;
				int x=0;
				while(x < 7){
					Inclination += fx[x] * pow((Azimuth-Azo)/Azs,x);
					x++;
				}
			}else{
				// CALCULATE INCLINATION FROM TIME INTO LAUNCH WINDOW
				// inclination = coeff. for inclination-from-time polynomial * Time into launch window
			}
			// Let's cheat a little. (Apollo 7)
			Inclination = 31.605;
			fprintf(lvlog,"Inclination = %f\r\n",Inclination);

			if(theta_N_op == true){
				// CALCULATE DESCENDING NODAL ANGLE FROM AZIMUTH
				DescNodeAngle = 0;
				int x=0;
				while(x < 7){
					DescNodeAngle += gx[x] * pow((Azimuth-Azo)/Azs,x);
					x++;
				}
			}else{
				// CALCULATE DESCENDING NODAL ANGLE FROM TIME INTO LAUNCH WINDOW
				// DNA = coeff. for DNA-from-time polynomial * Time into launch window
			}
			
			// Cheat a little more. (Apollo 7)
			DescNodeAngle = 119.0; 
			fprintf(lvlog,"DescNodeAngle = %f\r\n",DescNodeAngle);

			// Need to make those into radians
			Azimuth *= RAD;
			Inclination *= RAD;
			DescNodeAngle *= RAD;

			fprintf(lvlog,"Rad Convert: Az / Inc / DNA = %f %f %f\r\n",Azimuth,Inclination,DescNodeAngle);

			if (TerminalConditions == false)
			{
				// p is the semi-latus rectum of the desired terminal ellipse.
				p = (mu / C_3)*(pow(e, 2) - 1);
				fprintf(lvlog, "p = %f, mu = %f, e2 = %f, mu/C_3 = %f\r\n", p, mu, pow(e, 2), mu / C_3);

				// K_5 is the IGM terminal velocity constant
				K_5 = sqrt(mu / p);
				fprintf(lvlog, "K_5 = %f\r\n", K_5);

				R_T = p / (1 + (e*(cos(f))));
				V_T = K_5*sqrt((1 + ((2 * e)*(cos(f))) + pow(e, 2)));
				gamma_T = atan((e*(sin(f))) / (1 + (e*(cos(f)))));
				G_T = -mu / pow(R_T, 2);
			}
			fprintf(lvlog,"R_T = %f (Expecting 6,563,366), V_T = %f (Expecting 7793.0429), gamma_T = %f\r\n",R_T,V_T,gamma_T);

			// G MATRIX CALCULATION
			MX_A.m11 = cos_phi_L;  MX_A.m12 = sin_phi_L*sin(Azimuth); MX_A.m13 = -(sin_phi_L*cos(Azimuth));
			MX_A.m21 = -sin_phi_L; MX_A.m22 = cos_phi_L*sin(Azimuth); MX_A.m23 = -(cos_phi_L*cos(Azimuth));
			MX_A.m31 = 0;  MX_A.m32 = cos(Azimuth);  MX_A.m33 = sin(Azimuth);

			MX_B.m11 = cos(DescNodeAngle); MX_B.m12 = 0; MX_B.m13 = sin(DescNodeAngle);
			MX_B.m21 = sin(DescNodeAngle)*sin(Inclination); MX_B.m22 = cos(Inclination); 
			MX_B.m23 = -cos(DescNodeAngle)*sin(Inclination);
			MX_B.m31 = -sin(DescNodeAngle)*cos(Inclination); MX_B.m32 = sin(Inclination);
			MX_B.m33 = cos(DescNodeAngle)*cos(Inclination);

			MX_G = mul(MX_B,MX_A); // Matrix Multiply
			Y_u= -(PosS.x*MX_A.m21+PosS.y*MX_A.m22+PosS.z*MX_A.m23); //position component south of equator
			R = pow(pow(PosS.x,2)+pow(PosS.y,2)+pow(PosS.z,2),0.5);  //instantaneous distance from earth's center
			S = (-mu/pow(R,3))*(1+J*pow(a/R,2)*(1-5*pow(Y_u/R,2)));
			P = (mu/pow(R,2))*pow(a/R,2) *((2*J*Y_u)/R);
			ddotG_last.x = PosS.x*S+MX_A.m21*P; //gravity acceleration vector
			ddotG_last.y = PosS.y*S+MX_A.m22*P;
			ddotG_last.z = PosS.z*S+MX_A.m23*P;
			PCommandedAttitude.x = (1.5* PI) + Azimuth;
			PCommandedAttitude.y = 0;
			PCommandedAttitude.z = 0;
			lvimu.ZeroPIPACounters();
			sinceLastIGM = 0;
			GRR_init = true;
			fprintf(lvlog,"Initialization completed.\r\n\r\n");
			goto minorloop;
		}
		// various clocks the LVDC needs...
		if(LVDC_GRR == true){ TAS += simdt; } //time since GRR
		if(liftoff == true){ t_clock += simdt; } //time since liftoff
		sinceLastIGM += simdt;
		if(sinceLastIGM < 1.7){ goto minorloop; }
		dt_c = sinceLastIGM;
		IGMInterval = sinceLastIGM;
		sinceLastIGM = 0;
		IGMCycle++;				// For debugging
		fprintf(lvlog,"[%d+%f] *** Major Loop %d ***\r\n",LVDC_Timebase,LVDC_TB_ETime,IGMCycle);
		//powered flight nav
		if(LVDC_GRR == true){
			if(poweredflight == true){
				DotM_act.x += (lvimu.CDURegisters[LVRegPIPAX]); //read the PIPA CDUs
				DotM_act.y += (lvimu.CDURegisters[LVRegPIPAY]);
				DotM_act.z += (lvimu.CDURegisters[LVRegPIPAZ]);
			}
			Fm = pow((pow(((DotM_act.x - DotM_last.x)/dt_c),2)+ pow(((DotM_act.y - DotM_last.y)/dt_c),2)+ pow(((DotM_act.z - DotM_last.z)/dt_c),2)),0.5);
			PosS.x += (DotM_act.x + DotM_last.x) * dt_c / 2 + (DotG_last.x + ddotG_last.x * dt_c / 2)*dt_c + Dot0.x * dt_c; //position vector
			PosS.y += (DotM_act.y + DotM_last.y) * dt_c / 2 + (DotG_last.y + ddotG_last.y * dt_c / 2)*dt_c + Dot0.y * dt_c;
			PosS.z += (DotM_act.z + DotM_last.z) * dt_c / 2 + (DotG_last.z + ddotG_last.z * dt_c / 2)*dt_c + Dot0.z * dt_c;
			Y_u= -(PosS.x*MX_A.m21+PosS.y*MX_A.m22+PosS.z*MX_A.m23); //position component south of equator
			R = pow(pow(PosS.x,2)+pow(PosS.y,2)+pow(PosS.z,2),0.5); //instantaneous distance from earth's center
			S = (-mu/pow(R,3))*(1+J*pow(a/R,2)*(1-5*pow(Y_u/R,2)));
			P = (mu/pow(R,2))*pow(a/R,2) *((2*J*Y_u)/R);
			ddotG_act.x = PosS.x*S+MX_A.m21*P; //gravity acceleration vector
			ddotG_act.y = PosS.y*S+MX_A.m22*P;
			ddotG_act.z = PosS.z*S+MX_A.m23*P;
			CG = pow((pow(ddotG_act.x,2)+ pow(ddotG_act.y,2)+ pow(ddotG_act.z,2)),0.5);
			DotG_act.x = DotG_last.x + (ddotG_act.x  + ddotG_last.x) * dt_c / 2; //gravity velocity vector
			DotG_act.y = DotG_last.y + (ddotG_act.y  + ddotG_last.y) * dt_c / 2;
			DotG_act.z = DotG_last.z + (ddotG_act.z  + ddotG_last.z) * dt_c / 2;
			DotS.x = DotM_act.x + DotG_act.x + Dot0.x; //total velocity vector 
			DotS.y = DotM_act.y + DotG_act.y + Dot0.y;
			DotS.z = DotM_act.z + DotG_act.z + Dot0.z;
			V = pow(pow(DotS.x,2)+pow(DotS.y,2)+pow(DotS.z,2),0.5);
			//save the 'actual' variables as 'last' variables for the next step
			DotM_last = DotM_act;
			DotG_last = DotG_act;
			ddotG_last = ddotG_act;
			fprintf(lvlog,"Navigation \r\n");
			fprintf(lvlog,"Inertial Attitude: %f %f %f \r\n",CurrentAttitude.x*DEG,CurrentAttitude.y*DEG,CurrentAttitude.z*DEG);
			fprintf(lvlog,"DotM: %f %f %f \r\n", DotM_act.x,DotM_act.y,DotM_act.z);
			fprintf(lvlog,"Gravity velocity: %f %f %f \r\n", DotG_act.x,DotG_act.y,DotG_act.z);
			fprintf(lvlog,"EarthRel Position: %f %f %f \r\n",PosS.x,PosS.y,PosS.z);
			fprintf(lvlog,"EarthRel Velocity: %f %f %f \r\n",DotS.x,DotS.y,DotS.z);
			fprintf(lvlog,"Sensed Acceleration: %f \r\n",Fm);	
			fprintf(lvlog,"Gravity Acceleration: %f \r\n",CG);	
			fprintf(lvlog,"Total Velocity: %f \r\n",V);
			fprintf(lvlog,"Dist. from Earth's Center: %f \r\n",R);
			fprintf(lvlog,"S: %f \r\n",S);
			fprintf(lvlog,"P: %f \r\n",P);
			lvimu.ZeroPIPACounters();
		}
		if(liftoff == false){//liftoff not received; initial roll command for FCC
			CommandedAttitude.x =  (360-100)*RAD + Azimuth;
			CommandedAttitude.y =  0;
			CommandedAttitude.z =  0;
			fprintf(lvlog,"[%d+%f] Initial roll command: %f\r\n",LVDC_Timebase,LVDC_TB_ETime,CommandedAttitude.x*DEG);
			goto minorloop;
		}
		if(BOOST == false){//i.e. we're either in orbit or boosting out of orbit
			if(LVDC_Timebase == 4 && (LVDC_TB_ETime > TI5F2)){
				goto orbitalguidance;
			}else{
				goto minorloop;
			}
		} //TBD: 
		if(LVDC_Timebase < 3 || (LVDC_TB_ETime - T_LET < 0)){ 
			//Pre-IGM guidance:
			if(S1B_Engine_Out == true && T_EO1 == 0){
				//S1B engine out interrupt handling
				T_EO1 = 1;
				t_fail = t_clock;
				fprintf(lvlog,"[%d+%f] S1B engine out interrupt received! t_fail = %f\r\n",LVDC_Timebase,LVDC_TB_ETime,t_fail);
			}
			if(t_clock > t_1){
				//roll/pitch program
				if(t_clock >= t_2 && T_EO1 > 0){
					//time to re-calculate freeze time?
					T_EO1 = -1; //allow only one pass thru re-calculation
					if(t_fail <= t_2){ dT_F = t_3; }
					if(t_2 < t_clock && t_clock <= t_4){ dT_F = (B_11 * t_fail) + B_12; }
					if(t_4 < t_clock && t_clock <= t_5){ dT_F = (B_21 * t_fail) + B_22; }
					if(t_5 < t_clock){ dT_F = 0; }
					t_6 = t_clock + dT_F;
					T_ar = T_ar + (0.25*(T_ar - t_fail));
					fprintf(lvlog,"[%d+%f] Freeze time recalculated! t_6 = %f T_ar = %f\r\n",LVDC_Timebase,LVDC_TB_ETime,t_6,T_ar);
				}
				if(t_clock >= t_6){
					if (t_clock > T_ar){
						//time for pitch freeze?
						fprintf(lvlog,"[%d+%f] Pitch freeze! \r\n",LVDC_Timebase,LVDC_TB_ETime);
						CommandedAttitude.y = PCommandedAttitude.y;
						CommandedAttitude.x = 360 * RAD;
						CommandedAttitude.z = 0;
						goto limittest;
					}else{
						//Pre-IGM steering
						int x=0,y=0;						
						double Tc = t_clock - dT_F, cmd = 0;  
						if(Tc < T_S1){               x = 1; }
						if(T_S1 <= Tc && Tc < T_S2){ x = 2; }
						if(T_S2 <= Tc && Tc < T_S3){ x = 3; }
						if(T_S3 <= Tc){              x = 4; }
						while(y <= 4){
							cmd += (Fx[x][y] * ((double)pow(Tc,y)));
							y++;
						}
						CommandedAttitude.y = cmd * RAD;
						CommandedAttitude.x = 360 * RAD;
						CommandedAttitude.z = 0;
						fprintf(lvlog,"[%d+%f] Roll/pitch programm %f \r\n",LVDC_Timebase,LVDC_TB_ETime,cmd);
						goto limittest;
					}
				}else{
					CommandedAttitude.y = PCommandedAttitude.y;
					CommandedAttitude.x = 360 * RAD;
					CommandedAttitude.z = 0;
					goto limittest;
				}
			}else{
				CommandedAttitude.z = 0; //no yaw
				CommandedAttitude.y = 0; //no pitch
				CommandedAttitude.x = (360-100)*RAD + Azimuth; //no roll
				goto limittest;
			}
			//end of pre igm
		}
		if(HSL == false){		
			// If we are not in the high-speed loop
			fprintf(lvlog,"HSL False\r\n");
			// IGM STAGE LOGIC
			if(MRS == true){
				fprintf(lvlog,"Post-MRS\n");
				if(t_B1 <= t_B3){
					tau2 = V_ex2/Fm;
					fprintf(lvlog,"Normal Tau: tau2 = %f, F/m = %f, m = %f \r\n",tau2,Fm,owner->GetMass());
				}else{
					// This is the "ARTIFICIAL TAU" code.
					t_B3 += dt_c; 
					tau2 = tau2+(T_1*(dotM_1/dotM_2));
					fprintf(lvlog,"Art. Tau: tau2 = %f, T_1 = %f, dotM_1 = %f dotM_2 = %f \r\n",tau2,T_1,dotM_1,dotM_2);
					fprintf(lvlog,"Diff: %f \r\n",(tau2-(V_ex2/Fm)));
					T_2 = T_2+T_1*(dotM_1/dotM_2);
					T_1 = 0;
					fprintf(lvlog,"T_1 = 0\r\nT_2 = %f, dotM_1 = %f, dotM_2 = %f \r\n",T_2,dotM_1,dotM_2);
				}					
			}else{
				fprintf(lvlog,"Pre-MRS\n");
				if(T_1 < 0){	// If we're out of first-stage IGM time
					// Artificial Tau
					tau2 = tau2+(T_1*(dotM_1/dotM_2));
					fprintf(lvlog,"Art. Tau: tau2 = %f, T_1 = %f, dotM_1 = %f, dotM_2 = %f \r\n",tau2,T_1,dotM_1,dotM_2);
					T_2 = T_2+T_1*(dotM_1/dotM_2);
					T_1 = 0;
					fprintf(lvlog,"T_2 = %f, T_1 = %f, dotM_1 = %f, dotM_2 = %f \r\n",T_2,T_1,dotM_1,dotM_2);		
				}else{															
					tau1 = V_ex1/Fm; 
					fprintf(lvlog,"Normal Tau: tau1 = %f, F/m = %f m = %f\r\n",tau1,Fm, owner->GetMass());
				}
			}
			fprintf(lvlog,"--- STAGE INTEGRAL LOGIC ---\r\n");
			// CHI-TILDE LOGIC
			// STAGE INTEGRAL CALCULATIONS				
			Pos4 = mul(MX_G,PosS);
			fprintf(lvlog,"Pos4 = %f, %f, %f\r\n",Pos4.x,Pos4.y,Pos4.z);
			fprintf(lvlog,"T_1 = %f,T_2 = %f\r\n",T_1,T_2);
			L_1 = V_ex1 * log(tau1 / (tau1-T_1));
			J_1 = (L_1 * tau1) - (V_ex1 * T_1);
			S_1 = (L_1 * T_1) - J_1;
			Q_1 = (S_1 * tau1) - ((V_ex1 * pow(T_1,2)) / 2);
			P_1 = (J_1 * tau1) - ((V_ex1 * pow(T_1,2)) / 2);
			U_1 = (Q_1 * tau1) - ((V_ex1 * pow(T_1,3)) / 6);
			fprintf(lvlog,"L_1 = %f, J_1 = %f, S_1 = %f, Q_1 = %f, P_1 = %f, U_1 = %f\r\n",L_1,J_1,S_1,Q_1,P_1,U_1);

			Lt_2 = V_ex2 * log(tau2 / (tau2-Tt_2));
			fprintf(lvlog,"Lt_2 = %f, tau2 = %f, Tt_2 = %f\r\n",Lt_2,tau2,Tt_2);

			Jt_2 = (Lt_2 * tau2) - (V_ex2 * Tt_2);
			fprintf(lvlog,"Jt_2 = %f",Jt_2);
			Lt_Y = (L_1 + Lt_2);
			fprintf(lvlog,", Lt_Y = %f\r\n",Lt_Y);

			// SELECT RANGE OPTION				
gtupdate:	// Target of jump from further down
			fprintf(lvlog,"--- GT UPDATE ---\r\n");

			// RANGE ANGLE 1
			fprintf(lvlog,"RANGE ANGLE\r\n");
			d2 = (V * Tt_T) - Jt_2 + (Lt_Y * Tt_2) - (ROV / V_ex2) * 
				((tau1 - T_1) * L_1 + (tau2 - Tt_2) * Lt_2) *
				(Lt_Y + V - V_T);
			phi_T = ((atan2(Pos4.z,Pos4.x))+(((1/R_T)*(S_1+d2))*(cos(gamma_T))));
			fprintf(lvlog,"V = %f, d2 = %f, phi_T = %f\r\n",V,d2,phi_T);				

			// FREEZE TERMINAL CONDITIONS TEST
			if(!(Tt_T <= eps_3)){
				// UPDATE TERMINAL CONDITIONS
				fprintf(lvlog,"UPDATE TERMINAL CONDITIONS\r\n");
				f = phi_T + alpha_D;
				R_T = p/(1+((e*(cos(f)))));
				fprintf(lvlog,"f = %f, R_T = %f\r\n",f,R_T);
				V_T = K_5 * pow(1+((2*e)*(cos(f)))+pow(e,2),0.5);
				gamma_T = atan((e*(sin(f)))/(1+(e*(cos(f)))));
				G_T = -mu/pow(R_T,2);
				fprintf(lvlog,"V_T = %f, gamma_T = %f, G_T = %f\r\n",V_T,gamma_T,G_T);
			}

			// UNROTATED TERMINAL CONDITIONS
			fprintf(lvlog,"UNROTATED TERMINAL CONDITIONS\r\n");
			xi_T = R_T;					
			dot_zeta_T = V_T * (cos(gamma_T));
			dot_xi_T = V_T * (sin(gamma_T));
			ddot_zeta_GT = 0;
			ddot_xi_GT = G_T;
			fprintf(lvlog,"xi_T = %f, dot_zeta_T = %f, dot_xi_T = %f\r\n",xi_T,dot_zeta_T,dot_xi_T);
			fprintf(lvlog,"ddot_zeta_GT = %f, ddot_xi_GT = %f\r\n",ddot_zeta_GT,ddot_xi_GT);
				
			// ROTATION TO TERMINAL COORDINATES
			fprintf(lvlog,"--- ROTATION TO TERMINAL COORDINATES ---\r\n");
			// This is the last time PosS is referred to.
			MX_phi_T.m11 = (cos(phi_T));    MX_phi_T.m12 = 0; MX_phi_T.m13 = ((sin(phi_T)));
			MX_phi_T.m21 = 0;               MX_phi_T.m22 = 1; MX_phi_T.m23 = 0;
			MX_phi_T.m31 = (-sin(phi_T)); MX_phi_T.m32 = 0; MX_phi_T.m33 = (cos(phi_T));
			fprintf(lvlog,"MX_phi_T R1 = %f %f %f\r\n",MX_phi_T.m11,MX_phi_T.m12,MX_phi_T.m13);
			fprintf(lvlog,"MX_phi_T R2 = %f %f %f\r\n",MX_phi_T.m21,MX_phi_T.m22,MX_phi_T.m23);
			fprintf(lvlog,"MX_phi_T R3 = %f %f %f\r\n",MX_phi_T.m31,MX_phi_T.m32,MX_phi_T.m33);

			MX_K = mul(MX_phi_T,MX_G);
			fprintf(lvlog,"MX_K R1 = %f %f %f\r\n",MX_K.m11,MX_K.m12,MX_K.m13);
			fprintf(lvlog,"MX_K R2 = %f %f %f\r\n",MX_K.m21,MX_K.m22,MX_K.m23);
			fprintf(lvlog,"MX_K R3 = %f %f %f\r\n",MX_K.m31,MX_K.m32,MX_K.m33);

			PosXEZ = mul(MX_K,PosS);
			DotXEZ = mul(MX_K,DotS);	
			fprintf(lvlog,"PosXEZ = %f %f %f\r\n",PosXEZ.x,PosXEZ.y,PosXEZ.z);
			fprintf(lvlog,"DotXEZ = %f %f %f\r\n",DotXEZ.x,DotXEZ.y,DotXEZ.z);

			VECTOR3 RTT_T1,RTT_T2;
			RTT_T1.x = ddot_xi_GT; RTT_T1.y = 0;        RTT_T1.z = ddot_zeta_GT;
			RTT_T2 = ddotG_act;
			fprintf(lvlog,"RTT_T1 = %f %f %f\r\n",RTT_T1.x,RTT_T1.y,RTT_T1.z);
			fprintf(lvlog,"RTT_T2 = %f %f %f\r\n",RTT_T2.x,RTT_T2.y,RTT_T2.z);

			RTT_T2 = mul(MX_K,RTT_T2);
			fprintf(lvlog,"RTT_T2 (mul) = %f %f %f\r\n",RTT_T2.x,RTT_T2.y,RTT_T2.z);

			RTT_T1 = RTT_T1+RTT_T2;	  
			fprintf(lvlog,"RTT_T1 (add) = %f %f %f\r\n",RTT_T1.x,RTT_T1.y,RTT_T1.z);

			ddot_xi_G   = 0.5*RTT_T1.x;
			ddot_eta_G  = 0.5*RTT_T1.y;
			ddot_zeta_G = 0.5*RTT_T1.z;
			fprintf(lvlog,"ddot_XEZ_G = %f %f %f\r\n",ddot_xi_G,ddot_eta_G,ddot_zeta_G);

			// ESTIMATED TIME-TO-GO
			fprintf(lvlog,"--- ESTIMATED TIME-TO-GO ---\r\n");

			dot_dxit   = dot_xi_T - DotXEZ.x - (ddot_xi_G*Tt_T);
			dot_detat  = -DotXEZ.y - (ddot_eta_G * Tt_T);
			dot_dzetat = dot_zeta_T - DotXEZ.z - (ddot_zeta_G * Tt_T);
			fprintf(lvlog,"dot_XEZt = %f %f %f\r\n",dot_dxit,dot_detat,dot_dzetat);
			dV = pow((pow(dot_dxit,2)+pow(dot_detat,2)+pow(dot_dzetat,2)),0.5);
			dL_2 = (((pow(dot_dxit,2)+pow(dot_detat,2)+pow(dot_dzetat,2))/Lt_Y)-Lt_Y)/2;
			// if(dL_3 < 0){ sprintf(oapiDebugString(),"Est TTG: dL_3 %f (X/E/Z %f %f %f) @ Cycle %d (TB%d+%f)",dL_3,dot_dxit,dot_detat,dot_dzetat,IGMCycle,LVDC_Timebase,LVDC_TB_ETime);
			//	LVDC_GP_PC = 30; break; } 

			dT_2 = (dL_2*(tau2-Tt_2))/V_ex2;
			T_2 = Tt_2 + dT_2;
			T_T = Tt_T + dT_2;
			fprintf(lvlog,"dV = %f, dL_2 = %f, dT_2 = %f, T_2 = %f, T_T = %f\r\n",dV,dL_2,dT_2,T_2,T_T);

			// TARGET PARAMETER UPDATE
			if(!(UP > 0)){	
				fprintf(lvlog,"--- TARGET PARAMETER UPDATE ---\r\n");
				UP = 1; 
				Tt_2 = T_2;
				Tt_T = T_T;
				fprintf(lvlog,"UP = 1, Tt_2 = %f, Tt_T = %f\r\n",Tt_2,Tt_T);
				Lt_2 = Lt_2 + dL_2;
				Lt_Y = Lt_Y + dL_2;
				Jt_2 = Jt_2 + (dL_2*T_2);
				fprintf(lvlog,"Lt_2 = %f, Lt_Y = %f, Jt_2 = %f\r\n",Lt_2,Lt_Y,Jt_2);

				// NOTE: This is perfectly valid. Just because Dijkstra and Wirth think otherwise
				// does not mean it's gospel. I shouldn't have to defend my choice of instructions
				// because a bunch of people read the title of the paper with no context and take
				// it as a direct revelation from God with no further study into the issue.
				fprintf(lvlog,"RECYCLE\r\n");
				goto gtupdate; // Recycle. 
			}

			// tchi_y AND tchi_p CALCULATIONS
			fprintf(lvlog,"--- tchi_y/p CALCULATION ---\r\n");

			L_2 = Lt_2 + dL_2;
			J_2 = Jt_2 + (dL_2*T_2);
			S_2 = (L_2*T_2)-J_2;
			Q_2 = (S_2*tau2)-((V_ex2*pow(T_2,2))/2);
			P_2 = (J_2*(tau2+(2*T_2)))-((V_ex2*pow(T_2,2))/2);
			U_2 = (Q_2*(tau2+(2*T_2)))-((V_ex2*pow(T_2,3))/6);
			fprintf(lvlog,"L_2 = %f, J_2 = %f, S_2 = %f, Q_2 = %f, P_2 = %f, U_2 = %f\r\n",L_2,J_2,S_2,Q_2,P_2,U_2);

			// This is where velocity-to-be-gained is generated.

			dot_dxi   = dot_dxit   - (ddot_xi_G   * dT_2);
			dot_deta  = dot_detat  - (ddot_eta_G  * dT_2);
			dot_dzeta = dot_dzetat - (ddot_zeta_G * dT_2);
			fprintf(lvlog,"dot_dXEZ = %f %f %f\r\n",dot_dxi,dot_deta,dot_dzeta);

				
	//		sprintf(oapiDebugString(),".dxi = %f | .deta %f | .dzeta %f | dT3 %f",
	//			dot_dxi,dot_deta,dot_dzeta,dT_3);

			L_Y = L_1 + L_2;
			tchi_y_last = tchi_y;
			tchi_p_last = tchi_p;
			tchi_y = atan2(dot_deta,pow(pow(dot_dxi,2)+pow(dot_dzeta,2),0.5));
			tchi_p = atan2(dot_dxi,dot_dzeta);				
			UP = -1;
			fprintf(lvlog,"L_Y = %f, tchi_y = %f, tchi_p = %f, UP = -1\r\n",L_Y,tchi_y,tchi_p);

			// *** END OF CHI-TILDE LOGIC ***
			// Is it time for chi-tilde mode?
			if(Tt_T <= eps_2){
				fprintf(lvlog,"CHI BAR STEERING ON, REMOVE ALTITUDE CONSTRAINS (K_1-4 = 0)\r\n");
				// Yes
				// Go to the test that we would be testing if HSL was true
				K_1 = 0; K_2 = 0; K_3 = 0; K_4 = 0;
				// See the note above if the presence of this goto bothers you.
				// sprintf(oapiDebugString(),"LVDC: HISPEED LOOP ENTRY: Tt_T %f eps_2 %f", Tt_T,eps_2); LVDC_GP_PC = 30; break; // STOP
				goto hsl;
			}else{
				// No.
				// YAW STEERING PARAMETERS
				fprintf(lvlog,"--- YAW STEERING PARAMETERS ---\r\n");

				J_Y = J_1 + J_2 + (L_2*T_2);
				S_Y = S_1 - J_2 + (L_Y*T_2);
				Q_Y = Q_1 + Q_2 + (S_2*T_2) + ((T_2)*J_1);
				K_Y = L_Y/J_Y;
				D_Y = S_Y - (K_Y*Q_Y);
				fprintf(lvlog,"J_Y = %f, S_Y = %f, Q_Y = %f, K_Y = %f, D_Y = %f\r\n",J_Y,S_Y,Q_Y,K_Y,D_Y);

				deta = PosXEZ.y + (DotXEZ.y*T_T) + ((ddot_eta_G*pow(T_T,2))/2) + (S_Y*(sin(tchi_y)));
				K_3 = deta/(D_Y*(cos(tchi_y)));
				K_4 = K_Y*K_3;
				fprintf(lvlog,"deta = %f, K_3 = %f, K_4 = %f\r\n",deta,K_3,K_4);

				// PITCH STEERING PARAMETERS
				fprintf(lvlog,"--- PITCH STEERING PARAMETERS ---\r\n");

				L_P = L_Y*cos(tchi_y);
				C_2 = cos(tchi_y)+(K_3*sin(tchi_y));
				C_4 = K_4*sin(tchi_y);
				J_P = (J_Y*C_2) - (C_4*(P_1+P_2+(pow(T_2,2)*L_2)));
				fprintf(lvlog,"L_P = %f, C_2 = %f, C_4 = %f, J_P = %f\r\n",L_P,C_2,C_4,J_P);

				S_P = (S_Y*C_2) - (C_4*Q_Y);
				Q_P = (Q_Y*C_2) - (C_4*(U_1+U_2+(pow(T_2,2)*S_2)+((T_2)*P_1)));
				K_P = L_P/J_P;
				D_P = S_P - (K_P*Q_P);
				fprintf(lvlog,"S_P = %f, Q_P = %f, K_P = %f, D_P = %f\r\n",S_P,Q_P,K_P,D_P);

				dxi = PosXEZ.x - xi_T + (DotXEZ.x*T_T) + ((ddot_xi_G*pow(T_T,2))/2) + (S_P*(sin(tchi_p)));
				K_1 = dxi/(D_P*cos(tchi_p));
				K_2 = K_P*K_1;
				fprintf(lvlog,"dxi = %f, K_1 = %f, K_2 = %f, cos(tchi_p) = %f\r\n",dxi,K_1,K_2,cos(tchi_p));
			}
		}else{
hsl:		// HIGH-SPEED LOOP ENTRY				
			// CUTOFF VELOCITY EQUATIONS
			fprintf(lvlog,"--- CUTOFF VELOCITY EQUATIONS ---\r\n");
			V_0 = V_1;
			V_1 = V_2;
			//V_2 = 0.5 * (V+(pow(V_1,2)/V));
			V_2 = V;
			dtt_1 = dtt_2;
			dtt_2 = dt_c;					
			fprintf(lvlog,"V = %f, Tt_t = %f\r\n",V,Tt_T);
			fprintf(lvlog,"V = %f, V_0 = %f, V_1 = %f, V_2 = %f, dtt_1 = %f, dtt_2 = %f\r\n",V,V_0,V_1,V_2,dtt_1,dtt_2);
			if(Tt_T <= eps_4 && V + V_TC >= V_T){
				fprintf(lvlog,"--- HI SPEED LOOP ---\r\n");
				// TGO CALCULATION
				fprintf(lvlog,"--- TGO CALCULATION ---\r\n");
				if(GATE5 == false){
					fprintf(lvlog,"CHI FREEZE\r\n");
					// CHI FREEZE
					tchi_y = tchi_y_last;
					tchi_p = tchi_p_last;
					HSL = true;
					GATE5 = true;
					T_GO = T_2;
					fprintf(lvlog,"HSL = true, GATE5 = true, T_GO = %f\r\n",T_GO);
				}
					
				// TGO DETERMINATION
				fprintf(lvlog,"--- TGO DETERMINATION ---\r\n");

				a_2 = (((V_2-V_1)*dtt_1)-((V_1-V_0)*dtt_2))/(dtt_2*dtt_1*(dtt_2+dtt_1));
				a_1 = ((V_2-V_1)/dtt_2)+(a_2*dtt_2);
				T_GO = ((V_T-dV_B)-V_2)/(a_1+a_2*T_GO);
				T_CO = TAS+T_GO;
				fprintf(lvlog,"a_2 = %f, a_1 = %f, T_GO = %f, T_CO = %f, V_T = %f\r\n",a_2,a_1,T_GO,T_CO,V_T);

				// Done, go to navigation
				//sprintf(oapiDebugString(),"TB%d+%f | CP/Y %f %f | -HSL- TGO %f",
				//	LVDC_Timebase,LVDC_TB_ETime,PITCH,YAW,T_GO);

				goto minorloop;
			}
			// End of HSL
		}
		// GUIDANCE TIME UPDATE
		fprintf(lvlog,"--- GUIDANCE TIME UPDATE ---\r\n");

		if(BOOST){
			if(MRS == false){
				T_1 = T_1 - dt_c; 
			}else{
				if(t_B1 <= t_B3){
					T_2 = T_2 - dt_c;
				}else{
					// Here if t_B1 is bigger.
					fprintf(lvlog,"t_B1 = %f, t_B3 = %f\r\n",t_B1,t_B3);
					T_1 = (((dotM_1*(t_B3-t_B1))-(dotM_2*t_B3))*dt)/(dotM_1*t_B1);
				}
			}
		}
		fprintf(lvlog,"T_1 = %f, T_2 = %f, dt_c = %f\r\n",T_1,T_2,dt_c);
		Tt_2 = T_2;
		Tt_T = T_1+Tt_2;
		fprintf(lvlog,"Tt_2 = %f, Tt_T = %f\r\n",Tt_2,Tt_T);
	
		// IGM STEERING ANGLES
		fprintf(lvlog,"--- IGM STEERING ANGLES ---\r\n");

		//sprintf(oapiDebugString(),"IGM: K_1 %f K_2 %f K_3 %f K_4 %f",K_1,K_2,K_3,K_4);
		Xtt_y = ((tchi_y) - K_3 + (K_4 * t));
		Xtt_p = ((tchi_p) - K_1 + (K_2 * t));
		fprintf(lvlog,"Xtt_y = %f, Xtt_p = %f\r\n",Xtt_y,Xtt_p);

		// -- COMPUTE INVERSE OF [K] --
		// Get Determinate
		double det = MX_K.m11 * ((MX_K.m22*MX_K.m33) - (MX_K.m32*MX_K.m23))
					- MX_K.m12 * ((MX_K.m21*MX_K.m33) - (MX_K.m31*MX_K.m23))
					+ MX_K.m13 * ((MX_K.m21*MX_K.m32) - (MX_K.m31*MX_K.m22));
		// If the determinate is less than 0.0005, this is invalid.
		fprintf(lvlog,"det = %f (LESS THAN 0.0005 IS INVALID)\r\n",det);

		MATRIX3 MX_Ki; // TEMPORARY: Inverse of [K]
		MX_Ki.m11 =   ((MX_K.m22*MX_K.m33) - (MX_K.m23*MX_K.m32))  / det;
		MX_Ki.m12 =   ((MX_K.m13*MX_K.m32) - (MX_K.m12*MX_K.m33))  / det;
		MX_Ki.m13 =   ((MX_K.m12*MX_K.m23) - (MX_K.m13*MX_K.m22))  / det;
		MX_Ki.m21 =   ((MX_K.m23*MX_K.m31) - (MX_K.m21*MX_K.m33))  / det;
		MX_Ki.m22 =   ((MX_K.m11*MX_K.m33) - (MX_K.m13*MX_K.m31))  / det;
		MX_Ki.m23 =   ((MX_K.m13*MX_K.m21) - (MX_K.m11*MX_K.m23))  / det;
		MX_Ki.m31 =   ((MX_K.m21*MX_K.m32) - (MX_K.m22*MX_K.m31))  / det;
		MX_Ki.m32 =   ((MX_K.m12*MX_K.m31) - (MX_K.m11*MX_K.m32))  / det;
		MX_Ki.m33 =   ((MX_K.m11*MX_K.m22) - (MX_K.m12*MX_K.m21))  / det;
		fprintf(lvlog,"MX_Ki R1 = %f %f %f\r\n",MX_Ki.m11,MX_Ki.m12,MX_Ki.m13);
		fprintf(lvlog,"MX_Ki R2 = %f %f %f\r\n",MX_Ki.m21,MX_Ki.m22,MX_Ki.m23);
		fprintf(lvlog,"MX_Ki R3 = %f %f %f\r\n",MX_Ki.m31,MX_Ki.m32,MX_Ki.m33);

		// Done
		VECTOR3 VT; 
		VT.x = (sin(Xtt_p)*cos(Xtt_y));
		VT.y = (sin(Xtt_y));
		VT.z = (cos(Xtt_p)*cos(Xtt_y));
		fprintf(lvlog,"VT (set) = %f %f %f\r\n",VT.x,VT.y,VT.z);

		VT = mul(MX_Ki,VT);
		fprintf(lvlog,"VT (mul) = %f %f %f\r\n",VT.x,VT.y,VT.z);

		X_S1 = VT.x;
		X_S2 = VT.y;
		X_S3 = VT.z;
		fprintf(lvlog,"X_S1-3 = %f %f %f\r\n",X_S1,X_S2,X_S3);

		// FINALLY - COMMANDS!
		X_Zi = asin(X_S2);			// Yaw
		X_Yi = atan2(-X_S3,X_S1);	// Pitch
		fprintf(lvlog,"*** COMMAND ISSUED ***\r\n");
		fprintf(lvlog,"PITCH = %f, YAW = %f\r\n\r\n",X_Yi*DEG,X_Zi*DEG);
			
		// IGM is supposed to generate attitude directly.
		CommandedAttitude.x = 360 * RAD;    // ROLL
		CommandedAttitude.y = X_Yi; // PITCH
		CommandedAttitude.z = X_Zi; // YAW;				
		goto limittest;

orbitalguidance: //orbital guidance logic;

		fprintf(lvlog,"*** ORBITAL GUIDANCE ***\r\n");
		if(TAS-TA3 < 0){ //time for maneuver after CSM sep		
			if(TAS-TA1 > 0){ //1st maneuver to -20 pitch LVLH prior to CSM sep
				if(TAS-TA2 > 0){ //time for attitude hold
					if(INH2){
						alpha_1 = -20 * RAD; //if INH2: maintain orb rate
						CommandedAttitude.x = 180 * RAD;
						fprintf(lvlog,"inhibit attitude hold, maintain pitchdown\r\n");
						goto orbatt;
					}else{
						CommandedAttitude = PCommandedAttitude; //hold attitude for CSM sep
						fprintf(lvlog,"Attitude hold\r\n");
						goto minorloop;
					}
				}else{
					if(INH1){
						alpha_1 = 0 * RAD; //if INH1: no pitchdown
						CommandedAttitude.x = 360 * RAD;
						fprintf(lvlog,"inhibit pitchdown");
						goto orbatt;
					}else{
						alpha_1 = -20 * RAD; //from GRR +9780 till GRR+10275
						CommandedAttitude.x = 360 * RAD;
						fprintf(lvlog,"pitchdown");
						goto orbatt;
					}
				}
			}else{
				alpha_1 = 360 * RAD; //from TB4+20 till GRR +9780 0
				CommandedAttitude.x = 360 * RAD;
				fprintf(lvlog,"TB4+20\r\n");
				goto orbatt;
			}						
		}else{
			alpha_1 = 180 * RAD; //tail forward
			CommandedAttitude.x = 180 * RAD; //heads up
			fprintf(lvlog,"post sep attitude\r\n");
			goto orbatt;
		}

orbatt: Pos4 = mul(MX_G,PosS); //here we compute the steering angles...
		sin_chi_Yit = (Pos4.x * cos(alpha_1) + Pos4.z * sin(alpha_1))/(-R);
		cos_chi_Yit = (Pos4.z * cos(alpha_1) - Pos4.x * sin(alpha_1))/(-R);
		sin_chi_Zit = sin(alpha_2);
		cos_chi_Zit = cos(alpha_2);
		// -- COMPUTE INVERSE OF [G] -what an effort for those stupid angles!
		// Get Determinate
		double det1 = MX_G.m11 * ((MX_G.m22*MX_G.m33) - (MX_G.m32*MX_G.m23))
					- MX_G.m12 * ((MX_G.m21*MX_G.m33) - (MX_G.m31*MX_G.m23))
					+ MX_G.m13 * ((MX_G.m21*MX_G.m32) - (MX_G.m31*MX_G.m22));
		// If the determinate is less than 0.0005, this is invalid.
		MATRIX3 MX_Gi; // TEMPORARY: Inverse of [K]
		MX_Gi.m11 =   ((MX_G.m22*MX_G.m33) - (MX_G.m23*MX_G.m32))  / det1;
		MX_Gi.m12 =   ((MX_G.m13*MX_G.m32) - (MX_G.m12*MX_G.m33))  / det1;
		MX_Gi.m13 =   ((MX_G.m12*MX_G.m23) - (MX_G.m13*MX_G.m22))  / det1;
		MX_Gi.m21 =   ((MX_G.m23*MX_G.m31) - (MX_G.m21*MX_G.m33))  / det1;
		MX_Gi.m22 =   ((MX_G.m11*MX_G.m33) - (MX_G.m13*MX_G.m31))  / det1;
		MX_Gi.m23 =   ((MX_G.m13*MX_G.m21) - (MX_G.m11*MX_G.m23))  / det1;
		MX_Gi.m31 =   ((MX_G.m21*MX_G.m32) - (MX_G.m22*MX_G.m31))  / det1;
		MX_Gi.m32 =   ((MX_G.m12*MX_G.m31) - (MX_G.m11*MX_G.m32))  / det1;
		MX_Gi.m33 =   ((MX_G.m11*MX_G.m22) - (MX_G.m12*MX_G.m21))  / det1;
		VECTOR3 VT1; 
		VT1.x = (cos_chi_Yit * cos_chi_Zit);
		VT1.y = (sin_chi_Zit);
		VT1.z = (-sin_chi_Yit * cos_chi_Zit);
		fprintf(lvlog,"VT (set) = %f %f %f\r\n",VT1.x,VT1.y,VT1.z);

		VT1 = mul(MX_Gi,VT1);
		fprintf(lvlog,"VT (mul) = %f %f %f\r\n",VT1.x,VT1.y,VT1.z);

		X_S1 = VT1.x;
		X_S2 = VT1.y;
		X_S3 = VT1.z;
		fprintf(lvlog,"X_S1-3 = %f %f %f\r\n",X_S1,X_S2,X_S3);

		// COMMANDS
		X_Zi = asin(X_S2);			// Yaw
		X_Yi = atan2(-X_S3,X_S1);	// Pitch
		fprintf(lvlog,"*** COMMAND ISSUED ***\r\n");
		fprintf(lvlog,"PITCH = %f, YAW = %f\r\n\r\n",X_Yi*DEG,X_Zi*DEG);
		CommandedAttitude.y = X_Yi; // PITCH
		CommandedAttitude.z = X_Zi; // YAW;				

limittest:
		//command rate test; part of major loop;
		//if(CommandedAttitude.z < -45 * RAD && CommandedAttitude.z >= -180 * RAD){CommandedAttitude.z = -45 * RAD;}
		//if(CommandedAttitude.z > 45 * RAD && CommandedAttitude.z <= 180 * RAD){CommandedAttitude.z = 45 * RAD;}
		double diff; //aux variable for limit test
		diff = fmod((CommandedAttitude.x - PCommandedAttitude.x + TWO_PI),TWO_PI);
		if(diff > PI){ diff -= TWO_PI; }
		if(abs(diff/dt_c) > CommandRateLimits.x){
			if(diff > 0){
				CommandedAttitude.x = fmod(PCommandedAttitude.x + CommandRateLimits.x * dt_c,TWO_PI);
			}else{
				CommandedAttitude.x = fmod(PCommandedAttitude.x - CommandRateLimits.x * dt_c,TWO_PI);
			}
		}
		diff = fmod((CommandedAttitude.y - PCommandedAttitude.y + TWO_PI),TWO_PI);
		if(diff > PI){ diff -= TWO_PI; }
		if(abs(diff/dt_c) > CommandRateLimits.y){
			if(diff > 0){
				CommandedAttitude.y = fmod(PCommandedAttitude.y + CommandRateLimits.y * dt_c,TWO_PI);
			}else{
				CommandedAttitude.y = fmod(PCommandedAttitude.y - CommandRateLimits.y * dt_c,TWO_PI);
			}
		}
		diff = fmod((CommandedAttitude.z - PCommandedAttitude.z + TWO_PI),TWO_PI);
		if(diff > PI) {diff -= TWO_PI;} ;
		if(abs(diff/dt_c) > CommandRateLimits.z){
			if(diff > 0){
				CommandedAttitude.z = fmod(PCommandedAttitude.z + CommandRateLimits.z * dt_c,TWO_PI);
			}else{
				CommandedAttitude.z = fmod(PCommandedAttitude.z - CommandRateLimits.z * dt_c,TWO_PI);
			}
		}
		PCommandedAttitude = CommandedAttitude;

minorloop: //minor loop;
		if(T_GO - sinceLastIGM <= 0 && HSL == true && S4B_IGN == true){
			//Time for S4B cutoff? We need to check that here -IGM runs every 2 sec only, but cutoff has to be on the second			
			S4B_IGN = false;
			HSL = false;
			BOOST = false;
			LVDC_Timebase = 4;
			LVDC_TB_ETime = 0;
			fprintf(lvlog,"SIVB CUTOFF! TAS = %f \r\n",TAS);
		};
		//calculate delta attitude
		DeltaAtt.x = fmod((CurrentAttitude.x - CommandedAttitude.x + TWO_PI),TWO_PI);
		if (DeltaAtt.x > PI){ DeltaAtt.x -= TWO_PI; }	
		DeltaAtt.y = fmod((CurrentAttitude.y - CommandedAttitude.y + TWO_PI),TWO_PI);
		if (DeltaAtt.y > PI){ DeltaAtt.y -= TWO_PI; }
		DeltaAtt.z = fmod((CurrentAttitude.z - CommandedAttitude.z + TWO_PI),TWO_PI);
		if (DeltaAtt.z > PI){ DeltaAtt.z -= TWO_PI; }

		//-euler correction-
		//calculate correction factors
		A1 = cos(CurrentAttitude.x) * cos(CurrentAttitude.z);
		A2 = sin(CurrentAttitude.x);
		A3 = sin(CurrentAttitude.z);
		A4 = sin(CurrentAttitude.x) * cos(CurrentAttitude.z);
		A5 = cos(CurrentAttitude.x);
		// ROLL ERROR
		AttitudeError.x =-(DeltaAtt.x + A3 * DeltaAtt.y);
		// PITCH ERROR
		AttitudeError.y = -(A1 * DeltaAtt.y + A2 * DeltaAtt.z); 
		// YAW ERROR
		AttitudeError.z = -(-A4 * DeltaAtt.y + A5 * DeltaAtt.z);
	
		// S/C takeover function
		if(LVDC_Timebase == 4 && (owner->LVGuidanceSwitch.IsDown() && owner->agc.GetInputChannelBit(012, EnableSIVBTakeover))){
			//scaling factor seems to be 31.6; didn't find any source for it, but at least it leads to the right rates
			//note that any 'threshold solution' is pointless: ARTEMIS supports EMEM-selectable saturn rate output
			AttitudeError.x = owner->gdc.fdai_err_x * RAD / 31.6;
			AttitudeError.y = owner->gdc.fdai_err_y * RAD / 31.6;
			AttitudeError.z = owner->gdc.fdai_err_z * RAD / -31.6;
		}
		/* **** FLIGHT CONTROL COMPUTER OPERATIONS **** */
		if(LVDC_Timebase == 1 && LVDC_TB_ETime < 60){
			a_0p = a_0y = 2;
			a_0r = 0.3;
			a_1p = a_1y = 1.6;
			a_1r = 0.25;
		}
		if(LVDC_Timebase == 1 && LVDC_TB_ETime >= 60 && LVDC_TB_ETime < 90){
			a_0p = a_0y = 3;
			a_0r = 0.3;
			a_1p = a_1y = 1.6;
			a_1r = 0.25;
		}
		if(LVDC_Timebase == 1 && LVDC_TB_ETime >= 90 && LVDC_TB_ETime < 120){
			a_0p = a_0y = 2;
			a_0r = 0.3;
			a_1p = a_1y = 1.6;
			a_1r = 0.25;
		}
		if(LVDC_Timebase == 1 && LVDC_TB_ETime >= 120){
			a_0p = a_0y = 0.7;
			a_0r = 0.2;
			a_1p = a_1y = 0.75;
			a_1r = 0.15;
		}
		if(LVDC_Timebase == 3){
			a_0p = a_0y = 0.6;
			a_0r = 1;
			a_1p = a_1y = 0.5;
			a_1r = 5;
		}
		if(LVDC_Timebase == 4){
			a_0p = a_0y = 1;
			a_0r = 1;
			a_1p = a_1y = 5;
			a_1r = 5;
		}
		beta_pc = a_0p * AttitudeError.y + a_1p * AttRate.y;
		beta_yc = a_0y * AttitudeError.z + a_1y * AttRate.z;
		beta_rc = a_0r * AttitudeError.x + a_1r * AttRate.x;
		if(LVDC_Timebase < 3){
			beta_y1c = beta_yc + beta_rc/pow(2,0.5); //orbiter's engines are gimballed differently then the real one
			beta_p1c = beta_pc - beta_rc/pow(2,0.5);
			beta_y2c = beta_yc - beta_rc/pow(2,0.5);
			beta_p2c = beta_pc - beta_rc/pow(2,0.5);
			beta_y3c = beta_yc - beta_rc/pow(2,0.5);
			beta_p3c = beta_pc + beta_rc/pow(2,0.5);
			beta_y4c = beta_yc + beta_rc/pow(2,0.5);
			beta_p4c = beta_pc + beta_rc/pow(2,0.5);
			owner->SetThrusterDir(owner->th_main[0],_V(beta_y1c,beta_p1c,1)); 
			owner->SetThrusterDir(owner->th_main[1],_V(beta_y2c,beta_p2c,1));
			owner->SetThrusterDir(owner->th_main[2],_V(beta_y3c,beta_p3c,1)); 
			owner->SetThrusterDir(owner->th_main[3],_V(beta_y4c,beta_p4c,1)); 
		}
		if(LVDC_Timebase == 3){
			//SIVB powered flight
			beta_p1c = beta_pc; //gimbal angles
			beta_y1c = beta_yc;
			owner->SetThrusterDir(owner->th_main[0],_V(beta_y1c,beta_p1c,1));
			eps_p = 0; //we want neither the APS pitch thrusters to fire
			eps_ymr = -(a_0r * AttitudeError.x * DEG) - (a_1r * AttRate.x * DEG); //nor the yaw thrusters
			eps_ypr = (a_0r * AttitudeError.x * DEG) + (a_1r * AttRate.x * DEG);
		}
		if(LVDC_Timebase == 4){
			//SIVB coast flight; full APS control
			eps_p   = (a_0p * AttitudeError.y * DEG) + (a_1p * AttRate.y * DEG); //pitch thruster demand
			eps_ymr = (a_0y * AttitudeError.z * DEG) - (a_0r * AttitudeError.x * DEG) + (a_1y * AttRate.z * DEG) - (a_1r * AttRate.x * DEG); //yaw minus roll
			eps_ypr = (a_0y * AttitudeError.z * DEG) + (a_0r * AttitudeError.x * DEG) + (a_1y * AttRate.z * DEG) + (a_1r * AttRate.x * DEG); //yaw plus roll
		}
		if((LVDC_Timebase == 3 && S4B_IGN == true)|| LVDC_Timebase == 4){
			//APS thruster on/off control
			if(eps_p > 1){
				//fire+pitch
				if(eps_p >= 1.6){owner->SetThrusterLevel(owner->th_att_rot[1],1);}else{owner->SetThrusterLevel(owner->th_att_rot[1],(eps_p-1)/0.6);}
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[1],0);
			}
			if(eps_p < -1){
				//fire-pitch
				if(eps_p <= -1.6){owner->SetThrusterLevel(owner->th_att_rot[0],1);}else{owner->SetThrusterLevel(owner->th_att_rot[0],(-eps_p-1)/0.6);}
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[0],0);
			}
			if(eps_ymr > 1){
				//fire+yaw-roll;
				if(eps_ymr >= 1.6){owner->SetThrusterLevel(owner->th_att_rot[3],1);}else{owner->SetThrusterLevel(owner->th_att_rot[3],(eps_ymr-1)/0.6);}
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[3],0);
			}
			if(eps_ymr < -1){
				//fire-yaw+roll;
				if(eps_ymr <= -1.6){owner->SetThrusterLevel(owner->th_att_rot[5],1);}else{owner->SetThrusterLevel(owner->th_att_rot[5],(-eps_ymr-1)/0.6);}
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[5],0);
			}
			if(eps_ypr > 1){
				//fire+yaw+roll;
				if(eps_ypr >= 1.6){owner->SetThrusterLevel(owner->th_att_rot[4],1);}else{owner->SetThrusterLevel(owner->th_att_rot[4],(eps_ypr-1)/0.6);}
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[4],0);
			}
			if(eps_ypr < -1){
				//fire-yaw-roll;
				if(eps_ypr <= -1.6){owner->SetThrusterLevel(owner->th_att_rot[2],1);}else{owner->SetThrusterLevel(owner->th_att_rot[2],(-eps_ypr-1)/0.6);}
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[2],0);
			}
		}
		// Debug if we're launched
		if(LVDC_Timebase > -1){
			if(LVDC_Timebase < 4){
				sprintf(oapiDebugString(),"TB%d+%f | T1 = %f | T2 = %f | Tt_T = %f | ERR %f %f %f | eps %f %f %f | V = %f R = %f",
					LVDC_Timebase,LVDC_TB_ETime,
					T_1,Tt_2,Tt_T,
					AttitudeError.x*DEG,AttitudeError.y*DEG,AttitudeError.z*DEG,
					eps_p, eps_ymr, eps_ypr,V,R/1000);
			}else{
				// On-Orbit
				sprintf(oapiDebugString(),"TB%d+%.2f | ATT %.3f %.3f %.3f | CMD %.3f %.3f %.3f | ERR %.3f %.3f %.3f | eps %.3f %.3f %.3f | RATE %.3f %.3f %.3f | V = %.2f R= %.2f",
					LVDC_Timebase,LVDC_TB_ETime,
					CurrentAttitude.x*DEG,CurrentAttitude.y*DEG,CurrentAttitude.z*DEG,
					CommandedAttitude.x*DEG,CommandedAttitude.y*DEG,CommandedAttitude.z*DEG,
					AttitudeError.x*DEG,AttitudeError.y*DEG,AttitudeError.z*DEG,
					AttRate.x * DEG, AttRate.y * DEG, AttRate.z * DEG,
					eps_p, eps_ymr, eps_ypr,V,R/1000);
			}
		}
	}

	/*
		sprintf(oapiDebugString(),"LVDC: TB%d + %f | PS %f %f %f | VS %f %f %f",
			LVDC_Timebase,LVDC_TB_ETime,
			PosS.x,PosS.y,PosS.z,
			DotS.x,DotS.y,DotS.z);
			*/
//	CurrentAttitude.x*DEG,CurrentAttitude.y*DEG,CurrentAttitude.z*DEG,V);								

	// Update engine indicators and failure flags
	if(LVDC_EI_On == true){
		int i=0;
		switch(owner->stage){
			// 5-engine stages
			case PRELAUNCH_STAGE:
			case LAUNCH_STAGE_ONE:
				while (i<8){
				if(owner->GetThrusterLevel(owner->th_main[i]) >= 0.65  && owner->ENGIND[i] == true){  owner->ENGIND[i] = false; } 
				if(owner->GetThrusterLevel(owner->th_main[i]) < 0.65 && owner->ENGIND[i] == false){  owner->ENGIND[i] = true; }
				i++;
				}
				break;
			// S4B only
			case LAUNCH_STAGE_SIVB:
			case STAGE_ORBIT_SIVB:				
				if(owner->GetThrusterLevel(owner->th_main[0]) >= 0.65  && owner->ENGIND[0] == true){  owner->ENGIND[0] = false; } // UNLIGHT
				if(owner->GetThrusterLevel(owner->th_main[0]) < 0.65 && owner->ENGIND[0] == false){  owner->ENGIND[0] = true; }   // LIGHT
				break;	
			// Error
			default:
				LVDC_EI_On = false;
				break;
		}
	}else{
		owner->ENGIND[0] = false;
		owner->ENGIND[1] = false;
		owner->ENGIND[2] = false;
		owner->ENGIND[3] = false;
		owner->ENGIND[4] = false;
		owner->ENGIND[5] = false;
		owner->ENGIND[6] = false;
		owner->ENGIND[7] = false;
	}
	if(owner->stage == LAUNCH_STAGE_ONE && owner->MissionTime < 12.5){
		// Control contrail
		if(owner->MissionTime > 12){
			owner->contrailLevel = 0;
		}else{
			if (owner->MissionTime > 7){
				owner->contrailLevel = (12.0 - owner->MissionTime) / 100.0;
			}else{
				if(owner->MissionTime > 2){
					owner->contrailLevel = 1.38 - 0.95 / 5.0 * owner->MissionTime;
				}else{
					owner->contrailLevel = 1;
				}
			}
		}
	}

	/* **** ABORT HANDLING **** */
	// The abort PB will be pressed during prelaunch testing, but shouldn't actually trigger an abort before Mode 1 enabled.
	if(owner->bAbort && owner->MissionTime > -300){				
		owner->SetEngineLevel(ENGINE_MAIN, 0);						// Kill the engines
		owner->agc.SetInputChannelBit(030, SIVBSeperateAbort, true);// Notify the AGC of the abort
		owner->agc.SetInputChannelBit(030, LiftOff, true);			// and the liftoff, if it's not set already
		sprintf(oapiDebugString(),"");								// Clear the LVDC debug line
		LVDC_Stop = true;											// Stop LVDC program
		// ABORT MODE 1 - Use of LES to extract CM
		// Allowed from T - 5 minutes until LES jettison.
		if(owner->MissionTime > -300 && owner->LESAttached){			
			owner->SetEngineLevel(ENGINE_MAIN, 0);
			owner->SeparateStage(CM_STAGE);
			owner->SetStage(CM_STAGE);
			owner->StartAbort();			// Resets MT, fires LET if attached
			owner->bAbort = false;			// No further processing required
			return; 
		}
		// ABORT MODE 2/3/4 - Eject CSM from LV
		if(owner->stage == LAUNCH_STAGE_ONE){
			// The only way we will get here is if the LET was jettisoned early for some reason.
			owner->SeparateStage(LAUNCH_STAGE_TWO);
			owner->SetStage(LAUNCH_STAGE_TWO);
			return;
		}
		if(owner->stage == LAUNCH_STAGE_TWO){
			// The only way we will get here is if the LET was jettisoned early for some reason.
			owner->SeparateStage (LAUNCH_STAGE_TWO_ISTG_JET);
			owner->SetStage(LAUNCH_STAGE_TWO_ISTG_JET);
			return;
		}
		if(owner->stage == LAUNCH_STAGE_TWO_ISTG_JET){
			// This is the most likely entry point
			owner->SeparateStage(LAUNCH_STAGE_SIVB);
			owner->SetStage(LAUNCH_STAGE_SIVB);
		}
		if(owner->stage == LAUNCH_STAGE_SIVB || owner->stage == STAGE_ORBIT_SIVB){
			// Eject CSM
			owner->SeparateStage(CSM_LEM_STAGE);
			owner->SetStage(CSM_LEM_STAGE);
			// Staging finished.
			owner->StartAbort();			// Resets MT, sets abort light, resets engine lights, etc.
		}
		// Done with the abort request.
		owner->bAbort = false;
	}
}

void LVDC1B::SaveState(FILEHANDLE scn) {
	oapiWriteLine(scn, LVDC_START_STRING);
	// Thank heaven for text processing.
	// bool
	oapiWriteScenario_int(scn, "LVDC_alpha_D_op", alpha_D_op);
	oapiWriteScenario_int(scn, "LVDC_BOOST", BOOST);
	oapiWriteScenario_int(scn, "LVDC_CountPIPA", CountPIPA);
	oapiWriteScenario_int(scn, "LVDC_GATE", GATE);
	oapiWriteScenario_int(scn, "LVDC_GATE5", GATE5);
	oapiWriteScenario_int(scn, "LVDC_GRR_init", GRR_init);
	oapiWriteScenario_int(scn, "LVDC_HSL", HSL);
	oapiWriteScenario_int(scn, "LVDC_INH", INH);
	oapiWriteScenario_int(scn, "LVDC_INH1", INH1);
	oapiWriteScenario_int(scn, "LVDC_INH2", INH2);
	oapiWriteScenario_int(scn, "LVDC_i_op", i_op);
	oapiWriteScenario_int(scn, "LVDC_liftoff", liftoff);
	oapiWriteScenario_int(scn, "LVDC_LVDC_EI_On", LVDC_EI_On);
	oapiWriteScenario_int(scn, "LVDC_LVDC_GRR", LVDC_GRR);
	oapiWriteScenario_int(scn, "LVDC_LVDC_Stop", LVDC_Stop);
	oapiWriteScenario_int(scn, "LVDC_MRS", MRS);
	oapiWriteScenario_int(scn, "LVDC_poweredflight", poweredflight);
	oapiWriteScenario_int(scn, "LVDC_S1B_Engine_Out", S1B_Engine_Out);
	oapiWriteScenario_int(scn, "LVDC_S4B_IGN", S4B_IGN);
	oapiWriteScenario_int(scn, "LVDC_TerminalConditions", TerminalConditions);
	oapiWriteScenario_int(scn, "LVDC_theta_N_op", theta_N_op);
	// int
	oapiWriteScenario_int(scn, "LVDC_IGMCycle", IGMCycle);
	oapiWriteScenario_int(scn, "LVDC_LVDC_Timebase", LVDC_Timebase);
	oapiWriteScenario_int(scn, "LVDC_T_EO1", T_EO1);
	oapiWriteScenario_int(scn, "LVDC_T_EO2", T_EO2);
	oapiWriteScenario_int(scn, "LVDC_UP", UP);
	// double
	papiWriteScenario_double(scn, "LVDC_a", a);
	papiWriteScenario_double(scn, "LVDC_a_0p", a_0p);
	papiWriteScenario_double(scn, "LVDC_a_0r", a_0r);
	papiWriteScenario_double(scn, "LVDC_a_0y", a_0y);
	papiWriteScenario_double(scn, "LVDC_a_1", a_1);
	papiWriteScenario_double(scn, "LVDC_a_2", a_2);
	papiWriteScenario_double(scn, "LVDC_A1", A1);
	papiWriteScenario_double(scn, "LVDC_A2", A2);
	papiWriteScenario_double(scn, "LVDC_A3", A3);
	papiWriteScenario_double(scn, "LVDC_A4", A4);
	papiWriteScenario_double(scn, "LVDC_A5", A5);
	papiWriteScenario_double(scn, "LVDC_a_1p", a_1p);
	papiWriteScenario_double(scn, "LVDC_a_1r", a_1r);
	papiWriteScenario_double(scn, "LVDC_a_1y", a_1y);
	papiWriteScenario_double(scn, "LVDC_alpha_1", alpha_1);
	papiWriteScenario_double(scn, "LVDC_alpha_2", alpha_2);
	papiWriteScenario_double(scn, "LVDC_alpha_D", alpha_D);
	papiWriteScenario_double(scn, "LVDC_Azimuth", Azimuth);
	papiWriteScenario_double(scn, "LVDC_Azo", Azo);
	papiWriteScenario_double(scn, "LVDC_Azs", Azs);
	papiWriteScenario_double(scn, "LVDC_B_11", B_11);
	papiWriteScenario_double(scn, "LVDC_B_21", B_21);
	papiWriteScenario_double(scn, "LVDC_B_12", B_12);
	papiWriteScenario_double(scn, "LVDC_B_22", B_22);
	papiWriteScenario_double(scn, "LVDC_beta_p1c", beta_p1c);
	papiWriteScenario_double(scn, "LVDC_beta_p2c", beta_p2c);
	papiWriteScenario_double(scn, "LVDC_beta_p3c", beta_p3c);
	papiWriteScenario_double(scn, "LVDC_beta_p4c", beta_p4c);
	papiWriteScenario_double(scn, "LVDC_beta_pc", beta_pc);
	papiWriteScenario_double(scn, "LVDC_beta_rc", beta_rc);
	papiWriteScenario_double(scn, "LVDC_beta_y1c", beta_y1c);
	papiWriteScenario_double(scn, "LVDC_beta_y2c", beta_y2c);
	papiWriteScenario_double(scn, "LVDC_beta_y3c", beta_y3c);
	papiWriteScenario_double(scn, "LVDC_beta_y4c", beta_y4c);
	papiWriteScenario_double(scn, "LVDC_beta_yc", beta_yc);
	papiWriteScenario_double(scn, "LVDC_C_2", C_2);
	papiWriteScenario_double(scn, "LVDC_C_4", C_4);
	papiWriteScenario_double(scn, "LVDC_C_3", C_3);
	papiWriteScenario_double(scn, "LVDC_CG", CG);
	papiWriteScenario_double(scn, "LVDC_cos_chi_Yit", cos_chi_Yit);
	papiWriteScenario_double(scn, "LVDC_cos_chi_Zit", cos_chi_Zit);
	papiWriteScenario_double(scn, "LVDC_cos_phi_L", cos_phi_L);
	papiWriteScenario_double(scn, "LVDC_d2", d2);
	papiWriteScenario_double(scn, "LVDC_ddot_xi_G", ddot_xi_G);
	papiWriteScenario_double(scn, "LVDC_ddot_eta_G", ddot_eta_G);
	papiWriteScenario_double(scn, "LVDC_ddot_zeta_G", ddot_zeta_G);
	papiWriteScenario_double(scn, "LVDC_ddot_zeta_GT", ddot_zeta_GT);
	papiWriteScenario_double(scn, "LVDC_ddot_xi_GT", ddot_xi_GT);
	papiWriteScenario_double(scn, "LVDC_DescNodeAngle", DescNodeAngle);
	papiWriteScenario_double(scn, "LVDC_deta", deta);
	papiWriteScenario_double(scn, "LVDC_dxi", dxi);
	papiWriteScenario_double(scn, "LVDC_dot_dxi", dot_dxi);
	papiWriteScenario_double(scn, "LVDC_dot_deta", dot_deta);
	papiWriteScenario_double(scn, "LVDC_dot_dzeta", dot_dzeta);
	papiWriteScenario_double(scn, "LVDC_dot_dxit", dot_dxit);
	papiWriteScenario_double(scn, "LVDC_dot_detat", dot_detat);
	papiWriteScenario_double(scn, "LVDC_dot_dzetat", dot_dzetat);
	papiWriteScenario_double(scn, "LVDC_dotM_1", dotM_1);
	papiWriteScenario_double(scn, "LVDC_dotM_2", dotM_2);
	papiWriteScenario_double(scn, "LVDC_dot_phi_1", dot_phi_1);
	papiWriteScenario_double(scn, "LVDC_dot_phi_T", dot_phi_T);
	papiWriteScenario_double(scn, "LVDC_dot_zeta_T", dot_zeta_T);
	papiWriteScenario_double(scn, "LVDC_dot_xi_T", dot_xi_T);
	papiWriteScenario_double(scn, "LVDC_dot_eta_T", dot_eta_T);
	papiWriteScenario_double(scn, "LVDC_dt", dt);
	papiWriteScenario_double(scn, "LVDC_dT_2", dT_2);
	papiWriteScenario_double(scn, "LVDC_dt_c", dt_c);
	papiWriteScenario_double(scn, "LVDC_dT_F", dT_F);
	papiWriteScenario_double(scn, "LVDC_dt_LET", dt_LET);
	papiWriteScenario_double(scn, "LVDC_dtt_1", dtt_1);
	papiWriteScenario_double(scn, "LVDC_dtt_2", dtt_2);
	papiWriteScenario_double(scn, "LVDC_dV", dV);
	papiWriteScenario_double(scn, "LVDC_dV_B", dV_B);
	papiWriteScenario_double(scn, "LVDC_e", e);
	papiWriteScenario_double(scn, "LVDC_eps_2", eps_2);
	papiWriteScenario_double(scn, "LVDC_eps_3", eps_3);
	papiWriteScenario_double(scn, "LVDC_eps_4", eps_4);
	papiWriteScenario_double(scn, "LVDC_eps_p", eps_p);
	papiWriteScenario_double(scn, "LVDC_eps_ymr", eps_ymr);
	papiWriteScenario_double(scn, "LVDC_eps_ypr", eps_ypr);
	papiWriteScenario_double(scn, "LVDC_f", f);
	papiWriteScenario_double(scn, "LVDC_F", F);
	papiWriteScenario_double(scn, "LVDC_Fm", Fm);
	papiWriteScenario_double(scn, "LVDC_Fx[0][0]", Fx[0][0]);
	papiWriteScenario_double(scn, "LVDC_Fx[0][1]", Fx[0][1]);
	papiWriteScenario_double(scn, "LVDC_Fx[0][2]", Fx[0][2]);
	papiWriteScenario_double(scn, "LVDC_Fx[0][3]", Fx[0][3]);
	papiWriteScenario_double(scn, "LVDC_Fx[0][4]", Fx[0][4]);
	papiWriteScenario_double(scn, "LVDC_Fx[1][0]", Fx[1][0]);
	papiWriteScenario_double(scn, "LVDC_Fx[1][1]", Fx[1][1]);
	papiWriteScenario_double(scn, "LVDC_Fx[1][2]", Fx[1][2]);
	papiWriteScenario_double(scn, "LVDC_Fx[1][3]", Fx[1][3]);
	papiWriteScenario_double(scn, "LVDC_Fx[1][4]", Fx[1][4]);
	papiWriteScenario_double(scn, "LVDC_Fx[2][0]", Fx[2][0]);
	papiWriteScenario_double(scn, "LVDC_Fx[2][1]", Fx[2][1]);
	papiWriteScenario_double(scn, "LVDC_Fx[2][2]", Fx[2][2]);
	papiWriteScenario_double(scn, "LVDC_Fx[2][3]", Fx[2][3]);
	papiWriteScenario_double(scn, "LVDC_Fx[2][4]", Fx[2][4]);
	papiWriteScenario_double(scn, "LVDC_Fx[3][0]", Fx[3][0]);
	papiWriteScenario_double(scn, "LVDC_Fx[3][1]", Fx[3][1]);
	papiWriteScenario_double(scn, "LVDC_Fx[3][2]", Fx[3][2]);
	papiWriteScenario_double(scn, "LVDC_Fx[3][3]", Fx[3][3]);
	papiWriteScenario_double(scn, "LVDC_Fx[3][4]", Fx[3][4]);
	papiWriteScenario_double(scn, "LVDC_Fx[4][0]", Fx[4][0]);
	papiWriteScenario_double(scn, "LVDC_Fx[4][1]", Fx[4][1]);
	papiWriteScenario_double(scn, "LVDC_Fx[4][2]", Fx[4][2]);
	papiWriteScenario_double(scn, "LVDC_Fx[4][3]", Fx[4][3]);
	papiWriteScenario_double(scn, "LVDC_Fx[4][4]", Fx[4][4]);
	papiWriteScenario_double(scn, "LVDC_fx[0]", fx[0]);
	papiWriteScenario_double(scn, "LVDC_fx[1]", fx[1]);
	papiWriteScenario_double(scn, "LVDC_fx[2]", fx[2]);
	papiWriteScenario_double(scn, "LVDC_fx[3]", fx[3]);
	papiWriteScenario_double(scn, "LVDC_fx[4]", fx[4]);
	papiWriteScenario_double(scn, "LVDC_fx[5]", fx[5]);
	papiWriteScenario_double(scn, "LVDC_fx[6]", fx[6]);
	papiWriteScenario_double(scn, "LVDC_G_T", G_T);
	papiWriteScenario_double(scn, "LVDC_gx[0]", gx[0]);
	papiWriteScenario_double(scn, "LVDC_gx[1]", gx[1]);
	papiWriteScenario_double(scn, "LVDC_gx[2]", gx[2]);
	papiWriteScenario_double(scn, "LVDC_gx[3]", gx[3]);
	papiWriteScenario_double(scn, "LVDC_gx[4]", gx[4]);
	papiWriteScenario_double(scn, "LVDC_gx[5]", gx[5]);
	papiWriteScenario_double(scn, "LVDC_gx[6]", gx[6]);
	papiWriteScenario_double(scn, "LVDC_IGMInterval", IGMInterval);
	papiWriteScenario_double(scn, "LVDC_Inclination", Inclination);
	papiWriteScenario_double(scn, "LVDC_J", J);
	papiWriteScenario_double(scn, "LVDC_J_1", J_1);
	papiWriteScenario_double(scn, "LVDC_J_2", J_2);
	papiWriteScenario_double(scn, "LVDC_Jt_2", Jt_2);
	papiWriteScenario_double(scn, "LVDC_J_Y", J_Y);
	papiWriteScenario_double(scn, "LVDC_J_P", J_P);
	papiWriteScenario_double(scn, "LVDC_K_1", K_1);
	papiWriteScenario_double(scn, "LVDC_K_2", K_2);
	papiWriteScenario_double(scn, "LVDC_K_3", K_3);
	papiWriteScenario_double(scn, "LVDC_K_4", K_4);
	papiWriteScenario_double(scn, "LVDC_K_5", K_5);
	papiWriteScenario_double(scn, "LVDC_K_P1", K_P1);
	papiWriteScenario_double(scn, "LVDC_K_P2", K_P2);
	papiWriteScenario_double(scn, "LVDC_K_p", K_p);
	papiWriteScenario_double(scn, "LVDC_K_y", K_y);
	papiWriteScenario_double(scn, "LVDC_K_r", K_r);
	papiWriteScenario_double(scn, "LVDC_K_Y1", K_Y1);
	papiWriteScenario_double(scn, "LVDC_K_Y2", K_Y2);
	papiWriteScenario_double(scn, "LVDC_K_Y", K_Y);
	papiWriteScenario_double(scn, "LVDC_K_P", K_P);
	papiWriteScenario_double(scn, "LVDC_D_P", D_P);
	papiWriteScenario_double(scn, "LVDC_D_Y", D_Y);
	papiWriteScenario_double(scn, "LVDC_L_1", L_1);
	papiWriteScenario_double(scn, "LVDC_L_2", L_2);
	papiWriteScenario_double(scn, "LVDC_dL_2", dL_2);
	papiWriteScenario_double(scn, "LVDC_Lt_2", Lt_2);
	papiWriteScenario_double(scn, "LVDC_L_P", L_P);
	papiWriteScenario_double(scn, "LVDC_L_Y", L_Y);
	papiWriteScenario_double(scn, "LVDC_Lt_Y", Lt_Y);
	papiWriteScenario_double(scn, "LVDC_LVDC_TB_ETime", LVDC_TB_ETime);
	papiWriteScenario_double(scn, "LVDC_mu", mu);
	papiWriteScenario_double(scn, "LVDC_p", p);
	papiWriteScenario_double(scn, "LVDC_P_1", P_1);
	papiWriteScenario_double(scn, "LVDC_P_2", P_2);
	papiWriteScenario_double(scn, "LVDC_phi_lat", phi_lat);
	papiWriteScenario_double(scn, "LVDC_phi_lng", phi_lng);
	papiWriteScenario_double(scn, "LVDC_phi_T", phi_T);
	papiWriteScenario_double(scn, "LVDC_Q_1", Q_1);
	papiWriteScenario_double(scn, "LVDC_Q_2", Q_2);
	papiWriteScenario_double(scn, "LVDC_Q_Y", Q_Y);
	papiWriteScenario_double(scn, "LVDC_Q_P", Q_P);
	papiWriteScenario_double(scn, "LVDC_R", R);
	papiWriteScenario_double(scn, "LVDC_ROV", ROV);
	papiWriteScenario_double(scn, "LVDC_ROVs", ROVs);
	papiWriteScenario_double(scn, "LVDC_R_T", R_T);
	papiWriteScenario_double(scn, "LVDC_S1B_Sep_Time", S1B_Sep_Time);
	papiWriteScenario_double(scn, "LVDC_S_1", S_1);
	papiWriteScenario_double(scn, "LVDC_S_2", S_2);
	papiWriteScenario_double(scn, "LVDC_S_P", S_P);
	papiWriteScenario_double(scn, "LVDC_S_Y", S_Y);
	papiWriteScenario_double(scn, "LVDC_sinceLastIGM", sinceLastIGM);
	papiWriteScenario_double(scn, "LVDC_sin_chi_Yit", sin_chi_Yit);
	papiWriteScenario_double(scn, "LVDC_sin_chi_Zit", sin_chi_Zit);
	papiWriteScenario_double(scn, "LVDC_sin_phi_L", sin_phi_L);
	papiWriteScenario_double(scn, "LVDC_sin_ups", sin_ups);
	papiWriteScenario_double(scn, "LVDC_cos_ups", cos_ups);
	papiWriteScenario_double(scn, "LVDC_SMCG", SMCG);
	papiWriteScenario_double(scn, "LVDC_S", S);
	papiWriteScenario_double(scn, "LVDC_P", P);
	papiWriteScenario_double(scn, "LVDC_t", t);
	papiWriteScenario_double(scn, "LVDC_t_1", t_1);
	papiWriteScenario_double(scn, "LVDC_T_1", T_1);
	papiWriteScenario_double(scn, "LVDC_t_2", t_2);
	papiWriteScenario_double(scn, "LVDC_T_2", T_2);
	papiWriteScenario_double(scn, "LVDC_t_3", t_3);
	papiWriteScenario_double(scn, "LVDC_t_3i", t_3i);
	papiWriteScenario_double(scn, "LVDC_t_4", t_4);
	papiWriteScenario_double(scn, "LVDC_t_5", t_5);
	papiWriteScenario_double(scn, "LVDC_t_6", t_6);
	papiWriteScenario_double(scn, "LVDC_TA1", TA1);
	papiWriteScenario_double(scn, "LVDC_TA2", TA2);
	papiWriteScenario_double(scn, "LVDC_TA3", TA3);
	papiWriteScenario_double(scn, "LVDC_T_ar", T_ar);
	papiWriteScenario_double(scn, "LVDC_TAS", TAS);
	papiWriteScenario_double(scn, "LVDC_tau1", tau1);
	papiWriteScenario_double(scn, "LVDC_tau2", tau2);
	papiWriteScenario_double(scn, "LVDC_t_B1", t_B1);
	papiWriteScenario_double(scn, "LVDC_t_B3", t_B3);
	papiWriteScenario_double(scn, "LVDC_tchi_y_last", tchi_y_last);
	papiWriteScenario_double(scn, "LVDC_tchi_p_last", tchi_p_last);
	papiWriteScenario_double(scn, "LVDC_tchi_y", tchi_y);
	papiWriteScenario_double(scn, "LVDC_tchi_p", tchi_p);
	papiWriteScenario_double(scn, "LVDC_t_clock", t_clock);
	papiWriteScenario_double(scn, "LVDC_T_CO", T_CO);
	papiWriteScenario_double(scn, "LVDC_t_fail", t_fail);
	papiWriteScenario_double(scn, "LVDC_T_GO", T_GO);
	papiWriteScenario_double(scn, "LVDC_TI5F2", TI5F2);
	papiWriteScenario_double(scn, "LVDC_T_LET", T_LET);
	papiWriteScenario_double(scn, "LVDC_T_S1", T_S1);
	papiWriteScenario_double(scn, "LVDC_T_S2", T_S2);
	papiWriteScenario_double(scn, "LVDC_T_S3", T_S3);
	papiWriteScenario_double(scn, "LVDC_TSMC1", TSMC1);
	papiWriteScenario_double(scn, "LVDC_TSMC2", TSMC2);
	papiWriteScenario_double(scn, "LVDC_T_T", T_T);
	papiWriteScenario_double(scn, "LVDC_Tt_2", Tt_2);
	papiWriteScenario_double(scn, "LVDC_Tt_T", Tt_T);
	papiWriteScenario_double(scn, "LVDC_U_1", U_1);
	papiWriteScenario_double(scn, "LVDC_U_2", U_2);
	papiWriteScenario_double(scn, "LVDC_gamma_T", gamma_T);
	papiWriteScenario_double(scn, "LVDC_V", V);
	papiWriteScenario_double(scn, "LVDC_V_ex1", V_ex1);
	papiWriteScenario_double(scn, "LVDC_V_ex2", V_ex2);
	papiWriteScenario_double(scn, "LVDC_V_i", V_i);
	papiWriteScenario_double(scn, "LVDC_V_0", V_0);
	papiWriteScenario_double(scn, "LVDC_V_1", V_1);
	papiWriteScenario_double(scn, "LVDC_V_2", V_2);
	papiWriteScenario_double(scn, "LVDC_V_T", V_T);
	papiWriteScenario_double(scn, "LVDC_V_TC", V_TC);
	papiWriteScenario_double(scn, "LVDC_xi_T", xi_T);
	papiWriteScenario_double(scn, "LVDC_eta_T", eta_T);
	papiWriteScenario_double(scn, "LVDC_zeta_T", zeta_T);
	papiWriteScenario_double(scn, "LVDC_X_S1", X_S1);
	papiWriteScenario_double(scn, "LVDC_X_S2", X_S2);
	papiWriteScenario_double(scn, "LVDC_X_S3", X_S3);
	papiWriteScenario_double(scn, "LVDC_Xtt_y", Xtt_y);
	papiWriteScenario_double(scn, "LVDC_Xtt_p", Xtt_p);
	papiWriteScenario_double(scn, "LVDC_X_Zi", X_Zi);
	papiWriteScenario_double(scn, "LVDC_X_Yi", X_Yi);
	papiWriteScenario_double(scn, "LVDC_Y_u", Y_u);
	// VECTOR3
	papiWriteScenario_vec(scn, "LVDC_ACommandedAttitude", ACommandedAttitude);
	papiWriteScenario_vec(scn, "LVDC_AttitudeError", AttitudeError);
	papiWriteScenario_vec(scn, "LVDC_AttRate", AttRate);
	papiWriteScenario_vec(scn, "LVDC_CommandedAttitude", CommandedAttitude);
	papiWriteScenario_vec(scn, "LVDC_CommandRateLimits", CommandRateLimits);
	papiWriteScenario_vec(scn, "LVDC_CurrentAttitude", CurrentAttitude);
	papiWriteScenario_vec(scn, "LVDC_ddotG_act", ddotG_act);
	papiWriteScenario_vec(scn, "LVDC_ddotG_last", ddotG_last);
	papiWriteScenario_vec(scn, "LVDC_ddotM_act", ddotM_act);
	papiWriteScenario_vec(scn, "LVDC_ddotM_last", ddotM_last);
	papiWriteScenario_vec(scn, "LVDC_DDotXEZ_G", DDotXEZ_G);
	papiWriteScenario_vec(scn, "LVDC_DeltaAtt", DeltaAtt);
	papiWriteScenario_vec(scn, "LVDC_Dot0", Dot0);
	papiWriteScenario_vec(scn, "LVDC_DotG_act", DotG_act);
	papiWriteScenario_vec(scn, "LVDC_DotG_last", DotG_last);
	papiWriteScenario_vec(scn, "LVDC_DotM_act", DotM_act);
	papiWriteScenario_vec(scn, "LVDC_DotM_last", DotM_last);
	papiWriteScenario_vec(scn, "LVDC_DotS", DotS);
	papiWriteScenario_vec(scn, "LVDC_DotXEZ", DotXEZ);
	papiWriteScenario_vec(scn, "LVDC_PCommandedAttitude", PCommandedAttitude);
	papiWriteScenario_vec(scn, "LVDC_Pos4", Pos4);
	papiWriteScenario_vec(scn, "LVDC_PosS", PosS);
	papiWriteScenario_vec(scn, "LVDC_PosXEZ", PosXEZ);
	// MATRIX3
	papiWriteScenario_mx(scn, "LVDC_MX_A", MX_A);
	papiWriteScenario_mx(scn, "LVDC_MX_B", MX_B);
	papiWriteScenario_mx(scn, "LVDC_MX_G", MX_G);
	papiWriteScenario_mx(scn, "LVDC_MX_K", MX_K);
	papiWriteScenario_mx(scn, "LVDC_MX_phi_T", MX_phi_T);
	// Done
	oapiWriteLine(scn, LVDC_END_STRING);
	lvimu.SaveState(scn);
}

void LVDC1B::LoadState(FILEHANDLE scn){
	char *line;	
	int tmp = 0; // Used in boolean type loader

	if(Initialized){
		fprintf(lvlog,"LoadState() called\r\n");
		fflush(lvlog);
	}
	while (oapiReadScenario_nextline (scn, line)) {
		if (!strnicmp(line, LVDC_END_STRING, sizeof(LVDC_END_STRING))){
			break;
		}

		// OLD STUFF
		/*
		if (!strnicmp (line, "phi_lat", 7)) {
			sscanf(line + 7, "%lf", &phi_lat);
		} else if (!strnicmp (line, "phi_lng", 7)) {
			sscanf(line + 7, "%lf", &phi_lng);
		}else if (!strnicmp (line, "Azimuth", 7)) {
			sscanf(line + 7, "%lf", &Azimuth);
		}else if (!strnicmp (line, "DescNodeAngle", 13)) {
			sscanf(line + 13, "%lf", &DescNodeAngle);
		}else if (!strnicmp (line, "Inclination", 11)) {
			sscanf(line + 11, "%lf", &Inclination);
		}else if (!strnicmp (line, "TB", 2)) {
			sscanf(line + 2, "%i", &LVDC_Timebase);
		}else if (!strnicmp (line, "TB_ETime", 8)) {
			sscanf(line + 8, "%lf", &LVDC_TB_ETime);
		}else if (!strnicmp (line, "TAS", 3)) {
			sscanf(line + 3, "%lf", &TAS);
		}else if (!strnicmp (line, "t_clock", 7)) {
			sscanf(line + 7, "%lf", &t_clock);
		}else if (!strnicmp (line, "sinceLastIGM", 12)) {
			sscanf(line + 12, "%lf", &sinceLastIGM);
		}else if (!strnicmp (line, "DotM_act", 8)) {
			sscanf(line + 8, "%lf %lf %lf", &DotM_act.x,&DotM_act.y,&DotM_act.z);
		}else if (!strnicmp (line, "DotM_last", 9)) {
			sscanf(line + 9, "%lf %lf %lf", &DotM_last.x,&DotM_last.y,&DotM_last.z);
		}else if (!strnicmp (line, "PsnS", 4)) {
			sscanf(line + 4, "%lf %lf %lf", &PosS.x,&PosS.y,&PosS.z);
		}else if (!strnicmp (line, "Dot0", 4)) {
			sscanf(line + 4, "%lf %lf %lf", &Dot0.x,&Dot0.y,&Dot0.z);
		}else if (!strnicmp (line, "DotG_last", 9)) {
			sscanf(line + 9, "%lf %lf %lf", &DotG_last.x,&DotG_last.y,&DotG_last.z);
		}else if (!strnicmp (line, "ddotG_last", 10)) {
			sscanf(line + 10, "%lf %lf %lf", &ddotG_last.x,&ddotG_last.y,&ddotG_last.z);
		}else if (!strnicmp (line, "PCommandedAttitude", 18)) {
			sscanf(line + 18, "%lf %lf %lf", &PCommandedAttitude.x,&PCommandedAttitude.y,&PCommandedAttitude.z);
		}
		*/
		// NEW STUFF
		// Doing all this in one go makes the MS compiler barf.
		// Doing it in long chains makes the MS compiler silently optimize away the tail of the chain.
		// So we do it in small groups.
		// INT
		papiReadScenario_int(line, "LVDC_IGMCycle", IGMCycle);
		papiReadScenario_int(line, "LVDC_LVDC_Timebase", LVDC_Timebase);
		papiReadScenario_int(line, "LVDC_T_EO1", T_EO1);
		papiReadScenario_int(line, "LVDC_T_EO2", T_EO2);
		papiReadScenario_int(line, "LVDC_UP", UP);
		// BOOL
		papiReadScenario_bool(line, "LVDC_alpha_D_op", alpha_D_op);
		papiReadScenario_bool(line, "LVDC_BOOST", BOOST);
		papiReadScenario_bool(line, "LVDC_CountPIPA", CountPIPA);
		papiReadScenario_bool(line, "LVDC_GATE", GATE);
		papiReadScenario_bool(line, "LVDC_GATE5", GATE5);
		papiReadScenario_bool(line, "LVDC_GRR_init", GRR_init);
		papiReadScenario_bool(line, "LVDC_HSL", HSL);
		papiReadScenario_bool(line, "LVDC_INH", INH);
		papiReadScenario_bool(line, "LVDC_INH1", INH1);
		papiReadScenario_bool(line, "LVDC_INH2", INH2);
		papiReadScenario_bool(line, "LVDC_i_op", i_op);
		papiReadScenario_bool(line, "LVDC_liftoff", liftoff);
		papiReadScenario_bool(line, "LVDC_LVDC_EI_On", LVDC_EI_On);
		papiReadScenario_bool(line, "LVDC_LVDC_GRR", LVDC_GRR);
		papiReadScenario_bool(line, "LVDC_LVDC_Stop", LVDC_Stop);
		papiReadScenario_bool(line, "LVDC_MRS", MRS);
		papiReadScenario_bool(line, "LVDC_poweredflight", poweredflight);
		papiReadScenario_bool(line, "LVDC_S1B_Engine_Out", S1B_Engine_Out);
		papiReadScenario_bool(line, "LVDC_S4B_IGN", S4B_IGN);
		papiReadScenario_bool(line, "LVDC_TerminalConditions", TerminalConditions);
		papiReadScenario_bool(line, "LVDC_theta_N_op", theta_N_op);

		// DOUBLE
		papiReadScenario_double(line, "LVDC_a", a);
		papiReadScenario_double(line, "LVDC_a_0p", a_0p);
		papiReadScenario_double(line, "LVDC_a_0r", a_0r);
		papiReadScenario_double(line, "LVDC_a_0y", a_0y);
		papiReadScenario_double(line, "LVDC_a_1", a_1);
		papiReadScenario_double(line, "LVDC_a_2", a_2);
		papiReadScenario_double(line, "LVDC_A1", A1);
		papiReadScenario_double(line, "LVDC_A2", A2);
		papiReadScenario_double(line, "LVDC_A3", A3);
		papiReadScenario_double(line, "LVDC_A4", A4);
		papiReadScenario_double(line, "LVDC_A5", A5);
		papiReadScenario_double(line, "LVDC_a_1p", a_1p);
		papiReadScenario_double(line, "LVDC_a_1r", a_1r);
		papiReadScenario_double(line, "LVDC_a_1y", a_1y);
		papiReadScenario_double(line, "LVDC_alpha_1", alpha_1);
		papiReadScenario_double(line, "LVDC_alpha_2", alpha_2);
		papiReadScenario_double(line, "LVDC_alpha_D", alpha_D);
		papiReadScenario_double(line, "LVDC_Azimuth", Azimuth);
		papiReadScenario_double(line, "LVDC_Azo", Azo);
		papiReadScenario_double(line, "LVDC_Azs", Azs);
		papiReadScenario_double(line, "LVDC_B_11", B_11);
		papiReadScenario_double(line, "LVDC_B_12", B_12);
		papiReadScenario_double(line, "LVDC_B_21", B_21);
		papiReadScenario_double(line, "LVDC_B_22", B_22);
		papiReadScenario_double(line, "LVDC_beta_p1c", beta_p1c);
		papiReadScenario_double(line, "LVDC_beta_p2c", beta_p2c);
		papiReadScenario_double(line, "LVDC_beta_p3c", beta_p3c);
		papiReadScenario_double(line, "LVDC_beta_p4c", beta_p4c);
		papiReadScenario_double(line, "LVDC_beta_pc", beta_pc);
		papiReadScenario_double(line, "LVDC_beta_rc", beta_rc);
		papiReadScenario_double(line, "LVDC_beta_y1c", beta_y1c);
		papiReadScenario_double(line, "LVDC_beta_y2c", beta_y2c);
		papiReadScenario_double(line, "LVDC_beta_y3c", beta_y3c);
		papiReadScenario_double(line, "LVDC_beta_y4c", beta_y4c);
		papiReadScenario_double(line, "LVDC_beta_yc", beta_yc);
		papiReadScenario_double(line, "LVDC_C_2", C_2);
		papiReadScenario_double(line, "LVDC_C_3", C_3);
		papiReadScenario_double(line, "LVDC_C_4", C_4);
		papiReadScenario_double(line, "LVDC_CG", CG);
		papiReadScenario_double(line, "LVDC_cos_chi_Yit", cos_chi_Yit);
		papiReadScenario_double(line, "LVDC_cos_chi_Zit", cos_chi_Zit);
		papiReadScenario_double(line, "LVDC_cos_phi_L", cos_phi_L);
		papiReadScenario_double(line, "LVDC_d2", d2);
		papiReadScenario_double(line, "LVDC_ddot_xi_G", ddot_xi_G);
		papiReadScenario_double(line, "LVDC_ddot_eta_G", ddot_eta_G);
		papiReadScenario_double(line, "LVDC_ddot_zeta_G", ddot_zeta_G);
		papiReadScenario_double(line, "LVDC_ddot_zeta_GT", ddot_zeta_GT);
		papiReadScenario_double(line, "LVDC_ddot_xi_GT", ddot_xi_GT);
		papiReadScenario_double(line, "LVDC_DescNodeAngle", DescNodeAngle);
		papiReadScenario_double(line, "LVDC_deta", deta);
		papiReadScenario_double(line, "LVDC_dxi", dxi);
		papiReadScenario_double(line, "LVDC_dot_dxi", dot_dxi);
		papiReadScenario_double(line, "LVDC_dot_dzeta", dot_dzeta);
		papiReadScenario_double(line, "LVDC_dot_dxit", dot_dxit);
		papiReadScenario_double(line, "LVDC_dot_detat", dot_detat);
		papiReadScenario_double(line, "LVDC_dot_dzetat", dot_dzetat);
		papiReadScenario_double(line, "LVDC_dotM_1", dotM_1);
		papiReadScenario_double(line, "LVDC_dotM_2", dotM_2);
		papiReadScenario_double(line, "LVDC_dot_phi_1", dot_phi_1);
		papiReadScenario_double(line, "LVDC_dot_phi_T", dot_phi_T);
		papiReadScenario_double(line, "LVDC_dot_zeta_T", dot_zeta_T);
		papiReadScenario_double(line, "LVDC_dot_xi_T", dot_xi_T);
		papiReadScenario_double(line, "LVDC_dot_eta_T", dot_eta_T);
		papiReadScenario_double(line, "LVDC_dt", dt);
		papiReadScenario_double(line, "LVDC_dT_2", dT_2);
		papiReadScenario_double(line, "LVDC_dt_c", dt_c);
		papiReadScenario_double(line, "LVDC_dT_F", dT_F);
		papiReadScenario_double(line, "LVDC_dt_LET", dt_LET);
		papiReadScenario_double(line, "LVDC_dtt_1", dtt_1);
		papiReadScenario_double(line, "LVDC_dtt_2", dtt_2);
		papiReadScenario_double(line, "LVDC_dV", dV);
		papiReadScenario_double(line, "LVDC_dV_B", dV_B);
		papiReadScenario_double(line, "LVDC_e", e);
		papiReadScenario_double(line, "LVDC_eps_2", eps_2);
		papiReadScenario_double(line, "LVDC_eps_3", eps_3);
		papiReadScenario_double(line, "LVDC_eps_4", eps_4);
		papiReadScenario_double(line, "LVDC_eps_p", eps_p);
		papiReadScenario_double(line, "LVDC_eps_ymr", eps_ymr);
		papiReadScenario_double(line, "LVDC_eps_ypr", eps_ypr);
		papiReadScenario_double(line, "LVDC_e", e);
		papiReadScenario_double(line, "LVDC_F", F);
		papiReadScenario_double(line, "LVDC_Fm", Fm);
		papiReadScenario_double(line, "LVDC_Fx[0][0]", Fx[0][0]);
		papiReadScenario_double(line, "LVDC_Fx[0][1]", Fx[0][1]);
		papiReadScenario_double(line, "LVDC_Fx[0][2]", Fx[0][2]);
		papiReadScenario_double(line, "LVDC_Fx[0][3]", Fx[0][3]);
		papiReadScenario_double(line, "LVDC_Fx[0][4]", Fx[0][4]);
		papiReadScenario_double(line, "LVDC_Fx[1][0]", Fx[1][0]);
		papiReadScenario_double(line, "LVDC_Fx[1][1]", Fx[1][1]);
		papiReadScenario_double(line, "LVDC_Fx[1][2]", Fx[1][2]);
		papiReadScenario_double(line, "LVDC_Fx[1][3]", Fx[1][3]);
		papiReadScenario_double(line, "LVDC_Fx[1][4]", Fx[1][4]);
		papiReadScenario_double(line, "LVDC_Fx[2][0]", Fx[2][0]);
		papiReadScenario_double(line, "LVDC_Fx[2][1]", Fx[2][1]);
		papiReadScenario_double(line, "LVDC_Fx[2][2]", Fx[2][2]);
		papiReadScenario_double(line, "LVDC_Fx[2][3]", Fx[2][3]);
		papiReadScenario_double(line, "LVDC_Fx[2][4]", Fx[2][4]);
		papiReadScenario_double(line, "LVDC_Fx[3][0]", Fx[3][0]);
		papiReadScenario_double(line, "LVDC_Fx[3][1]", Fx[3][1]);
		papiReadScenario_double(line, "LVDC_Fx[3][2]", Fx[3][2]);
		papiReadScenario_double(line, "LVDC_Fx[3][3]", Fx[3][3]);
		papiReadScenario_double(line, "LVDC_Fx[3][4]", Fx[3][4]);
		papiReadScenario_double(line, "LVDC_Fx[4][0]", Fx[4][0]);
		papiReadScenario_double(line, "LVDC_Fx[4][1]", Fx[4][1]);
		papiReadScenario_double(line, "LVDC_Fx[4][2]", Fx[4][2]);
		papiReadScenario_double(line, "LVDC_Fx[4][3]", Fx[4][3]);
		papiReadScenario_double(line, "LVDC_Fx[4][4]", Fx[4][4]);
		papiReadScenario_double(line, "LVDC_fx[0]", fx[0]);
		papiReadScenario_double(line, "LVDC_fx[1]", fx[1]);
		papiReadScenario_double(line, "LVDC_fx[2]", fx[2]);
		papiReadScenario_double(line, "LVDC_fx[3]", fx[3]);
		papiReadScenario_double(line, "LVDC_fx[4]", fx[4]);
		papiReadScenario_double(line, "LVDC_fx[5]", fx[5]);
		papiReadScenario_double(line, "LVDC_fx[6]", fx[6]);
		papiReadScenario_double(line, "LVDC_G_T", G_T);
		papiReadScenario_double(line, "LVDC_gx[0]", gx[0]);
		papiReadScenario_double(line, "LVDC_gx[1]", gx[1]);
		papiReadScenario_double(line, "LVDC_gx[2]", gx[2]);
		papiReadScenario_double(line, "LVDC_gx[3]", gx[3]);
		papiReadScenario_double(line, "LVDC_gx[4]", gx[4]);
		papiReadScenario_double(line, "LVDC_gx[5]", gx[5]);
		papiReadScenario_double(line, "LVDC_gx[6]", gx[6]);
		papiReadScenario_double(line, "LVDC_IGMInterval", IGMInterval);
		papiReadScenario_double(line, "LVDC_Inclination", Inclination);
		papiReadScenario_double(line, "LVDC_J", J);
		papiReadScenario_double(line, "LVDC_J_1", J_1);
		papiReadScenario_double(line, "LVDC_J_2", J_2);
		papiReadScenario_double(line, "LVDC_Jt_2", Jt_2);
		papiReadScenario_double(line, "LVDC_J_Y", J_Y);
		papiReadScenario_double(line, "LVDC_J_P", J_P);
		papiReadScenario_double(line, "LVDC_K_1", K_1);
		papiReadScenario_double(line, "LVDC_K_2", K_2);
		papiReadScenario_double(line, "LVDC_K_3", K_3);
		papiReadScenario_double(line, "LVDC_K_4", K_4);
		papiReadScenario_double(line, "LVDC_K_5", K_5);
		papiReadScenario_double(line, "LVDC_K_P1", K_P1);
		papiReadScenario_double(line, "LVDC_K_P2", K_P2);
		papiReadScenario_double(line, "LVDC_K_p", K_p);
		papiReadScenario_double(line, "LVDC_K_y", K_y);
		papiReadScenario_double(line, "LVDC_K_r", K_r);
		papiReadScenario_double(line, "LVDC_K_Y1", K_Y1);
		papiReadScenario_double(line, "LVDC_K_Y2", K_Y2);
		papiReadScenario_double(line, "LVDC_K_Y", K_Y);
		papiReadScenario_double(line, "LVDC_K_P", K_P);
		papiReadScenario_double(line, "LVDC_D_P", D_P);
		papiReadScenario_double(line, "LVDC_D_Y", D_Y);
		papiReadScenario_double(line, "LVDC_L_1", L_1);
		papiReadScenario_double(line, "LVDC_L_2", L_2);
		papiReadScenario_double(line, "LVDC_dL_2", dL_2);
		papiReadScenario_double(line, "LVDC_Lt_2", Lt_2);
		papiReadScenario_double(line, "LVDC_L_P", L_P);
		papiReadScenario_double(line, "LVDC_L_Y", L_Y);
		papiReadScenario_double(line, "LVDC_Lt_Y", Lt_Y);
		papiReadScenario_double(line, "LVDC_LVDC_TB_ETime", LVDC_TB_ETime);
		papiReadScenario_double(line, "LVDC_mu", mu);
		papiReadScenario_double(line, "LVDC_p", p);
		papiReadScenario_double(line, "LVDC_P_1", P_1);
		papiReadScenario_double(line, "LVDC_P_2", P_2);
		papiReadScenario_double(line, "LVDC_phi_lat", phi_lat);
		papiReadScenario_double(line, "LVDC_phi_lng", phi_lng);
		papiReadScenario_double(line, "LVDC_phi_T", phi_T);
		papiReadScenario_double(line, "LVDC_Q_1", Q_1);
		papiReadScenario_double(line, "LVDC_Q_2", Q_2);
		papiReadScenario_double(line, "LVDC_Q_Y", Q_Y);
		papiReadScenario_double(line, "LVDC_Q_P", Q_P);
		papiReadScenario_double(line, "LVDC_R", R);
		papiReadScenario_double(line, "LVDC_ROV", ROV);
		papiReadScenario_double(line, "LVDC_ROVs", ROVs);
		papiReadScenario_double(line, "LVDC_R_T", R_T);
		papiReadScenario_double(line, "LVDC_S1B_Sep_Time", S1B_Sep_Time);
		papiReadScenario_double(line, "LVDC_S_1", S_1);
		papiReadScenario_double(line, "LVDC_S_2", S_2);
		papiReadScenario_double(line, "LVDC_S_P", S_P);
		papiReadScenario_double(line, "LVDC_S_Y", S_Y);
		papiReadScenario_double(line, "LVDC_sinceLastIGM", sinceLastIGM);
		papiReadScenario_double(line, "LVDC_sin_chi_Yit", sin_chi_Yit);
		papiReadScenario_double(line, "LVDC_sin_chi_Zit", sin_chi_Zit);
		papiReadScenario_double(line, "LVDC_sin_phi_L", sin_phi_L);
		papiReadScenario_double(line, "LVDC_sin_ups", sin_ups);
		papiReadScenario_double(line, "LVDC_cos_ups", cos_ups);
		papiReadScenario_double(line, "LVDC_SMCG", SMCG);
		papiReadScenario_double(line, "LVDC_S", S);
		papiReadScenario_double(line, "LVDC_P", P);
		papiReadScenario_double(line, "LVDC_t", t);
		papiReadScenario_double(line, "LVDC_t_1", t_1);
		papiReadScenario_double(line, "LVDC_T_1", T_1);
		papiReadScenario_double(line, "LVDC_t_2", t_2);
		papiReadScenario_double(line, "LVDC_T_2", T_2);
		papiReadScenario_double(line, "LVDC_t_3", t_3);
		papiReadScenario_double(line, "LVDC_t_3i", t_3i);
		papiReadScenario_double(line, "LVDC_t_4", t_4);
		papiReadScenario_double(line, "LVDC_t_5", t_5);
		papiReadScenario_double(line, "LVDC_t_6", t_6);
		papiReadScenario_double(line, "LVDC_TA1", TA1);
		papiReadScenario_double(line, "LVDC_TA2", TA2);
		papiReadScenario_double(line, "LVDC_TA3", TA3);
		papiReadScenario_double(line, "LVDC_T_ar", T_ar);
		papiReadScenario_double(line, "LVDC_TAS", TAS);
		papiReadScenario_double(line, "LVDC_tau1", tau1);
		papiReadScenario_double(line, "LVDC_tau2", tau2);
		papiReadScenario_double(line, "LVDC_t_B1", t_B1);
		papiReadScenario_double(line, "LVDC_t_B3", t_B3);
		papiReadScenario_double(line, "LVDC_tchi_y_last", tchi_y_last);
		papiReadScenario_double(line, "LVDC_tchi_p_last", tchi_p_last);
		papiReadScenario_double(line, "LVDC_tchi_y", tchi_y);
		papiReadScenario_double(line, "LVDC_tchi_p", tchi_p);
		papiReadScenario_double(line, "LVDC_t_clock", t_clock);
		papiReadScenario_double(line, "LVDC_T_CO", T_CO);
		papiReadScenario_double(line, "LVDC_t_fail", t_fail);
		papiReadScenario_double(line, "LVDC_T_GO", T_GO);
		papiReadScenario_double(line, "LVDC_TI5F2", TI5F2);
		papiReadScenario_double(line, "LVDC_T_LET", T_LET);
		papiReadScenario_double(line, "LVDC_T_S1", T_S1);
		papiReadScenario_double(line, "LVDC_T_S2", T_S2);
		papiReadScenario_double(line, "LVDC_T_S3", T_S3);
		papiReadScenario_double(line, "LVDC_TSMC1", TSMC1);
		papiReadScenario_double(line, "LVDC_TSMC2", TSMC2);
		papiReadScenario_double(line, "LVDC_T_T", T_T);
		papiReadScenario_double(line, "LVDC_Tt_2", Tt_2);
		papiReadScenario_double(line, "LVDC_Tt_T", Tt_T);
		papiReadScenario_double(line, "LVDC_U_1", U_1);
		papiReadScenario_double(line, "LVDC_U_2", U_2);
		papiReadScenario_double(line, "LVDC_gamma_T", gamma_T);
		papiReadScenario_double(line, "LVDC_V", V);
		papiReadScenario_double(line, "LVDC_V_ex1", V_ex1);
		papiReadScenario_double(line, "LVDC_V_ex2", V_ex2);
		papiReadScenario_double(line, "LVDC_V_i", V_i);
		papiReadScenario_double(line, "LVDC_V_0", V_0);
		papiReadScenario_double(line, "LVDC_V_1", V_1);
		papiReadScenario_double(line, "LVDC_V_2", V_2);
		papiReadScenario_double(line, "LVDC_V_T", V_T);
		papiReadScenario_double(line, "LVDC_V_TC", V_TC);
		papiReadScenario_double(line, "LVDC_xi_T", xi_T);
		papiReadScenario_double(line, "LVDC_eta_T", eta_T);
		papiReadScenario_double(line, "LVDC_zeta_T", zeta_T);
		papiReadScenario_double(line, "LVDC_X_S1", X_S1);
		papiReadScenario_double(line, "LVDC_X_S2", X_S2);
		papiReadScenario_double(line, "LVDC_X_S3", X_S3);
		papiReadScenario_double(line, "LVDC_Xtt_y", Xtt_y);
		papiReadScenario_double(line, "LVDC_Xtt_p", Xtt_p);
		papiReadScenario_double(line, "LVDC_X_Zi", X_Zi);
		papiReadScenario_double(line, "LVDC_X_Yi", X_Yi);
		papiReadScenario_double(line, "LVDC_Y_u", Y_u);

		// VECTOR3
		papiReadScenario_vec(line, "LVDC_ACommandedAttitude", ACommandedAttitude);
		papiReadScenario_vec(line, "LVDC_AttitudeError", AttitudeError);
		papiReadScenario_vec(line, "LVDC_AttRate", AttRate);
		papiReadScenario_vec(line, "LVDC_CommandedAttitude", CommandedAttitude);
		papiReadScenario_vec(line, "LVDC_CommandRateLimits", CommandRateLimits);
		papiReadScenario_vec(line, "LVDC_CurrentAttitude", CurrentAttitude);
		papiReadScenario_vec(line, "LVDC_ddotG_act", ddotG_act);
		papiReadScenario_vec(line, "LVDC_ddotG_last", ddotG_last);
		papiReadScenario_vec(line, "LVDC_ddotM_act", ddotM_act);
		papiReadScenario_vec(line, "LVDC_ddotM_last", ddotM_last);
		papiReadScenario_vec(line, "LVDC_DDotXEZ_G", DDotXEZ_G);
		papiReadScenario_vec(line, "LVDC_DeltaAtt", DeltaAtt);
		papiReadScenario_vec(line, "LVDC_Dot0", Dot0);
		papiReadScenario_vec(line, "LVDC_DotG_act", DotG_act);
		papiReadScenario_vec(line, "LVDC_DotG_last", DotG_last);
		papiReadScenario_vec(line, "LVDC_DotM_act", DotM_act);
		papiReadScenario_vec(line, "LVDC_DotM_last", DotM_last);
		papiReadScenario_vec(line, "LVDC_DotS", DotS);
		papiReadScenario_vec(line, "LVDC_DotXEZ", DotXEZ);
		papiReadScenario_vec(line, "LVDC_PCommandedAttitude", PCommandedAttitude);
		papiReadScenario_vec(line, "LVDC_Pos4", Pos4);
		papiReadScenario_vec(line, "LVDC_PosS", PosS);
		papiReadScenario_vec(line, "LVDC_PosXEZ", PosXEZ);

		// MATRIX3
		papiReadScenario_mat(line, "LVDC_MX_A", MX_A);
		papiReadScenario_mat(line, "LVDC_MX_B", MX_B);
		papiReadScenario_mat(line, "LVDC_MX_G", MX_G);
		papiReadScenario_mat(line, "LVDC_MX_K", MX_K);
		papiReadScenario_mat(line, "LVDC_MX_phi_T", MX_phi_T);
	}	
	if(oapiReadScenario_nextline (scn, line)){
		if (!strnicmp(line, LVIMU_START_STRING, sizeof(LVIMU_START_STRING))) {
			// fprintf(lvlog, "LVIMU LoadState() called\r\n");
			// fflush(lvlog);
			lvimu.LoadState(scn);
			/*
			if(lvimu.Initialized) { fprintf(lvlog, "LVIMU Initialized\r\n"); }
			if(lvimu.Operate){ fprintf(lvlog, "LVIMU Operate\r\n"); }
			if(lvimu.Caged) { fprintf(lvlog, "LVIMU Caged\r\n"); }			
			if(lvimu.TurnedOn) { fprintf(lvlog, "LVIMU Turned On\r\n"); }
			fflush(lvlog);
			*/
		}
	}
	return;
}

// ***************************
// DS20150720 LVDC++ ON WHEELS
// ***************************

// Constructor
LVDC::LVDC(){
	int x=0;
	Initialized = false;					// Reset cloberness flag
	// Zeroize
	// booleans
	alpha_D_op = false;
	BOOST = false;
	CountPIPA = false;
	Direct_Ascent = false;
	directstageint = false;
	directstagereset = false;
	first_op = false;
	TerminalConditions = false;
	GATE = false;
	GATE0 = false;
	GATE1 = false;
	GATE2 = false;
	GATE3 = false;
	GATE4 = false;
	GATE5 = false;
	GATE6 = false;
	HSL = false;
	INH = false;
	INH1 = false;
	INH2 = false;
	init = false;
	i_op = false;
	liftoff = false;
	LVDC_EI_On = false;
	LVDC_GRR = false;
	MRS = false;
	poweredflight = false;
	ROT = false;
	S1_Engine_Out = false;
	S2_BURNOUT = false;
	S2_ENGINE_OUT = false;
	S2_IGNITION = false;
	S2_Startup = false;
	S4B_IGN = false;
	theta_N_op = false;
	TU = false;
	TU10 = false;
	// Integers
	IGMCycle = 0;
	LVDC_Stop = 0;
	LVDC_Timebase = 0;
	T_EO1 = 0;
	T_EO2 = 0;
	UP = 0;
	// doubles
	a = 0;
	a_0p = 0;
	a_0r = 0;
	a_0y = 0;
	a_1 = 0;
	a_2 = 0;
	a_1p = 0;
	a_1r = 0;
	a_1y = 0;
	alpha_1 = 0;
	alpha_2 = 0;
	alpha_D = 0;
	Azimuth = 0;
	Azo = 0;
	Azs = 0;
	B_11 = 0;
	B_21 = 0;
	B_12 = 0;
	B_22 = 0;
	beta_p1c = 0;
	beta_p2c = 0;
	beta_p3c = 0;
	beta_p4c = 0;
	beta_pc = 0;
	beta_rc = 0;
	beta_y1c = 0;
	beta_y2c = 0;
	beta_y3c = 0;
	beta_y4c = 0;
	beta_yc = 0;
	C_2 = 0;
	C_4 = 0;
	C_3 = 0;
	Cf = 0;
	CG = 0;
	cos_chi_Yit = 0;
	cos_chi_Zit = 0;
	cos_sigma = 0.0;
	Ct = 0;
	Ct_o = 0;
	D = 0;
	d2 = 0;
	ddot_zeta_GT = 0;
	ddot_xi_GT = 0;
	DEC = 0;
	deta = 0;
	dxi = 0;
	dot_dxi = 0;
	dot_deta = 0;
	dot_dzeta = 0;
	dot_dxit = 0;
	dot_detat = 0;
	dot_dzetat = 0;
	dotM_1 = 0;
	dotM_2 = 0;
	dotM_2R = 0;
	dotM_3 = 0;
	dotM_3R = 0;
	dot_phi_1 = 0;
	dot_phi_T = 0;
	dot_zeta_T = 0;
	dot_xi_T = 0;
	dot_eta_T = 0;
	dt = 0;
	dT_3 = 0;
	dT_4 = 0;
	dt_c = 0;
	dT_cost = 0;
	dT_F = 0;
	dt_g = 0;
	dt_LET = 0;
	dT_LIM = 0;
	dtt_1 = 0;
	dtt_2 = 0;
	dTt_4 = 0;
	dV = 0;
	dV_B = 0;
	e = 0;
	e_N = 0;
	eps_1 = 0;
	eps_2 = 0;
	eps_3 = 0;
	eps_4 = 0;
	eps_1R = 0;
	eps_2R = 0;
	eps_3R = 0;
	eps_4R = 0;
	eps_p = 0;
	eps_ymr = 0;
	eps_ypr = 0;
	f = 0;
	F = 0;
	Fm = 0;
	for(x=0; x < 5; x++){
		int y=0;
		for(y=0; y < 5; y++){
			Fx[x][y] = 0;
		}
		hx[0][y] = 0;
		hx[1][y] = 0;
		hx[2][y] = 0;
		Drag_Area[x] = 0;
	}
	for(x=0; x < 7; x++){
		fx[x] = 0;
		fxt[x] = 0;
		gx[x] = 0;
		gxt[x] = 0;
	}
	for(x=0; x < 4; x++){
		GPitch[x] = 0;
		GYaw[x] = 0;
		OPitch[x] = 0;
		OYaw[x] = 0;
	}
	for (x = 0; x < 6; x++) {
		Rho[x] = 0;
	}
	for (x = 0; x < 2; x++)
	{
		int y;
		TABLE15[x].alphaS_TS = 0;
		TABLE15[x].beta = 0;
		TABLE15[x].f = 0;
		TABLE15[x].T_ST = 0;
		TABLE15[x].R_N = 0;
		for (y = 0; y < 15; y++)
		{
			TABLE15[x].target[y].alpha_D = 0;
			TABLE15[x].target[y].cos_sigma = 0;
			TABLE15[x].target[y].C_3 = 0;
			TABLE15[x].target[y].DEC = 0;
			TABLE15[x].target[y].e_N = 0;
			TABLE15[x].target[y].RAS = 0;
			TABLE15[x].target[y].t_D = 0;
		}
	}
	G_T = 0;
	H = 0;
	IGMInterval = 0;
	Inclination = 0;
	J = 0;
	J_1 = 0;
	J_2 = 0;
	J_3 = 0;
	J_12 = 0;
	Jt_3 = 0;
	J_Y = 0;
	J_P = 0;
	K_1 = 0;
	K_2 = 0;
	K_3 = 0;
	K_4 = 0;
	K_5 = 0;
	K_P1 = 0;
	K_P2 = 0;
	K_Y1 = 0;
	K_Y2 = 0;
	K_Y = 0;
	K_P = 0;
	D_P = 0;
	D_Y = 0;
	L_1 = 0;
	L_2 = 0;
	L_3 = 0;
	dL_3 = 0;
	Lt_3 = 0;
	L_12 = 0;
	L_P = 0;
	L_Y = 0;
	Lt_Y = 0;
	LVDC_TB_ETime = 0;
	mu = 0;
	p = 0;
	P_1 = 0;
	P_2 = 0;
	P_3 = 0;
	P_12 = 0;
	phi_L = 0;
	phi_T = 0;
	Q_1 = 0;
	Q_2 = 0;
	Q_3 = 0;
	Q_12 = 0;
	Q_Y = 0;
	Q_P = 0;
	R = 0;
	RAS = 0;
	RateGain = 0;
	ErrorGain = 0;
	ROV = 0;
	ROVR = 0;
	ROVs = 0;
	R_T = 0;
	S_1 = 0;
	S_2 = 0;
	S_3 = 0;
	S_12 = 0;
	S_P = 0;
	S_Y = 0;
	S1_Sep_Time = 0;
	sinceLastCycle = 0;
	sinceLastGuidanceCycle = 0;
	sin_chi_Yit = 0;
	sin_chi_Zit = 0;
	sin_gam = 0;
	cos_gam = 0;
	SMCG = 0;
	S = 0;
	S_34 = 0;
	P = 0;
	P_34 = 0;
	t = 0;
	T_0 = 0;
	t_1 = 0;
	T_1 = 0;
	T_1c = 0;
	t_2 = 0;
	T_2 = 0;
	T_2R = 0;
	t_21 = 0;
	t_3 = 0;
	T_3 = 0;
	t_3i = 0;
	t_4 = 0;
	T_4N = 0;
	t_5 = 0;
	t_6 = 0;
	TA1 = 0;
	TA2 = 0;
	T_ar = 0;
	TAS = 0;
	tau1 = 0;
	tau2 = 0;
	tau2N = 0;
	tau3 = 0;
	tau3N = 0;
	tau3R = 0;
	t_B1 = 0;
	TB1 = 0;
	t_B2 = 0;
	TB2 = 0;
	t_B3 = 0;
	TB3 = 0;
	t_B4 = 0;
	TB4 = 0;
	TB4A = 0;
	TB5 = 0;
	TB6 = 0;
	TB7 = 0;
	T_c = 0;
	tchi_y_last = 0;
	tchi_p_last = 0;
	tchi_y = 0;
	tchi_p = 0;
	t_clock = 0;
	T_CO = 0;
	t_fail = 0;
	T_GO = 0;
	theta_N = 0;
	TI5F2 = 0;
	T_IGM = 0;
	T_LET = 0;
	T_RG = 0;
	T_RP = 0;
	T_S1 = 0;
	T_S2 = 0;
	T_S3 = 0;
	TS4BS = 0;
	TSMC1 = 0;
	TSMC2 = 0;
	T_ST = 0;
	T_T = 0;
	Tt_3 = 0;
	Tt_3R = 0;
	Tt_T = 0;
	U_1 = 0;
	U_2 = 0;
	U_3 = 0;
	U_12 = 0;
	gamma_T = 0;
	V = 0;
	V_ex1 = 0;
	V_ex2 = 0;
	V_ex2R = 0;
	V_ex3 = 0;
	V_ex3R = 0;
	V_i = 0;
	V_0 = 0;
	V_1 = 0;
	V_2 = 0;
	V_S2T = 0;
	V_T = 0;
	V_TC = 0;
	xi_T = 0;
	eta_T = 0;
	zeta_T = 0;
	X_1 = 0;
	X_2 = 0;
	X_S1 = 0;
	X_S2 = 0;
	X_S3 = 0;
	Xtt_y = 0;
	Xtt_p = 0;
	X_Zi = 0;
	X_Yi = 0;
	Y_u = 0;
	// VECTOR3
	ACommandedAttitude = _V(0,0,0);
	AttitudeError = _V(0,0,0);
	AttRate = _V(0,0,0);
	CommandedAttitude = _V(0,0,0);
	CommandRateLimits = _V(0,0,0);
	CurrentAttitude = _V(0,0,0);
	ddotG_act = _V(0,0,0);
	ddotG_last = _V(0,0,0);
	ddotM_act = _V(0,0,0);
	ddotM_last = _V(0,0,0);
	DDotXEZ_G = _V(0,0,0);
	DotG_act = _V(0,0,0);
	DotG_last = _V(0,0,0);
	DotM_act = _V(0,0,0);
	DotM_last = _V(0,0,0);
	DotS = _V(0,0,0);
	DotXEZ = _V(0,0,0);
	PCommandedAttitude = _V(0,0,0);
	Pos4 = _V(0,0,0);
	PosS = _V(0,0,0);
	PosXEZ = _V(0,0,0);
	TargetVector = _V(0, 0, 0);
	WV = _V(0,0,0);
	XLunarAttitude = _V(0,0,0);
	// MATRIX3
	MX_A = _M(0,0,0,0,0,0,0,0,0);
	MX_B = _M(0,0,0,0,0,0,0,0,0);
	MX_G = _M(0,0,0,0,0,0,0,0,0);
	MX_K = _M(0,0,0,0,0,0,0,0,0);
	MX_phi_T = _M(0,0,0,0,0,0,0,0,0);
	//TABLE15 and TABLE 25
	TABLE15[0] = {};
	TABLE15[1] = {};
	tgt_index = 0;
}

// Setup
void LVDC::Init(Saturn* vs){
	if(vs == NULL){ return; }				// Bail
	if(Initialized == true){ 
		if(owner == vs){
			fprintf(lvlog,"init called after init, ignored\r\n");
			fflush(lvlog);
			return;
		}else{
			fprintf(lvlog,"init called after init with new owner, proceeding\r\n");
			fflush(lvlog);
		}
	}
	owner = vs;								// Our ship
	lvimu.Init();							// Initialize IMU
	lvrg.Init(owner);						// LV Rate Gyro Package
	lvimu.SetVessel(owner);					// set vessel pointer
	lvimu.CoarseAlignEnableFlag = false;	// Clobber this
	//presettings in order of boeing listing for easier maintainece
	//GENERAL
	C_3 = -60731530.2; // Stored as twice the etc etc.
	  //C_3 = -60903382.7388059;
	Direct_Ascent = false;					// flag for selecting direct ascent targeting; not used normally
	GATE = false;							// 'chi-freeze-gate': freezes steering commands when true
	GATE0 = false;							// allows single pass through restart preparations (TB6 start) when false
	GATE1 = false;							// allows single pass through out-of-orbit targeting calculations when false
	GATE2 = false;							// logic switch for first or second opportunity out-of-orbit targeting; false for first
	GATE3 = false;							// allows single pass through out-of-orbit IGM precalculations when false
	GATE4 = false;							// allows single pass through direct-staging guidance update when false
	GATE5 = false;							// allows single pass through HSL initialization when false
	GATE6 = false;
	INH = false;							// inhibits restart preparations; set by x-lunar inject/inhibit switch
	INH1 = true;							// inhibits first EPO roll/pitch maneuver
	INH2 = true;							// inhibits second EPO roll/pitch maneuver
	TA1 = 2700;								//time for TB5 start to first maneuver
	TA2 = 5160;								//time for TB5 start to second maneuver
	TB1 = TB2 = TB3 = TB4 = TB4A = TB5 = TB6 = TB7 = 100000; //LVDC's elapsed timebase times; set to 0 when resp. TB starts
	T_LET = 40.671;							// LET Jettison Time, i.e. the time IGM starts after start of TB3
	TU = false;								// flag indicating target update has been received from ground
	TU10 = false;							// flag indicating 10-parameter target update has been received
	UP = 0;									// switching variable for Tt_t parameter update
	alpha_D_op = true;
	i_op = true;							// flag for selecting method of EPO inclination calculation
	theta_N_op = true;						// flag for selecting method of EPO descending node calculation
	TerminalConditions = true;
	directstagereset = true;
	//PRE_IGM GUIDANCE
	B_11 = -0.62;							// Coefficients for determining freeze time after S1C engine failure
	B_12 = 40.9;							// dto.
	B_21 = -0.3611;							// dto.
	B_22 = 29.25;							// dto.

	Drag_Area[0] = 0.0;
	Drag_Area[1] = 0.0;
	Drag_Area[2] = 0.0;
	Drag_Area[3] = 0.0;
	Drag_Area[4] = 0.0;
	// PITCH POLYNOMIAL (Apollo 9)
	Fx[1][0] =  3.19840;
	Fx[1][1] =  -0.544236;
	Fx[1][2] =  0.0351605;
	Fx[1][3] =  -0.00116379;
	Fx[1][4] =  0.000011386;
	Fx[2][0] =  -10.9607;
	Fx[2][1] =  0.946620;
	Fx[2][2] =  -0.0294206;
	Fx[2][3] =  0.000207717;
	Fx[2][4] =  -0.000000439036;
	Fx[3][0] =  78.7826;
	Fx[3][1] =  -2.83749;
	Fx[3][2] =  0.0289710;
	Fx[3][3] =  -0.000178363;
	Fx[3][4] =  0.000000463029;
	Fx[4][0] =  69.9191;
	Fx[4][1] =  -2.007490;
	Fx[4][2] =  0.0105367;
	Fx[4][3] =  -0.0000233163;
	Fx[4][4] =  0.0000000136702;
	t_1 = 13;								// Backup timer for Pre-IGM pitch maneuver
	t_2 = 25;								// Time to initiate pitch freeze for S1C engine failure
	t_3 = 36;								// Constant pitch freeze for S1C engine failure prior to t_2
	t_3i = 0;								// Clock time at S4B ignition
	t_4 = 45;								// Upper bound of validity for first segment of pitch freeze
	t_5 = 81;								// Upper bound of validity for second segment of pitch freeze
	t_6 = 0;								// Time to terminate pitch freeze after S1C engine failure
	T_ar = 147;								// S1C Tilt Arrest Time	   
	T_S1 = 33.6;							// Pitch Polynomial Segment Times
	T_S2 = 68.6;							// dto.
	T_S3 = 95.6;							// dto.
	T_EO1 = 0;								// switching constant for SIC engine-out handling
	T_EO2 = 0;								// allows single pass through IGM engine-out presettings when 0
	dt = 1.7;								// Nominal powered-flight or coast-guidance computation-cycle interval
	dT_F=0;									// Period of frozen pitch in S1C
	dt_LET = 35.1;							// Nominal time between SII ign and LET jet
	t_fail =0;								// S1C Engine Failure time
	CommandRateLimits=_V(1*RAD,1*RAD,1*RAD);// Radians per second
	//IGM BOOST TO ORBIT
	Ct = 0;
	Ct_o = 10;
	Cf = 0.087996;
	// Inclination from azimuth polynomial
	fx[0] = 32.55754;  fx[1] = -15.84615; fx[2] = 11.64780; fx[3] = 9.890970;
	fx[4] = -5.111430; fx[5] = 0;         fx[6] = 0;
	// Descending Node Angle from azimuth polynomial
	gx[0] = 123.1935; gx[1] = -55.06485; gx[2] = -35.26208; gx[3] = 26.01324;
	gx[4] = -1.47591; gx[5] = 0;         gx[6] = 0;	
	// Launch azimuth from time polynomial
	hx[0][0] = 72.0;	hx[0][1] = 0.0;	hx[0][2] = 0.0;	hx[0][3] = 0.0;	hx[0][4] = 0.0;
	hx[1][0] = 72.0;	hx[1][1] = 0.0;	hx[1][2] = 0.0;	hx[1][3] = 0.0;	hx[1][4] = 0.0;
	hx[2][0] = 72.0;	hx[2][1] = 0.0;	hx[2][2] = 0.0;	hx[2][3] = 0.0;	hx[2][4] = 0.0;
	// Air density polynomial
	Rho[0] = 0.179142e-6;	Rho[1] = -0.37213949e-11;	Rho[2] = 0.31057886e-16;
	Rho[3] = -0.12962178e-21;	Rho[4] = 0.2698641e-27;	Rho[5] = -0.2238826e-33;
	// Out-of-orbit parameters
	TABLE15[0].alphaS_TS = 14.2691472;
	TABLE15[0].beta = 61.89975;
	TABLE15[0].f = 14.26968;
	TABLE15[0].R_N = 6575100;
	TABLE15[0].T_ST = 15000.0;
	TABLE15[0].target[0].cos_sigma = 9.958662e-1;
	TABLE15[0].target[1].cos_sigma = 9.958662e-1;
	TABLE15[0].target[0].C_3 = -1.418676e6;
	TABLE15[0].target[1].C_3 = -1.418676e6;
	TABLE15[0].target[0].DEC = -26.646912;
	TABLE15[0].target[1].DEC = -26.646912;
	TABLE15[0].target[0].e_N = 0.9765500;
	TABLE15[0].target[1].e_N = 0.9765500;
	TABLE15[0].target[0].RAS = -114.382494;
	TABLE15[0].target[1].RAS = -114.382494;
	TABLE15[0].target[0].t_D = 0.0;
	TABLE15[0].target[1].t_D = 1000.0;

	MRS = false;							// MR Shift
	dotM_1 = 1224.13817;//1219.299283;					// Mass flowrate of S2 from approximately LET jettison to second MRS
	dotM_2 = 890.2122217;//61.8088872;					// Mass flowrate of S2 after second MRS
	dotM_2R = 178.0424443;//188.221437;//187.007;
	dotM_3 = 215.2292029;//222.4339038;					// Mass flowrate of S4B during first burn
	dotM_3R = 217.6503205;//218.586;
	ROT = false;
	ROTR = true;
	dV_B = 1.782; // AP11// dV_B = 2.0275; // AP9// Velocity cutoff bias for orbital insertion
	dV_BR = 2.8816;
	ROV = 1.48119724870249; //0.75-17
	ROVs = 1.5;
	ROVR = 0.0;
	phi_L = 0.4993088329;					// Geodetic Launch site latitude
	R_N = 6575100;
	SMCG = 0.05*RAD;
	TS4BS = 13.5;
	TSMC1 = 20; TSMC2 = 5; // AP9
	TSMC3 = 466;
	// TSMC1 = 60.6 TSMC2 = 15 // AP11
	T_c = 8; // T_c = 6.5; 					// Coast time between S2 burnout and S4B ignition
	T_1 = 249.1; //T_1  = 237.796;			// Time left in first-stage IGM
	T_2 = 91.8; //T_2 = 111;					// Time left in second and fourth stage IGM
	T_2R = 10.0;
	T_3 = 0;								// Time left in third and fifth stage IGM
	T_1c = T_1 + T_2 + T_c;					// Sum of the burn times of IGM first, second, and coast guidance stages
	T_4N = 165.0;//120.565; //T_4N = 120.565;		// Nominal time of S4B first burn
	Tt_3 = T_4N;//188; //Tt_3 = 135.6;				// Estimated third or fifth stage burn time
	Tt_3R = 315.0;//340.0;
	Tt_T = T_1c + Tt_3;						// Time-To-Go computed using Tt_3
	t = 0;									// Time from accelerometer reading to next steering command
	t_B1 = 4;								// Transition time for the S2 mixture ratio to shift from 5.5 to 4.7
	t_B2 = 0;
	t_B3 = 0;								// Time from second S2 MRS signal
	t_B4 = 0;
	t_D = 0;
	t_D0 = 0.0;
	t_D1 = 0.0;
	t_D2 = 10984.2;
	t_D3 = 16503.1;
	t_DS0 = 0.0;
	t_DS1 = 10984.2;
	t_DS2 = 16503.1;
	t_DS3 = 0.0;
	theta_EO = 0.0;
	TI5F2 = 20.0;

	double day;
	T_LO = modf(oapiGetSimMJD(), &day)*24.0*3600.0 - owner->MissionTime - 17.0;
	t_SD1 = 10984.2;
	t_SD2 = 5518.9;
	t_SD3 = 1233.6;
	//dt: not set; dependend on cycle time
	dt_g = 1.0;
	dT_LIM = 90;							// Limit to dT_4;
	V_ex1 = 4153.941218;//4148.668555;
	V_ex2 = 4221.827032;//4158.852692;
	V_ex2R = 4221.827032;//4228.02;
	V_ex3 = 4184.41823;//4130.010682;
	V_ex3R = 4184.41823;//4130.010682;//4193.05;
	V_S2T = 7007.18;
	V_TC = 300;
	eps_1 = 0;								// IGM range angle calculation selection
	eps_1R = 500.0;
	eps_2 = 32;								// Time to begin chi bar steering
	eps_2R = 15;
	eps_3 = 10000;							// Terminal condition freeze time
	eps_3R = 3.59;
	eps_4 = 3;								// Time to enable HSL loop & chi freeze
	eps_4R = 3.59;
	mu = 398603200000000;					// Product of G and Earth's mass
	tau2 = 308.95;							// Time to consume all fuel between MRS and S2 Cutoff
	tau2N = 721;
	tau3 = 709.7853;//748.7;							// Time to consume all fuel of SIVB
	tau3R = tau3 - T_4N;//576;
	tau3N = tau3;							// artificial tau3
	omega_E = 2.32115e-5*PI;
	//rate limits: set in pre-igm
	alpha_1 = 0;							// orbital guidance pitch
	alpha_2 = 0;							// orbital guidance yaw
	K_P1 = 0.0;//4.3 * RAD;					// restart attitude coefficients
	K_P2 = 0;
	K_Y1 = 0;
	K_Y2 = 0;
	K_T3 = -.274;
	K_pc = 75.0;
	first_op = true;
	//IGM out-of-orbit
	T_RG = 578.6;
	T_RP = 0;
	T_IGM = 583;
	T_ST = 0;
	alpha_TS = 0;
	beta = 0;

	//Not in boeing doc, but needed for nav:
	a = 6378137;							// earth's equatorial radius
	J = 1.62345e-3;							// first coefficient of earth's gravity
	D = 0.7875e-5;
	H = 0.575e-5;

	//'real' software variable, i.e. those are computed at runtime
	// Software flags
	liftoff = false;
	poweredflight = false;
	HSL=false;								// High-Speed Loop flag
	BOOST=false;							// Boost To Orbit
	S4B_IGN=false;							// SIVB Ignition
	S4B_REIGN = false;						// SIVB Reignition
	S2_IGNITION=false;						// S2 Ignition
	S2_ENGINE_OUT=false;					// S2 Engine Failure
	S2_BURNOUT=false;						// SII Burn Out
	LVDC_GRR = false;
	S1_Engine_Out = false;		
	tau1 = 1.0;								// Time to consume all fuel before S2 MRS
	Fm=0;									// sensed total accel
	Inclination=0;							// Inclination
	theta_N = 0;
	cos_sigma = 0.0;
	Azo=72.0; Azs=36.0;							// Variables for scaling the -from-azimuth polynomials
	CommandedAttitude=_V(0,0,0);			// Commanded Attitude (RADIANS)
	PCommandedAttitude=_V(0,0,0);			// Previous Commanded Attitude (RADIANS)
	CurrentAttitude=_V(0,0,0);				// Current Attitude   (RADIANS)
	F=0;									// Force in Newtons, I assume.	
	K_Y=0; K_P=0; D_P=0; D_Y=0;				// Intermediate variables in IGM
	P_1=0; P_2=0; P_3=0; P_12=0;	
	L_1=0; L_2=0; L_3=0; dL_3=0; Lt_3=0; L_12=0; L_P=0; L_Y=0; Lt_Y=0;
	J_1=0; J_2=0; J_3=0; J_12=0; Jt_3=0; J_Y=0; J_P=0; 
	S_1=0; S_2=0; S_3=0; S_12=0; S_P=0; S_Y=0; 
	U_1=0; U_2=0; U_3=0; U_12=0; 
	Q_1=0; Q_2=0; Q_3=0; Q_12=0; Q_Y=0; Q_P=0; 
	d2=0;
	f=0;									// True anomaly of the predicted cutoff radius vector
	e=0;									// Eccentricity of the transfer ellipse
	e_N = 0;
	C_2=0; C_4=0;							// IGM coupling terms for pitch steering
	p=0;									// semilatus rectum of terminal ellipse
	K_1=0; K_2=0; K_3=0; K_4=0;				// Correction to chi-tilde steering angles, K_i
	K_5=0;									// IGM terminal velocity constant
	R=0;									// Instantaneous Radius Magnitude
	R_T=6563366.0;							// Desired terminal radius
	V=0;									// Instantaneous vehicle velocity
	V_T=7793.0429;							// Desired terminal velocity
	V_i=0; V_0=0; V_1=0; V_2=0;				// Parameters for cutoff velocity computation
	gamma_T=0;								// Desired terminal flight-path angle
	MX_A=_M(0,0,0,0,0,0,0,0,0);				// Transform matrix from earth-centered plumbline to equatorial
	MX_B=_M(0,0,0,0,0,0,0,0,0);				// Transform matrix from equatorial to orbital coordinates
	MX_G=_M(0,0,0,0,0,0,0,0,0);				// Transform matrix from earth-centered plumbline to orbital
	MX_K=_M(0,0,0,0,0,0,0,0,0);				// Transform matrix from earth-centered plumbline to terminal
	MX_phi_T=_M(0,0,0,0,0,0,0,0,0);			// Matrix made from phi_T
	phi_T=0;								// Angle used to estimate location of terminal radius in orbital plane
	Pos4=_V(0,0,0);							// Position in the orbital reference system
	PosS=_V(0,0,0);							// Position in the earth-centered plumbline system. SPACE-FIXED.
	DotS=_V(0,0,0);							// VELOCITY in the earth-centered plumbline system
	DotM_act=_V(0,0,0);						// actual sensed velocity from platform
	ddotM_act =_V(0,0,0);
	ddotM_last =_V(0,0,0);
	ddotG_act=_V(0,0,0);					// actual computed acceleration from gravity
	DotG_act=_V(0,0,0);						// actual computed velocity from gravity
	DotM_last=_V(0,0,0);					// last sensed velocity from platform
	ddotG_last=_V(0,0,0);					// last computed acceleration from gravity
	DotG_last=_V(0,0,0);					// last computed velocity from gravity
	alpha_D=0;								// Angle from perigee to DN vector
	alpha_D_op=true;						// Option to determine alpha_D or load it
	G_T= -9.255;							// Magnitude of desired terminal gravitational acceleration
	xi_T=0; eta_T=0; zeta_T=0;				// Desired position components in the terminal reference system
	PosXEZ=_V(0,0,0);						// Position components in the terminal reference system
	DotXEZ=_V(0,0,0);						// Instantaneous something
	deta=0; dxi=0;							// Position components to be gained in this axis
	dT_3=0;									// Correction to third or fifth stage burn time
	dT_4=0;									// Difference between nominal and actual 1st S4B burn time
	dTt_4=0;								// Limited value of above
	T_T=0;									// Time-To-Go computed using T_3
	X_1 = 0;
	X_2 = 0;
	
	tchi_y=0; tchi_p=0;						// Angles to null velocity deficiencies without regard to terminal data
	dot_zeta_T=0; dot_xi_T=0; dot_eta_T=0;	// I don't know.
	ddot_zeta_GT=0; ddot_xi_GT=0;
	DDotXEZ_G=_V(0,0,0);					// ???							
	dot_dxit=0; dot_detat=0; dot_dzetat=0; 	// Intermediate velocity deficiency used in time-to-go computation
	dot_dxi=0; dot_deta=0; dot_dzeta=0; 	// More Deltas
	Xtt_y=0; Xtt_p=0; 						// IGM computed steering angles in terminal system
	X_S1=0; X_S2=0; X_S3=0; 				// Direction cosines of the thrust vector
	sin_gam=0; cos_gam=0;					// Sine and cosine of upsilon (flight-path angle)
	dot_phi_1=0; dot_phi_T=0; 				// ???
	dtt_1=0; dtt_2=0;						// Used in TGO determination
	dt = 1.7;								// Nominal powered-flight or coast-guidance computation-cycle interval
	a_1=0; a_2=0;							// Acceleration terms used to determine TGO
	T_GO=0;									// Time before S4B shutdown
	T_CO=0;									// Predicted time of S4B shutdown, from GRR
	dV=0;
	t_21 = 0;
	TAS=0;
	t_clock = 0;


	// Set up remainder
	LVDC_Timebase = -1;						// Start up halted in pre-launch pre-GRR loop
	LVDC_TB_ETime = 0;
	LVDC_Stop = 0;
	IGMCycle = 0;
	sinceLastCycle = 0;
	sinceLastGuidanceCycle = 0;
	OrbNavCycle = 0;
	// INTERNAL (NON-REAL-LVDC) FLAGS
	LVDC_EI_On = false;
	S1_Sep_Time = 0;
	CountPIPA = false;
	if(!Initialized){ lvlog = fopen("lvlog.txt","w+"); }
	fprintf(lvlog,"init complete\r\n");
	fflush(lvlog);
	Initialized = true;
}

void LVDC::SaveState(FILEHANDLE scn) {
	oapiWriteLine(scn, LVDC_START_STRING);
	// Here we go
	oapiWriteScenario_int(scn, "LVDC_alpha_D_op", alpha_D_op);
	oapiWriteScenario_int(scn, "LVDC_BOOST", BOOST);
	oapiWriteScenario_int(scn, "LVDC_CountPIPA", CountPIPA);
	oapiWriteScenario_int(scn, "LVDC_Direct_Ascent", Direct_Ascent);
	oapiWriteScenario_int(scn, "LVDC_directstageint", directstageint);
	oapiWriteScenario_int(scn, "LVDC_directstagereset", directstagereset);
	oapiWriteScenario_int(scn, "LVDC_first_op", first_op);
	oapiWriteScenario_int(scn, "LVDC_GATE", GATE);
	oapiWriteScenario_int(scn, "LVDC_GATE0", GATE0);
	oapiWriteScenario_int(scn, "LVDC_GATE1", GATE1);
	oapiWriteScenario_int(scn, "LVDC_GATE2", GATE2);
	oapiWriteScenario_int(scn, "LVDC_GATE3", GATE3);
	oapiWriteScenario_int(scn, "LVDC_GATE4", GATE4);
	oapiWriteScenario_int(scn, "LVDC_GATE5", GATE5);
	oapiWriteScenario_int(scn, "LVDC_GATE6", GATE6);
	oapiWriteScenario_int(scn, "LVDC_HSL", HSL);
	oapiWriteScenario_int(scn, "LVDC_INH", INH);
	oapiWriteScenario_int(scn, "LVDC_INH1", INH1);
	oapiWriteScenario_int(scn, "LVDC_INH2", INH2);
	oapiWriteScenario_int(scn, "LVDC_init", init);
	oapiWriteScenario_int(scn, "LVDC_i_op", i_op);
	oapiWriteScenario_int(scn, "LVDC_liftoff", liftoff);
	oapiWriteScenario_int(scn, "LVDC_LVDC_EI_On", LVDC_EI_On);
	oapiWriteScenario_int(scn, "LVDC_LVDC_GRR", LVDC_GRR);
	oapiWriteScenario_int(scn, "LVDC_MRS", MRS);
	oapiWriteScenario_int(scn, "LVDC_OrbNavCycle", OrbNavCycle);
	oapiWriteScenario_int(scn, "LVDC_poweredflight", poweredflight);
	oapiWriteScenario_int(scn, "LVDC_ROT", ROT);
	oapiWriteScenario_int(scn, "LVDC_ROTR", ROTR);
	oapiWriteScenario_int(scn, "LVDC_S1_Engine_Out", S1_Engine_Out);
	oapiWriteScenario_int(scn, "LVDC_S2_BURNOUT", S2_BURNOUT);
	oapiWriteScenario_int(scn, "LVDC_S2_ENGINE_OUT", S2_ENGINE_OUT);
	oapiWriteScenario_int(scn, "LVDC_S2_IGNITION", S2_IGNITION);
	oapiWriteScenario_int(scn, "LVDC_S2_Startup", S2_Startup);
	oapiWriteScenario_int(scn, "LVDC_S4B_IGN", S4B_IGN);
	oapiWriteScenario_int(scn, "LVDC_S4B_REIGN", S4B_REIGN);
	oapiWriteScenario_int(scn, "LVDC_TerminalConditions", TerminalConditions);
	oapiWriteScenario_int(scn, "LVDC_theta_N_op", theta_N_op);
	oapiWriteScenario_int(scn, "LVDC_TU", TU);
	oapiWriteScenario_int(scn, "LVDC_TU10", TU10);
	oapiWriteScenario_int(scn, "LVDC_IGMCycle", IGMCycle);
	oapiWriteScenario_int(scn, "LVDC_LVDC_Stop", LVDC_Stop);
	oapiWriteScenario_int(scn, "LVDC_LVDC_Timebase", LVDC_Timebase);
	oapiWriteScenario_int(scn, "LVDC_tgt_index", tgt_index);
	oapiWriteScenario_int(scn, "LVDC_T_EO1", T_EO1);
	oapiWriteScenario_int(scn, "LVDC_T_EO2", T_EO2);
	oapiWriteScenario_int(scn, "LVDC_UP", UP);
	papiWriteScenario_double(scn, "LVDC_a", a);
	papiWriteScenario_double(scn, "LVDC_a_0p", a_0p);
	papiWriteScenario_double(scn, "LVDC_a_0r", a_0r);
	papiWriteScenario_double(scn, "LVDC_a_0y", a_0y);
	papiWriteScenario_double(scn, "LVDC_a_1", a_1);
	papiWriteScenario_double(scn, "LVDC_a_2", a_2);
	papiWriteScenario_double(scn, "LVDC_a_1p", a_1p);
	papiWriteScenario_double(scn, "LVDC_a_1r", a_1r);
	papiWriteScenario_double(scn, "LVDC_a_1y", a_1y);
	papiWriteScenario_double(scn, "LVDC_alpha_1", alpha_1);
	papiWriteScenario_double(scn, "LVDC_alpha_2", alpha_2);
	papiWriteScenario_double(scn, "LVDC_alpha_D", alpha_D);
	papiWriteScenario_double(scn, "LVDC_alpha_TS", alpha_TS);
	papiWriteScenario_double(scn, "LVDC_ALFTSA", TABLE15[0].alphaS_TS);
	papiWriteScenario_double(scn, "LVDC_ALFTSB", TABLE15[1].alphaS_TS);
	papiWriteScenario_double(scn, "LVDC_Azimuth", Azimuth);
	papiWriteScenario_double(scn, "LVDC_Azo", Azo);
	papiWriteScenario_double(scn, "LVDC_Azs", Azs);
	papiWriteScenario_double(scn, "LVDC_B_11", B_11);
	papiWriteScenario_double(scn, "LVDC_B_21", B_21);
	papiWriteScenario_double(scn, "LVDC_B_12", B_12);
	papiWriteScenario_double(scn, "LVDC_B_22", B_22);
	papiWriteScenario_double(scn, "LVDC_beta", beta);
	papiWriteScenario_double(scn, "LVDC_BETAA", TABLE15[0].beta);
	papiWriteScenario_double(scn, "LVDC_BETAB", TABLE15[1].beta);
	papiWriteScenario_double(scn, "LVDC_beta_p1c", beta_p1c);
	papiWriteScenario_double(scn, "LVDC_beta_p2c", beta_p2c);
	papiWriteScenario_double(scn, "LVDC_beta_p3c", beta_p3c);
	papiWriteScenario_double(scn, "LVDC_beta_p4c", beta_p4c);
	papiWriteScenario_double(scn, "LVDC_beta_pc", beta_pc);
	papiWriteScenario_double(scn, "LVDC_beta_rc", beta_rc);
	papiWriteScenario_double(scn, "LVDC_beta_y1c", beta_y1c);
	papiWriteScenario_double(scn, "LVDC_beta_y2c", beta_y2c);
	papiWriteScenario_double(scn, "LVDC_beta_y3c", beta_y3c);
	papiWriteScenario_double(scn, "LVDC_beta_y4c", beta_y4c);
	papiWriteScenario_double(scn, "LVDC_beta_yc", beta_yc);
	papiWriteScenario_double(scn, "LVDC_C_2", C_2);
	papiWriteScenario_double(scn, "LVDC_C_3", C_3);
	papiWriteScenario_double(scn, "LVDC_C_4", C_4);
	papiWriteScenario_double(scn, "LVDC_C3A0", TABLE15[0].target[0].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A1", TABLE15[0].target[1].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A2", TABLE15[0].target[2].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A3", TABLE15[0].target[3].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A4", TABLE15[0].target[4].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A5", TABLE15[0].target[5].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A6", TABLE15[0].target[6].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A7", TABLE15[0].target[7].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A8", TABLE15[0].target[8].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A9", TABLE15[0].target[9].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A10", TABLE15[0].target[10].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A11", TABLE15[0].target[11].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A12", TABLE15[0].target[12].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A13", TABLE15[0].target[13].C_3);
	papiWriteScenario_double(scn, "LVDC_C3A14", TABLE15[0].target[14].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B0", TABLE15[1].target[0].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B1", TABLE15[1].target[1].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B2", TABLE15[1].target[2].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B3", TABLE15[1].target[3].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B4", TABLE15[1].target[4].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B5", TABLE15[1].target[5].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B6", TABLE15[1].target[6].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B7", TABLE15[1].target[7].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B8", TABLE15[1].target[8].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B9", TABLE15[1].target[9].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B10", TABLE15[1].target[10].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B11", TABLE15[1].target[11].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B12", TABLE15[1].target[12].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B13", TABLE15[1].target[13].C_3);
	papiWriteScenario_double(scn, "LVDC_C3B14", TABLE15[1].target[14].C_3);
	papiWriteScenario_double(scn, "LVDC_CCSA0", TABLE15[0].target[0].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA1", TABLE15[0].target[1].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA2", TABLE15[0].target[2].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA3", TABLE15[0].target[3].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA4", TABLE15[0].target[4].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA5", TABLE15[0].target[5].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA6", TABLE15[0].target[6].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA7", TABLE15[0].target[7].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA8", TABLE15[0].target[8].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA9", TABLE15[0].target[9].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA10", TABLE15[0].target[10].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA11", TABLE15[0].target[11].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA12", TABLE15[0].target[12].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA13", TABLE15[0].target[13].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSA14", TABLE15[0].target[14].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB0", TABLE15[1].target[0].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB1", TABLE15[1].target[1].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB2", TABLE15[1].target[2].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB3", TABLE15[1].target[3].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB4", TABLE15[1].target[4].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB5", TABLE15[1].target[5].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB6", TABLE15[1].target[6].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB7", TABLE15[1].target[7].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB8", TABLE15[1].target[8].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB9", TABLE15[1].target[9].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB10", TABLE15[1].target[10].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB11", TABLE15[1].target[11].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB12", TABLE15[1].target[12].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB13", TABLE15[1].target[13].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_CCSB14", TABLE15[1].target[14].cos_sigma);
	papiWriteScenario_double(scn, "LVDC_Cf", Cf);
	papiWriteScenario_double(scn, "LVDC_CG", CG);
	papiWriteScenario_double(scn, "LVDC_cos_chi_Yit", cos_chi_Yit);
	papiWriteScenario_double(scn, "LVDC_cos_chi_Zit", cos_chi_Zit);
	papiWriteScenario_double(scn, "LVDC_cos_sigma", cos_sigma);
	papiWriteScenario_double(scn, "LVDC_Ct", Ct);
	papiWriteScenario_double(scn, "LVDC_Ct_o", Ct_o);
	papiWriteScenario_double(scn, "LVDC_D", D);
	papiWriteScenario_double(scn, "LVDC_d2", d2);
	papiWriteScenario_double(scn, "LVDC_ddot_zeta_GT", ddot_zeta_GT);
	papiWriteScenario_double(scn, "LVDC_ddot_xi_GT", ddot_xi_GT);
	papiWriteScenario_double(scn, "LVDC_DEC", DEC);
	papiWriteScenario_double(scn, "LVDC_DECA0", TABLE15[0].target[0].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA1", TABLE15[0].target[1].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA2", TABLE15[0].target[2].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA3", TABLE15[0].target[3].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA4", TABLE15[0].target[4].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA5", TABLE15[0].target[5].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA6", TABLE15[0].target[6].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA7", TABLE15[0].target[7].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA8", TABLE15[0].target[8].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA9", TABLE15[0].target[9].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA10", TABLE15[0].target[10].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA11", TABLE15[0].target[11].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA12", TABLE15[0].target[12].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA13", TABLE15[0].target[13].DEC);
	papiWriteScenario_double(scn, "LVDC_DECA14", TABLE15[0].target[14].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB0", TABLE15[1].target[0].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB1", TABLE15[1].target[1].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB2", TABLE15[1].target[2].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB3", TABLE15[1].target[3].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB4", TABLE15[1].target[4].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB5", TABLE15[1].target[5].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB6", TABLE15[1].target[6].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB7", TABLE15[1].target[7].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB8", TABLE15[1].target[8].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB9", TABLE15[1].target[9].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB10", TABLE15[1].target[10].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB11", TABLE15[1].target[11].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB12", TABLE15[1].target[12].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB13", TABLE15[1].target[13].DEC);
	papiWriteScenario_double(scn, "LVDC_DECB14", TABLE15[1].target[14].DEC);
	papiWriteScenario_double(scn, "LVDC_deta", deta);
	papiWriteScenario_double(scn, "LVDC_dxi", dxi);
	papiWriteScenario_double(scn, "LVDC_dot_dxi", dot_dxi);
	papiWriteScenario_double(scn, "LVDC_dot_deta", dot_deta);
	papiWriteScenario_double(scn, "LVDC_dot_dzeta", dot_dzeta);
	papiWriteScenario_double(scn, "LVDC_dot_dxit", dot_dxit);
	papiWriteScenario_double(scn, "LVDC_dot_detat", dot_detat);
	papiWriteScenario_double(scn, "LVDC_dot_dzetat", dot_dzetat);
	papiWriteScenario_double(scn, "LVDC_dotM_1", dotM_1);
	papiWriteScenario_double(scn, "LVDC_dotM_2", dotM_2);
	papiWriteScenario_double(scn, "LVDC_dotM_2R", dotM_2R);
	papiWriteScenario_double(scn, "LVDC_dotM_3", dotM_3);
	papiWriteScenario_double(scn, "LVDC_dotM_3R", dotM_3R);
	papiWriteScenario_double(scn, "LVDC_dot_phi_1", dot_phi_1);
	papiWriteScenario_double(scn, "LVDC_dot_phi_T", dot_phi_T);
	papiWriteScenario_double(scn, "LVDC_dot_zeta_T", dot_zeta_T);
	papiWriteScenario_double(scn, "LVDC_dot_xi_T", dot_xi_T);
	papiWriteScenario_double(scn, "LVDC_dot_eta_T", dot_eta_T);
	papiWriteScenario_double(scn, "LVDC_Drag_Area[0]", Drag_Area[0]);
	papiWriteScenario_double(scn, "LVDC_Drag_Area[1]", Drag_Area[1]);
	papiWriteScenario_double(scn, "LVDC_Drag_Area[2]", Drag_Area[2]);
	papiWriteScenario_double(scn, "LVDC_Drag_Area[3]", Drag_Area[3]);
	papiWriteScenario_double(scn, "LVDC_Drag_Area[4]", Drag_Area[4]);
	papiWriteScenario_double(scn, "LVDC_dt", dt);
	papiWriteScenario_double(scn, "LVDC_dT_3", dT_3);
	papiWriteScenario_double(scn, "LVDC_dT_4", dT_4);
	papiWriteScenario_double(scn, "LVDC_dt_c", dt_c);
	papiWriteScenario_double(scn, "LVDC_dT_cost", dT_cost);
	papiWriteScenario_double(scn, "LVDC_dT_F", dT_F);
	papiWriteScenario_double(scn, "LVDC_dt_g", dt_g);
	papiWriteScenario_double(scn, "LVDC_dt_LET", dt_LET);
	papiWriteScenario_double(scn, "LVDC_dT_LIM", dT_LIM);
	papiWriteScenario_double(scn, "LVDC_dtt_1", dtt_1);
	papiWriteScenario_double(scn, "LVDC_dtt_2", dtt_2);
	papiWriteScenario_double(scn, "LVDC_dTt_4", dTt_4);
	papiWriteScenario_double(scn, "LVDC_dV", dV);
	papiWriteScenario_double(scn, "LVDC_dV_B", dV_B);
	papiWriteScenario_double(scn, "LVDC_dV_BR", dV_BR);
	papiWriteScenario_double(scn, "LVDC_e", e);
	papiWriteScenario_double(scn, "LVDC_e_N", e_N);
	papiWriteScenario_double(scn, "LVDC_ENA0", TABLE15[0].target[0].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA1", TABLE15[0].target[1].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA2", TABLE15[0].target[2].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA3", TABLE15[0].target[3].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA4", TABLE15[0].target[4].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA5", TABLE15[0].target[5].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA6", TABLE15[0].target[6].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA7", TABLE15[0].target[7].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA8", TABLE15[0].target[8].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA9", TABLE15[0].target[9].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA10", TABLE15[0].target[10].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA11", TABLE15[0].target[11].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA12", TABLE15[0].target[12].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA13", TABLE15[0].target[13].e_N);
	papiWriteScenario_double(scn, "LVDC_ENA14", TABLE15[0].target[14].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB0", TABLE15[1].target[0].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB1", TABLE15[1].target[1].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB2", TABLE15[1].target[2].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB3", TABLE15[1].target[3].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB4", TABLE15[1].target[4].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB5", TABLE15[1].target[5].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB6", TABLE15[1].target[6].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB7", TABLE15[1].target[7].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB8", TABLE15[1].target[8].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB9", TABLE15[1].target[9].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB10", TABLE15[1].target[10].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB11", TABLE15[1].target[11].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB12", TABLE15[1].target[12].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB13", TABLE15[1].target[13].e_N);
	papiWriteScenario_double(scn, "LVDC_ENB14", TABLE15[1].target[14].e_N);
	papiWriteScenario_double(scn, "LVDC_eps_1", eps_1);
	papiWriteScenario_double(scn, "LVDC_eps_1R", eps_1R);
	papiWriteScenario_double(scn, "LVDC_eps_2", eps_2);
	papiWriteScenario_double(scn, "LVDC_eps_2R", eps_2R);
	papiWriteScenario_double(scn, "LVDC_eps_3", eps_3);
	papiWriteScenario_double(scn, "LVDC_eps_3R", eps_3R);
	papiWriteScenario_double(scn, "LVDC_eps_4", eps_4);
	papiWriteScenario_double(scn, "LVDC_eps_4R", eps_4R);
	papiWriteScenario_double(scn, "LVDC_eps_p", eps_p);
	papiWriteScenario_double(scn, "LVDC_eps_ymr", eps_ymr);
	papiWriteScenario_double(scn, "LVDC_eps_ypr", eps_ypr);
	papiWriteScenario_double(scn, "LVDC_f", f);
	papiWriteScenario_double(scn, "LVDC_F", F);
	papiWriteScenario_double(scn, "LVDC_FA", TABLE15[0].f);
	papiWriteScenario_double(scn, "LVDC_FB", TABLE15[1].f);
	papiWriteScenario_double(scn, "LVDC_Fm", Fm);
	papiWriteScenario_double(scn, "LVDC_Fx[0][0]", Fx[0][0]);
	papiWriteScenario_double(scn, "LVDC_Fx[0][1]", Fx[0][1]);
	papiWriteScenario_double(scn, "LVDC_Fx[0][2]", Fx[0][2]);
	papiWriteScenario_double(scn, "LVDC_Fx[0][3]", Fx[0][3]);
	papiWriteScenario_double(scn, "LVDC_Fx[0][4]", Fx[0][4]);
	papiWriteScenario_double(scn, "LVDC_Fx[1][0]", Fx[1][0]);
	papiWriteScenario_double(scn, "LVDC_Fx[1][1]", Fx[1][1]);
	papiWriteScenario_double(scn, "LVDC_Fx[1][2]", Fx[1][2]);
	papiWriteScenario_double(scn, "LVDC_Fx[1][3]", Fx[1][3]);
	papiWriteScenario_double(scn, "LVDC_Fx[1][4]", Fx[1][4]);
	papiWriteScenario_double(scn, "LVDC_Fx[2][0]", Fx[2][0]);
	papiWriteScenario_double(scn, "LVDC_Fx[2][1]", Fx[2][1]);
	papiWriteScenario_double(scn, "LVDC_Fx[2][2]", Fx[2][2]);
	papiWriteScenario_double(scn, "LVDC_Fx[2][3]", Fx[2][3]);
	papiWriteScenario_double(scn, "LVDC_Fx[2][4]", Fx[2][4]);
	papiWriteScenario_double(scn, "LVDC_Fx[3][0]", Fx[3][0]);
	papiWriteScenario_double(scn, "LVDC_Fx[3][1]", Fx[3][1]);
	papiWriteScenario_double(scn, "LVDC_Fx[3][2]", Fx[3][2]);
	papiWriteScenario_double(scn, "LVDC_Fx[3][3]", Fx[3][3]);
	papiWriteScenario_double(scn, "LVDC_Fx[3][4]", Fx[3][4]);
	papiWriteScenario_double(scn, "LVDC_Fx[4][0]", Fx[4][0]);
	papiWriteScenario_double(scn, "LVDC_Fx[4][1]", Fx[4][1]);
	papiWriteScenario_double(scn, "LVDC_Fx[4][2]", Fx[4][2]);
	papiWriteScenario_double(scn, "LVDC_Fx[4][3]", Fx[4][3]);
	papiWriteScenario_double(scn, "LVDC_Fx[4][4]", Fx[4][4]);
	papiWriteScenario_double(scn, "LVDC_fx[0]", fx[0]);
	papiWriteScenario_double(scn, "LVDC_fx[1]", fx[1]);
	papiWriteScenario_double(scn, "LVDC_fx[2]", fx[2]);
	papiWriteScenario_double(scn, "LVDC_fx[3]", fx[3]);
	papiWriteScenario_double(scn, "LVDC_fx[4]", fx[4]);
	papiWriteScenario_double(scn, "LVDC_fx[5]", fx[5]);
	papiWriteScenario_double(scn, "LVDC_fx[6]", fx[6]);
	papiWriteScenario_double(scn, "LVDC_fxt[0]", fxt[0]);
	papiWriteScenario_double(scn, "LVDC_fxt[1]", fxt[1]);
	papiWriteScenario_double(scn, "LVDC_fxt[2]", fxt[2]);
	papiWriteScenario_double(scn, "LVDC_fxt[3]", fxt[3]);
	papiWriteScenario_double(scn, "LVDC_fxt[4]", fxt[4]);
	papiWriteScenario_double(scn, "LVDC_fxt[5]", fxt[5]);
	papiWriteScenario_double(scn, "LVDC_fxt[6]", fxt[6]);
	papiWriteScenario_double(scn, "LVDC_GPitch[0]", GPitch[0]);
	papiWriteScenario_double(scn, "LVDC_GPitch[1]", GPitch[1]);
	papiWriteScenario_double(scn, "LVDC_GPitch[2]", GPitch[2]);
	papiWriteScenario_double(scn, "LVDC_GPitch[3]", GPitch[3]);
	papiWriteScenario_double(scn, "LVDC_GYaw[0]", GYaw[0]);
	papiWriteScenario_double(scn, "LVDC_GYaw[1]", GYaw[1]);
	papiWriteScenario_double(scn, "LVDC_GYaw[2]", GYaw[2]);
	papiWriteScenario_double(scn, "LVDC_GYaw[3]", GYaw[3]);
	papiWriteScenario_double(scn, "LVDC_G_T", G_T);
	papiWriteScenario_double(scn, "LVDC_gx[0]", gx[0]);
	papiWriteScenario_double(scn, "LVDC_gx[1]", gx[1]);
	papiWriteScenario_double(scn, "LVDC_gx[2]", gx[2]);
	papiWriteScenario_double(scn, "LVDC_gx[3]", gx[3]);
	papiWriteScenario_double(scn, "LVDC_gx[4]", gx[4]);
	papiWriteScenario_double(scn, "LVDC_gx[5]", gx[5]);
	papiWriteScenario_double(scn, "LVDC_gx[6]", gx[6]);
	papiWriteScenario_double(scn, "LVDC_gxt[0]", gxt[0]);
	papiWriteScenario_double(scn, "LVDC_gxt[1]", gxt[1]);
	papiWriteScenario_double(scn, "LVDC_gxt[2]", gxt[2]);
	papiWriteScenario_double(scn, "LVDC_gxt[3]", gxt[3]);
	papiWriteScenario_double(scn, "LVDC_gxt[4]", gxt[4]);
	papiWriteScenario_double(scn, "LVDC_gxt[5]", gxt[5]);
	papiWriteScenario_double(scn, "LVDC_gxt[6]", gxt[6]);
	papiWriteScenario_double(scn, "LVDC_H", H);
	papiWriteScenario_double(scn, "LVDC_hx[0][0]", hx[0][0]);
	papiWriteScenario_double(scn, "LVDC_hx[0][1]", hx[0][1]);
	papiWriteScenario_double(scn, "LVDC_hx[0][2]", hx[0][2]);
	papiWriteScenario_double(scn, "LVDC_hx[0][3]", hx[0][3]);
	papiWriteScenario_double(scn, "LVDC_hx[0][4]", hx[0][4]);
	papiWriteScenario_double(scn, "LVDC_hx[1][0]", hx[1][0]);
	papiWriteScenario_double(scn, "LVDC_hx[1][1]", hx[1][1]);
	papiWriteScenario_double(scn, "LVDC_hx[1][2]", hx[1][2]);
	papiWriteScenario_double(scn, "LVDC_hx[1][3]", hx[1][3]);
	papiWriteScenario_double(scn, "LVDC_hx[1][4]", hx[1][4]);
	papiWriteScenario_double(scn, "LVDC_hx[2][0]", hx[2][0]);
	papiWriteScenario_double(scn, "LVDC_hx[2][1]", hx[2][1]);
	papiWriteScenario_double(scn, "LVDC_hx[2][2]", hx[2][2]);
	papiWriteScenario_double(scn, "LVDC_hx[2][3]", hx[2][3]);
	papiWriteScenario_double(scn, "LVDC_hx[2][4]", hx[2][4]);
	papiWriteScenario_double(scn, "LVDC_IGMInterval", IGMInterval);
	papiWriteScenario_double(scn, "LVDC_Inclination", Inclination);
	papiWriteScenario_double(scn, "LVDC_J", J);
	papiWriteScenario_double(scn, "LVDC_J_1", J_1);
	papiWriteScenario_double(scn, "LVDC_J_2", J_2);
	papiWriteScenario_double(scn, "LVDC_J_3", J_3);
	papiWriteScenario_double(scn, "LVDC_J_12", J_12);
	papiWriteScenario_double(scn, "LVDC_Jt_3", Jt_3);
	papiWriteScenario_double(scn, "LVDC_J_Y", J_Y);
	papiWriteScenario_double(scn, "LVDC_J_P", J_P);
	papiWriteScenario_double(scn, "LVDC_K_1", K_1);
	papiWriteScenario_double(scn, "LVDC_K_2", K_2);
	papiWriteScenario_double(scn, "LVDC_K_3", K_3);
	papiWriteScenario_double(scn, "LVDC_K_4", K_4);
	papiWriteScenario_double(scn, "LVDC_K_5", K_5);
	papiWriteScenario_double(scn, "LVDC_K_P1", K_P1);
	papiWriteScenario_double(scn, "LVDC_K_P2", K_P2);
	papiWriteScenario_double(scn, "LVDC_K_Y1", K_Y1);
	papiWriteScenario_double(scn, "LVDC_K_Y2", K_Y2);
	papiWriteScenario_double(scn, "LVDC_K_Y", K_Y);
	papiWriteScenario_double(scn, "LVDC_K_P", K_P);
	papiWriteScenario_double(scn, "LVDC_D_P", D_P);
	papiWriteScenario_double(scn, "LVDC_D_Y", D_Y);
	papiWriteScenario_double(scn, "LVDC_L_1", L_1);
	papiWriteScenario_double(scn, "LVDC_L_2", L_2);
	papiWriteScenario_double(scn, "LVDC_L_3", L_3);
	papiWriteScenario_double(scn, "LVDC_dL_3", dL_3);
	papiWriteScenario_double(scn, "LVDC_Lt_3", Lt_3);
	papiWriteScenario_double(scn, "LVDC_L_12", L_12);
	papiWriteScenario_double(scn, "LVDC_L_P", L_P);
	papiWriteScenario_double(scn, "LVDC_L_Y", L_Y);
	papiWriteScenario_double(scn, "LVDC_Lt_Y", Lt_Y);
	papiWriteScenario_double(scn, "LVDC_LVDC_TB_ETime", LVDC_TB_ETime);
	papiWriteScenario_double(scn, "LVDC_mu", mu);
	papiWriteScenario_double(scn, "LVDC_omega_E", omega_E);
	papiWriteScenario_double(scn, "LVDC_OPitch[0]", OPitch[0]);
	papiWriteScenario_double(scn, "LVDC_OPitch[1]", OPitch[1]);
	papiWriteScenario_double(scn, "LVDC_OPitch[2]", OPitch[2]);
	papiWriteScenario_double(scn, "LVDC_OPitch[3]", OPitch[3]);
	papiWriteScenario_double(scn, "LVDC_OYaw[0]", OYaw[0]);
	papiWriteScenario_double(scn, "LVDC_OYaw[1]", OYaw[1]);
	papiWriteScenario_double(scn, "LVDC_OYaw[2]", OYaw[2]);
	papiWriteScenario_double(scn, "LVDC_OYaw[3]", OYaw[3]);
	papiWriteScenario_double(scn, "LVDC_p", p);
	papiWriteScenario_double(scn, "LVDC_P_1", P_1);
	papiWriteScenario_double(scn, "LVDC_P_2", P_2);
	papiWriteScenario_double(scn, "LVDC_P_3", P_3);
	papiWriteScenario_double(scn, "LVDC_P_12", P_12);
	papiWriteScenario_double(scn, "LVDC_phi_L", phi_L);
	papiWriteScenario_double(scn, "LVDC_phi_T", phi_T);
	papiWriteScenario_double(scn, "LVDC_Q_1", Q_1);
	papiWriteScenario_double(scn, "LVDC_Q_2", Q_2);
	papiWriteScenario_double(scn, "LVDC_Q_3", Q_3);
	papiWriteScenario_double(scn, "LVDC_Q_12", Q_12);
	papiWriteScenario_double(scn, "LVDC_Q_Y", Q_Y);
	papiWriteScenario_double(scn, "LVDC_Q_P", Q_P);
	papiWriteScenario_double(scn, "LVDC_R", R);
	papiWriteScenario_double(scn, "LVDC_RAS", RAS);
	papiWriteScenario_double(scn, "LVDC_RASA0", TABLE15[0].target[0].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA1", TABLE15[0].target[1].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA2", TABLE15[0].target[2].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA3", TABLE15[0].target[3].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA4", TABLE15[0].target[4].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA5", TABLE15[0].target[5].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA6", TABLE15[0].target[6].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA7", TABLE15[0].target[7].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA8", TABLE15[0].target[8].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA9", TABLE15[0].target[9].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA10", TABLE15[0].target[10].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA11", TABLE15[0].target[11].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA12", TABLE15[0].target[12].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA13", TABLE15[0].target[13].RAS);
	papiWriteScenario_double(scn, "LVDC_RASA14", TABLE15[0].target[14].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB0", TABLE15[1].target[0].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB1", TABLE15[1].target[1].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB2", TABLE15[1].target[2].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB3", TABLE15[1].target[3].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB4", TABLE15[1].target[4].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB5", TABLE15[1].target[5].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB6", TABLE15[1].target[6].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB7", TABLE15[1].target[7].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB8", TABLE15[1].target[8].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB9", TABLE15[1].target[9].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB10", TABLE15[1].target[10].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB11", TABLE15[1].target[11].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB12", TABLE15[1].target[12].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB13", TABLE15[1].target[13].RAS);
	papiWriteScenario_double(scn, "LVDC_RASB14", TABLE15[1].target[14].RAS);
	papiWriteScenario_double(scn, "LVDC_RateGain", RateGain);
	papiWriteScenario_double(scn, "LVDC_ErrorGain", ErrorGain);
	papiWriteScenario_double(scn, "LVDC_rho", rho);
	papiWriteScenario_double(scn, "LVDC_Rho[0]", Rho[0]);
	papiWriteScenario_double(scn, "LVDC_Rho[1]", Rho[1]);
	papiWriteScenario_double(scn, "LVDC_Rho[2]", Rho[2]);
	papiWriteScenario_double(scn, "LVDC_Rho[3]", Rho[3]);
	papiWriteScenario_double(scn, "LVDC_Rho[4]", Rho[4]);
	papiWriteScenario_double(scn, "LVDC_Rho[5]", Rho[5]);
	papiWriteScenario_double(scn, "LVDC_R_N", R_N);
	papiWriteScenario_double(scn, "LVDC_RNA", TABLE15[0].R_N);
	papiWriteScenario_double(scn, "LVDC_RNB", TABLE15[1].R_N);
	papiWriteScenario_double(scn, "LVDC_ROV", ROV);
	papiWriteScenario_double(scn, "LVDC_ROVR", ROVR);
	papiWriteScenario_double(scn, "LVDC_ROVs", ROVs);
	papiWriteScenario_double(scn, "LVDC_R_T", R_T);
	papiWriteScenario_double(scn, "LVDC_S_1", S_1);
	papiWriteScenario_double(scn, "LVDC_S_2", S_2);
	papiWriteScenario_double(scn, "LVDC_S_3", S_3);
	papiWriteScenario_double(scn, "LVDC_S_12", S_12);
	papiWriteScenario_double(scn, "LVDC_S_P", S_P);
	papiWriteScenario_double(scn, "LVDC_S_Y", S_Y);
	papiWriteScenario_double(scn, "LVDC_S1_Sep_Time", S1_Sep_Time);
	papiWriteScenario_double(scn, "LVDC_sinceLastCycle", sinceLastCycle);
	papiWriteScenario_double(scn, "LVDC_sinceLastGuidanceCycle", sinceLastGuidanceCycle);
	papiWriteScenario_double(scn, "LVDC_sin_chi_Yit", sin_chi_Yit);
	papiWriteScenario_double(scn, "LVDC_sin_chi_Zit", sin_chi_Zit);
	papiWriteScenario_double(scn, "LVDC_sin_gam", sin_gam);
	papiWriteScenario_double(scn, "LVDC_cos_gam", cos_gam);
	papiWriteScenario_double(scn, "LVDC_SMCG", SMCG);
	papiWriteScenario_double(scn, "LVDC_S", S);
	papiWriteScenario_double(scn, "LVDC_P", P);
	papiWriteScenario_double(scn, "LVDC_S_34", S_34);
	papiWriteScenario_double(scn, "LVDC_P_34", P_34);
	papiWriteScenario_double(scn, "LVDC_t", t);
	papiWriteScenario_double(scn, "LVDC_T_0", T_0);
	papiWriteScenario_double(scn, "LVDC_t_1", t_1);
	papiWriteScenario_double(scn, "LVDC_T_1", T_1);
	papiWriteScenario_double(scn, "LVDC_T_1c", T_1c);
	papiWriteScenario_double(scn, "LVDC_t_2", t_2);
	papiWriteScenario_double(scn, "LVDC_T_2", T_2);
	papiWriteScenario_double(scn, "LVDC_t_21", t_21);
	papiWriteScenario_double(scn, "LVDC_T_2R", T_2R);
	papiWriteScenario_double(scn, "LVDC_t_3", t_3);
	papiWriteScenario_double(scn, "LVDC_T_3", T_3);
	papiWriteScenario_double(scn, "LVDC_t_3i", t_3i);
	papiWriteScenario_double(scn, "LVDC_t_4", t_4);
	papiWriteScenario_double(scn, "LVDC_T_4N", T_4N);
	papiWriteScenario_double(scn, "LVDC_t_5", t_5);
	papiWriteScenario_double(scn, "LVDC_t_6", t_6);
	papiWriteScenario_double(scn, "LVDC_TA1", TA1);
	papiWriteScenario_double(scn, "LVDC_TA2", TA2);
	papiWriteScenario_double(scn, "LVDC_T_ar", T_ar);
	papiWriteScenario_double(scn, "LVDC_TAS", TAS);
	papiWriteScenario_double(scn, "LVDC_tau1", tau1);
	papiWriteScenario_double(scn, "LVDC_tau2", tau2);
	papiWriteScenario_double(scn, "LVDC_tau2N", tau2N);
	papiWriteScenario_double(scn, "LVDC_tau3", tau3);
	papiWriteScenario_double(scn, "LVDC_tau3N", tau3N);
	papiWriteScenario_double(scn, "LVDC_tau3R", tau3R);
	papiWriteScenario_double(scn, "LVDC_t_B1", t_B1);
	papiWriteScenario_double(scn, "LVDC_TB1", TB1);
	papiWriteScenario_double(scn, "LVDC_t_B2", t_B2);
	papiWriteScenario_double(scn, "LVDC_TB2", TB2);
	papiWriteScenario_double(scn, "LVDC_t_B3", t_B3);
	papiWriteScenario_double(scn, "LVDC_TB3", TB3);
	papiWriteScenario_double(scn, "LVDC_t_B4", t_B4);
	papiWriteScenario_double(scn, "LVDC_TB4", TB4);
	papiWriteScenario_double(scn, "LVDC_TB4A", TB4A);
	papiWriteScenario_double(scn, "LVDC_TB5", TB5);
	papiWriteScenario_double(scn, "LVDC_TB6", TB6);
	papiWriteScenario_double(scn, "LVDC_TB7", TB7);
	papiWriteScenario_double(scn, "LVDC_T_c", T_c);
	papiWriteScenario_double(scn, "LVDC_tchi_y_last", tchi_y_last);
	papiWriteScenario_double(scn, "LVDC_tchi_p_last", tchi_p_last);
	papiWriteScenario_double(scn, "LVDC_tchi_y", tchi_y);
	papiWriteScenario_double(scn, "LVDC_tchi_p", tchi_p);
	papiWriteScenario_double(scn, "LVDC_t_clock", t_clock);
	papiWriteScenario_double(scn, "LVDC_T_CO", T_CO);
	papiWriteScenario_double(scn, "LVDC_t_D", t_D);
	papiWriteScenario_double(scn, "LVDC_t_D0", t_D0);
	papiWriteScenario_double(scn, "LVDC_t_D1", t_D1);
	papiWriteScenario_double(scn, "LVDC_t_D2", t_D2);
	papiWriteScenario_double(scn, "LVDC_t_D3", t_D3);
	papiWriteScenario_double(scn, "LVDC_t_DS0", t_DS0);
	papiWriteScenario_double(scn, "LVDC_t_DS1", t_DS1);
	papiWriteScenario_double(scn, "LVDC_t_DS2", t_DS2);
	papiWriteScenario_double(scn, "LVDC_t_DS3", t_DS3);
	papiWriteScenario_double(scn, "LVDC_t_fail", t_fail);
	papiWriteScenario_double(scn, "LVDC_T_GO", T_GO);
	papiWriteScenario_double(scn, "LVDC_TETEO", theta_EO);
	papiWriteScenario_double(scn, "LVDC_theta_N", theta_N);
	papiWriteScenario_double(scn, "LVDC_TI5F2", TI5F2);
	papiWriteScenario_double(scn, "LVDC_T_IGM", T_IGM);
	papiWriteScenario_double(scn, "LVDC_T_L", T_L);
	papiWriteScenario_double(scn, "LVDC_T_LET", T_LET);
	papiWriteScenario_double(scn, "LVDC_T_LO", T_LO);
	papiWriteScenario_double(scn, "LVDC_TPA0", TABLE15[0].target[0].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA1", TABLE15[0].target[1].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA2", TABLE15[0].target[2].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA3", TABLE15[0].target[3].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA4", TABLE15[0].target[4].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA5", TABLE15[0].target[5].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA6", TABLE15[0].target[6].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA7", TABLE15[0].target[7].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA8", TABLE15[0].target[8].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA9", TABLE15[0].target[9].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA10", TABLE15[0].target[10].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA11", TABLE15[0].target[11].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA12", TABLE15[0].target[12].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA13", TABLE15[0].target[13].t_D);
	papiWriteScenario_double(scn, "LVDC_TPA14", TABLE15[0].target[14].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB0", TABLE15[1].target[0].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB1", TABLE15[1].target[1].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB2", TABLE15[1].target[2].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB3", TABLE15[1].target[3].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB4", TABLE15[1].target[4].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB5", TABLE15[1].target[5].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB6", TABLE15[1].target[6].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB7", TABLE15[1].target[7].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB8", TABLE15[1].target[8].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB9", TABLE15[1].target[9].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB10", TABLE15[1].target[10].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB11", TABLE15[1].target[11].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB12", TABLE15[1].target[12].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB13", TABLE15[1].target[13].t_D);
	papiWriteScenario_double(scn, "LVDC_TPB14", TABLE15[1].target[14].t_D);
	papiWriteScenario_double(scn, "LVDC_T_RG", T_RG);
	papiWriteScenario_double(scn, "LVDC_T_RP", T_RP);
	papiWriteScenario_double(scn, "LVDC_T_S1", T_S1);
	papiWriteScenario_double(scn, "LVDC_T_S2", T_S2);
	papiWriteScenario_double(scn, "LVDC_T_S3", T_S3);
	papiWriteScenario_double(scn, "LVDC_TS4BS", TS4BS);
	papiWriteScenario_double(scn, "LVDC_t_SD1", t_SD1);
	papiWriteScenario_double(scn, "LVDC_t_SD2", t_SD2);
	papiWriteScenario_double(scn, "LVDC_t_SD3", t_SD3);
	papiWriteScenario_double(scn, "LVDC_TSMC1", TSMC1);
	papiWriteScenario_double(scn, "LVDC_TSMC2", TSMC2);
	papiWriteScenario_double(scn, "LVDC_T_ST", T_ST);
	papiWriteScenario_double(scn, "LVDC_TSTA", TABLE15[0].T_ST);
	papiWriteScenario_double(scn, "LVDC_TSTB", TABLE15[1].T_ST);
	papiWriteScenario_double(scn, "LVDC_T_T", T_T);
	papiWriteScenario_double(scn, "LVDC_Tt_3", Tt_3);
	papiWriteScenario_double(scn, "LVDC_Tt_T", Tt_T);
	papiWriteScenario_double(scn, "LVDC_U_1", U_1);
	papiWriteScenario_double(scn, "LVDC_U_2", U_2);
	papiWriteScenario_double(scn, "LVDC_U_3", U_3);
	papiWriteScenario_double(scn, "LVDC_U_12", U_12);
	papiWriteScenario_double(scn, "LVDC_gamma_T", gamma_T);
	papiWriteScenario_double(scn, "LVDC_V", V);
	papiWriteScenario_double(scn, "LVDC_V_ex1", V_ex1);
	papiWriteScenario_double(scn, "LVDC_V_ex2", V_ex2);
	papiWriteScenario_double(scn, "LVDC_V_ex2R", V_ex2R);
	papiWriteScenario_double(scn, "LVDC_V_ex3", V_ex3);
	papiWriteScenario_double(scn, "LVDC_V_ex3R", V_ex3R);
	papiWriteScenario_double(scn, "LVDC_V_i", V_i);
	papiWriteScenario_double(scn, "LVDC_V_0", V_0);
	papiWriteScenario_double(scn, "LVDC_V_1", V_1);
	papiWriteScenario_double(scn, "LVDC_V_2", V_2);
	papiWriteScenario_double(scn, "LVDC_V_S2T", V_S2T);
	papiWriteScenario_double(scn, "LVDC_V_T", V_T);
	papiWriteScenario_double(scn, "LVDC_V_TC", V_TC);
	papiWriteScenario_double(scn, "LVDC_xi_T", xi_T);
	papiWriteScenario_double(scn, "LVDC_eta_T", eta_T);
	papiWriteScenario_double(scn, "LVDC_zeta_T", zeta_T);
	papiWriteScenario_double(scn, "LVDC_X_S1", X_S1);
	papiWriteScenario_double(scn, "LVDC_X_S2", X_S2);
	papiWriteScenario_double(scn, "LVDC_X_S3", X_S3);
	papiWriteScenario_double(scn, "LVDC_Xtt_y", Xtt_y);
	papiWriteScenario_double(scn, "LVDC_Xtt_p", Xtt_p);
	papiWriteScenario_double(scn, "LVDC_X_Zi", X_Zi);
	papiWriteScenario_double(scn, "LVDC_X_Yi", X_Yi);
	papiWriteScenario_double(scn, "LVDC_Y_u", Y_u);
	papiWriteScenario_vec(scn, "LVDC_ACommandedAttitude", ACommandedAttitude);
	papiWriteScenario_vec(scn, "LVDC_AttitudeError", AttitudeError);
	papiWriteScenario_vec(scn, "LVDC_AttRate", AttRate);
	papiWriteScenario_vec(scn, "LVDC_CommandedAttitude", CommandedAttitude);
	papiWriteScenario_vec(scn, "LVDC_CommandRateLimits", CommandRateLimits);
	papiWriteScenario_vec(scn, "LVDC_CurrentAttitude", CurrentAttitude);
	papiWriteScenario_vec(scn, "LVDC_ddotG_act", ddotG_act);
	papiWriteScenario_vec(scn, "LVDC_ddotG_last", ddotG_last);
	papiWriteScenario_vec(scn, "LVDC_ddotM_act", ddotM_act);
	papiWriteScenario_vec(scn, "LVDC_ddotM_last", ddotM_last);
	papiWriteScenario_vec(scn, "LVDC_DDotXEZ_G", DDotXEZ_G);
	papiWriteScenario_vec(scn, "LVDC_DotG_act", DotG_act);
	papiWriteScenario_vec(scn, "LVDC_DotG_last", DotG_last);
	papiWriteScenario_vec(scn, "LVDC_DotM_act", DotM_act);
	papiWriteScenario_vec(scn, "LVDC_DotM_last", DotM_last);
	papiWriteScenario_vec(scn, "LVDC_DotS", DotS);
	papiWriteScenario_vec(scn, "LVDC_DotXEZ", DotXEZ);
	papiWriteScenario_vec(scn, "LVDC_PCommandedAttitude", PCommandedAttitude);
	papiWriteScenario_vec(scn, "LVDC_Pos4", Pos4);
	papiWriteScenario_vec(scn, "LVDC_PosS", PosS);
	papiWriteScenario_vec(scn, "LVDC_PosXEZ", PosXEZ);
	papiWriteScenario_vec(scn, "LVDC_TargetVector", TargetVector);
	papiWriteScenario_vec(scn, "LVDC_WV", WV);
	papiWriteScenario_vec(scn, "LVDC_XLunarAttitude", XLunarAttitude);
	papiWriteScenario_mx(scn, "LVDC_MX_A", MX_A);
	papiWriteScenario_mx(scn, "LVDC_MX_B", MX_B);
	papiWriteScenario_mx(scn, "LVDC_MX_G", MX_G);
	papiWriteScenario_mx(scn, "LVDC_MX_K", MX_K);
	papiWriteScenario_mx(scn, "LVDC_MX_phi_T", MX_phi_T);
	// All done
	oapiWriteLine(scn, LVDC_END_STRING);
	lvimu.SaveState(scn);
}

void LVDC::LoadState(FILEHANDLE scn){
	char *line;	
	int tmp=0; // for bool loader
	if(Initialized){
		fprintf(lvlog,"LoadState() called\r\n");
		fflush(lvlog);
	}
	while (oapiReadScenario_nextline (scn, line)) {
		if (!strnicmp(line, LVDC_END_STRING, sizeof(LVDC_END_STRING))){
			break;
		}
		// are we there yet?
		// Doing all this in one go makes the MS compiler barf.
		// Doing it in long chains makes the MS compiler silently optimize away the tail of the chain.
		// So we do it in single lines.
		// booleans
		papiReadScenario_bool(line, "LVDC_alpha_D_op", alpha_D_op);
		papiReadScenario_bool(line, "LVDC_BOOST", BOOST);
		papiReadScenario_bool(line, "LVDC_CountPIPA", CountPIPA);
		papiReadScenario_bool(line, "LVDC_Direct_Ascent", Direct_Ascent);
		papiReadScenario_bool(line, "LVDC_directstageint", directstageint);
		papiReadScenario_bool(line, "LVDC_directstagereset", directstagereset);
		papiReadScenario_bool(line, "LVDC_first_op", first_op);
		papiReadScenario_bool(line, "LVDC_GATE", GATE);
		papiReadScenario_bool(line, "LVDC_GATE0", GATE0);
		papiReadScenario_bool(line, "LVDC_GATE1", GATE1);
		papiReadScenario_bool(line, "LVDC_GATE2", GATE2);
		papiReadScenario_bool(line, "LVDC_GATE3", GATE3);
		papiReadScenario_bool(line, "LVDC_GATE4", GATE4);
		papiReadScenario_bool(line, "LVDC_GATE5", GATE5);
		papiReadScenario_bool(line, "LVDC_GATE6", GATE6);
		papiReadScenario_bool(line, "LVDC_HSL", HSL);
		papiReadScenario_bool(line, "LVDC_INH", INH);
		papiReadScenario_bool(line, "LVDC_INH1", INH1);
		papiReadScenario_bool(line, "LVDC_INH2", INH2);
		papiReadScenario_bool(line, "LVDC_init", init);
		papiReadScenario_bool(line, "LVDC_i_op", i_op);
		papiReadScenario_bool(line, "LVDC_liftoff", liftoff);
		papiReadScenario_bool(line, "LVDC_LVDC_EI_On", LVDC_EI_On);
		papiReadScenario_bool(line, "LVDC_LVDC_GRR", LVDC_GRR);
		papiReadScenario_bool(line, "LVDC_MRS", MRS);
		papiReadScenario_bool(line, "LVDC_poweredflight", poweredflight);
		papiReadScenario_bool(line, "LVDC_ROT", ROT);
		papiReadScenario_bool(line, "LVDC_ROTR", ROTR);
		papiReadScenario_bool(line, "LVDC_S1_Engine_Out", S1_Engine_Out);
		papiReadScenario_bool(line, "LVDC_S2_BURNOUT", S2_BURNOUT);
		papiReadScenario_bool(line, "LVDC_S2_ENGINE_OUT", S2_ENGINE_OUT);
		papiReadScenario_bool(line, "LVDC_S2_IGNITION", S2_IGNITION);
		papiReadScenario_bool(line, "LVDC_S2_Startup", S2_Startup);
		papiReadScenario_bool(line, "LVDC_S4B_IGN", S4B_IGN);
		papiReadScenario_bool(line, "LVDC_S4B_REIGN", S4B_REIGN);
		papiReadScenario_bool(line, "LVDC_TerminalConditions", TerminalConditions);
		papiReadScenario_bool(line, "LVDC_theta_N_op", theta_N_op);
		papiReadScenario_bool(line, "LVDC_TU", TU);
		papiReadScenario_bool(line, "LVDC_TU10", TU10);

		// integers
		papiReadScenario_int(line, "LVDC_IGMCycle", IGMCycle);
		papiReadScenario_int(line, "LVDC_OrbNavCycle", OrbNavCycle);
		papiReadScenario_int(line, "LVDC_LVDC_Stop", LVDC_Stop);
		papiReadScenario_int(line, "LVDC_LVDC_Timebase", LVDC_Timebase);
		papiReadScenario_int(line, "LVDC_tgt_index", tgt_index);
		papiReadScenario_int(line, "LVDC_T_EO1", T_EO1);
		papiReadScenario_int(line, "LVDC_T_EO2", T_EO2);
		papiReadScenario_int(line, "LVDC_UP", UP);

		// doubles
		papiReadScenario_double(line, "LVDC_a", a);
		papiReadScenario_double(line, "LVDC_a_0p", a_0p);
		papiReadScenario_double(line, "LVDC_a_0r", a_0r);
		papiReadScenario_double(line, "LVDC_a_0y", a_0y);
		papiReadScenario_double(line, "LVDC_a_1", a_1);
		papiReadScenario_double(line, "LVDC_a_2", a_2);
		papiReadScenario_double(line, "LVDC_a_1p", a_1p);
		papiReadScenario_double(line, "LVDC_a_1r", a_1r);
		papiReadScenario_double(line, "LVDC_a_1y", a_1y);
		papiReadScenario_double(line, "LVDC_alpha_1", alpha_1);
		papiReadScenario_double(line, "LVDC_alpha_2", alpha_2);
		papiReadScenario_double(line, "LVDC_alpha_D", alpha_D);
		papiReadScenario_double(line, "LVDC_alpha_TS", alpha_TS);
		papiReadScenario_double(line, "LVDC_ALFTSA", TABLE15[0].alphaS_TS);
		papiReadScenario_double(line, "LVDC_ALFTSB", TABLE15[1].alphaS_TS);
		papiReadScenario_double(line, "LVDC_Azimuth", Azimuth);
		papiReadScenario_double(line, "LVDC_Azo", Azo);
		papiReadScenario_double(line, "LVDC_Azs", Azs);
		papiReadScenario_double(line, "LVDC_B_11", B_11);
		papiReadScenario_double(line, "LVDC_B_12", B_12);
		papiReadScenario_double(line, "LVDC_B_21", B_21);
		papiReadScenario_double(line, "LVDC_B_22", B_22);
		papiReadScenario_double(line, "LVDC_beta", beta);
		papiReadScenario_double(line, "LVDC_BETAA", TABLE15[0].beta);
		papiReadScenario_double(line, "LVDC_BETAB", TABLE15[1].beta);
		papiReadScenario_double(line, "LVDC_beta_p1c", beta_p1c);
		papiReadScenario_double(line, "LVDC_beta_p2c", beta_p2c);
		papiReadScenario_double(line, "LVDC_beta_p3c", beta_p3c);
		papiReadScenario_double(line, "LVDC_beta_p4c", beta_p4c);
		papiReadScenario_double(line, "LVDC_beta_pc", beta_pc);
		papiReadScenario_double(line, "LVDC_beta_rc", beta_rc);
		papiReadScenario_double(line, "LVDC_beta_y1c", beta_y1c);
		papiReadScenario_double(line, "LVDC_beta_y2c", beta_y2c);
		papiReadScenario_double(line, "LVDC_beta_y3c", beta_y3c);
		papiReadScenario_double(line, "LVDC_beta_y4c", beta_y4c);
		papiReadScenario_double(line, "LVDC_beta_yc", beta_yc);
		papiReadScenario_double(line, "LVDC_C_2", C_2);
		papiReadScenario_double(line, "LVDC_C_3", C_3);
		papiReadScenario_double(line, "LVDC_C_4", C_4);
		papiReadScenario_double(line, "LVDC_C3A0", TABLE15[0].target[0].C_3);
		papiReadScenario_double(line, "LVDC_C3A1", TABLE15[0].target[1].C_3);
		papiReadScenario_double(line, "LVDC_C3A2", TABLE15[0].target[2].C_3);
		papiReadScenario_double(line, "LVDC_C3A3", TABLE15[0].target[3].C_3);
		papiReadScenario_double(line, "LVDC_C3A4", TABLE15[0].target[4].C_3);
		papiReadScenario_double(line, "LVDC_C3A5", TABLE15[0].target[5].C_3);
		papiReadScenario_double(line, "LVDC_C3A6", TABLE15[0].target[6].C_3);
		papiReadScenario_double(line, "LVDC_C3A7", TABLE15[0].target[7].C_3);
		papiReadScenario_double(line, "LVDC_C3A8", TABLE15[0].target[8].C_3);
		papiReadScenario_double(line, "LVDC_C3A9", TABLE15[0].target[9].C_3);
		papiReadScenario_double(line, "LVDC_C3A10", TABLE15[0].target[10].C_3);
		papiReadScenario_double(line, "LVDC_C3A11", TABLE15[0].target[11].C_3);
		papiReadScenario_double(line, "LVDC_C3A12", TABLE15[0].target[12].C_3);
		papiReadScenario_double(line, "LVDC_C3A13", TABLE15[0].target[13].C_3);
		papiReadScenario_double(line, "LVDC_C3A14", TABLE15[0].target[14].C_3);
		papiReadScenario_double(line, "LVDC_C3B0", TABLE15[1].target[0].C_3);
		papiReadScenario_double(line, "LVDC_C3B1", TABLE15[1].target[1].C_3);
		papiReadScenario_double(line, "LVDC_C3B2", TABLE15[1].target[2].C_3);
		papiReadScenario_double(line, "LVDC_C3B3", TABLE15[1].target[3].C_3);
		papiReadScenario_double(line, "LVDC_C3B4", TABLE15[1].target[4].C_3);
		papiReadScenario_double(line, "LVDC_C3B5", TABLE15[1].target[5].C_3);
		papiReadScenario_double(line, "LVDC_C3B6", TABLE15[1].target[6].C_3);
		papiReadScenario_double(line, "LVDC_C3B7", TABLE15[1].target[7].C_3);
		papiReadScenario_double(line, "LVDC_C3B8", TABLE15[1].target[8].C_3);
		papiReadScenario_double(line, "LVDC_C3B9", TABLE15[1].target[9].C_3);
		papiReadScenario_double(line, "LVDC_C3B10", TABLE15[1].target[10].C_3);
		papiReadScenario_double(line, "LVDC_C3B11", TABLE15[1].target[11].C_3);
		papiReadScenario_double(line, "LVDC_C3B12", TABLE15[1].target[12].C_3);
		papiReadScenario_double(line, "LVDC_C3B13", TABLE15[1].target[13].C_3);
		papiReadScenario_double(line, "LVDC_C3B14", TABLE15[1].target[14].C_3);
		papiReadScenario_double(line, "LVDC_CCSA0", TABLE15[0].target[0].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA1", TABLE15[0].target[1].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA2", TABLE15[0].target[2].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA3", TABLE15[0].target[3].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA4", TABLE15[0].target[4].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA5", TABLE15[0].target[5].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA6", TABLE15[0].target[6].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA7", TABLE15[0].target[7].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA8", TABLE15[0].target[8].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA9", TABLE15[0].target[9].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA10", TABLE15[0].target[10].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA11", TABLE15[0].target[11].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA12", TABLE15[0].target[12].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA13", TABLE15[0].target[13].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSA14", TABLE15[0].target[14].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB0", TABLE15[1].target[0].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB1", TABLE15[1].target[1].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB2", TABLE15[1].target[2].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB3", TABLE15[1].target[3].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB4", TABLE15[1].target[4].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB5", TABLE15[1].target[5].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB6", TABLE15[1].target[6].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB7", TABLE15[1].target[7].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB8", TABLE15[1].target[8].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB9", TABLE15[1].target[9].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB10", TABLE15[1].target[10].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB11", TABLE15[1].target[11].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB12", TABLE15[1].target[12].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB13", TABLE15[1].target[13].cos_sigma);
		papiReadScenario_double(line, "LVDC_CCSB14", TABLE15[1].target[14].cos_sigma);
		papiReadScenario_double(line, "LVDC_Cf", Cf);
		papiReadScenario_double(line, "LVDC_CG", CG);
		papiReadScenario_double(line, "LVDC_cos_chi_Yit", cos_chi_Yit);
		papiReadScenario_double(line, "LVDC_cos_chi_Zit", cos_chi_Zit);
		papiReadScenario_double(line, "LVDC_cos_sigma", cos_sigma);
		papiReadScenario_double(line, "LVDC_Ct", Ct);
		papiReadScenario_double(line, "LVDC_Ct_o", Ct_o);
		papiReadScenario_double(line, "LVDC_D", D);
		papiReadScenario_double(line, "LVDC_d2", d2);
		papiReadScenario_double(line, "LVDC_ddot_xi_GT", ddot_xi_GT);
		papiReadScenario_double(line, "LVDC_ddot_zeta_GT", ddot_zeta_GT);
		papiReadScenario_double(line, "LVDC_DEC", DEC);
		papiReadScenario_double(line, "LVDC_DECA0", TABLE15[0].target[0].DEC);
		papiReadScenario_double(line, "LVDC_DECA1", TABLE15[0].target[1].DEC);
		papiReadScenario_double(line, "LVDC_DECA2", TABLE15[0].target[2].DEC);
		papiReadScenario_double(line, "LVDC_DECA3", TABLE15[0].target[3].DEC);
		papiReadScenario_double(line, "LVDC_DECA4", TABLE15[0].target[4].DEC);
		papiReadScenario_double(line, "LVDC_DECA5", TABLE15[0].target[5].DEC);
		papiReadScenario_double(line, "LVDC_DECA6", TABLE15[0].target[6].DEC);
		papiReadScenario_double(line, "LVDC_DECA7", TABLE15[0].target[7].DEC);
		papiReadScenario_double(line, "LVDC_DECA8", TABLE15[0].target[8].DEC);
		papiReadScenario_double(line, "LVDC_DECA9", TABLE15[0].target[9].DEC);
		papiReadScenario_double(line, "LVDC_DECA10", TABLE15[0].target[10].DEC);
		papiReadScenario_double(line, "LVDC_DECA11", TABLE15[0].target[11].DEC);
		papiReadScenario_double(line, "LVDC_DECA12", TABLE15[0].target[12].DEC);
		papiReadScenario_double(line, "LVDC_DECA13", TABLE15[0].target[13].DEC);
		papiReadScenario_double(line, "LVDC_DECA14", TABLE15[0].target[14].DEC);
		papiReadScenario_double(line, "LVDC_DECB0", TABLE15[1].target[0].DEC);
		papiReadScenario_double(line, "LVDC_DECB1", TABLE15[1].target[1].DEC);
		papiReadScenario_double(line, "LVDC_DECB2", TABLE15[1].target[2].DEC);
		papiReadScenario_double(line, "LVDC_DECB3", TABLE15[1].target[3].DEC);
		papiReadScenario_double(line, "LVDC_DECB4", TABLE15[1].target[4].DEC);
		papiReadScenario_double(line, "LVDC_DECB5", TABLE15[1].target[5].DEC);
		papiReadScenario_double(line, "LVDC_DECB6", TABLE15[1].target[6].DEC);
		papiReadScenario_double(line, "LVDC_DECB7", TABLE15[1].target[7].DEC);
		papiReadScenario_double(line, "LVDC_DECB8", TABLE15[1].target[8].DEC);
		papiReadScenario_double(line, "LVDC_DECB9", TABLE15[1].target[9].DEC);
		papiReadScenario_double(line, "LVDC_DECB10", TABLE15[1].target[10].DEC);
		papiReadScenario_double(line, "LVDC_DECB11", TABLE15[1].target[11].DEC);
		papiReadScenario_double(line, "LVDC_DECB12", TABLE15[1].target[12].DEC);
		papiReadScenario_double(line, "LVDC_DECB13", TABLE15[1].target[13].DEC);
		papiReadScenario_double(line, "LVDC_DECB14", TABLE15[1].target[14].DEC);
		papiReadScenario_double(line, "LVDC_deta", deta);
		papiReadScenario_double(line, "LVDC_dxi", dxi);
		papiReadScenario_double(line, "LVDC_dot_dxi", dot_dxi);
		papiReadScenario_double(line, "LVDC_dot_deta", dot_deta);
		papiReadScenario_double(line, "LVDC_dot_dzeta", dot_dzeta);
		papiReadScenario_double(line, "LVDC_dot_dxit", dot_dxit);
		papiReadScenario_double(line, "LVDC_dot_detat", dot_detat);
		papiReadScenario_double(line, "LVDC_dot_dzetat", dot_dzetat);
		papiReadScenario_double(line, "LVDC_dotM_1", dotM_1);
		papiReadScenario_double(line, "LVDC_dotM_2", dotM_2);
		papiReadScenario_double(line, "LVDC_dotM_2R", dotM_2R);
		papiReadScenario_double(line, "LVDC_dotM_3", dotM_3);
		papiReadScenario_double(line, "LVDC_dotM_3R", dotM_3R);
		papiReadScenario_double(line, "LVDC_dot_phi_1", dot_phi_1);
		papiReadScenario_double(line, "LVDC_dot_phi_T", dot_phi_T);
		papiReadScenario_double(line, "LVDC_dot_zeta_T", dot_zeta_T);
		papiReadScenario_double(line, "LVDC_dot_xi_T", dot_xi_T);
		papiReadScenario_double(line, "LVDC_dot_eta_T", dot_eta_T);
		papiReadScenario_double(line, "LVDC_Drag_Area[0]", Drag_Area[0]);
		papiReadScenario_double(line, "LVDC_Drag_Area[1]", Drag_Area[1]);
		papiReadScenario_double(line, "LVDC_Drag_Area[2]", Drag_Area[2]);
		papiReadScenario_double(line, "LVDC_Drag_Area[3]", Drag_Area[3]);
		papiReadScenario_double(line, "LVDC_Drag_Area[4]", Drag_Area[4]);
		papiReadScenario_double(line, "LVDC_dt", dt);
		papiReadScenario_double(line, "LVDC_dT_3", dT_3);
		papiReadScenario_double(line, "LVDC_dT_4", dT_4);
		papiReadScenario_double(line, "LVDC_dt_c", dt_c);
		papiReadScenario_double(line, "LVDC_dT_cost", dT_cost);
		papiReadScenario_double(line, "LVDC_dT_F", dT_F);
		papiReadScenario_double(line, "LVDC_dt_g", dt_g);
		papiReadScenario_double(line, "LVDC_dt_LET", dt_LET);
		papiReadScenario_double(line, "LVDC_dT_LIM", dT_LIM);
		papiReadScenario_double(line, "LVDC_dtt_1", dtt_1);
		papiReadScenario_double(line, "LVDC_dtt_2", dtt_2);
		papiReadScenario_double(line, "LVDC_dTt_4", dTt_4);
		papiReadScenario_double(line, "LVDC_dV", dV);
		papiReadScenario_double(line, "LVDC_dV_B", dV_B);
		papiReadScenario_double(line, "LVDC_dV_BR", dV_BR);
		papiReadScenario_double(line, "LVDC_e", e);
		papiReadScenario_double(line, "LVDC_e_N", e_N);
		papiReadScenario_double(line, "LVDC_ENA0", TABLE15[0].target[0].e_N);
		papiReadScenario_double(line, "LVDC_ENA1", TABLE15[0].target[1].e_N);
		papiReadScenario_double(line, "LVDC_ENA2", TABLE15[0].target[2].e_N);
		papiReadScenario_double(line, "LVDC_ENA3", TABLE15[0].target[3].e_N);
		papiReadScenario_double(line, "LVDC_ENA4", TABLE15[0].target[4].e_N);
		papiReadScenario_double(line, "LVDC_ENA5", TABLE15[0].target[5].e_N);
		papiReadScenario_double(line, "LVDC_ENA6", TABLE15[0].target[6].e_N);
		papiReadScenario_double(line, "LVDC_ENA7", TABLE15[0].target[7].e_N);
		papiReadScenario_double(line, "LVDC_ENA8", TABLE15[0].target[8].e_N);
		papiReadScenario_double(line, "LVDC_ENA9", TABLE15[0].target[9].e_N);
		papiReadScenario_double(line, "LVDC_ENA10", TABLE15[0].target[10].e_N);
		papiReadScenario_double(line, "LVDC_ENA11", TABLE15[0].target[11].e_N);
		papiReadScenario_double(line, "LVDC_ENA12", TABLE15[0].target[12].e_N);
		papiReadScenario_double(line, "LVDC_ENA13", TABLE15[0].target[13].e_N);
		papiReadScenario_double(line, "LVDC_ENA14", TABLE15[0].target[14].e_N);
		papiReadScenario_double(line, "LVDC_ENB0", TABLE15[1].target[0].e_N);
		papiReadScenario_double(line, "LVDC_ENB1", TABLE15[1].target[1].e_N);
		papiReadScenario_double(line, "LVDC_ENB2", TABLE15[1].target[2].e_N);
		papiReadScenario_double(line, "LVDC_ENB3", TABLE15[1].target[3].e_N);
		papiReadScenario_double(line, "LVDC_ENB4", TABLE15[1].target[4].e_N);
		papiReadScenario_double(line, "LVDC_ENB5", TABLE15[1].target[5].e_N);
		papiReadScenario_double(line, "LVDC_ENB6", TABLE15[1].target[6].e_N);
		papiReadScenario_double(line, "LVDC_ENB7", TABLE15[1].target[7].e_N);
		papiReadScenario_double(line, "LVDC_ENB8", TABLE15[1].target[8].e_N);
		papiReadScenario_double(line, "LVDC_ENB9", TABLE15[1].target[9].e_N);
		papiReadScenario_double(line, "LVDC_ENB10", TABLE15[1].target[10].e_N);
		papiReadScenario_double(line, "LVDC_ENB11", TABLE15[1].target[11].e_N);
		papiReadScenario_double(line, "LVDC_ENB12", TABLE15[1].target[12].e_N);
		papiReadScenario_double(line, "LVDC_ENB13", TABLE15[1].target[13].e_N);
		papiReadScenario_double(line, "LVDC_ENB14", TABLE15[1].target[14].e_N);
		papiReadScenario_double(line, "LVDC_eps_1", eps_1);
		papiReadScenario_double(line, "LVDC_eps_1R", eps_1R);
		papiReadScenario_double(line, "LVDC_eps_2", eps_2);
		papiReadScenario_double(line, "LVDC_eps_2R", eps_2R);
		papiReadScenario_double(line, "LVDC_eps_3", eps_3);
		papiReadScenario_double(line, "LVDC_eps_3R", eps_3R);
		papiReadScenario_double(line, "LVDC_eps_4", eps_4);
		papiReadScenario_double(line, "LVDC_eps_4R", eps_4R);
		papiReadScenario_double(line, "LVDC_eps_p", eps_p);
		papiReadScenario_double(line, "LVDC_eps_ymr", eps_ymr);
		papiReadScenario_double(line, "LVDC_eps_ypr", eps_ypr);
		papiReadScenario_double(line, "LVDC_f", f);
		papiReadScenario_double(line, "LVDC_F", F);
		papiReadScenario_double(line, "LVDC_FA", TABLE15[0].f);
		papiReadScenario_double(line, "LVDC_FB", TABLE15[1].f);
		papiReadScenario_double(line, "LVDC_Fm", Fm);
		papiReadScenario_double(line, "LVDC_fx[0]", fx[0]);
		papiReadScenario_double(line, "LVDC_fx[1]", fx[1]);
		papiReadScenario_double(line, "LVDC_fx[2]", fx[2]);
		papiReadScenario_double(line, "LVDC_fx[3]", fx[3]);
		papiReadScenario_double(line, "LVDC_fx[4]", fx[4]);
		papiReadScenario_double(line, "LVDC_fx[5]", fx[5]);
		papiReadScenario_double(line, "LVDC_fx[6]", fx[6]);
		papiReadScenario_double(line, "LVDC_fxt[0]", fxt[0]);
		papiReadScenario_double(line, "LVDC_fxt[1]", fxt[1]);
		papiReadScenario_double(line, "LVDC_fxt[2]", fxt[2]);
		papiReadScenario_double(line, "LVDC_fxt[3]", fxt[3]);
		papiReadScenario_double(line, "LVDC_fxt[4]", fxt[4]);
		papiReadScenario_double(line, "LVDC_fxt[5]", fxt[5]);
		papiReadScenario_double(line, "LVDC_fxt[6]", fxt[6]);
		papiReadScenario_double(line, "LVDC_Fx[0][0]", Fx[0][0]);
		papiReadScenario_double(line, "LVDC_Fx[0][1]", Fx[0][1]);
		papiReadScenario_double(line, "LVDC_Fx[0][2]", Fx[0][2]);
		papiReadScenario_double(line, "LVDC_Fx[0][3]", Fx[0][3]);
		papiReadScenario_double(line, "LVDC_Fx[0][4]", Fx[0][4]);
		papiReadScenario_double(line, "LVDC_Fx[1][0]", Fx[1][0]);
		papiReadScenario_double(line, "LVDC_Fx[1][1]", Fx[1][1]);
		papiReadScenario_double(line, "LVDC_Fx[1][2]", Fx[1][2]);
		papiReadScenario_double(line, "LVDC_Fx[1][3]", Fx[1][3]);
		papiReadScenario_double(line, "LVDC_Fx[1][4]", Fx[1][4]);
		papiReadScenario_double(line, "LVDC_Fx[2][0]", Fx[2][0]);
		papiReadScenario_double(line, "LVDC_Fx[2][1]", Fx[2][1]);
		papiReadScenario_double(line, "LVDC_Fx[2][2]", Fx[2][2]);
		papiReadScenario_double(line, "LVDC_Fx[2][3]", Fx[2][3]);
		papiReadScenario_double(line, "LVDC_Fx[2][4]", Fx[2][4]);
		papiReadScenario_double(line, "LVDC_Fx[3][0]", Fx[3][0]);
		papiReadScenario_double(line, "LVDC_Fx[3][1]", Fx[3][1]);
		papiReadScenario_double(line, "LVDC_Fx[3][2]", Fx[3][2]);
		papiReadScenario_double(line, "LVDC_Fx[3][3]", Fx[3][3]);
		papiReadScenario_double(line, "LVDC_Fx[3][4]", Fx[3][4]);
		papiReadScenario_double(line, "LVDC_Fx[4][0]", Fx[4][0]);
		papiReadScenario_double(line, "LVDC_Fx[4][1]", Fx[4][1]);
		papiReadScenario_double(line, "LVDC_Fx[4][2]", Fx[4][2]);
		papiReadScenario_double(line, "LVDC_Fx[4][3]", Fx[4][3]);
		papiReadScenario_double(line, "LVDC_Fx[4][4]", Fx[4][4]);
		papiReadScenario_double(line, "LVDC_GPitch[0]", GPitch[0]);
		papiReadScenario_double(line, "LVDC_GPitch[1]", GPitch[1]);
		papiReadScenario_double(line, "LVDC_GPitch[2]", GPitch[2]);
		papiReadScenario_double(line, "LVDC_GPitch[3]", GPitch[3]);
		papiReadScenario_double(line, "LVDC_GYaw[0]", GYaw[0]);
		papiReadScenario_double(line, "LVDC_GYaw[1]", GYaw[1]);
		papiReadScenario_double(line, "LVDC_GYaw[2]", GYaw[2]);
		papiReadScenario_double(line, "LVDC_GYaw[3]", GYaw[3]);
		papiReadScenario_double(line, "LVDC_G_T", G_T);
		papiReadScenario_double(line, "LVDC_gx[0]", gx[0]);
		papiReadScenario_double(line, "LVDC_gx[1]", gx[1]);
		papiReadScenario_double(line, "LVDC_gx[2]", gx[2]);
		papiReadScenario_double(line, "LVDC_gx[3]", gx[3]);
		papiReadScenario_double(line, "LVDC_gx[4]", gx[4]);
		papiReadScenario_double(line, "LVDC_gx[5]", gx[5]);
		papiReadScenario_double(line, "LVDC_gx[6]", gx[6]);
		papiReadScenario_double(line, "LVDC_gxt[0]", gxt[0]);
		papiReadScenario_double(line, "LVDC_gxt[1]", gxt[1]);
		papiReadScenario_double(line, "LVDC_gxt[2]", gxt[2]);
		papiReadScenario_double(line, "LVDC_gxt[3]", gxt[3]);
		papiReadScenario_double(line, "LVDC_gxt[4]", gxt[4]);
		papiReadScenario_double(line, "LVDC_gxt[5]", gxt[5]);
		papiReadScenario_double(line, "LVDC_gxt[6]", gxt[6]);
		papiReadScenario_double(line, "LVDC_H", H);
		papiReadScenario_double(line, "LVDC_hx[0][0]", hx[0][0]);
		papiReadScenario_double(line, "LVDC_hx[0][1]", hx[0][1]);
		papiReadScenario_double(line, "LVDC_hx[0][2]", hx[0][2]);
		papiReadScenario_double(line, "LVDC_hx[0][3]", hx[0][3]);
		papiReadScenario_double(line, "LVDC_hx[0][4]", hx[0][4]);
		papiReadScenario_double(line, "LVDC_hx[1][0]", hx[1][0]);
		papiReadScenario_double(line, "LVDC_hx[1][1]", hx[1][1]);
		papiReadScenario_double(line, "LVDC_hx[1][2]", hx[1][2]);
		papiReadScenario_double(line, "LVDC_hx[1][3]", hx[1][3]);
		papiReadScenario_double(line, "LVDC_hx[1][4]", hx[1][4]);
		papiReadScenario_double(line, "LVDC_hx[2][0]", hx[2][0]);
		papiReadScenario_double(line, "LVDC_hx[2][1]", hx[2][1]);
		papiReadScenario_double(line, "LVDC_hx[2][2]", hx[2][2]);
		papiReadScenario_double(line, "LVDC_hx[2][3]", hx[2][3]);
		papiReadScenario_double(line, "LVDC_hx[2][4]", hx[2][4]);
		papiReadScenario_double(line, "LVDC_IGMInterval", IGMInterval);
		papiReadScenario_double(line, "LVDC_Inclination", Inclination);
		papiReadScenario_double(line, "LVDC_J", J);
		papiReadScenario_double(line, "LVDC_J_1", J_1);
		papiReadScenario_double(line, "LVDC_J_2", J_2);
		papiReadScenario_double(line, "LVDC_J_3", J_3);
		papiReadScenario_double(line, "LVDC_J_12", J_12);
		papiReadScenario_double(line, "LVDC_Jt_3", Jt_3);
		papiReadScenario_double(line, "LVDC_J_P", J_P);
		papiReadScenario_double(line, "LVDC_J_Y", J_Y);
		papiReadScenario_double(line, "LVDC_K_1", K_1);
		papiReadScenario_double(line, "LVDC_K_2", K_2);
		papiReadScenario_double(line, "LVDC_K_3", K_3);
		papiReadScenario_double(line, "LVDC_K_4", K_4);
		papiReadScenario_double(line, "LVDC_K_5", K_5);
		papiReadScenario_double(line, "LVDC_K_P1", K_P1);
		papiReadScenario_double(line, "LVDC_K_P2", K_P2);
		papiReadScenario_double(line, "LVDC_K_Y1", K_Y1);
		papiReadScenario_double(line, "LVDC_K_Y2", K_Y2);
		papiReadScenario_double(line, "LVDC_K_P", K_P);
		papiReadScenario_double(line, "LVDC_K_Y", K_Y);
		papiReadScenario_double(line, "LVDC_D_P", D_P);
		papiReadScenario_double(line, "LVDC_D_Y", D_Y);
		papiReadScenario_double(line, "LVDC_L_1", L_1);
		papiReadScenario_double(line, "LVDC_L_2", L_2);
		papiReadScenario_double(line, "LVDC_L_3", L_3);
		papiReadScenario_double(line, "LVDC_dL_3", dL_3);
		papiReadScenario_double(line, "LVDC_Lt_3", Lt_3);
		papiReadScenario_double(line, "LVDC_L_12", L_12);
		papiReadScenario_double(line, "LVDC_L_P", L_P);
		papiReadScenario_double(line, "LVDC_L_Y", L_Y);
		papiReadScenario_double(line, "LVDC_Lt_Y", Lt_Y);
		papiReadScenario_double(line, "LVDC_LVDC_TB_ETime", LVDC_TB_ETime);
		papiReadScenario_double(line, "LVDC_mu", mu);
		papiReadScenario_double(line, "LVDC_omega_E", omega_E);
		papiReadScenario_double(line, "LVDC_OPitch[0]", OPitch[0]);
		papiReadScenario_double(line, "LVDC_OPitch[1]", OPitch[1]);
		papiReadScenario_double(line, "LVDC_OPitch[2]", OPitch[2]);
		papiReadScenario_double(line, "LVDC_OPitch[3]", OPitch[3]);
		papiReadScenario_double(line, "LVDC_OYaw[0]", OYaw[0]);
		papiReadScenario_double(line, "LVDC_OYaw[1]", OYaw[1]);
		papiReadScenario_double(line, "LVDC_OYaw[2]", OYaw[2]);
		papiReadScenario_double(line, "LVDC_OYaw[3]", OYaw[3]);
		papiReadScenario_double(line, "LVDC_p", p);
		papiReadScenario_double(line, "LVDC_P_1", P_1);
		papiReadScenario_double(line, "LVDC_P_2", P_2);
		papiReadScenario_double(line, "LVDC_P_3", P_3);
		papiReadScenario_double(line, "LVDC_P_12", P_12);
		papiReadScenario_double(line, "LVDC_phi_L", phi_L);
		papiReadScenario_double(line, "LVDC_phi_T", phi_T);
		papiReadScenario_double(line, "LVDC_Q_1", Q_1);
		papiReadScenario_double(line, "LVDC_Q_2", Q_2);
		papiReadScenario_double(line, "LVDC_Q_3", Q_3);
		papiReadScenario_double(line, "LVDC_Q_12", Q_12);
		papiReadScenario_double(line, "LVDC_Q_P", Q_P);
		papiReadScenario_double(line, "LVDC_Q_Y", Q_Y);
		papiReadScenario_double(line, "LVDC_R", R);
		papiReadScenario_double(line, "LVDC_RAS", RAS);
		papiReadScenario_double(line, "LVDC_RASA0", TABLE15[0].target[0].RAS);
		papiReadScenario_double(line, "LVDC_RASA1", TABLE15[0].target[1].RAS);
		papiReadScenario_double(line, "LVDC_RASA2", TABLE15[0].target[2].RAS);
		papiReadScenario_double(line, "LVDC_RASA3", TABLE15[0].target[3].RAS);
		papiReadScenario_double(line, "LVDC_RASA4", TABLE15[0].target[4].RAS);
		papiReadScenario_double(line, "LVDC_RASA5", TABLE15[0].target[5].RAS);
		papiReadScenario_double(line, "LVDC_RASA6", TABLE15[0].target[6].RAS);
		papiReadScenario_double(line, "LVDC_RASA7", TABLE15[0].target[7].RAS);
		papiReadScenario_double(line, "LVDC_RASA8", TABLE15[0].target[8].RAS);
		papiReadScenario_double(line, "LVDC_RASA9", TABLE15[0].target[9].RAS);
		papiReadScenario_double(line, "LVDC_RASA10", TABLE15[0].target[10].RAS);
		papiReadScenario_double(line, "LVDC_RASA11", TABLE15[0].target[11].RAS);
		papiReadScenario_double(line, "LVDC_RASA12", TABLE15[0].target[12].RAS);
		papiReadScenario_double(line, "LVDC_RASA13", TABLE15[0].target[13].RAS);
		papiReadScenario_double(line, "LVDC_RASA14", TABLE15[0].target[14].RAS);
		papiReadScenario_double(line, "LVDC_RASB0", TABLE15[1].target[0].RAS);
		papiReadScenario_double(line, "LVDC_RASB1", TABLE15[1].target[1].RAS);
		papiReadScenario_double(line, "LVDC_RASB2", TABLE15[1].target[2].RAS);
		papiReadScenario_double(line, "LVDC_RASB3", TABLE15[1].target[3].RAS);
		papiReadScenario_double(line, "LVDC_RASB4", TABLE15[1].target[4].RAS);
		papiReadScenario_double(line, "LVDC_RASB5", TABLE15[1].target[5].RAS);
		papiReadScenario_double(line, "LVDC_RASB6", TABLE15[1].target[6].RAS);
		papiReadScenario_double(line, "LVDC_RASB7", TABLE15[1].target[7].RAS);
		papiReadScenario_double(line, "LVDC_RASB8", TABLE15[1].target[8].RAS);
		papiReadScenario_double(line, "LVDC_RASB9", TABLE15[1].target[9].RAS);
		papiReadScenario_double(line, "LVDC_RASB10", TABLE15[1].target[10].RAS);
		papiReadScenario_double(line, "LVDC_RASB11", TABLE15[1].target[11].RAS);
		papiReadScenario_double(line, "LVDC_RASB12", TABLE15[1].target[12].RAS);
		papiReadScenario_double(line, "LVDC_RASB13", TABLE15[1].target[13].RAS);
		papiReadScenario_double(line, "LVDC_RASB14", TABLE15[1].target[14].RAS);
		papiReadScenario_double(line, "LVDC_RateGain", RateGain);
		papiReadScenario_double(line, "LVDC_ErrorGain", ErrorGain);
		papiReadScenario_double(line, "LVDC_rho", rho);
		papiReadScenario_double(line, "LVDC_R_N", R_N);
		papiReadScenario_double(line, "LVDC_RNA", TABLE15[0].R_N);
		papiReadScenario_double(line, "LVDC_RNB", TABLE15[1].R_N);
		papiReadScenario_double(line, "LVDC_Rho[0]", Rho[0]);
		papiReadScenario_double(line, "LVDC_Rho[1]", Rho[1]);
		papiReadScenario_double(line, "LVDC_Rho[2]", Rho[2]);
		papiReadScenario_double(line, "LVDC_Rho[3]", Rho[3]);
		papiReadScenario_double(line, "LVDC_Rho[4]", Rho[4]);
		papiReadScenario_double(line, "LVDC_Rho[5]", Rho[5]);
		papiReadScenario_double(line, "LVDC_ROV", ROV);
		papiReadScenario_double(line, "LVDC_ROVR", ROVR);
		papiReadScenario_double(line, "LVDC_ROVs", ROVs);
		papiReadScenario_double(line, "LVDC_R_T", R_T);
		papiReadScenario_double(line, "LVDC_S_1", S_1);
		papiReadScenario_double(line, "LVDC_S_2", S_2);
		papiReadScenario_double(line, "LVDC_S_3", S_3);
		papiReadScenario_double(line, "LVDC_S_12", S_12);
		papiReadScenario_double(line, "LVDC_S_P", S_P);
		papiReadScenario_double(line, "LVDC_S_Y", S_Y);
		papiReadScenario_double(line, "LVDC_S1_Sep_Time", S1_Sep_Time);
		papiReadScenario_double(line, "LVDC_sinceLastCycle", sinceLastCycle);
		papiReadScenario_double(line, "LVDC_sinceLastGuidanceCycle", sinceLastGuidanceCycle);
		papiReadScenario_double(line, "LVDC_sin_chi_Yit", sin_chi_Yit);
		papiReadScenario_double(line, "LVDC_sin_chi_Zit", sin_chi_Zit);
		papiReadScenario_double(line, "LVDC_sin_gam", sin_gam);
		papiReadScenario_double(line, "LVDC_cos_gam", cos_gam);
		papiReadScenario_double(line, "LVDC_SMCG", SMCG);
		papiReadScenario_double(line, "LVDC_S", S);
		papiReadScenario_double(line, "LVDC_P", P);
		papiReadScenario_double(line, "LVDC_S_34", S_34);
		papiReadScenario_double(line, "LVDC_P_34", P_34);
		papiReadScenario_double(line, "LVDC_t", t);
		papiReadScenario_double(line, "LVDC_T_0", T_0);
		papiReadScenario_double(line, "LVDC_t_1", t_1);
		papiReadScenario_double(line, "LVDC_T_1", T_1);
		papiReadScenario_double(line, "LVDC_T_1c", T_1c);
		papiReadScenario_double(line, "LVDC_t_2", t_2);
		papiReadScenario_double(line, "LVDC_T_2", T_2);
		papiReadScenario_double(line, "LVDC_t_21", t_21);
		papiReadScenario_double(line, "LVDC_T_2R", T_2R);
		papiReadScenario_double(line, "LVDC_t_3", t_3);
		papiReadScenario_double(line, "LVDC_T_3", T_3);
		papiReadScenario_double(line, "LVDC_t_3i", t_3i);
		papiReadScenario_double(line, "LVDC_t_4", t_4);
		papiReadScenario_double(line, "LVDC_T_4N", T_4N);
		papiReadScenario_double(line, "LVDC_t_5", t_5);
		papiReadScenario_double(line, "LVDC_t_6", t_6);
		papiReadScenario_double(line, "LVDC_TA1", TA1);
		papiReadScenario_double(line, "LVDC_TA2", TA2);
		papiReadScenario_double(line, "LVDC_T_ar", T_ar);
		papiReadScenario_double(line, "LVDC_TAS", TAS);
		papiReadScenario_double(line, "LVDC_tau1", tau1);
		papiReadScenario_double(line, "LVDC_tau2", tau2);
		papiReadScenario_double(line, "LVDC_tau2N", tau2N);
		papiReadScenario_double(line, "LVDC_tau3", tau3);
		papiReadScenario_double(line, "LVDC_tau3N", tau3N);
		papiReadScenario_double(line, "LVDC_tau3R", tau3R);
		papiReadScenario_double(line, "LVDC_t_B1", t_B1);
		papiReadScenario_double(line, "LVDC_TB1", TB1);
		papiReadScenario_double(line, "LVDC_t_B2", t_B2);
		papiReadScenario_double(line, "LVDC_TB2", TB2);
		papiReadScenario_double(line, "LVDC_t_B3", t_B3);
		papiReadScenario_double(line, "LVDC_TB3", TB3);
		papiReadScenario_double(line, "LVDC_t_B4", t_B4);
		papiReadScenario_double(line, "LVDC_TB4", TB4);
		papiReadScenario_double(line, "LVDC_TB4A", TB4A);
		papiReadScenario_double(line, "LVDC_TB5", TB5);
		papiReadScenario_double(line, "LVDC_TB6", TB6);
		papiReadScenario_double(line, "LVDC_TB7", TB7);
		papiReadScenario_double(line, "LVDC_T_c", T_c);
		papiReadScenario_double(line, "LVDC_tchi_p_last", tchi_p_last);
		papiReadScenario_double(line, "LVDC_tchi_y_last", tchi_y_last);
		papiReadScenario_double(line, "LVDC_tchi_p", tchi_p);
		papiReadScenario_double(line, "LVDC_tchi_y", tchi_y);
		papiReadScenario_double(line, "LVDC_t_clock", t_clock);
		papiReadScenario_double(line, "LVDC_T_CO", T_CO);
		papiReadScenario_double(line, "LVDC_t_D", t_D);
		papiReadScenario_double(line, "LVDC_t_D0", t_D0);
		papiReadScenario_double(line, "LVDC_t_D1", t_D1);
		papiReadScenario_double(line, "LVDC_t_D2", t_D2);
		papiReadScenario_double(line, "LVDC_t_D3", t_D3);
		papiReadScenario_double(line, "LVDC_t_DS0", t_DS0);
		papiReadScenario_double(line, "LVDC_t_DS1", t_DS1);
		papiReadScenario_double(line, "LVDC_t_DS2", t_DS2);
		papiReadScenario_double(line, "LVDC_t_DS3", t_DS3);
		papiReadScenario_double(line, "LVDC_t_fail", t_fail);
		papiReadScenario_double(line, "LVDC_T_GO", T_GO);
		papiReadScenario_double(line, "LVDC_TETEO", theta_EO);
		papiReadScenario_double(line, "LVDC_theta_N", theta_N);
		papiReadScenario_double(line, "LVDC_TI5F2", TI5F2);
		papiReadScenario_double(line, "LVDC_T_IGM", T_IGM);
		papiReadScenario_double(line, "LVDC_T_L", T_L);
		papiReadScenario_double(line, "LVDC_T_LET", T_LET);
		papiReadScenario_double(line, "LVDC_T_LO", T_LO);
		papiReadScenario_double(line, "LVDC_TPA0", TABLE15[0].target[0].t_D);
		papiReadScenario_double(line, "LVDC_TPA1", TABLE15[0].target[1].t_D);
		papiReadScenario_double(line, "LVDC_TPA2", TABLE15[0].target[2].t_D);
		papiReadScenario_double(line, "LVDC_TPA3", TABLE15[0].target[3].t_D);
		papiReadScenario_double(line, "LVDC_TPA4", TABLE15[0].target[4].t_D);
		papiReadScenario_double(line, "LVDC_TPA5", TABLE15[0].target[5].t_D);
		papiReadScenario_double(line, "LVDC_TPA6", TABLE15[0].target[6].t_D);
		papiReadScenario_double(line, "LVDC_TPA7", TABLE15[0].target[7].t_D);
		papiReadScenario_double(line, "LVDC_TPA8", TABLE15[0].target[8].t_D);
		papiReadScenario_double(line, "LVDC_TPA9", TABLE15[0].target[9].t_D);
		papiReadScenario_double(line, "LVDC_TPA10", TABLE15[0].target[10].t_D);
		papiReadScenario_double(line, "LVDC_TPA11", TABLE15[0].target[11].t_D);
		papiReadScenario_double(line, "LVDC_TPA12", TABLE15[0].target[12].t_D);
		papiReadScenario_double(line, "LVDC_TPA13", TABLE15[0].target[13].t_D);
		papiReadScenario_double(line, "LVDC_TPA14", TABLE15[0].target[14].t_D);
		papiReadScenario_double(line, "LVDC_TPB0", TABLE15[1].target[0].t_D);
		papiReadScenario_double(line, "LVDC_TPB1", TABLE15[1].target[1].t_D);
		papiReadScenario_double(line, "LVDC_TPB2", TABLE15[1].target[2].t_D);
		papiReadScenario_double(line, "LVDC_TPB3", TABLE15[1].target[3].t_D);
		papiReadScenario_double(line, "LVDC_TPB4", TABLE15[1].target[4].t_D);
		papiReadScenario_double(line, "LVDC_TPB5", TABLE15[1].target[5].t_D);
		papiReadScenario_double(line, "LVDC_TPB6", TABLE15[1].target[6].t_D);
		papiReadScenario_double(line, "LVDC_TPB7", TABLE15[1].target[7].t_D);
		papiReadScenario_double(line, "LVDC_TPB8", TABLE15[1].target[8].t_D);
		papiReadScenario_double(line, "LVDC_TPB9", TABLE15[1].target[9].t_D);
		papiReadScenario_double(line, "LVDC_TPB10", TABLE15[1].target[10].t_D);
		papiReadScenario_double(line, "LVDC_TPB11", TABLE15[1].target[11].t_D);
		papiReadScenario_double(line, "LVDC_TPB12", TABLE15[1].target[12].t_D);
		papiReadScenario_double(line, "LVDC_TPB13", TABLE15[1].target[13].t_D);
		papiReadScenario_double(line, "LVDC_TPB14", TABLE15[1].target[14].t_D);
		papiReadScenario_double(line, "LVDC_T_RG", T_RG);
		papiReadScenario_double(line, "LVDC_T_RP", T_RP);
		papiReadScenario_double(line, "LVDC_T_S1", T_S1);
		papiReadScenario_double(line, "LVDC_T_S2", T_S2);
		papiReadScenario_double(line, "LVDC_T_S3", T_S3);
		papiReadScenario_double(line, "LVDC_TS4BS", TS4BS);
		papiReadScenario_double(line, "LVDC_t_SD1", t_SD1);
		papiReadScenario_double(line, "LVDC_t_SD2", t_SD2);
		papiReadScenario_double(line, "LVDC_t_SD3", t_SD3);
		papiReadScenario_double(line, "LVDC_TSMC1", TSMC1);
		papiReadScenario_double(line, "LVDC_TSMC2", TSMC2);
		papiReadScenario_double(line, "LVDC_T_ST", T_ST);
		papiReadScenario_double(line, "LVDC_TSTA", TABLE15[0].T_ST);
		papiReadScenario_double(line, "LVDC_TSTB", TABLE15[1].T_ST);
		papiReadScenario_double(line, "LVDC_T_T", T_T);
		papiReadScenario_double(line, "LVDC_Tt_3", Tt_3);
		papiReadScenario_double(line, "LVDC_Tt_T", Tt_T);
		papiReadScenario_double(line, "LVDC_U_1", U_1);
		papiReadScenario_double(line, "LVDC_U_2", U_2);
		papiReadScenario_double(line, "LVDC_U_3", U_3);
		papiReadScenario_double(line, "LVDC_U_12", U_12);
		papiReadScenario_double(line, "LVDC_gamma_T", gamma_T);
		papiReadScenario_double(line, "LVDC_V", V);
		papiReadScenario_double(line, "LVDC_V_ex1", V_ex1);
		papiReadScenario_double(line, "LVDC_V_ex2", V_ex2);
		papiReadScenario_double(line, "LVDC_V_ex2R", V_ex2R);
		papiReadScenario_double(line, "LVDC_V_ex3", V_ex3);
		papiReadScenario_double(line, "LVDC_V_ex3R", V_ex3R);
		papiReadScenario_double(line, "LVDC_V_i", V_i);
		papiReadScenario_double(line, "LVDC_V_0", V_0);
		papiReadScenario_double(line, "LVDC_V_1", V_1);
		papiReadScenario_double(line, "LVDC_V_2", V_2);
		papiReadScenario_double(line, "LVDC_V_S2T", V_S2T);
		papiReadScenario_double(line, "LVDC_V_T", V_T);
		papiReadScenario_double(line, "LVDC_V_TC", V_TC);
		papiReadScenario_double(line, "LVDC_xi_T", xi_T);
		papiReadScenario_double(line, "LVDC_eta_T", eta_T);
		papiReadScenario_double(line, "LVDC_zeta_T", zeta_T);
		papiReadScenario_double(line, "LVDC_X_S1", X_S1);
		papiReadScenario_double(line, "LVDC_X_S2", X_S2);
		papiReadScenario_double(line, "LVDC_X_S3", X_S3);
		papiReadScenario_double(line, "LVDC_Xtt_p", Xtt_p);
		papiReadScenario_double(line, "LVDC_Xtt_y", Xtt_y);
		papiReadScenario_double(line, "LVDC_X_Zi", X_Zi);
		papiReadScenario_double(line, "LVDC_X_Yi", X_Yi);
		papiReadScenario_double(line, "LVDC_Y_u", Y_u);

		// VECTOR3
		papiReadScenario_vec(line, "LVDC_ACommandedAttitude", ACommandedAttitude);
		papiReadScenario_vec(line, "LVDC_AttitudeError", AttitudeError);
		papiReadScenario_vec(line, "LVDC_AttRate", AttRate);
		papiReadScenario_vec(line, "LVDC_CommandedAttitude", CommandedAttitude);
		papiReadScenario_vec(line, "LVDC_CommandRateLimits", CommandRateLimits);
		papiReadScenario_vec(line, "LVDC_CurrentAttitude", CurrentAttitude);
		papiReadScenario_vec(line, "LVDC_ddotG_act", ddotG_act);
		papiReadScenario_vec(line, "LVDC_ddotG_last", ddotG_last);
		papiReadScenario_vec(line, "LVDC_ddotM_act", ddotM_act);
		papiReadScenario_vec(line, "LVDC_ddotM_last", ddotM_last);
		papiReadScenario_vec(line, "LVDC_DDotXEZ_G", DDotXEZ_G);
		papiReadScenario_vec(line, "LVDC_DotG_act", DotG_act);
		papiReadScenario_vec(line, "LVDC_DotG_last", DotG_last);
		papiReadScenario_vec(line, "LVDC_DotM_act", DotM_act);
		papiReadScenario_vec(line, "LVDC_DotM_last", DotM_last);
		papiReadScenario_vec(line, "LVDC_DotS", DotS);
		papiReadScenario_vec(line, "LVDC_DotXEZ", DotXEZ);
		papiReadScenario_vec(line, "LVDC_PCommandedAttitude", PCommandedAttitude);
		papiReadScenario_vec(line, "LVDC_Pos4", Pos4);
		papiReadScenario_vec(line, "LVDC_PosS", PosS);
		papiReadScenario_vec(line, "LVDC_PosXEZ", PosXEZ);
		papiReadScenario_vec(line, "LVDC_TargetVector", TargetVector);
		papiReadScenario_vec(line, "LVDC_WV", WV);
		papiReadScenario_vec(line, "LVDC_XLunarAttitude", XLunarAttitude);

		// MATRIX3
		papiReadScenario_mat(line, "LVDC_MX_A", MX_A);
		papiReadScenario_mat(line, "LVDC_MX_B", MX_B);
		papiReadScenario_mat(line, "LVDC_MX_G", MX_G);
		papiReadScenario_mat(line, "LVDC_MX_K", MX_K);
		papiReadScenario_mat(line, "LVDC_MX_phi_T", MX_phi_T);
		// Done
	}
	if(oapiReadScenario_nextline (scn, line)){
		if (!strnicmp(line, LVIMU_START_STRING, sizeof(LVIMU_START_STRING))) {
			lvimu.LoadState(scn);
		}
	}
	return;
}

void LVDC::TimeStep(double simt, double simdt) {
	if(owner == NULL){ return; }
	if (owner->stage < PRELAUNCH_STAGE) { return; }
	// Is the LVDC running?
	if(LVDC_Stop == 0){
		// Update timebase ET
		LVDC_TB_ETime += simdt;	

		// Note that GenericTimestep will update MissionTime.

		//Switch Check, TBD: Integrate with old CSM to IU Connector
		INH = owner->TLIEnableSwitch.GetState() == TOGGLESWITCH_DOWN;
		
		//Reset Direct Staging switch for S-IVB shutdown
		if (directstageint && !directstagereset && owner->SIISIVBSepSwitch.GetState() == TOGGLESWITCH_DOWN)
		{
			directstagereset = true;
		}

		/* **** LVDC GUIDANCE PROGRAM **** */		
		switch(LVDC_Timebase){//this is the sequential event control logic
			case -1: // LOOP WAITING FOR PTL
				// Limit time accel to 100x
				if(oapiGetTimeAcceleration() > 100){ oapiSetTimeAcceleration(100); } 

				// Prelaunch tank venting between -3:00h and engine ignition
				// No clue if the venting start time is correct
				if(owner->MissionTime < -10800){
					owner->SwitchSelector(10);
				}else{
					owner->SwitchSelector(11);
				}

				// BEFORE PTL COMMAND (T-00:20:00) STOPS HERE
				if(owner->MissionTime < -1200){
					double Source  = fabs(owner->MissionTime);
					double Minutes = Source/60;
					double Hours   = (int)Minutes/60;				
					double Seconds = Source - ((int)Minutes*60);
					Minutes       -= Hours*60;
					sprintf(oapiDebugString(),"LVDC: T - %d:%d:%f | AWAITING PTL INTERRUPT",(int)Hours,(int)Minutes,Seconds);
					lvimu.ZeroIMUCDUFlag = true;					// Zero IMU CDUs
					break;
				}
		
				// Engine lights on at T-00:04:10
				if (owner->MissionTime >= -250 && LVDC_EI_On == false) { LVDC_EI_On = true; }

				// Between PTL signal and GRR, we monitor the IMU for any failure signals and do vehicle self-tests.
				// At GRR we transfer control to the flight program and start TB0.

				// BEFORE GRR (T-00:00:17) STOPS HERE
				if (owner->MissionTime < -17){
					sprintf(oapiDebugString(),"LVDC: T %f | IMU XYZ %f %f %f PIPA %f %f %f | TV %f | AWAITING GRR",owner->MissionTime,
						lvimu.CDURegisters[LVRegCDUX],lvimu.CDURegisters[LVRegCDUY],lvimu.CDURegisters[LVRegCDUZ],
						lvimu.CDURegisters[LVRegPIPAX],lvimu.CDURegisters[LVRegPIPAY],lvimu.CDURegisters[LVRegPIPAZ],atan((double)45));
					break;
				}else{
					LVDC_Timebase = 0;
					LVDC_TB_ETime = 0;
					break;
				}			

			case 0: 
				if(LVDC_GRR == false){		
					BOOST = true;
					LVDC_GRR = true;								// Mark event
					poweredflight = true;
					oapiSetTimeAcceleration (1);					// Set time acceleration to 1
					owner->SwitchSelector(12);
				}

				// At 10 seconds, play the countdown sound.
				if (owner->MissionTime >= -10.3) { // Was -10.9
					owner->SwitchSelector(13);
				}
				// Shut down venting at T - 9
				if(owner->MissionTime > -9 && owner->prelaunchvent[0] != NULL) { owner->SwitchSelector(14); }

				// SATURN V ENGINE STARTUP
				// Engine startup was staggered 1-2-2, with engine 5 starting first, then 1+3, then 2+4. 
				// This happened by the starter solenoid operating at T-6.585 for engine 5.

				// Engine 5 combustion chamber ignition was at T-3.315, engines 1+3 at T-3.035, and engines 2+4 at T-2.615
				// The engines idled in low-range thrust (about 2.5% thrust) for about 0.3 seconds
				// and then rose to 93% thrust in 0.85 seconds.
				// The rise from 93 to 100 percent thrust took 0.75 second.
				// Total engine startup time was 1.9 seconds.

				// Source: Apollo 8 LV Flight Evaluation

				// Transition from seperate throttles to single throttle
				if(owner->MissionTime < -0.715){ 
					int x=0; // Start Sequence Index
					double tm_1,tm_2,tm_3,tm_4; // CC light, 1st rise start, and 2nd rise start, and 100% thrust times.
					double SumThrust=0;
					double thrst[3];	// Thrust Settings for 1-2-2 start (see below)
					while(x < 3){
						thrst[x] = 0;
						switch(x){
							case 0: // Engine 5
								tm_1 = -3.315; 
								break;
							case 1: // Engine 1+3
								tm_1 = -3.035; 
								break;
							case 2: // Engine 2+4
								tm_1 = -2.615; 
								break;
						}
						tm_2 = tm_1 + 0.3;  // Start of 1st rise
						tm_3 = tm_2 + 0.85; // Start of 2nd rise
						tm_4 = tm_3 + 0.75; // End of 2nd rise
						if(owner->MissionTime >= tm_1){
							// Light CC
							if(owner->MissionTime < tm_2){
								// Idle at 2.5% thrust
								thrst[x] = 0.025;
							}else{
								if(owner->MissionTime < tm_3){
									// Rise to 93% at a rate of 106 percent per second
									thrst[x] = 0.025+(1.06*(owner->MissionTime-tm_2));
								}else{
									if(owner->MissionTime < tm_4){
										// Rise to 100% at a rate of 9 percent per second.
										thrst[x] = 0.93+(0.09*(owner->MissionTime-tm_3));
									}else{
										// Hold 100%
										thrst[x] = 1;
									}
								}
							}
						}
						x++; // Do next
					}
					SumThrust = thrst[0]+(thrst[1]*2)+(thrst[2]*2);
	//				sprintf(oapiDebugString(),"LVDC: T %f | TB0 + %f | TH 0/1/2 = %f %f %f Sum %f",
	//					MissionTime,LVDC_TB_ETime,thrst[0],thrst[1],thrst[2],SumThrust);
					if(SumThrust > 0){
						owner->SetThrusterLevel(owner->th_main[2],thrst[1]); // Engine 1
						owner->SetThrusterLevel(owner->th_main[1],thrst[2]); // Engine 2
						owner->SetThrusterLevel(owner->th_main[3],thrst[1]); // Engine 3
						owner->SetThrusterLevel(owner->th_main[0],thrst[2]); // Engine 4
						owner->SetThrusterLevel(owner->th_main[4],thrst[0]); // Engine 5

						owner->contrailLevel = SumThrust/5;
						owner->AddForce(_V(0, 0, -10. * owner->THRUST_FIRST_VAC), _V(0, 0, 0)); // Maintain hold-down lock
					}
				}else{
					// Get 100% thrust on all engines.
					owner->SetThrusterGroupLevel(owner->thg_main,1);
					owner->contrailLevel = 1;				
					owner->AddForce(_V(0, 0, -10. * owner->THRUST_FIRST_VAC), _V(0, 0, 0));
				}

				// LIFTOFF
				if(owner->MissionTime >= 0){
					TB1 = TAS;//-simdt;
					LVDC_Timebase = 1;
					LVDC_TB_ETime = 0;
					break;
				}
				break;

			case 1: // LIFTOFF TIME
				if(liftoff == false){
					liftoff = true;
					owner->SwitchSelector(15);
					// Fall into TB1
					sinceLastCycle = 1.7-simdt; // Rig to pass on fall-in
				}

				// Soft-Release Pin Dragging
				if(owner->MissionTime < 0.5){
				  double PinDragFactor = 1 - (owner->MissionTime*2);
				  owner->AddForce(_V(0, 0, -(owner->THRUST_FIRST_VAC * PinDragFactor)), _V(0, 0, 0));
				}

				// S1C CECO TRIGGER:
				// I have multiple conflicting leads as to the CECO trigger.
				// One says it happens at 4G acceleration and another says it happens by a timer at T+135.5			
				if(owner->MissionTime > 125.9){ 
					// Apollo 11
					owner->SwitchSelector(16);
					S1_Engine_Out = true;
					// Begin timebase 2
					TB2 = TAS;//-simdt;
					LVDC_Timebase = 2;
					LVDC_TB_ETime = 0;
					break;
				}
				break;

			case 2:
				// S1B/C OECO TRIGGER
				// Done by low-level sensor.
				// Apollo 8 cut off at 32877, Apollo 11 cut off at 31995.
				if (owner->stage == LAUNCH_STAGE_ONE && owner->GetFuelMass() <= 0){
					// For S1B/C thruster calibration
					fprintf(lvlog,"[T+%f] S1 OECO - Thrust %f N @ Alt %f\r\n\r\n",owner->MissionTime,owner->GetThrusterMax(owner->th_main[0]),owner->GetAltitude());
					owner->SwitchSelector(17);
					// Set timer
					S1_Sep_Time = owner->MissionTime;
					// Begin timebase 3
					TB3 = TAS;//-simdt;
					LVDC_Timebase = 3;
					LVDC_TB_ETime = 0;
				}
				break;

			case 3:
				// S1B/C SEPARATION TRIGGER
				if(owner->stage == LAUNCH_STAGE_ONE  && LVDC_TB_ETime >= 0.5){
					owner->SwitchSelector(18);					
					S2_Startup = false;
				}

				// S2 ENGINE STARTUP
				if(owner->stage == LAUNCH_STAGE_TWO  && LVDC_TB_ETime >= 2.4 && LVDC_TB_ETime < 4.4){
					S2_Startup = true;
					owner->SwitchSelector(19);
					owner->SetThrusterGroupLevel(owner->thg_main, ((LVDC_TB_ETime-2.4)*0.45));
				}
				if(owner->stage == LAUNCH_STAGE_TWO  && LVDC_TB_ETime >= 5 && S2_IGNITION == false){
					owner->SwitchSelector(20);
					S2_IGNITION = true;
					S1_Sep_Time = 0; // All done
				}

				// Drop Interstage Ring
				if(owner->stage == LAUNCH_STAGE_TWO  && LVDC_TB_ETime >= 30.7 && owner->SIISepState == true){
					owner->SwitchSelector(21);
					owner->SIISepState = false;
				}

				// And jettison LET
				if(owner->stage == LAUNCH_STAGE_TWO_ISTG_JET  && LVDC_TB_ETime > dt_LET && owner->LESAttached){
					T_LET = LVDC_TB_ETime;	// Update this. If the LET jettison never happens, the placeholder value
											// will start IGM anyway.
					owner->SwitchSelector(22);					
				}		

				// IECO
				/*if (LVDC_TB_ETime >= 30.7)
				{
					if (oapiGetPropellantMass(owner->ph_2nd) / oapiGetPropellantMaxMass(owner->ph_2nd) < 0.15 && S2_ENGINE_OUT == false && owner->GetApolloNo() >= 10)
					{
						S2_ENGINE_OUT = true;
						owner->SwitchSelector(24);
					}
				}*/
			
				// MR Shift
				if(LVDC_TB_ETime > 284.4 && owner->stage == LAUNCH_STAGE_TWO_ISTG_JET && MRS == false){
					fprintf(lvlog,"[TB%d+%f] MR Shift\r\n",LVDC_Timebase,LVDC_TB_ETime);
					// sprintf(oapiDebugString(),"LVDC: EMR SHIFT"); LVDC_GP_PC = 30; break;
					owner->SwitchSelector(23);
					MRS = true;
				}

				// After MRS, check for S2 OECO (was allowed to happen by itself)
				if(MRS == true){
					double oetl = owner->GetThrusterLevel(owner->th_main[0])+owner->GetThrusterLevel(owner->th_main[1])+owner->GetThrusterLevel(owner->th_main[2])+owner->GetThrusterLevel(owner->th_main[3]);
					if(oetl == 0){
						fprintf(lvlog,"[MT %f] TB4 Start\r\n",simt);
						// S2 OECO, start TB4
						owner->SetThrusterGroupLevel(owner->thg_main, 0);
						S2_BURNOUT = true;
						MRS = false;
						TB4 = TAS;//-simdt;
						LVDC_Timebase = 4;
						LVDC_TB_ETime = 0;					
					}
				}
				
				if (LVDC_TB_ETime >= 1.4 && owner->SIISIVBSepSwitch.GetState())
				{
					owner->stage = LAUNCH_STAGE_TWO_ISTG_JET;
					directstageint = true;
					directstagereset = false;
					owner->SetThrusterGroupLevel(owner->thg_main, 0);
					S2_BURNOUT = true;
					MRS = false;
					TB4A = TAS;
					LVDC_Timebase = 40;
					LVDC_TB_ETime = 0;
				}
				break;

			case 4:
			case 40:
				// S2 STAGE SEP
				if (LVDC_TB_ETime > 0.8 && owner->stage <= LAUNCH_STAGE_TWO_ISTG_JET) {
					// S2ShutS.done(); No CECO on AP8
					fprintf(lvlog,"[%d+%f] S2/S4B STAGING\r\n",LVDC_Timebase,LVDC_TB_ETime);
					owner->SPUShiftS.done(); // Make sure it's done
					owner->ClearEngineIndicators();
					owner->SeparateStage(LAUNCH_STAGE_SIVB);
					owner->SetStage(LAUNCH_STAGE_SIVB);
					owner->AddRCS_S4B();
					owner->SetSIVBThrusters(true);
					owner->SetThrusterGroupLevel(owner->thg_ver,1.0);
					owner->SetThrusterResource(owner->th_main[0], owner->ph_3rd);
					owner->SwitchSelector(5);					
				}
			
				if(LVDC_TB_ETime >= 4 && LVDC_TB_ETime < 6.8 && owner->stage == LAUNCH_STAGE_SIVB){
					owner->SetThrusterGroupLevel(owner->thg_main, ((LVDC_TB_ETime-4)*0.36));
				}
				if(LVDC_TB_ETime >= 8.6 && S4B_IGN == false && owner->stage == LAUNCH_STAGE_SIVB){
					owner->SetThrusterGroupLevel(owner->thg_main, 1.0);
					owner->SetThrusterGroupLevel(owner->thg_ver, 0.0);
					S4B_IGN=true;
				}

				//Manual S-IVB Shutdown
				if (S4B_IGN == true && ((owner->SIISIVBSepSwitch.GetState() == TOGGLESWITCH_UP && directstagereset) || owner->GetThrusterLevel(owner->th_main[0]) == 0))
				{
					S4B_IGN = false;
					TB5 = TAS;//-simdt;
					LVDC_Timebase = 5;
					LVDC_TB_ETime = 0;
					fprintf(lvlog, "SIVB CUTOFF! TAS = %f \r\n", TAS);
				}

				// CSM/LV separation
				if (owner->CSMLVPyros.Blown()) {
					owner->SeparateStage(CSM_LEM_STAGE);
					owner->SetStage(CSM_LEM_STAGE);
					LVDC_EI_On = false;
					//LVDC_Stop = true;
					//return; // Stop here
				}
				break;
			case 5:
				// TB5 timed events
				// Cutoff transient thrust
				if(LVDC_TB_ETime < 2){
					if(LVDC_TB_ETime < 0.25){
						// 95% of thrust dies in the first .25 second
						owner->SetThrusterLevel(owner->th_main[0], 1-(LVDC_TB_ETime*3.3048));
					}else{
						if(LVDC_TB_ETime < 1.5){
							// The remainder dies over the next 1.25 second
							owner->SetThrusterLevel(owner->th_main[0], 0.1738-((LVDC_TB_ETime-0.25)*0.1390));
						}else{
							// Engine is completely shut down at 1.5 second
							owner->SetThrusterLevel(owner->th_main[0], 0);
						}
					}
					fprintf(lvlog,"S4B CUTOFF: Time %f Thrust %f\r\n",LVDC_TB_ETime,owner->GetThrusterLevel(owner->th_main[0]));
				}

				if (LVDC_TB_ETime >= 10 && LVDC_EI_On == true){
					owner->SetStage(STAGE_ORBIT_SIVB);
					LVDC_EI_On = false;
				}
				if(LVDC_TB_ETime < 87 && owner->GetThrusterGroupLevel(owner->thg_ver) < 1){//ullage thrust on
					owner->SetThrusterGroupLevel(owner->thg_ver, 1);
				}
				if(LVDC_TB_ETime >= 87 && owner->GetThrusterGroupLevel(owner->thg_ver) > 0){//ullage thrust off
					owner->SetThrusterGroupLevel(owner->thg_ver, 0);
				}
				if(LVDC_TB_ETime > 100){
					//powered flight nav off
					poweredflight = false;
				}

				// Fuel boiloff every ten seconds.
				if (owner->MissionTime >= owner->NextMissionEventTime) {
					if (owner->GetThrusterLevel(owner->th_main[0]) < 0.5) {
						owner->SIVBBoiloff();
					}
					owner->NextMissionEventTime = owner->MissionTime + 10.0;
				}
				// CSM/LV separation
				if (owner->CSMLVPyros.Blown()) {
					owner->SeparateStage(CSM_LEM_STAGE);
					owner->SetStage(CSM_LEM_STAGE);
					LVDC_EI_On = false;
					//LVDC_Stop = true;
					//return; // Stop here
				}
				break;
			case 6:
				//TB6 timed events
				if (poweredflight == false)
				{poweredflight = true;}

				// SII SEP light
				if (S4B_REIGN == false && owner->SIISepState == false && LVDC_TB_ETime < 38.0)
				{
					owner->SetSIISep();	//Set SII SEP light to notify crew of TB6 start
					owner->TLI_Begun();
				}
				if(LVDC_TB_ETime>=38 && LVDC_TB_ETime < 493.6 && S4B_REIGN==false && owner->SIISepState == true)
				{owner->ClearSIISep();} //This would signal the crew to start their event timer at 51:00, counting up
				if (LVDC_TB_ETime >= 493.6 && LVDC_TB_ETime < 560.0 && owner->SIISepState == false)
				{owner->SetSIISep();}
				if (LVDC_TB_ETime >= 560.0 && owner->SIISepState == true)
				{owner->ClearSIISep();}

				//Ullage
				if(LVDC_TB_ETime>=496.3 && S4B_REIGN == false)
				{owner->SetThrusterGroupLevel(owner->thg_ver,1);} //Ullage thrust starts
				if(LVDC_TB_ETime >= 573 && S4B_REIGN == false)
				{owner->SetThrusterGroupLevel(owner->thg_ver, 0);}//Ullage thrust ends
				if(LVDC_TB_ETime>= T_RG - 1.0 && S4B_REIGN == false && LVDC_EI_On == false)
				{
					LVDC_EI_On = true;	//Engine start notification at T-0:01
					owner->SetThrusterResource(owner->th_main[0], owner->ph_3rd);
					owner->SwitchSelector(6);
				}	
				if (LVDC_TB_ETime >= T_RG && S4B_REIGN == false) {
					owner->SetThrusterGroupLevel(owner->thg_main, ((LVDC_TB_ETime - 578.6)*0.53)); //Engine ignites at MR 4.5 and throttles up
					fprintf(lvlog, "S4B IGNITION: Time %f Thrust %f\r\n", LVDC_TB_ETime, owner->GetThrusterLevel(owner->th_main[0]));
				}
				if(LVDC_TB_ETime>=580.3 && S4B_REIGN==false)
				{
					S4B_REIGN = true;
					owner->SetThrusterGroupLevel(owner->thg_main, 1);
				}
				if (LVDC_TB_ETime >= T_IGM + 10.0 && MRS == false)
				{
					owner->SwitchSelector(7);//Final MRS
					MRS = true;
				}

				//Manual S-IVB Shutdown
				if (S4B_REIGN == true && ((owner->SIISIVBSepSwitch.GetState() == TOGGLESWITCH_UP && directstagereset) || owner->GetThrusterLevel(owner->th_main[0]) == 0))
				{
					S4B_REIGN = false;
					TB7 = TAS;//-simdt;
					LVDC_Timebase = 7;
					LVDC_TB_ETime = 0;
					fprintf(lvlog, "SIVB CUTOFF! TAS = %f \r\n", TAS);
					owner->TLI_Ended();
				}
				break;
			case 7:
				// TB7 timed events
				// Cutoff transient thrust
				if (LVDC_TB_ETime < 2) {
					if (LVDC_TB_ETime < 0.25) {
						// 95% of thrust dies in the first .25 second
						owner->SetThrusterLevel(owner->th_main[0], 1 - (LVDC_TB_ETime*3.3048));
					}
					else {
						if (LVDC_TB_ETime < 1.5) {
							// The remainder dies over the next 1.25 second
							owner->SetThrusterLevel(owner->th_main[0], 0.1738 - ((LVDC_TB_ETime - 0.25)*0.1390));
						}
						else {
							// Engine is completely shut down at 1.5 second
							owner->SetThrusterLevel(owner->th_main[0], 0);
						}
					}
					fprintf(lvlog, "S4B CUTOFF: Time %f Thrust %f\r\n", LVDC_TB_ETime, owner->GetThrusterLevel(owner->th_main[0]));
				}
				if (LVDC_TB_ETime >= 10 && LVDC_EI_On == true) {
					LVDC_EI_On = false;
				}

				if (LVDC_TB_ETime > 20 && poweredflight) {
					//powered flight nav off
					poweredflight = false;
				}
				// CSM/LV separation
				if (owner->CSMLVPyros.Blown()) 
				{
					owner->SeparateStage(CSM_LEM_STAGE);
					owner->SetStage(CSM_LEM_STAGE);
					LVDC_EI_On = false;
				}
				break;
		}
		lvimu.Timestep(simt);								// Give a timestep to the LV IMU
		lvrg.Timestep(simdt);								// and RG
		CurrentAttitude = lvimu.GetTotalAttitude();			// Get current attitude	
		AttRate = lvrg.GetRates();							// Get rates	
		//This is the actual LVDC code & logic; has to be independent from any of the above events
		if(LVDC_GRR && init == false)
		{
			fprintf(lvlog,"[T%f] GRR received!\r\n",owner->MissionTime);

			// Initial Position & Velocity from Apollo 9 operational trajectory
			/*PosS.x = 6373324.5;
			PosS.y = 19255.8;
			PosS.z = 1174.4;*/
			/*DotM_act.x = -0.451;
			DotM_act.y = 125.646;
			DotM_act.z = 388.841;*/
			PosS.x = 6373418.5;
			PosS.y = 0;
			PosS.z = 0;
			/*DotS.x = 0;
			DotS.y = 126.08;
			DotS.z = 388.03;*/

			// Ground launch targeting

			double day = 0.0;
			T_L = modf(oapiGetSimMJD(),&day)*24.0*3600.0;
			t_D = T_L - T_LO;
			//t_D = TABLE15.target[tgt_index].t_D;

			fprintf(lvlog, "Time into launch window = %f\r\n", t_D);

			//Azimuth determination
			if (t_DS0 <= t_D && t_D < t_DS1)
			{
				Azimuth = hx[0][0] + hx[0][1]*((t_D - t_D1) / t_SD1) + hx[0][2]*pow((t_D - t_D1) / t_SD1, 2) + hx[0][3]*pow((t_D - t_D1) / t_SD1, 3) + hx[0][4]*pow((t_D - t_D1) / t_SD1, 4);
			}
			else if (t_DS1 <= t_D && t_D < t_DS2)
			{
				Azimuth = hx[1][0] + hx[1][1]*((t_D - t_D2) / t_SD2) + hx[1][2]*pow((t_D - t_D2) / t_SD2, 2) + hx[1][3]*pow((t_D - t_D2) / t_SD2, 3) + hx[1][4]*pow((t_D - t_D2) / t_SD2, 4);
			}
			else
			{
				Azimuth = hx[2][0] + hx[2][1]*((t_D - t_D3) / t_SD3) + hx[2][2]*pow((t_D - t_D1) / t_SD3, 2) + hx[2][3]*pow((t_D - t_D3) / t_SD3, 3) + hx[2][4]*pow((t_D - t_D3) / t_SD3, 4);
			}

			if (i_op)
			{
				Inclination = fx[0] + fx[1]*(Azimuth - Azo) / Azs + fx[2]*pow((Azimuth - Azo) / Azs, 2) + fx[3]*pow((Azimuth - Azo) / Azs, 3)
					+ fx[4]*pow((Azimuth - Azo) / Azs, 4) + fx[5]*pow((Azimuth - Azo) / Azs, 5) + fx[6]*pow((Azimuth - Azo) / Azs, 6);
			}
			else
			{
				Inclination = fxt[0] + fxt[1]*(t_D - t_D0) / t_S + fxt[2]*pow((t_D - t_D0) / t_S, 2) + fxt[3]*pow((t_D - t_D0) / t_S, 3)
					+ fxt[4]*pow((t_D - t_D0) / t_S, 4) + fxt[5]*pow((t_D - t_D0) / t_S, 5) + fxt[6]*pow((t_D - t_D0) / t_S, 6);
			}

			if (theta_N_op)
			{
				theta_N = gx[0] + gx[1]*(Azimuth - Azo) / Azs + gx[2]*pow((Azimuth - Azo) / Azs, 2) + gx[3]*pow((Azimuth - Azo) / Azs, 3)
					+ gx[4]*pow((Azimuth - Azo) / Azs, 4) + gx[5]*pow((Azimuth - Azo) / Azs, 5) + gx[6]*pow((Azimuth - Azo) / Azs, 6);
			}
			else
			{
				theta_N = gxt[0] + gxt[1]*(t_D - t_D0) / t_S + gxt[2]*pow((t_D - t_D0) / t_S, 2) + gxt[3]*pow((t_D - t_D0) / t_S, 3)
					+ gxt[4]*pow((t_D - t_D0) / t_S, 4) + gxt[5]*pow((t_D - t_D0) / t_S, 5) + gxt[6]*pow((t_D - t_D0) / t_S, 6);
			}

			// preset to fixed value to be independent from any external stuff
			// Azimuth = 72.124;
			fprintf(lvlog,"Azimuth = %f\r\n",Azimuth);

			// Let's cheat a little. (Apollo 8)
			//Inclination = 32.5031;
			fprintf(lvlog,"Inclination = %f\r\n",Inclination);

			// Cheat a little more. (Apollo 8)
			// DescNodeAngle = 123.004; 
			fprintf(lvlog,"DescNodeAngle = %f\r\n", theta_N);

			// Need to make those into radians
			Azimuth *= RAD;
			Inclination *= RAD;
			theta_N *= RAD;

			fprintf(lvlog,"Rad Convert: Az / Inc / DNA = %f %f %f\r\n",Azimuth,Inclination, theta_N);

			if (TerminalConditions == false)
			{
				if (Direct_Ascent) {
					C_3 = TABLE15[0].target[0].C_3;
					e = TABLE15[0].target[0].e_N;
					f = TABLE15[0].f;
					alpha_D = TABLE15[0].target[0].alpha_D;
					eps_3 = 0;
					sprintf(oapiDebugString(), "LVDC: DIRECT-ASCENT"); // STOP
				}

				// p is the semi-latus rectum of the desired terminal ellipse.
				p = (mu / C_3)*(pow(e, 2) - 1);
				fprintf(lvlog, "p = %f, mu = %f, e2 = %f, mu/C_3 = %f\r\n", p, mu, pow(e, 2), mu / C_3);

				// K_5 is the IGM terminal velocity constant
				K_5 = sqrt(mu / p);
				fprintf(lvlog, "K_5 = %f\r\n", K_5);

				R_T = p / (1 + e*cos(f));
				V_T = K_5*sqrt((1 + 2 * e*cos(f) + pow(e, 2)));
				gamma_T = atan2((e*(sin(f))), (1 + (e*(cos(f)))));
				G_T = -mu / pow(R_T, 2);
			}
			fprintf(lvlog,"R_T = %f (Expecting 6,563,366), V_T = %f (Expecting 7793.0429), gamma_T = %f\r\n",R_T,V_T,gamma_T);

			// G MATRIX CALCULATION
			MX_A.m11 = cos(phi_L);  MX_A.m12 = sin(phi_L)*sin(Azimuth); MX_A.m13 = -(sin(phi_L)*cos(Azimuth));
			MX_A.m21 = -sin(phi_L); MX_A.m22 = cos(phi_L)*sin(Azimuth); MX_A.m23 = -(cos(phi_L)*cos(Azimuth));
			MX_A.m31 = 0;  MX_A.m32 = cos(Azimuth);  MX_A.m33 = sin(Azimuth);

			MX_B.m11 = cos(theta_N); MX_B.m12 = 0; MX_B.m13 = sin(theta_N);
			MX_B.m21 = sin(theta_N)*sin(Inclination); MX_B.m22 = cos(Inclination); MX_B.m23 = -cos(theta_N)*sin(Inclination);
			MX_B.m31 = -sin(theta_N)*cos(Inclination); MX_B.m32 = sin(Inclination);MX_B.m33 = cos(theta_N)*cos(Inclination);

			MX_G = mul(MX_B,MX_A); // Matrix Multiply

			VECTOR3 U_Z = _V(0.0, -1.0, 0.0);
			U_Z = tmul(MX_A, U_Z);
			DotS = crossp(U_Z*omega_E, PosS);

			fprintf(lvlog, "Initial Velocity = %f %f %f\r\n", DotS.x, DotS.y, DotS.z);
		
			Y_u= -(PosS.x*MX_A.m21+PosS.y*MX_A.m22+PosS.z*MX_A.m23); //position component south of equator
			R = pow(pow(PosS.x,2)+pow(PosS.y,2)+pow(PosS.z,2),0.5); //instantaneous distance from earth's center
			S = (-mu/pow(R,3))*(1+J*pow(a/R,2)*(1-5*pow(Y_u/R,2)));
			P = (-mu/pow(R,2))*pow(a/R,2) *((2*J*Y_u)/R);
			ddotG_last.x = PosS.x*S-MX_A.m21*P; //gravity acceleration vector
			ddotG_last.y = PosS.y*S-MX_A.m22*P;
			ddotG_last.z = PosS.z*S-MX_A.m23*P;
			DotG_last = DotS;
			PCommandedAttitude.x = (1.5* PI) + Azimuth;
			PCommandedAttitude.y = 0;
			PCommandedAttitude.z = 0;

			lvimu.ZeroIMUCDUFlag = false;					// Release IMU CDUs
			lvimu.DriveGimbals(Azimuth - PI05, 0, 0);		// Now bring to alignment 
			lvimu.SetCaged(false);							// Release IMU
			CountPIPA = true;								// Enable PIPA storage	

			lvimu.ZeroPIPACounters();
			sinceLastCycle = 0;
			init = true;
			fprintf(lvlog, "Initialization completed.\r\n\r\n");
			goto minorloop;
		}
		// various clocks the LVDC needs...
		/*if (TB7 > -100000){
			TB7 += simdt;
		}else{
			//timebases
			if (TB6 > -100000){
				TB6 += simdt;
			}else{
				if (TB5 > -100000){
					TB5 += simdt;
				}else{
					if (TB4 > -100000){
						TB4 += simdt;
					}else{
						if (TB3 > -100000){
							TB3 += simdt;
						}else{
							if (TB2 > -100000){
								TB2 += simdt;
							}else{
								if (TB1 > -100000){
									TB1 += simdt; 
								}
							}
						}
					}
				}
			}
		}*/
		if(LVDC_GRR == true){TAS += simdt;} //time since GRR
		if(liftoff == true){t_clock += simdt;} //time since liftoff
		if(S2_IGNITION == true && t_21 == 0){t_21 = t_clock;} //I hope this is the right way to determine t_21; the boeing doc is silent on that
		
		//Major loop(s)
		if(LVDC_GRR == true){
			if (poweredflight == true)
			{
				//powered flight nav
				sinceLastCycle += simdt;
				if (sinceLastCycle < 1.7)
				{ goto minorloop; }
				dt_c = sinceLastCycle;
				sinceLastCycle = 0;
				IGMCycle++;				// For debugging
				fprintf(lvlog, "[%d+%f] *** Major Loop (powered) %d ***\r\n", LVDC_Timebase, LVDC_TB_ETime, IGMCycle);
				//read the PIPA CDUs
				DotM_act.x += (lvimu.CDURegisters[LVRegPIPAX]);
				DotM_act.y += (lvimu.CDURegisters[LVRegPIPAY]);
				DotM_act.z += (lvimu.CDURegisters[LVRegPIPAZ]);
				Fm = pow((pow(((DotM_act.x - DotM_last.x) / dt_c), 2) + pow(((DotM_act.y - DotM_last.y) / dt_c), 2) + pow(((DotM_act.z - DotM_last.z) / dt_c), 2)), 0.5);
				PosS = PosS + (DotM_act + DotM_last) * dt_c / 2.0 + (DotG_last + ddotG_last * dt_c / 2.0)*dt_c; //position vector
				Y_u = -(PosS.x*MX_A.m21 + PosS.y*MX_A.m22 + PosS.z*MX_A.m23); //position component south of equator
				R = length(PosS); //instantaneous distance from earth's center
				S = (-mu / pow(R, 3))*(1.0 + J*pow(a / R, 2)*(1.0 - 5.0 * pow(Y_u / R, 2)));
				P = (-mu / pow(R, 2))*pow(a / R, 2) *(2.0 * J*Y_u / R);
				ddotG_act.x = PosS.x*S - MX_A.m21*P; //gravity acceleration vector
				ddotG_act.y = PosS.y*S - MX_A.m22*P;
				ddotG_act.z = PosS.z*S - MX_A.m23*P;
				CG = pow((pow(ddotG_act.x, 2) + pow(ddotG_act.y, 2) + pow(ddotG_act.z, 2)), 0.5);
				DotG_act = DotG_last + (ddotG_act + ddotG_last)*dt_c / 2.0; //gravity velocity vector
				DotS = DotM_act + DotG_act; //total velocity vector
				V = length(DotS);
				//save the 'actual' variables as 'last' variables for the next step
				DotM_last = DotM_act;
				DotG_last = DotG_act;
				ddotG_last = ddotG_act;

				ddotM_act = ddotG_last; //For orbital nav initialization

				fprintf(lvlog, "Powered Navigation \r\n");
				fprintf(lvlog, "Inertial Attitude: %f %f %f \r\n", CurrentAttitude.x*DEG, CurrentAttitude.y*DEG, CurrentAttitude.z*DEG);
				fprintf(lvlog, "DotM: %f %f %f \r\n", DotM_act.x, DotM_act.y, DotM_act.z);
				fprintf(lvlog, "Accelerometer readings: %f %f %f\r\n",lvimu.CDURegisters[LVRegPIPAX], lvimu.CDURegisters[LVRegPIPAY], lvimu.CDURegisters[LVRegPIPAZ]);
				fprintf(lvlog, "Gravity velocity: %f %f %f \r\n", DotG_act.x, DotG_act.y, DotG_act.z);
				fprintf(lvlog, "EarthRel Position: %f %f %f \r\n", PosS.x, PosS.y, PosS.z);
				fprintf(lvlog, "SV Accuracy: %f \r\n", SVCompare());
				fprintf(lvlog, "EarthRel Velocity: %f %f %f \r\n", DotS.x, DotS.y, DotS.z);
				fprintf(lvlog, "Sensed Acceleration: %f \r\n", Fm);
				fprintf(lvlog, "Gravity Acceleration: %f \r\n", CG);
				fprintf(lvlog, "Total Velocity: %f \r\n", V);
				fprintf(lvlog, "Dist. from Earth's Center: %f \r\n", R);
				fprintf(lvlog, "S: %f \r\n", S);
				fprintf(lvlog, "P: %f \r\n", P);
				lvimu.ZeroPIPACounters();
			}
			else
			{
				//Orbital navigation
				sinceLastCycle += simdt;
				sinceLastGuidanceCycle += simdt;
				if (sinceLastGuidanceCycle>1.0)
				{
					dt_g = sinceLastGuidanceCycle;
					sinceLastGuidanceCycle = 0.0;
					goto GuidanceLoop;
				}
				if(sinceLastCycle<8.0)
				{goto minorloop;}
				dt_c = sinceLastCycle;
				sinceLastCycle = 0.0;
				OrbNavCycle++;		//For debugging
				fprintf(lvlog, "[%d+%f] *** Major Loop (orbital) %d ***\r\n", LVDC_Timebase, LVDC_TB_ETime, OrbNavCycle);
				//4-second intermediate integration
				PosS_4sec = PosS + DotS*dt_c / 2.0 + ddotM_act*dt_c*dt_c/8.0;
				DotS_4sec = DotS + ddotM_act*dt_c / 2.0;

				//Gravity (4sec)
				Y_u = -(PosS_4sec.x*MX_A.m21 + PosS_4sec.y*MX_A.m22 + PosS_4sec.z*MX_A.m23); //position component south of equator
				R = length(PosS_4sec); //instantaneous distance from earth's center
				S_34 = H*pow(a / R, 3)*(Y_u / R)*(3.0 - 7.0*pow(Y_u / R, 2)) + (D / 7.0)*pow(a / R, 4)*(3.0 - 42.0*pow(Y_u / R, 2) + 63.0*pow(Y_u / R, 4));
				S = (-mu / pow(R, 3))*(1.0 + J*pow(a / R, 2)*(1.0 - 5.0 * pow(Y_u / R, 2)) + S_34);
				P_34 = (H / 5.0)*pow(a / R, 2)*(15.0*Y_u / R - 3.0) + (D / 7.0)*pow(a / R, 2)*Y_u / R*(12.0 - 28.0*pow(Y_u / R, 2));
				P = (-mu / pow(R, 2))*pow(a / R, 2) *((2.0 * J*Y_u) / R + P_34);
				ddotG_act.x = PosS_4sec.x*S - MX_A.m21*P; //gravity acceleration vector
				ddotG_act.y = PosS_4sec.y*S - MX_A.m22*P;
				ddotG_act.z = PosS_4sec.z*S - MX_A.m23*P;

				//Drag (4sec)
				rho = Rho[0] + (R - a)*(Rho[1] + (R - a)*(Rho[2] + (R - a)*(Rho[3] + (R - a)*(Rho[4] + (R - a)*Rho[5]))));
				gamma = asin(dotp(PosS_4sec, DotS_4sec) / R / length(DotS_4sec));
				drag_area = Drag_Area[0] + Drag_Area[1] * gamma + Drag_Area[2] * pow(gamma, 2) + Drag_Area[3] * pow(gamma, 3) + Drag_Area[4] * pow(gamma, 4);
				DotS_R = _V(DotS_4sec.x + omega_E*(MX_A.m23*PosS_4sec.z - MX_A.m21*PosS_4sec.y), DotS_4sec.y + omega_E*(MX_A.m21*PosS_4sec.x - MX_A.m22*PosS_4sec.z), DotS_4sec.z + omega_E*(MX_A.m22*PosS_4sec.y - MX_A.m23*PosS_4sec.x));
				V_R = Mag(DotS_R);
				DDotS_D = -DotS_R*rho*drag_area*V_R / (2.0*owner->GetMass());

				DDotS_4sec = ddotG_act + DDotS_D;

				//8-second intermediate integration
				PosS_8secP = PosS + DotS*dt_c + DDotS_4sec*dt_c*dt_c/2.0;
				DotS_8secP = DotS_4sec + DDotS_4sec*dt_c;

				//Gravity (8sec intermediate)
				Y_u = -(PosS_8secP.x*MX_A.m21 + PosS_8secP.y*MX_A.m22 + PosS_8secP.z*MX_A.m23); //position component south of equator
				R = length(PosS_8secP); //instantaneous distance from earth's center
				S_34 = H*pow(a / R, 3)*(Y_u / R)*(3.0 - 7.0*pow(Y_u / R, 2)) + (D / 7.0)*pow(a / R, 4)*(3.0 - 42.0*pow(Y_u / R, 2) + 63.0*pow(Y_u / R, 4));
				S = (-mu / pow(R, 3))*(1.0 + J*pow(a / R, 2)*(1.0 - 5.0 * pow(Y_u / R, 2)) + S_34);
				P_34 = (H / 5.0)*pow(a / R, 2)*(15.0*Y_u / R - 3.0) + (D / 7.0)*pow(a / R, 2)*Y_u / R*(12.0 - 28.0*pow(Y_u / R, 2));
				P = (-mu / pow(R, 2))*pow(a / R, 2) *((2.0 * J*Y_u) / R + P_34);
				ddotG_act.x = PosS_8secP.x*S - MX_A.m21*P; //gravity acceleration vector
				ddotG_act.y = PosS_8secP.y*S - MX_A.m22*P;
				ddotG_act.z = PosS_8secP.z*S - MX_A.m23*P;

				//Drag (8sec intermediate)
				rho = Rho[0] + (R - a)*(Rho[1] + (R - a)*(Rho[2] + (R - a)*(Rho[3] + (R - a)*(Rho[4] + (R - a)*Rho[5]))));
				gamma = asin(dotp(PosS_8secP, DotS_8secP) / R / length(DotS_8secP));
				drag_area = Drag_Area[0] + Drag_Area[1] * gamma + Drag_Area[2] * pow(gamma, 2) + Drag_Area[3] * pow(gamma, 3) + Drag_Area[4] * pow(gamma, 4);
				DotS_R = _V(DotS_8secP.x + omega_E*(MX_A.m23*PosS_8secP.z - MX_A.m21*PosS_8secP.y), DotS_8secP.y + omega_E*(MX_A.m21*PosS_8secP.x - MX_A.m22*PosS_8secP.z), DotS_8secP.z + omega_E*(MX_A.m22*PosS_8secP.y - MX_A.m23*PosS_8secP.x));
				V_R = Mag(DotS_R);
				DDotS_D = -DotS_R*rho*drag_area*V_R / (2.0*owner->GetMass());

				DDotS_8secP = ddotG_act + DDotS_D;

				//8-second final integration
				PosS_8sec = PosS + DotS*dt_c + (ddotM_act + DDotS_4sec*2.0)*dt_c*dt_c / 6.0;
				DotS_8sec = DotS + (ddotM_act + DDotS_4sec*4.0 + DDotS_8secP)*dt_c / 6.0;

				//Gravity (8sec final)
				Y_u = -(PosS_8sec.x*MX_A.m21 + PosS_8sec.y*MX_A.m22 + PosS_8sec.z*MX_A.m23); //position component south of equator
				R = length(PosS_8sec); //instantaneous distance from earth's center
				S_34 = H*pow(a / R, 3)*(Y_u / R)*(3.0 - 7.0*pow(Y_u / R, 2)) + (D / 7.0)*pow(a / R, 4)*(3.0 - 42.0*pow(Y_u / R, 2) + 63.0*pow(Y_u / R, 4));
				S = (-mu / pow(R, 3))*(1.0 + J*pow(a / R, 2)*(1.0 - 5.0 * pow(Y_u / R, 2)) + S_34);
				P_34 = (H / 5.0)*pow(a / R, 2)*(15.0*Y_u / R - 3.0) + (D / 7.0)*pow(a / R, 2)*Y_u / R*(12.0 - 28.0*pow(Y_u / R, 2));
				P = (-mu / pow(R, 2))*pow(a / R, 2) *((2.0 * J*Y_u) / R + P_34);
				ddotG_act.x = PosS_8sec.x*S - MX_A.m21*P; //gravity acceleration vector
				ddotG_act.y = PosS_8sec.y*S - MX_A.m22*P;
				ddotG_act.z = PosS_8sec.z*S - MX_A.m23*P;

				//Drag (8sec final)
				rho = Rho[0] + (R - a)*(Rho[1] + (R - a)*(Rho[2] + (R - a)*(Rho[3] + (R - a)*(Rho[4] + (R - a)*Rho[5]))));
				gamma = asin(dotp(PosS_8sec, DotS_8sec) / R / length(DotS_8sec));
				drag_area = Drag_Area[0] + Drag_Area[1] * gamma + Drag_Area[2] * pow(gamma, 2) + Drag_Area[3] * pow(gamma, 3) + Drag_Area[4] * pow(gamma, 4);
				DotS_R = _V(DotS_8sec.x + omega_E*(MX_A.m23*PosS_8sec.z - MX_A.m21*PosS_8sec.y), DotS_8sec.y + omega_E*(MX_A.m21*PosS_8sec.x - MX_A.m22*PosS_8sec.z), DotS_8sec.z + omega_E*(MX_A.m22*PosS_8sec.y - MX_A.m23*PosS_8sec.x));
				V_R = Mag(DotS_R);
				DDotS_D = -DotS_R*rho*drag_area*V_R / (2.0*owner->GetMass());

				ddotM_act = ddotG_act + DDotS_D;
				// The messy RK3 having been done, we now commit the integrated position and velocity into platform data
				PosS = PosS_8sec;
				DotS = DotS_8sec;
				R = length(PosS);
				V = length(DotS);

				if (OrbNavCycle == 1) //State Vector update
				{
					VECTOR3 pos, vel;
					MATRIX3 mat;
					double day;
					modf(oapiGetSimMJD(), &day);
					mat = OrbMech::Orbiter2PACSS13(day + T_L / 24.0 / 3600.0, 28.6082888*RAD, -80.6041140*RAD, Azimuth);
					owner->GetRelativePos(owner->GetGravityRef(), pos);
					owner->GetRelativeVel(owner->GetGravityRef(), vel);
					PosS = mul(mat, pos);
					DotS = mul(mat, vel);
				}

				CG = pow((pow(ddotG_act.x, 2) + pow(ddotG_act.y, 2) + pow(ddotG_act.z, 2)), 0.5);
				R = pow(pow(PosS.x, 2) + pow(PosS.y, 2) + pow(PosS.z, 2), 0.5);
				V = pow(pow(DotS.x, 2) + pow(DotS.y, 2) + pow(DotS.z, 2), 0.5);

				ddotG_last = ddotM_act; //For powered nav initialization
				DotM_act = _V(0.0, 0.0, 0.0);
				DotM_last = _V(0.0, 0.0, 0.0);
				DotG_last = DotS;
				lvimu.ZeroPIPACounters();

				fprintf(lvlog, "Orbital Navigation \r\n");
				fprintf(lvlog, "Inertial Attitude: %f %f %f \r\n", CurrentAttitude.x*DEG, CurrentAttitude.y*DEG, CurrentAttitude.z*DEG);
				fprintf(lvlog, "DDotM: %f %f %f \r\n", ddotM_act.x, ddotM_act.y, ddotM_act.z);
				fprintf(lvlog, "EarthRel Position: %f %f %f \r\n", PosS.x, PosS.y, PosS.z);
				fprintf(lvlog, "SV Accuracy: %f \r\n", SVCompare());
				fprintf(lvlog, "EarthRel Velocity: %f %f %f \r\n", DotS.x, DotS.y, DotS.z);
				fprintf(lvlog, "Drag Acceleration: %f \r\n", length(DDotS_D));
				fprintf(lvlog, "Gravity Acceleration: %f \r\n", CG);
				fprintf(lvlog, "Total Velocity: %f \r\n", V);
				fprintf(lvlog, "Dist. from Earth's Center: %f \r\n", R);
				fprintf(lvlog, "S: %f \r\n", S);
				fprintf(lvlog, "P: %f \r\n", P);
			}
			
		}
GuidanceLoop:
		if(liftoff == false){//liftoff not received; initial roll command for FCC
			CommandedAttitude.x =  (1.5* PI) + Azimuth;
			CommandedAttitude.y =  0;
			CommandedAttitude.z =  0;
			//Just clogs the lvlog
			//fprintf(lvlog,"[%d+%f] Initial roll command: %f\r\n",LVDC_Timebase,LVDC_TB_ETime,CommandedAttitude.x*DEG);
			goto minorloop;
		}
		if(BOOST == false){//i.e. we're either in orbit or boosting out of orbit
			if(TAS - TB7<0){
				if(TAS - TB5 < TI5F2){ goto minorloop; }
				if(TAS - TB6 - T_IGM<0){goto restartprep;}else{goto IGM;};
			}else{
				if (TAS - TB7 < 20) { goto minorloop; }else{goto orbitalguidance;}
			}
		} //TBD: 
		if(directstageint == true){//direct stage interrupt update
			if(GATE4 == false){//check if we haven't gone through it before
				Tt_3 = Tt_3 + Cf * (V_S2T - V) + dT_cost;
				T_1 = 0;
				T_2 = 0;
				T_c = 0;
				T_1c = 0;
				Tt_T = Tt_3;
				ROV = ROVs;
				//S4B_IGN = true;
				GATE4 = true;
				fprintf(lvlog,"[%d+%f] Direct stage interrupt received! Guidance update executed!\r\n",LVDC_Timebase,LVDC_TB_ETime);
			}
			if(TAS-TB4A-TS4BS < 0){ goto minorloop; }else{ goto IGM; }						
		}
		if(TAS-TB3-T_LET < 0){
			// Pre-IGM guidance:
			if(S1_Engine_Out == true && T_EO1 == 0){
				// S1C engine out interrupt handling
				T_EO1 = 1;
				t_fail = t_clock;
				fprintf(lvlog,"[%d+%f] S1C engine out interrupt received! t_fail = %f\r\n",LVDC_Timebase,LVDC_TB_ETime,t_fail);
			}				
			if((PosS.x - a) > 137 || t_clock > t_1){
				//roll/pitch program
				if (t_clock >= t_2 && T_EO1 > 0){
					//time to re-calculate freeze time?
					T_EO1 = -1; //allow only one pass thru re-calculation
					if (t_fail <= t_2){dT_F = t_3;}
					if (t_2 < t_clock && t_clock <= t_4){ dT_F = (B_11 * t_fail) + B_12; }
					if (t_4 < t_clock && t_clock <= t_5){ dT_F = (B_21 * t_fail) + B_22; }
					if (t_5 < t_clock){ dT_F = 0; }
					t_6 = t_clock + dT_F;
					T_ar = T_ar + (0.25*(T_ar - t_fail));
					fprintf(lvlog,"[%d+%f] Freeze time recalculated! t_6 = %f T_ar = %f\r\n",LVDC_Timebase,LVDC_TB_ETime,t_6,T_ar);
				}
				if (t_clock >= t_6){
					if (t_clock > T_ar){
						//time for pitch freeze?
						if (S2_IGNITION && S2_ENGINE_OUT && T_EO2 == 0){
							//pre-IGM S2 engine fail handling
							T_EO2 = 1;
							T_0 = t_21 + dt_LET - t_clock;
							T_1 = (T_0/4) + ((5 * T_1)/4);
							T_2 = 5 * T_2 / 4;
							tau3 = 5 * tau2 / 4;
							CommandedAttitude.y = PCommandedAttitude.y;
							CommandedAttitude.x = 360 * RAD;
							CommandedAttitude.z = 0;
							fprintf(lvlog,"[%d+%f] Pre-IGM SII engine out interrupt received!\r\n",LVDC_Timebase,LVDC_TB_ETime);
							goto minorloop;
						}else{
							fprintf(lvlog,"[%d+%f] Pitch freeze! \r\n",LVDC_Timebase,LVDC_TB_ETime);
							CommandedAttitude.y = PCommandedAttitude.y;
							CommandedAttitude.x = 360 * RAD;
							CommandedAttitude.z = 0;
							goto minorloop;
						}
					}else{
						//Pre-IGM steering
						int x=0,y=0;						
						double Tc = t_clock - dT_F, cmd = 0;  
						if(Tc < T_S1){               x = 1; }
						if(T_S1 <= Tc && Tc < T_S2){ x = 2; }
						if(T_S2 <= Tc && Tc < T_S3){ x = 3; }
						if(T_S3 <= Tc){              x = 4; }
						while(y <= 4){
							cmd += (Fx[x][y] * ((double)pow(Tc,y)));
							y++;
						}
						CommandedAttitude.y = cmd * RAD;
						CommandedAttitude.x = 360 * RAD;
						CommandedAttitude.z = 0;
						fprintf(lvlog,"[%d+%f] Roll/pitch programm %f \r\n",LVDC_Timebase,LVDC_TB_ETime,cmd);
						goto minorloop;
					}
				}else{CommandedAttitude.y = PCommandedAttitude.y;
					  CommandedAttitude.x = 360 * RAD;
					  CommandedAttitude.z = 0;
					  goto minorloop;
				}
			}else{
				// S-IC yaw maneuver
				fprintf(lvlog,"[%d+%f] Yaw maneuver\r\n",LVDC_Timebase,LVDC_TB_ETime);
				if(1 <= t_clock && t_clock < 8.75){
					//yaw command issued between t +1s and t+8.75s
					CommandedAttitude.z = 1.25*RAD;
				}else{
					CommandedAttitude.z = 0;
				}
				CommandedAttitude.y = 0; //no pitch
				CommandedAttitude.x = (1.5* PI) + Azimuth; //no roll
				goto minorloop;
			}
		}
		//end of pre igm
IGM:	if(HSL == false){		
			// We are not in the high-speed loop
			fprintf(lvlog,"HSL False\r\n");
			// IGM STAGE LOGIC
			if (S4B_REIGN)
			{
				fprintf(lvlog, "S-IVB 2nd BURN\n");
				if (MRS)
				{
					fprintf(lvlog, "MRS\r\n");
					Tt_3 += T_2*(dotM_2 / dotM_3);
					fprintf(lvlog, "Tt_3 = %f\r\n", Tt_3);
					if(t_B2<=t_B4)
					{goto relightentry1;}
					t_B4 += dt_c;
					fprintf(lvlog, "t_B4 = %f\r\n", t_B4);
				}
				else
				{
					if(T_2<0)
					{
						P_c += dt_c;
						if(P_c>K_pc)
						{
							MRS = true;
							t_B2 = 0;
							fprintf(lvlog, "MRS\r\n");
						}
					}
					else
					{goto taubypass;}
				}
				tau3 += T_2*(dotM_2 / dotM_3);
				T_2 = 0;
			taubypass:
				if(Ct>=Ct_o)
				{goto relightentry2;}
				else
				{
					tau2 = tau2N + (V_ex2 * 1.0 / Fm - dt_c / 2.0 - tau2N)*pow(Ct / Ct_o, 4);
					tau2N -= dt_c;
					Ct += dt_c;
					fprintf(lvlog, "Art. Tau Mode 2: tau2 = %f, tau2N = %f, Ct = %f, Diff = %f\r\n", tau2, tau2N, Ct, tau2 - V_ex2 / Fm);
					goto relightentry3;
				}
			}
			if(S4B_IGN == true){
				fprintf(lvlog,"S-IVB 1st BURN\n");
				if (Ct >= Ct_o){
					relightentry1:
					tau3 = V_ex3/Fm;
					fprintf(lvlog,"Normal Tau: tau3 = %f, F = %f, m = %f \r\n",tau3,owner->GetThrusterMax(owner->th_main[0])*owner->GetThrusterLevel(owner->th_main[0]),owner->GetMass());
				}else{
					tau3 = tau3N + (V_ex3/Fm - dt_c/2 - tau3N)*pow((Ct/Ct_o),4);
					tau3N = tau3N - dt_c;
					Ct = Ct + dt_c;
					fprintf(lvlog,"Art. Tau Mode 3: tau3 = %f, tau3N = %f, Ct = %f, Diff = %f\r\n",tau3,tau3N,Ct,tau3-V_ex3/Fm);								
				}
				GATE = false; //end chi freeze
				T_c = 0;
				T_2 = 0;
				T_1 = 0;
				fprintf(lvlog,"GATE = false, T_c = 0, T_1 = 0, T_2 = 0\r\n");
				goto chitilde;
			}
			if(S2_BURNOUT == true){
				fprintf(lvlog,"SII CUTOFF\n");
				if (T_c < 0){
					//this prevents T_c from getting negative in case of late SIVB ignition
					T_c = 0;
					T_2 = 0;
					T_1 = 0;
					fprintf(lvlog,"T_c = 0, T_1 = 0, T_2 = 0\r\n");
					goto chitilde;
				}else{
					//chi freeze, kill the first two stage integrals
					GATE = true;
					T_2 = 0;
					T_1 = 0;
					fprintf(lvlog,"GATE = true, T_1 = 0, T_2 = 0\r\n");
					goto chitilde;
				}				
			}
			if(S2_ENGINE_OUT == true && T_EO2 == 0){
				T_1 = 5.0 * T_1 / 4.0;
				T_2 = 5.0 * T_2 / 4.0;
				tau2 = 5.0 * tau2 / 4.0;
				T_EO2 = 1;
			}
			if(MRS == true){
				fprintf(lvlog,"Post-MRS\n");
				if(t_B1 <= t_B3){
					relightentry2:
					tau2 = V_ex2/Fm;
					fprintf(lvlog,"Normal Tau: tau2 = %f, F/m = %f, m = %f \r\n",tau2,Fm,owner->GetMass());
				}else{
					// This is the "ARTIFICIAL TAU" code.
					t_B3 += dt_c; 
					tau2 = tau2+(T_1*(dotM_1/dotM_2));
					fprintf(lvlog,"Art. Tau: tau2 = %f, T_1 = %f, dotM_1 = %f dotM_2 = %f \r\n",tau2,T_1,dotM_1,dotM_2);
					fprintf(lvlog,"Diff: %f \r\n",(tau2-V_ex2/Fm));
				}
				// This T_2 test is also tested after T_1 < 0 etc etc
				relightentry3:
				if(T_2 > 0){
					T_2 = T_2+T_1*(dotM_1/dotM_2);
					T_1 = 0;
					fprintf(lvlog,"T_1 = 0\r\nT_2 = %f, dotM_1 = %f, dotM_2 = %f \r\n",T_2,dotM_1,dotM_2);
					// Go to CHI-TILDE LOGIC
				}else{
					T_2 = 0;
					T_1 = 0;
					fprintf(lvlog,"T_1 = 0, T_2 = 0\r\n");
					// Go to CHI-TILDE LOGIC
				}
				if(T_2 < 11 && !S4B_REIGN){GATE = true;}//pre SIVB-staging chi-freeze
			}else{
				fprintf(lvlog,"Pre-MRS\n");
				if(T_1 < 0){	
					// If we're out of first-stage IGM time
					// Artificial Tau
					tau2 = tau2+(T_1*(dotM_1/dotM_2));
					fprintf(lvlog,"Art. Tau: tau2 = %f, T_1 = %f, dotM_1 = %f, dotM_2 = %f \r\n",tau2,T_1,dotM_1,dotM_2);
					if(T_2 > 0){
						T_2 = T_2+T_1*(dotM_1/dotM_2);
						T_1 = 0;
						fprintf(lvlog,"T_2 = %f, T_1 = %f, dotM_1 = %f, dotM_2 = %f \r\n",T_2,T_1,dotM_1,dotM_2);
					}else{
						T_2 = 0;
						T_1 = 0;
						fprintf(lvlog,"T_2 = 0\r\n");
					}					
				}else{															
					tau1 = V_ex1/Fm; 
					fprintf(lvlog,"Normal Tau: tau1 = %f, F/m = %f m = %f\r\n",tau1,Fm, owner->GetMass());
				}
			}
			fprintf(lvlog,"--- STAGE INTEGRAL LOGIC ---\r\n");

			// CHI-TILDE LOGIC
			// STAGE INTEGRAL CALCULATIONS				
chitilde:	Pos4 = mul(MX_G,PosS);
			fprintf(lvlog,"Pos4 = %f, %f, %f\r\n",Pos4.x,Pos4.y,Pos4.z);
			fprintf(lvlog,"T_1 = %f,T_2 = %f\r\n",T_1,T_2);
			L_1 = V_ex1 * log(tau1 / (tau1-T_1));
			J_1 = (L_1 * tau1) - (V_ex1 * T_1);
			S_1 = (L_1 * T_1) - J_1;
			Q_1 = (S_1 * tau1) - ((V_ex1 * pow(T_1,2)) / 2);
			P_1 = (J_1 * tau1) - ((V_ex1 * pow(T_1,2)) / 2);
			U_1 = (Q_1 * tau1) - ((V_ex1 * pow(T_1,3)) / 6);
			fprintf(lvlog,"L_1 = %f, J_1 = %f, S_1 = %f, Q_1 = %f, P_1 = %f, U_1 = %f\r\n",L_1,J_1,S_1,Q_1,P_1,U_1);

			L_2 = V_ex2 * log(tau2 / (tau2-T_2));
			J_2 = (L_2 * tau2) - (V_ex2 * T_2);
			S_2 = (L_2 * T_2) - J_2;
			Q_2 = (S_2 * tau2) - ((V_ex2 * pow(T_2,2)) / 2);
			P_2 = (J_2 * tau2) - ((V_ex2 * pow(T_2,2)) / 2);
			U_2 = (Q_2 * tau2) - ((V_ex2 * pow(T_2,3)) / 6);
			fprintf(lvlog,"L_2 = %f, J_2 = %f, S_2 = %f, Q_2 = %f, P_2 = %f, U_2 = %f\r\n",L_2,J_2,S_2,Q_2,P_2,U_2);

			L_12 = L_1 + L_2;
			J_12 = J_1 + J_2 + (L_2 * T_1);
			S_12 = S_1 - J_2 + (L_12 * (T_2 + T_c));
			Q_12 = Q_1 + Q_2 + (S_2 * T_1) + (J_1 * T_2);
			P_12 = P_1 + P_2 + (T_1 * ((2 * J_2) + (L_2 * T_1)));
			U_12 = U_1 + U_2 + (T_1 * ((2 * Q_2) + (S_2 * T_1))) + (T_2 * P_1);
			fprintf(lvlog,"L_12 = %f, J_12 = %f, S_12 = %f, Q_12 = %f, P_12 = %f, U_12 = %f\r\n",L_12,J_12,S_12,Q_12,P_12,U_12);

			Lt_3 = V_ex3 * log(tau3 / (tau3-Tt_3));
			fprintf(lvlog,"Lt_3 = %f, tau3 = %f, Tt_3 = %f\r\n",Lt_3,tau3,Tt_3);

			Jt_3 = (Lt_3 * tau3) - (V_ex3 * Tt_3);
			fprintf(lvlog,"Jt_3 = %f",Jt_3);
			Lt_Y = (L_12 + Lt_3);
			fprintf(lvlog,", Lt_Y = %f\r\n",Lt_Y);

			// SELECT RANGE OPTION				
gtupdate:	// Target of jump from further down
			fprintf(lvlog,"--- GT UPDATE ---\r\n");

			if(Tt_T <= eps_1){
				// RANGE ANGLE 2 (out-of orbit)
				fprintf(lvlog,"RANGE ANGLE 2\r\n");
				sprintf(oapiDebugString(),"LVDC: RANGE ANGLE 2: %f %f",Tt_T,eps_1); 
				// LVDC_GP_PC = 30; // STOP
				V = length(DotS);
				R = length(PosS);
				sin_gam = ((PosS.x*DotS.x)+(PosS.y*DotS.y)+(PosS.z*DotS.z))/(R*V);
				cos_gam = pow(1.0-pow(sin_gam,2),0.5);
				dot_phi_1 = (V*cos_gam)/R;
				dot_phi_T = (V_T*cos(gamma_T))/R_T;
				phi_T = atan2(Pos4.z,Pos4.x)+(((dot_phi_1+dot_phi_T)/2.0)*Tt_T);
				fprintf(lvlog, "V = %f, dot_phi_1 = %f, dot_phi_T = %f, phi_T = %f\r\n", V, dot_phi_1, dot_phi_T, phi_T);
			}else{
				// RANGE ANGLE 1 (into orbit)
				fprintf(lvlog,"RANGE ANGLE 1\r\n");
				d2 = (V * Tt_T) - Jt_3 + (Lt_Y * Tt_3) - (ROV / V_ex3) * 
					((tau1 - T_1) * L_1 + (tau2 - T_2) * L_2 + (tau3 - Tt_3) * Lt_3) *
					(Lt_Y + V - V_T);
				phi_T = atan2(Pos4.z, Pos4.x) + (1.0 / R_T)*(S_12 + d2)*cos(gamma_T);
				fprintf(lvlog,"V = %f, d2 = %f, phi_T = %f\r\n",V,d2,phi_T);
			}
			// FREEZE TERMINAL CONDITIONS TEST
			if(!(Tt_T <= eps_3)){
				// UPDATE TERMINAL CONDITIONS
				fprintf(lvlog,"UPDATE TERMINAL CONDITIONS\r\n");
				f = phi_T + alpha_D;
				R_T = p/(1+((e*(cos(f)))));
				fprintf(lvlog, "f = %f, R_T = %f, phi_T = %f, alpha_D = %f\r\n", f, R_T, phi_T, alpha_D);
				V_T = K_5 * pow(1+((2*e)*(cos(f)))+pow(e,2),0.5);
				gamma_T = atan2((e*(sin(f))),(1+(e*(cos(f)))));
				G_T = -mu/pow(R_T,2);
				fprintf(lvlog,"V_T = %f, gamma_T = %f, G_T = %f\r\n",V_T,gamma_T,G_T);
			}
			// ROT TEST
			if(ROT){
				// ROTATED TERMINAL CONDITIONS (out-of-orbit)
				fprintf(lvlog,"ROTATED TERMINAL CONDITIONS\r\n");
				//sprintf(oapiDebugString(),"LVDC: ROTATED TERMINAL CNDS");
				xi_T = R_T*cos(gamma_T);
				dot_zeta_T = V_T;
				dot_xi_T = 0.0;
				ddot_zeta_GT = G_T*sin(gamma_T);
				ddot_xi_GT = G_T*cos(gamma_T);
				phi_T = phi_T - gamma_T;
				fprintf(lvlog, "xi_T = %f, dot_zeta_T = %f, dot_xi_T = %f\r\n", xi_T, dot_zeta_T, dot_xi_T);
				fprintf(lvlog, "ddot_zeta_GT = %f, ddot_xi_GT = %f\r\n", ddot_zeta_GT, ddot_xi_GT);

				// LVDC_GP_PC = 30; // STOP
			}else{
				// UNROTATED TERMINAL CONDITIONS (into-orbit)
				fprintf(lvlog,"UNROTATED TERMINAL CONDITIONS\r\n");
				xi_T = R_T;					
				dot_zeta_T = V_T * (cos(gamma_T));
				dot_xi_T = V_T * (sin(gamma_T));
				ddot_zeta_GT = 0;
				ddot_xi_GT = G_T;
				fprintf(lvlog,"xi_T = %f, dot_zeta_T = %f, dot_xi_T = %f\r\n",xi_T,dot_zeta_T,dot_xi_T);
				fprintf(lvlog,"ddot_zeta_GT = %f, ddot_xi_GT = %f\r\n",ddot_zeta_GT,ddot_xi_GT);
			}
			// ROTATION TO TERMINAL COORDINATES
			fprintf(lvlog,"--- ROTATION TO TERMINAL COORDINATES ---\r\n");
			// This is the last time PosS is referred to.
			MX_phi_T.m11 = (cos(phi_T));    MX_phi_T.m12 = 0; MX_phi_T.m13 = ((sin(phi_T)));
			MX_phi_T.m21 = 0;               MX_phi_T.m22 = 1; MX_phi_T.m23 = 0;
			MX_phi_T.m31 = (-sin(phi_T)); MX_phi_T.m32 = 0; MX_phi_T.m33 = (cos(phi_T));
			fprintf(lvlog,"MX_phi_T R1 = %f %f %f\r\n",MX_phi_T.m11,MX_phi_T.m12,MX_phi_T.m13);
			fprintf(lvlog,"MX_phi_T R2 = %f %f %f\r\n",MX_phi_T.m21,MX_phi_T.m22,MX_phi_T.m23);
			fprintf(lvlog,"MX_phi_T R3 = %f %f %f\r\n",MX_phi_T.m31,MX_phi_T.m32,MX_phi_T.m33);

			MX_K = mul(MX_phi_T,MX_G);
			fprintf(lvlog,"MX_K R1 = %f %f %f\r\n",MX_K.m11,MX_K.m12,MX_K.m13);
			fprintf(lvlog,"MX_K R2 = %f %f %f\r\n",MX_K.m21,MX_K.m22,MX_K.m23);
			fprintf(lvlog,"MX_K R3 = %f %f %f\r\n",MX_K.m31,MX_K.m32,MX_K.m33);

			PosXEZ = mul(MX_K,PosS);
			DotXEZ = mul(MX_K,DotS);	
			fprintf(lvlog,"PosXEZ = %f %f %f\r\n",PosXEZ.x,PosXEZ.y,PosXEZ.z);
			fprintf(lvlog,"DotXEZ = %f %f %f\r\n",DotXEZ.x,DotXEZ.y,DotXEZ.z);

			VECTOR3 RTT_T1,RTT_T2;
			RTT_T1.x = ddot_xi_GT; RTT_T1.y = 0;        RTT_T1.z = ddot_zeta_GT;
			RTT_T2 = ddotG_act;
			fprintf(lvlog,"RTT_T1 = %f %f %f\r\n",RTT_T1.x,RTT_T1.y,RTT_T1.z);
			fprintf(lvlog,"RTT_T2 = %f %f %f\r\n",RTT_T2.x,RTT_T2.y,RTT_T2.z);

			RTT_T2 = mul(MX_K,RTT_T2);
			fprintf(lvlog,"RTT_T2 (mul) = %f %f %f\r\n",RTT_T2.x,RTT_T2.y,RTT_T2.z);

			RTT_T1 = RTT_T1+RTT_T2;	  
			fprintf(lvlog,"RTT_T1 (add) = %f %f %f\r\n",RTT_T1.x,RTT_T1.y,RTT_T1.z);

			DDotXEZ_G  = _V(0.5*RTT_T1.x, 0.5*RTT_T1.y, 0.5*RTT_T1.z);
			fprintf(lvlog,"ddot_XEZ_G = %f %f %f\r\n", DDotXEZ_G.x, DDotXEZ_G.y, DDotXEZ_G.z);

			// ESTIMATED TIME-TO-GO
			fprintf(lvlog,"--- ESTIMATED TIME-TO-GO ---\r\n");

			dot_dxit   = dot_xi_T - DotXEZ.x - (DDotXEZ_G.x*Tt_T);
			dot_detat  = -DotXEZ.y - (DDotXEZ_G.y * Tt_T);
			dot_dzetat = dot_zeta_T - DotXEZ.z - (DDotXEZ_G.z * Tt_T);
			fprintf(lvlog,"dot_XEZt = %f %f %f\r\n",dot_dxit,dot_detat,dot_dzetat);
			dV = pow((pow(dot_dxit,2)+pow(dot_detat,2)+pow(dot_dzetat,2)),0.5);
			dL_3 = (((pow(dot_dxit,2)+pow(dot_detat,2)+pow(dot_dzetat,2))/Lt_Y)-Lt_Y)/2;
			// if(dL_3 < 0){ sprintf(oapiDebugString(),"Est TTG: dL_3 %f (X/E/Z %f %f %f) @ Cycle %d (TB%d+%f)",dL_3,dot_dxit,dot_detat,dot_dzetat,IGMCycle,LVDC_Timebase,LVDC_TB_ETime);
			//	LVDC_GP_PC = 30; break; } 

			dT_3 = (dL_3*(tau3-Tt_3))/V_ex3;
			T_3 = Tt_3 + dT_3;
			T_T = Tt_T + dT_3;
			fprintf(lvlog,"dV = %f, dL_3 = %f, dT_3 = %f, T_3 = %f, T_T = %f\r\n",dV,dL_3,dT_3,T_3,T_T);

			// TARGET PARAMETER UPDATE
			if(!(UP > 0)){	
				fprintf(lvlog,"--- TARGET PARAMETER UPDATE ---\r\n");
				UP = 1; 
				Tt_3 = T_3;
				Tt_T = T_T;
				fprintf(lvlog,"UP = 1, Tt_3 = %f, Tt_T = %f\r\n",Tt_3,Tt_T);
				Lt_3 = Lt_3 + dL_3;
				Lt_Y = Lt_Y + dL_3;
				Jt_3 = Jt_3 + (dL_3*T_3);
				fprintf(lvlog,"Lt_3 = %f, Lt_Y = %f, Jt_3 = %f\r\n",Lt_3,Lt_Y,Jt_3);

				// NOTE: This is perfectly valid. Just because Dijkstra and Wirth think otherwise
				// does not mean it's gospel. I shouldn't have to defend my choice of instructions
				// because a bunch of people read the title of the paper with no context and take
				// it as a direct revelation from God with no further study into the issue.
				fprintf(lvlog,"RECYCLE\r\n");
				goto gtupdate; // Recycle. 
			}

			// tchi_y AND tchi_p CALCULATIONS
			fprintf(lvlog,"--- tchi_y/p CALCULATION ---\r\n");

			L_3 = Lt_3 + dL_3;
			J_3 = Jt_3 + (dL_3*T_3);
			S_3 = (L_3*T_3)-J_3;
			Q_3 = (S_3*tau3)-((V_ex3*pow(T_3,2))/2);
			P_3 = (J_3*(tau3+(2*T_1c)))-((V_ex3*pow(T_3,2))/2);
			U_3 = (Q_3*(tau3+(2*T_1c)))-((V_ex3*pow(T_3,3))/6);
			fprintf(lvlog,"L_3 = %f, J_3 = %f, S_3 = %f, Q_3 = %f, P_3 = %f, U_3 = %f\r\n",L_3,J_3,S_3,Q_3,P_3,U_3);

			// This is where velocity-to-be-gained is generated.

			dot_dxi   = dot_dxit   - (DDotXEZ_G.x   * dT_3);
			dot_deta  = dot_detat  - (DDotXEZ_G.y  * dT_3);
			dot_dzeta = dot_dzetat - (DDotXEZ_G.z * dT_3);
			fprintf(lvlog,"dot_dXEZ = %f %f %f\r\n",dot_dxi,dot_deta,dot_dzeta);

			//				sprintf(oapiDebugString(),".dxi = %f | .deta %f | .dzeta %f | dT3 %f",
			//					dot_dxi,dot_deta,dot_dzeta,dT_3);

			L_Y = L_12 + L_3;
			tchi_y_last = tchi_y;
			tchi_p_last = tchi_p;
			tchi_y = atan2(dot_deta,pow(pow(dot_dxi,2)+pow(dot_dzeta,2),0.5));
			tchi_p = atan2(dot_dxi,dot_dzeta);				
			UP = -1;
			fprintf(lvlog,"L_Y = %f, tchi_y = %f, tchi_p = %f, UP = -1\r\n",L_Y,tchi_y,tchi_p);

			// *** END OF CHI-TILDE LOGIC ***
			// Is it time for chi-tilde mode?
			if(Tt_T <= eps_2){
				fprintf(lvlog,"CHI BAR STERRING ON, REMOVE ALTITUDE CONSTRAINS (K_1-4 = 0)\r\n");
				// Yes
				// Go to the test that we would be testing if HSL was true
				K_1 = 0; K_2 = 0; K_3 = 0; K_4 = 0;
				// See the note above if the presence of this goto bothers you.
				// sprintf(oapiDebugString(),"LVDC: HISPEED LOOP ENTRY: Tt_T %f eps_2 %f", Tt_T,eps_2); LVDC_GP_PC = 30; break; // STOP
				goto hsl;
			}else{
				// No.
				// YAW STEERING PARAMETERS
				fprintf(lvlog,"--- YAW STEERING PARAMETERS ---\r\n");

				J_Y = J_12 + J_3 + (L_3*T_1c);
				S_Y = S_12 - J_3 + (L_Y*T_3);
				Q_Y = Q_12 + Q_3 + (S_3*T_1c) + ((T_c+T_3)*J_12);
				K_Y = L_Y/J_Y;
				D_Y = S_Y - (K_Y*Q_Y);
				fprintf(lvlog,"J_Y = %f, S_Y = %f, Q_Y = %f, K_Y = %f, D_Y = %f\r\n",J_Y,S_Y,Q_Y,K_Y,D_Y);

				deta = PosXEZ.y + (DotXEZ.y*T_T) + ((DDotXEZ_G.y*pow(T_T,2))/2) + (S_Y*(sin(tchi_y)));
				K_3 = deta/(D_Y*(cos(tchi_y)));
				K_4 = K_Y*K_3;
				fprintf(lvlog,"deta = %f, K_3 = %f, K_4 = %f\r\n",deta,K_3,K_4);

				// PITCH STEERING PARAMETERS
				fprintf(lvlog,"--- PITCH STEERING PARAMETERS ---\r\n");

				L_P = L_Y*cos(tchi_y);
				C_2 = cos(tchi_y)+(K_3*sin(tchi_y));
				C_4 = K_4*sin(tchi_y);
				J_P = (J_Y*C_2) - (C_4*(P_12+P_3+(pow(T_1c,2)*L_3)));
				fprintf(lvlog,"L_P = %f, C_2 = %f, C_4 = %f, J_P = %f\r\n",L_P,C_2,C_4,J_P);

				S_P = (S_Y*C_2) - (C_4*Q_Y);
				Q_P = (Q_Y*C_2) - (C_4*(U_12+U_3+(pow(T_1c,2)*S_3)+((T_3+T_c)*P_12)));
				K_P = L_P/J_P;
				D_P = S_P - (K_P*Q_P);
				fprintf(lvlog,"S_P = %f, Q_P = %f, K_P = %f, D_P = %f\r\n",S_P,Q_P,K_P,D_P);

				dxi = PosXEZ.x - xi_T + (DotXEZ.x*T_T) + ((DDotXEZ_G.x*pow(T_T,2))/2) + (S_P*(sin(tchi_p)));
				K_1 = dxi/(D_P*cos(tchi_p));
				K_2 = K_P*K_1;
				fprintf(lvlog,"dxi = %f, K_1 = %f, K_2 = %f, cos(tchi_p) = %f\r\n",dxi,K_1,K_2,cos(tchi_p));
			}
		}else{
hsl:		// HIGH-SPEED LOOP ENTRY				
			// CUTOFF VELOCITY EQUATIONS
			fprintf(lvlog,"--- CUTOFF VELOCITY EQUATIONS ---\r\n");
			V_0 = V_1;
			V_1 = V_2;
			//V_2 = 0.5 * (V+(pow(V_1,2)/V));
			V_2 = V;
			dtt_1 = dtt_2;
			dtt_2 = dt_c;					
			fprintf(lvlog,"V = %f, Tt_t = %f\r\n",V,Tt_T);
			fprintf(lvlog,"V = %f, V_0 = %f, V_1 = %f, V_2 = %f, dtt_1 = %f, dtt_2 = %f\r\n",V,V_0,V_1,V_2,dtt_1,dtt_2);
			if(Tt_T <= eps_4 && V + V_TC >= V_T){
				fprintf(lvlog,"--- HI SPEED LOOP ---\r\n");
				// TGO CALCULATION
				fprintf(lvlog,"--- TGO CALCULATION ---\r\n");
				if(GATE5 == false){
					fprintf(lvlog,"CHI FREEZE\r\n");
					// CHI FREEZE
					tchi_y = tchi_y_last;
					tchi_p = tchi_p_last;
					GATE = true;
					HSL = true;
					GATE5 = true;
					T_GO = T_3;
					fprintf(lvlog,"HSL = true, GATE5 = true, T_GO = %f\r\n",T_GO);
				}
				if(BOOST == true){
					fprintf(lvlog,"BOOST-TO-ORBIT ACTIVE\r\n");
					// dT_4 CALCULATION
					if (LVDC_Timebase == 40)
					{
						t_3i = TB4A + T_c;
					}
					else
					{
						t_3i = TB4 + T_c;
					}
					dT_4 = TAS-t_3i-T_4N;
					//dT_4 = t_3i - T_4N;
					fprintf(lvlog,"t_3i = %f, dT_4 = %f\r\n",t_3i,dT_4);
					if(fabs(dT_4) <= dT_LIM){							
						dTt_4 = dT_4;
					}else{
						fprintf(lvlog,"dTt_4 CLAMPED\r\n");
						dTt_4 = dT_LIM;
					}
					fprintf(lvlog,"dTt_4 = %f\r\n",dTt_4);
				}else{
					// TRANSLUNAR INJECTION VELOCITY
					fprintf(lvlog,"TRANSLUNAR INJECTION\r\n");
					double dotR = dotp(PosS, DotS) / R;
					R_T = R + dotR*(T_3 - dt);
					V_T = sqrt(C_3 + 2.0*mu / R_T);
					dV_B = dV_BR;
					sprintf(oapiDebugString(),"LVDC: HISPEED LOOP, TLI VELOCITY: %f %f %f %f %f",Tt_T,eps_4,V,V_TC,V_T);
					fprintf(lvlog, "TLI VELOCITY: Tt_T: %f, eps_4: %f, V: %f, V_TC: %f, V_T: %f\r\n", Tt_T, eps_4, V, V_TC, V_T);
					// LVDC_GP_PC = 30; // STOP
				}
				// TGO DETERMINATION
				fprintf(lvlog,"--- TGO DETERMINATION ---\r\n");

				a_2 = (((V_2-V_1)*dtt_1)-((V_1-V_0)*dtt_2))/(dtt_2*dtt_1*(dtt_2+dtt_1));
				a_1 = ((V_2-V_1)/dtt_2)+(a_2*dtt_2);
				T_GO = ((V_T-dV_B)-V_2)/(a_1+a_2*T_GO);
				T_CO = TAS+T_GO;
				fprintf(lvlog,"a_2 = %f, a_1 = %f, T_GO = %f, T_CO = %f, V_T = %f\r\n",a_2,a_1,T_GO,T_CO,V_T);

				// S4B CUTOFF?
				if(S4B_IGN == false && (LVDC_Timebase < 6 || LVDC_Timebase == 40)){
					fprintf(lvlog,"*** HSL EXIT SETTINGS ***\r\n");
					GATE = false;
					GATE5 = false;
					Tt_T = 1000;
					HSL = false;
					BOOST = false;
					goto minorloop;
				}
				// S4B 2ND CUTOFF?
				if(S4B_REIGN == false && (LVDC_Timebase >= 6 && LVDC_Timebase != 40)) {
					fprintf(lvlog, "*** HSL EXIT SETTINGS ***\r\n");
					GATE = false;
					GATE5 = false;
					Tt_T = 1000;
					HSL = false;
					BOOST = false;
					goto minorloop;
				}
				// Done, go to navigation
				sprintf(oapiDebugString(),"TB%d+%f | CP/Y %f %f | -HSL- TGO %f",LVDC_Timebase,LVDC_TB_ETime,CommandedAttitude.y,CommandedAttitude.z,T_GO);
				goto minorloop;
			}
			// End of high-speed loop
		}
		// GUIDANCE TIME UPDATE
		fprintf(lvlog,"--- GUIDANCE TIME UPDATE ---\r\n");
		if(BOOST){
			if(S4B_IGN){
				T_3 = T_3 - dt_c;
			}else{
				if(S2_BURNOUT){
					T_c = T_c - dt_c;
				}else{
					if(MRS == false){
						T_1 = T_1 - dt_c; 
					}else{
						if(t_B1 <= t_B3){
							T_2 = T_2 - dt_c;
						}else{
							// Here if t_B1 is bigger.
							fprintf(lvlog,"t_B1 = %f, t_B3 = %f\r\n",t_B1,t_B3);
							T_1 = (((dotM_1*(t_B3-t_B1))-(dotM_2*t_B3))*dt)/(dotM_1*t_B1);
						}
					}
				}
			}
			fprintf(lvlog,"T_1 = %f, T_2 = %f, T_3 = %f, T_c = %f dt_c = %f\r\n",T_1,T_2,T_3,T_c,dt_c);
		}else{
			// MRS TEST
			fprintf(lvlog,"MRS TEST\r\n");
			sprintf(oapiDebugString(),"LVDC: MRS TEST"); 
			if (MRS)
			{
				if (t_B2 <= t_B4)
				{
					T_3 = T_3 - dt_c;
				}
				else
				{
					T_2 = (dotM_2*(t_B4 - t_B2) - dotM_3*t_B4)*dt_c / (dotM_2*t_B2);
				}
			}
			else
			{
				T_2 = T_2 - dt_c;
			}
			fprintf(lvlog, "T_2 = %f, T_3 = %f, dt_c = %f\r\n", T_2, T_3, dt_c);
			// LVDC_GP_PC = 30; // STOP
		}
		Tt_3 = T_3;
		T_1c = T_1+T_2+T_c;			
		Tt_T = T_1c+Tt_3;
		fprintf(lvlog,"Tt_3 = %f, T_1c = %f, Tt_T = %f\r\n",Tt_3,T_1c,Tt_T);
		if(GATE){
			// FREEZE CHI
			fprintf(lvlog,"Thru GATE; CHI FREEZE\r\n");
			sprintf(oapiDebugString(),"LVDC: CHI FREEZE");
			goto minorloop;
		}else{
			// IGM STEERING ANGLES
			fprintf(lvlog,"--- IGM STEERING ANGLES ---\r\n");

			//sprintf(oapiDebugString(),"IGM: K_1 %f K_2 %f K_3 %f K_4 %f",K_1,K_2,K_3,K_4);
			Xtt_y = ((tchi_y) - K_3 + (K_4 * t));
			Xtt_p = ((tchi_p) - K_1 + (K_2 * t));
			fprintf(lvlog,"Xtt_y = %f, Xtt_p = %f\r\n",Xtt_y,Xtt_p);

			// -- COMPUTE INVERSE OF [K] --
			// Get Determinate
			double det = MX_K.m11 * ((MX_K.m22*MX_K.m33) - (MX_K.m32*MX_K.m23))
						- MX_K.m12 * ((MX_K.m21*MX_K.m33) - (MX_K.m31*MX_K.m23))
						+ MX_K.m13 * ((MX_K.m21*MX_K.m32) - (MX_K.m31*MX_K.m22));
			// If the determinate is less than 0.0005, this is invalid.
			fprintf(lvlog,"det = %f (LESS THAN 0.0005 IS INVALID)\r\n",det);

			MATRIX3 MX_Ki; // TEMPORARY: Inverse of [K]
			MX_Ki.m11 =   ((MX_K.m22*MX_K.m33) - (MX_K.m23*MX_K.m32))  / det;
			MX_Ki.m12 =   ((MX_K.m13*MX_K.m32) - (MX_K.m12*MX_K.m33))  / det;
			MX_Ki.m13 =   ((MX_K.m12*MX_K.m23) - (MX_K.m13*MX_K.m22))  / det;
			MX_Ki.m21 =   ((MX_K.m23*MX_K.m31) - (MX_K.m21*MX_K.m33))  / det;
			MX_Ki.m22 =   ((MX_K.m11*MX_K.m33) - (MX_K.m13*MX_K.m31))  / det;
			MX_Ki.m23 =   ((MX_K.m13*MX_K.m21) - (MX_K.m11*MX_K.m23))  / det;
			MX_Ki.m31 =   ((MX_K.m21*MX_K.m32) - (MX_K.m22*MX_K.m31))  / det;
			MX_Ki.m32 =   ((MX_K.m12*MX_K.m31) - (MX_K.m11*MX_K.m32))  / det;
			MX_Ki.m33 =   ((MX_K.m11*MX_K.m22) - (MX_K.m12*MX_K.m21))  / det;
			fprintf(lvlog,"MX_Ki R1 = %f %f %f\r\n",MX_Ki.m11,MX_Ki.m12,MX_Ki.m13);
			fprintf(lvlog,"MX_Ki R2 = %f %f %f\r\n",MX_Ki.m21,MX_Ki.m22,MX_Ki.m23);
			fprintf(lvlog,"MX_Ki R3 = %f %f %f\r\n",MX_Ki.m31,MX_Ki.m32,MX_Ki.m33);

			// Done
			VECTOR3 VT; 
			VT.x = (sin(Xtt_p)*cos(Xtt_y));
			VT.y = (sin(Xtt_y));
			VT.z = (cos(Xtt_p)*cos(Xtt_y));
			fprintf(lvlog,"VT (set) = %f %f %f\r\n",VT.x,VT.y,VT.z);

			VT = mul(MX_Ki,VT);
			fprintf(lvlog,"VT (mul) = %f %f %f\r\n",VT.x,VT.y,VT.z);

			X_S1 = VT.x;
			X_S2 = VT.y;
			X_S3 = VT.z;
			fprintf(lvlog,"X_S1-3 = %f %f %f\r\n",X_S1,X_S2,X_S3);

			// FINALLY - COMMANDS!
			X_Zi = asin(X_S2);			// Yaw
			X_Yi = atan2(-X_S3,X_S1);	// Pitch
			fprintf(lvlog,"*** COMMAND ISSUED ***\r\n");
			fprintf(lvlog,"PITCH = %f, YAW = %f\r\n\r\n",X_Yi*DEG,X_Zi*DEG);
			// IGM is supposed to generate attitude directly.
			CommandedAttitude.x = 360 * RAD;    // ROLL
			CommandedAttitude.y = X_Yi; // PITCH
			CommandedAttitude.z = X_Zi; // YAW;	
			goto minorloop;
		}					

orbitalguidance: 
		//orbital guidance logic
		fprintf(lvlog,"*** ORBITAL GUIDANCE ***\r\n");
		if(TAS-TB7<0){
			if(TAS-TB6<0){
				if(TAS-TB5-TA1 >= 0){
					// presettings for orbital maneuver; don't know if we ever need them, but at least it's there...for Apollo 9!
					if(TAS-TB5-TA2 >= 0){
						if(INH2){
							alpha_1 = 0 * RAD;
							CommandedAttitude.x = 360 * RAD;
							fprintf(lvlog, "inhibit attitude hold, maintain orbrate\r\n");
							goto orbatt;
						}else{
							CommandedAttitude = ACommandedAttitude;
							fprintf(lvlog, "Attitude hold\r\n");
							goto minorloop;
						}
					}else{
						if(INH1){
							alpha_1 = 0 * RAD;
							CommandedAttitude.x = 360 * RAD;
							fprintf(lvlog, "No pitch down, maintain orbrate\r\n");
							goto orbatt;
						}else{
							alpha_1 = XLunarAttitude.y;
							alpha_2 = XLunarAttitude.z;
							CommandedAttitude.x = XLunarAttitude.x;
							fprintf(lvlog, "Pitch down\r\n");
							goto orbatt;
						}
					}
				}else{
					alpha_1 = 0 * RAD;
					CommandedAttitude.x = 360 * RAD;
					goto orbatt;
				}
			}else{
				if(first_op){
					alpha_1 = K_P1 + K_P2 * dTt_4; //restart angles
					alpha_2 = K_Y1 + K_Y2 * dTt_4;
					goto orbatt;
				}else{
					alpha_1 = 0 * RAD;
					CommandedAttitude.x = 360 * RAD;
					goto orbatt;
				}
			}
		}else{
			if (TAS - TB7 - 900 < 0) {
				alpha_1 = 0 * RAD;
				CommandedAttitude.x = 360 * RAD;
				goto orbatt;
			}
			else
			{
				if (GATE6)
				{	
					//attitude hold for T&D
					CommandedAttitude = ACommandedAttitude;
					fprintf(lvlog, "T&D attitude hold\r\n");
					goto minorloop;
				}
				else
				{
					//attitude for T&D					
					alpha_1 = XLunarAttitude.y;
					alpha_2 = XLunarAttitude.z;
					CommandedAttitude.x = XLunarAttitude.x;
					GATE6 = true;
					fprintf(lvlog, "T&D attitude\r\n");
					goto orbatt;
				}
			}
		} 
		goto minorloop;

orbatt: Pos4 = mul(MX_G,PosS); //here we compute the steering angles...
		sin_chi_Yit = (Pos4.x * cos(alpha_1) + Pos4.z * sin(alpha_1))/(-R);
		cos_chi_Yit = (Pos4.z * cos(alpha_1) - Pos4.x * sin(alpha_1))/(-R);
		sin_chi_Zit = sin(alpha_2);
		cos_chi_Zit = cos(alpha_2);
		// -- COMPUTE INVERSE OF [G] -what an effort for those stupid angles!
		// Get Determinate
		double det = MX_G.m11 * ((MX_G.m22*MX_G.m33) - (MX_G.m32*MX_G.m23))
					- MX_G.m12 * ((MX_G.m21*MX_G.m33) - (MX_G.m31*MX_G.m23))
					+ MX_G.m13 * ((MX_G.m21*MX_G.m32) - (MX_G.m31*MX_G.m22));
		// If the determinate is less than 0.0005, this is invalid.
		MATRIX3 MX_Gi; // TEMPORARY: Inverse of [K]
		MX_Gi.m11 =   ((MX_G.m22*MX_G.m33) - (MX_G.m23*MX_G.m32))  / det;
		MX_Gi.m12 =   ((MX_G.m13*MX_G.m32) - (MX_G.m12*MX_G.m33))  / det;
		MX_Gi.m13 =   ((MX_G.m12*MX_G.m23) - (MX_G.m13*MX_G.m22))  / det;
		MX_Gi.m21 =   ((MX_G.m23*MX_G.m31) - (MX_G.m21*MX_G.m33))  / det;
		MX_Gi.m22 =   ((MX_G.m11*MX_G.m33) - (MX_G.m13*MX_G.m31))  / det;
		MX_Gi.m23 =   ((MX_G.m13*MX_G.m21) - (MX_G.m11*MX_G.m23))  / det;
		MX_Gi.m31 =   ((MX_G.m21*MX_G.m32) - (MX_G.m22*MX_G.m31))  / det;
		MX_Gi.m32 =   ((MX_G.m12*MX_G.m31) - (MX_G.m11*MX_G.m32))  / det;
		MX_Gi.m33 =   ((MX_G.m11*MX_G.m22) - (MX_G.m12*MX_G.m21))  / det;
		VECTOR3 VT; 
		VT.x = (cos_chi_Yit * cos_chi_Zit);
		VT.y = (sin_chi_Zit);
		VT.z = (-sin_chi_Yit * cos_chi_Zit);
		fprintf(lvlog,"VT (set) = %f %f %f\r\n",VT.x,VT.y,VT.z);

		VT = mul(MX_Gi,VT);
		fprintf(lvlog,"VT (mul) = %f %f %f\r\n",VT.x,VT.y,VT.z);

		X_S1 = VT.x;
		X_S2 = VT.y;
		X_S3 = VT.z;
		fprintf(lvlog,"X_S1-3 = %f %f %f\r\n",X_S1,X_S2,X_S3);

		// FINALLY - COMMANDS!
		X_Zi = asin(X_S2);			// Yaw
		X_Yi = atan2(-X_S3,X_S1);	// Pitch
		fprintf(lvlog,"*** COMMAND ISSUED ***\r\n");
		fprintf(lvlog,"PITCH = %f, YAW = %f\r\n\r\n",X_Yi*DEG,X_Zi*DEG);
		CommandedAttitude.y = X_Yi; // PITCH
		CommandedAttitude.z = X_Zi; // YAW;
		ACommandedAttitude = CommandedAttitude;
		goto minorloop;

restartprep:
		{
			// TLI restart & targeting logic; TBD;

			//Determine if XLUNAR-INHIBIT
			if (GATE0)	//Restart prep enabled?
			{
				goto INHcheck;
			}
			if (!GATE1)	//OOB targeting enabled?
			{
				if (GATE2)	//First opportunity targeting passed?
				{
					//Second opportunity targeting from TABLE

					tgt_index = 0;
					while (t_D > TABLE15[1].target[tgt_index].t_D)
					{
						tgt_index++;
					}
					fprintf(lvlog, "Target index = %d \r\n", tgt_index);

					double tdint0, tdint1;

					tdint0 = TABLE15[1].target[tgt_index - 1].t_D;
					tdint1 = TABLE15[1].target[tgt_index].t_D;

					RAS = LinInter(tdint0, tdint1, TABLE15[1].target[tgt_index - 1].RAS*RAD, TABLE15[1].target[tgt_index].RAS*RAD, t_D);
					DEC = LinInter(tdint0, tdint1, TABLE15[1].target[tgt_index - 1].DEC*RAD, TABLE15[1].target[tgt_index].DEC*RAD, t_D);
					C_3 = LinInter(tdint0, tdint1, TABLE15[1].target[tgt_index - 1].C_3, TABLE15[1].target[tgt_index].C_3, t_D);
					cos_sigma = LinInter(tdint0, tdint1, TABLE15[1].target[tgt_index - 1].cos_sigma, TABLE15[1].target[tgt_index].cos_sigma, t_D);
					e_N = LinInter(tdint0, tdint1, TABLE15[1].target[tgt_index - 1].e_N, TABLE15[1].target[tgt_index].e_N, t_D);

					fprintf(lvlog, "Selected TLI Targeting Parameters (Second Opportunity): \r\n");
					fprintf(lvlog, "RAS: %f, DEC: %f, C_3 = %f, cos_sigma = %f, e_N = %f \r\n", RAS*DEG, DEC*DEG, C_3, cos_sigma, e_N);

					f = TABLE15[1].f*RAD;
					beta = TABLE15[1].beta*RAD;
					alpha_TS = TABLE15[1].alphaS_TS*RAD;
					T_ST = TABLE15[1].T_ST;
					R_N = TABLE15[1].R_N;
					TargetVector = _V(cos(RAS)*cos(DEC), sin(RAS)*cos(DEC), sin(DEC));
					GATE1 = true;
				}
				else
				{
					//First opportunity targeting from TABLE

					tgt_index = 0;
					while (t_D > TABLE15[0].target[tgt_index].t_D)
					{
						tgt_index++;
					}
					fprintf(lvlog, "Target index = %d \r\n", tgt_index);

					double tdint0, tdint1;

					tdint0 = TABLE15[0].target[tgt_index - 1].t_D;
					tdint1 = TABLE15[0].target[tgt_index].t_D;

					RAS = LinInter(tdint0, tdint1, TABLE15[0].target[tgt_index - 1].RAS*RAD, TABLE15[0].target[tgt_index].RAS*RAD, t_D);
					DEC = LinInter(tdint0, tdint1, TABLE15[0].target[tgt_index - 1].DEC*RAD, TABLE15[0].target[tgt_index].DEC*RAD, t_D);
					C_3 = LinInter(tdint0, tdint1, TABLE15[0].target[tgt_index - 1].C_3, TABLE15[0].target[tgt_index].C_3, t_D);
					cos_sigma = LinInter(tdint0, tdint1, TABLE15[0].target[tgt_index - 1].cos_sigma, TABLE15[0].target[tgt_index].cos_sigma, t_D);
					e_N = LinInter(tdint0, tdint1, TABLE15[0].target[tgt_index - 1].e_N, TABLE15[0].target[tgt_index].e_N, t_D);

					fprintf(lvlog, "Selected TLI Targeting Parameters (First Opportunity): \r\n");
					fprintf(lvlog, "RAS: %f, DEC: %f, C_3 = %f, cos_sigma = %f, e_N = %f \r\n", RAS*DEG, DEC*DEG, C_3, cos_sigma, e_N);

					f = TABLE15[0].f*RAD;
					beta = TABLE15[0].beta*RAD;
					alpha_TS = TABLE15[0].alphaS_TS*RAD;
					T_ST = TABLE15[0].T_ST;
					R_N = TABLE15[0].R_N;
					TargetVector = _V(cos(RAS)*cos(DEC), sin(RAS)*cos(DEC), sin(DEC));
					GATE1 = GATE2 = true;
				}
			}

			//Did ground (MCC/RTCC) provide a target update?
			if (TU)
			{
				//Check for 7- or 10-parameter update
				if (TU10)
				{
					/*
					Target uploading parameters go here; depends on RTCC socketing

					10-parameter update relies on the LVDC to determine the restart time, through the so-called S*T_p test. This starts TB6 when the dot product of the target vector and the burn node
					(pseudonodal) vector is less than a specified magnitude, effectively determining that the cross-plane error in vectors is sufficiently small.

					Needs 10 parameters:
					T_X,Y,Z		Target vector in ephemeral coordinates
					alpha_TS	Desired angle between unit target vector and unit nodal vector
					beta		Angle between pseudonodal vector and radius vector, inplane at restart time
					theta_N		Angle of descending node of transfer ellipse, referenced from launch point
					C_3			Vis-viva energy of transfer ellipse
					f			True anomaly of transfer ellipse
					cos_sigma	Cosine of angle between perigee vector and target vector
					T_ST		Time constant for S*T_P test (determines reignition time and validity of transfer solution)
					*/
				}
				else
				{
					/*
					Target uploading parameters go here; depends on RTCC socketing

					7-parameter update provides a pre-calculated ellipse and TB6 time, using the preloaded T_RG to select the ignition time. This bypasses the S*T_P test, and goes straight into IGM pre-calcs
					without further ado, aside from the INHIBIT checks. alpha_D_op is also set to 0 to bypass onboard calculation of alpha_D.

					Needs 7 parameters:
					T_RP		Time to initate restart preparations (TB6)
					C_3			Vis-viva energy of transfer ellipse
					Inclination	Desired inclination of transfer ellipse, equatorial ref.
					e_N			Eccentricity of the nominal transfer ellipse
					alpha_D		Angle between perigee and descending nodal vector of transfer ellipse
					f			True anomaly of transfer ellipse
					*/

					fprintf(lvlog, "7-parameter update: T_RP: %f, C_3: %f, Inc: %f�, e: %f, alpha_D: %f�, f: %f�, theta_N: %f� \r\n", T_RP, C_3, Inclination*DEG, e, alpha_D*DEG, f*DEG, theta_N*DEG);

					alpha_D_op = 0;
					first_op = false;

					if (TAS - TB5 - T_RP < 0) //Sufficient time after TB6?
					{
						goto O3precalc;
					}
					else
					{
						goto INHcheck;
					}
				}
			}
			
			if (TAS - TB5 - T_ST < 0) //Sufficient time before S*T_P test?
			{
				fprintf(lvlog, "Time until first TB6 check = %f \r\n", TAS - TB5 - T_ST);
				goto orbitalguidance;
			}

			//Determination of S-bar and S-bar-dot
			theta_E = theta_EO + omega_E*t_D;

			MX_EPH = mul(OrbMech::transpose_matrix(MX_A), _M(cos(theta_E), sin(theta_E), 0, 0, 0, -1, -sin(theta_E), cos(theta_E), 0));

			T_P = mul(MX_EPH, unit(TargetVector));
			N = unit(crossp(PosS, DotS));
			PosP = crossp(N,unit(PosS));
			Sbar = unit(PosS)*cos(beta) + PosP*sin(beta);
			DotP = crossp(N, DotS / Mag(PosS));

			Sbardot = DotS / Mag(PosS)*cos(beta) + DotP*sin(beta);

			if(dotp(Sbardot,T_P)<0 && dotp(Sbar,T_P)<=cos(alpha_TS))
			{
				goto INHcheck;
			}
			else
			{goto orbitalguidance;}
			
		INHcheck:
			if (INH)	//XLUNAR switch to INHIBIT in the CSM?
			{
				GATE0 = GATE1 = false;	//Select second opportunity targeting
				first_op = false;
				goto orbitalguidance;
			}
			else if (!GATE0)
			{
				GATE0 = true;	//Bypass targeting routines
				TB6 = TAS;//-simdt;
				LVDC_TB_ETime = 0;
				LVDC_Timebase = 6;
				goto restartprep;
			}
			else if (TAS - TB6 - T_RG < 0) //Time elapsed enough for TB6?
			{goto orbitalguidance;}
		}

O3precalc:
		//Calculates IGM parameters for out-of-orbit burn
		if (GATE3) //IGM Targeting enabled?
		{goto orbitalguidance;}
		if (TU)
		{
			if (!TU10)
			{
				p = (mu / C_3)*(pow(e,2) - 1);
				goto O3GMatrix;
			}
		}

		//Nominal ellipse calculations go here
		cos_psiT = Sbar*T_P;
		sin_psiT = sqrt(1.0 - pow(cos_psiT, 2));
		Sbar_1 = (Sbar*cos_psiT - T_P)*(1.0 / sin_psiT);
		Cbar_1 = crossp(Sbar_1, Sbar);
		Inclination = acos(_V(MX_A.m21, MX_A.m22, MX_A.m23)*Cbar_1);
		X_1 = dotp(_V(MX_A.m31, MX_A.m32, MX_A.m33),crossp(Cbar_1, _V(MX_A.m21, MX_A.m22, MX_A.m23)));
		X_2 = dotp(_V(MX_A.m11, MX_A.m12, MX_A.m13),crossp(Cbar_1, _V(MX_A.m21, MX_A.m22, MX_A.m23)));
		theta_N = atan2(X_1, X_2);
		p_N = mu / C_3*(pow(e_N, 2) - 1.0);
		T_M = p_N / (1.0 - e_N*cos_sigma);
		R = length(PosS);
		e = R/R_N*(e_N-1)+1.0;
		p = mu / C_3*(pow(e, 2) - 1.0);

		if (alpha_D_op)
		{
			//alpha_D = acos(dotp(Sbar, T_P)) - acos((1.0 - p / T_M) / e) + atan2(X_1, X_2);
			alpha_D = acos(dotp(Sbar, T_P)) - acos((1.0 - p / T_M) / e) + atan2(dotp(Sbar_1, crossp(Cbar_1, _V(MX_A.m21, MX_A.m22, MX_A.m23))), dotp(Sbar, crossp(Cbar_1, _V(MX_A.m21, MX_A.m22, MX_A.m23))));
		}
		else
		{
			alpha_D = TABLE15[1].target[tgt_index].alpha_D;
		}

		fprintf(lvlog, "Elliptic parameters: Inc: %f�, e: %f, p: %f, theta_N: %f�, alpha_D: %f�, f: %f�\r\n", Inclination*DEG, e, p, theta_N*DEG, alpha_D*DEG, f*DEG);

	O3GMatrix:
		MX_B = _M(cos(theta_N), 0, sin(theta_N), sin(theta_N)*sin(Inclination), cos(Inclination), -cos(theta_N)*sin(Inclination),
			-sin(theta_N)*cos(Inclination), sin(Inclination), cos(theta_N)*cos(Inclination));
		MX_G = mul(MX_B, MX_A);
		R_T = p / (1.0 + e*cos(f));
		K_5 = sqrt(mu / p);
		V_T = K_5*sqrt(1.0 + 2.0 * e*cos(f) + pow(e, 2));
		gamma_T = atan((e*sin(f)) / (1.0 + cos(f)));
		G_T = -mu / pow(R_T, 2);

		fprintf(lvlog, "TLI Targets: R_T: %f, V_T: %f, gamma_T: %f, G_T: %f\r\n", R_T, V_T, gamma_T, G_T);

		//Update IGM parameters
		Ct = 0.0;
		dotM_2 = dotM_2R;
		dotM_3 = dotM_3R;
		P_c = 0.0;
		ROT = ROTR;
		ROV = ROVR;
		T_2 = T_2R;
		T_1c = T_2;
		Tt_3 = Tt_3R - K_T3*dTt_4;
		Tt_T = T_2 + Tt_3;
		t_B4 = 0.0;
		V_ex2 = V_ex2R;
		V_ex3 = V_ex3R;
		V_TC = 150;
		eps_1 = eps_1R;
		eps_2 = eps_2R;
		eps_3 = eps_3R;
		eps_4 = eps_4R;
		tau3 = tau3R - dTt_4;

		fprintf(lvlog, "Tt_3 = %f, dTt_4 = %f\r\n", Tt_3, dTt_4);

		//Bypass further burn calculations

		GATE3 = true;
		goto orbitalguidance;
	
minorloop:
		//minor loop; TBD: move IGM steering angles & HSL logic here
		if(T_GO - sinceLastCycle <= 0 && HSL == true && S4B_IGN == true){
			//Time for S4B cutoff? We need to check that here -IGM runs every 2 sec only, but cutoff has to be on the second			
			S4B_IGN = false;
			TB5 = TAS;//-simdt;
			LVDC_Timebase = 5;
			LVDC_TB_ETime = 0;
			fprintf(lvlog,"SIVB CUTOFF! TAS = %f \r\n",TAS);
		}
		if (T_GO - sinceLastCycle <= 0 && HSL == true && S4B_REIGN == true) {
			//Time for S4B cutoff? We need to check that here -IGM runs every 2 sec only, but cutoff has to be on the second			
			S4B_REIGN = false;
			TB7 = TAS;//-simdt;
			LVDC_Timebase = 7;
			LVDC_TB_ETime = 0;
			fprintf(lvlog, "SIVB CUTOFF! TAS = %f \r\n", TAS);
			owner->TLI_Ended();
		}

		if(CommandedAttitude.z < -45 * RAD){CommandedAttitude.z = -45 * RAD; } //yaw limits
		if(CommandedAttitude.z > 45 * RAD){CommandedAttitude.z = 45 * RAD; }
		double diff; //aux variable for limit test
		diff = fmod((CommandedAttitude.x - PCommandedAttitude.x + TWO_PI),TWO_PI);
		if(diff > PI){ diff -= TWO_PI; }
		if(abs(diff/dt_g) > CommandRateLimits.x){
			if(diff > 0){
				CommandedAttitude.x = PCommandedAttitude.x + CommandRateLimits.x * dt_g;
			}else{
				CommandedAttitude.x = PCommandedAttitude.x - CommandRateLimits.x * dt_g;
			}
		}
		diff = fmod((CommandedAttitude.y - PCommandedAttitude.y + TWO_PI),TWO_PI);
		if(diff > PI){ diff -= TWO_PI; }
		if(abs(diff/dt_g) > CommandRateLimits.y){
			if(diff > 0){
				CommandedAttitude.y = PCommandedAttitude.y + CommandRateLimits.y * dt_g;
			}else{
				CommandedAttitude.y = PCommandedAttitude.y - CommandRateLimits.y * dt_g;
			}
		}
		diff = fmod((CommandedAttitude.z - PCommandedAttitude.z + TWO_PI),TWO_PI);
		if(diff > PI){ diff -= TWO_PI; }
		if(abs(diff/dt_g) > CommandRateLimits.z){
			if(diff > 0){
				CommandedAttitude.z = PCommandedAttitude.z + CommandRateLimits.z * dt_g;
			}else{
				CommandedAttitude.z = PCommandedAttitude.z - CommandRateLimits.z * dt_g;
			}
		}
		PCommandedAttitude = CommandedAttitude;

		/* **** LVDA **** */
		VECTOR3 DeltaAtt;
		double A1, A2, A3, A4, A5;
		//calculate delta attitude
		DeltaAtt.x = fmod((CurrentAttitude.x - CommandedAttitude.x + TWO_PI), TWO_PI);
		if (DeltaAtt.x > PI) { DeltaAtt.x -= TWO_PI; }
		DeltaAtt.y = fmod((CurrentAttitude.y - CommandedAttitude.y + TWO_PI), TWO_PI);
		if (DeltaAtt.y > PI) { DeltaAtt.y -= TWO_PI; }
		DeltaAtt.z = fmod((CurrentAttitude.z - CommandedAttitude.z + TWO_PI), TWO_PI);
		if (DeltaAtt.z > PI) { DeltaAtt.z -= TWO_PI; }

		//-euler correction-
		//calculate correction factors
		A1 = cos(CurrentAttitude.x) * cos(CurrentAttitude.z);
		A2 = sin(CurrentAttitude.x);
		A3 = sin(CurrentAttitude.z);
		A4 = sin(CurrentAttitude.x) * cos(CurrentAttitude.z);
		A5 = cos(CurrentAttitude.x);
		// ROLL ERROR
		AttitudeError.x = -(DeltaAtt.x + A3 * DeltaAtt.y);
		// PITCH ERROR
		AttitudeError.y = -(A1 * DeltaAtt.y + A2 * DeltaAtt.z);
		// YAW ERROR
		AttitudeError.z = -(-A4 * DeltaAtt.y + A5 * DeltaAtt.z);

		// LV takeover
		// AS-506 Tech Info Summary says this is enabled in TB1. The LVDA will follow the CMC needles.
		// The needles are driven by polynomial until S1C/S2 staging, after which the astronaut can tell the CMC he wants control.
		if(LVDC_Timebase == 5 && (owner->LVGuidanceSwitch.IsDown() && owner->agc.GetInputChannelBit(012, EnableSIVBTakeover))){
			//scaling factor seems to be 31.6; didn't find any source for it, but at least it leads to the right rates
			//note that any 'threshold solution' is pointless: ARTEMIS supports EMEM-selectable saturn rate output
			AttitudeError.x = owner->gdc.fdai_err_x * RAD / 31.6;
			AttitudeError.y = owner->gdc.fdai_err_y * RAD / 31.6;
			AttitudeError.z = owner->gdc.fdai_err_z * RAD / -31.6;
		}

		/* **** FLIGHT CONTROL COMPUTER OPERATIONS **** */
		if(LVDC_Timebase == 1 && LVDC_TB_ETime < 105){
			a_0p = a_0y = 0.9;
			a_0r = 0.9;
			a_1p = a_1y = 0.69;
			a_1r = 0.69;
		}
		if(LVDC_Timebase == 1 && LVDC_TB_ETime >= 105 && LVDC_TB_ETime < 120){
			a_0p = a_0y = 0.45;
			a_0r = 0.45;
			a_1p = a_1y = 0.44;
			a_1r = 0.44;
		}
		if(LVDC_Timebase == 1 && LVDC_TB_ETime >= 120){
			a_0p = a_0y = 0.32;
			a_0r = 0.32;
			a_1p = a_1y = 0.30;
			a_1r = 0.30;
		}
		if(LVDC_Timebase == 3 && LVDC_TB_ETime < 60){
			a_0p = a_0y = 1.12;
			a_0r = 1.12;
			a_1p = a_1y = 1.9;
			a_1r = 1.9;
		}
		if(LVDC_Timebase == 3 && LVDC_TB_ETime >= 60 && LVDC_TB_ETime < 190){
			a_0p = a_0y = 0.65;
			a_0r = 0.65;
			a_1p = a_1y = 1.1;
			a_1r = 1.1;
		}
		if(LVDC_Timebase == 3 && LVDC_TB_ETime >= 190){
			a_0p = a_0y = 0.44;
			a_0r = 0.44;
			a_1p = a_1y = 0.74;
			a_1r = 0.74;
		}
		if(LVDC_Timebase == 4 || LVDC_Timebase == 40){
			a_0p = a_0y = 0.81;
			a_0r = 1;
			a_1p = a_1y = 0.97;
			a_1r = 5;
		}
		if(LVDC_Timebase == 5){
			a_0p = a_0y = 1;
			a_0r = 1;
			a_1p = a_1y = 5;
			a_1r = 5;
		}
		if (LVDC_Timebase == 6) {
			a_0p = a_0y = 0.81;
			a_0r = 1;
			a_1p = a_1y = 0.7;
			a_1r = 5;
		}
		if (LVDC_Timebase == 7) {
			a_0p = a_0y = 1;
			a_0r = 1;
			a_1p = a_1y = 5;
			a_1r = 5;
		}
		beta_pc = a_0p * AttitudeError.y + a_1p * AttRate.y;
		beta_yc = a_0y * AttitudeError.z + a_1y * AttRate.z;
		beta_rc = a_0r * AttitudeError.x + a_1r * AttRate.x;
		if(LVDC_Timebase < 4){
			//orbiter's engines are gimballed differently then the real one
			beta_p1c = beta_pc + beta_rc/pow(2,0.5);
			beta_p2c = beta_pc + beta_rc/pow(2,0.5);
			beta_p3c = beta_pc - beta_rc/pow(2,0.5);
			beta_p4c = beta_pc - beta_rc/pow(2,0.5);
			beta_y1c = beta_yc + beta_rc/pow(2,0.5);
			beta_y2c = beta_yc - beta_rc/pow(2,0.5);
			beta_y3c = beta_yc - beta_rc/pow(2,0.5);
			beta_y4c = beta_yc + beta_rc/pow(2,0.5);
			if(LVDC_Timebase < 3){
				//SIC
				owner->SetThrusterDir(owner->th_main[0],_V(beta_y4c,beta_p4c,1)); 
				owner->SetThrusterDir(owner->th_main[1],_V(beta_y2c,beta_p2c,1));
			}else{
				//SII: engines 2 & 4 are flipped!
				owner->SetThrusterDir(owner->th_main[0],_V(beta_y2c,beta_p2c,1)); 
				owner->SetThrusterDir(owner->th_main[1],_V(beta_y4c,beta_p4c,1)); 
			}
			//1 & 3 are the same on both stages
			owner->SetThrusterDir(owner->th_main[2],_V(beta_y1c,beta_p1c,1)); 
			owner->SetThrusterDir(owner->th_main[3],_V(beta_y3c,beta_p3c,1)); 
		}
		if (LVDC_Timebase == 4 || LVDC_Timebase == 40 || (LVDC_Timebase == 6 && S4B_REIGN == true)) {
			//SIVB powered flight
			beta_p1c = beta_pc; //gimbal angles
			beta_y1c = beta_yc;
			owner->SetThrusterDir(owner->th_main[0], _V(beta_y1c, beta_p1c, 1));
			eps_p = 0; //we want neither the APS pitch thrusters to fire
			eps_ymr = -(a_0r * AttitudeError.x * DEG) - (a_1r * AttRate.x * DEG); //nor the yaw thrusters
			eps_ypr = (a_0r * AttitudeError.x * DEG) + (a_1r * AttRate.x * DEG);
		}
		if(LVDC_Timebase == 5 || (LVDC_Timebase == 6 && S4B_REIGN == false) || LVDC_Timebase == 7){
			//SIVB coast flight; full APS control
			eps_p   = (a_0p * AttitudeError.y * DEG) + (a_1p * AttRate.y * DEG); //pitch thruster demand
			eps_ymr = (a_0y * AttitudeError.z * DEG) - (a_0r * AttitudeError.x * DEG) + (a_1y * AttRate.z * DEG) - (a_1r * AttRate.x * DEG); //yaw minus roll
			eps_ypr = (a_0y * AttitudeError.z * DEG) + (a_0r * AttitudeError.x * DEG) + (a_1y * AttRate.z * DEG) + (a_1r * AttRate.x * DEG); //yaw plus roll
		}
		if(((LVDC_Timebase == 4 || LVDC_Timebase == 40) && S4B_IGN == true)|| LVDC_Timebase == 5 || LVDC_Timebase == 6 || LVDC_Timebase == 7){
			//APS thruster on/off control
			if(eps_p > 1){
				//fire+pitch
				if(eps_p >= 1.6){ owner->SetThrusterLevel(owner->th_att_rot[1],1); }else{ owner->SetThrusterLevel(owner->th_att_rot[1],(eps_p-1)/0.6); }
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[1],0);
			}
			if(eps_p < -1){
				//fire-pitch
				if(eps_p <= -1.6){ owner->SetThrusterLevel(owner->th_att_rot[0],1); }else{ owner->SetThrusterLevel(owner->th_att_rot[0],(-eps_p-1)/0.6); }
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[0],0);
			}
			if(eps_ymr > 1){
				//fire+yaw-roll;
				if(eps_ymr >= 1.6){ owner->SetThrusterLevel(owner->th_att_rot[3],1); }else{ owner->SetThrusterLevel(owner->th_att_rot[3],(eps_ymr-1)/0.6); }
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[3],0);
			}
			if(eps_ymr < -1){
				//fire-yaw+roll;
				if(eps_ymr <= -1.6){ owner->SetThrusterLevel(owner->th_att_rot[5],1); }else{ owner->SetThrusterLevel(owner->th_att_rot[5],(-eps_ymr-1)/0.6); }
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[5],0);
			}
			if(eps_ypr > 1){
				//fire+yaw+roll;
				if(eps_ypr >= 1.6){ owner->SetThrusterLevel(owner->th_att_rot[4],1); }else{ owner->SetThrusterLevel(owner->th_att_rot[4],(eps_ypr-1)/0.6); }
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[4],0);
			}
			if(eps_ypr < -1){
				//fire-yaw-roll;
				if(eps_ypr <= -1.6){ owner->SetThrusterLevel(owner->th_att_rot[2],1); }else{ owner->SetThrusterLevel(owner->th_att_rot[2],(-eps_ypr-1)/0.6); }
			}else{
				owner->SetThrusterLevel(owner->th_att_rot[2],0);
			}
		}
		// Debug if we're launched
		if(LVDC_Timebase > -1){
			if(LVDC_Timebase < 5 || (LVDC_Timebase == 6 && S4B_REIGN)){
				sprintf(oapiDebugString(),"TB%d+%f | T1 = %f | T2 = %f | T3 = %f | Tt_T = %f | ERR %f %f %f | V = %f R= %f",
					LVDC_Timebase,LVDC_TB_ETime,
					T_1,T_2,Tt_3,Tt_T,
					AttitudeError.x*DEG,AttitudeError.y*DEG,AttitudeError.z*DEG,
					V, R/1000);
			} else if (LVDC_Timebase == 40)	{
				sprintf(oapiDebugString(), "TB4A+%f | T1 = %f | T2 = %f | T3 = %f | Tt_T = %f | ERR %f %f %f | V = %f R= %f",
					LVDC_TB_ETime,
					T_1, T_2, Tt_3, Tt_T,
					AttitudeError.x*DEG, AttitudeError.y*DEG, AttitudeError.z*DEG,
					V, R / 1000);
			} else{
				sprintf(oapiDebugString(),"TB%d+%f |CMD %f %f %f | ERR %f %f %f | eps %f %f %f | V = %f R= %f",
					LVDC_Timebase,LVDC_TB_ETime,
					CommandedAttitude.x*DEG,CommandedAttitude.y*DEG,CommandedAttitude.z*DEG,
					AttitudeError.x*DEG,AttitudeError.y*DEG,AttitudeError.z*DEG,
					eps_p, eps_ymr, eps_ypr,V,R/1000);				
			}
		}
		/*
		sprintf(oapiDebugString(),"LVDC: TB%d + %f | PS %f %f %f | VS %f %f %f",
			LVDC_Timebase,LVDC_TB_ETime,
			PosS.x,PosS.y,PosS.z,
			DotS.x,DotS.y,DotS.z);
			*/
		//	CurrentAttitude.x*DEG,CurrentAttitude.y*DEG,CurrentAttitude.z*DEG,V);								

		// Update engine indicators and failure flags
		if(LVDC_EI_On == true){
			double level;
			switch(owner->stage){
				// 5-engine stages
				case PRELAUNCH_STAGE:
				case LAUNCH_STAGE_ONE:
					if(owner->GetThrusterLevel(owner->th_main[0]) >= 0.65  && owner->ENGIND[3] == true){ owner->ENGIND[3] = false; } 
					if(owner->GetThrusterLevel(owner->th_main[0]) < 0.65 && owner->ENGIND[3] == false){  owner->ENGIND[3] = true; }   
					if(owner->GetThrusterLevel(owner->th_main[1]) >= 0.65  && owner->ENGIND[1] == true){ owner->ENGIND[1] = false; } 
					if(owner->GetThrusterLevel(owner->th_main[1]) < 0.65 && owner->ENGIND[1] == false){  owner->ENGIND[1] = true; }   
					if(owner->GetThrusterLevel(owner->th_main[2]) >= 0.65  && owner->ENGIND[0] == true){ owner->ENGIND[0] = false; } 
					if(owner->GetThrusterLevel(owner->th_main[2]) < 0.65 && owner->ENGIND[0] == false){  owner->ENGIND[0] = true; }   
					if(owner->GetThrusterLevel(owner->th_main[3]) >= 0.65  && owner->ENGIND[2] == true){ owner->ENGIND[2] = false; } 
					if(owner->GetThrusterLevel(owner->th_main[3]) < 0.65 && owner->ENGIND[2] == false){  owner->ENGIND[2] = true; }   
					if(owner->GetThrusterLevel(owner->th_main[4]) >= 0.65  && owner->ENGIND[4] == true){ owner->ENGIND[4] = false; } 
					if(owner->GetThrusterLevel(owner->th_main[4]) < 0.65 && owner->ENGIND[4] == false){  owner->ENGIND[4] = true; }   
					break;
				case LAUNCH_STAGE_TWO:
				case LAUNCH_STAGE_TWO_ISTG_JET:
					if(owner->GetThrusterLevel(owner->th_main[0]) >= 0.65  && owner->ENGIND[1] == true){ owner->ENGIND[1] = false; } 
					if(owner->GetThrusterLevel(owner->th_main[0]) < 0.65 && owner->ENGIND[1] == false){  owner->ENGIND[1] = true; }   
					if(owner->GetThrusterLevel(owner->th_main[1]) >= 0.65  && owner->ENGIND[3] == true){ owner->ENGIND[3] = false; } 
					if(owner->GetThrusterLevel(owner->th_main[1]) < 0.65 && owner->ENGIND[3] == false){  owner->ENGIND[3] = true; }   
					if(owner->GetThrusterLevel(owner->th_main[2]) >= 0.65  && owner->ENGIND[0] == true){ owner->ENGIND[0] = false; } 
					if(owner->GetThrusterLevel(owner->th_main[2]) < 0.65 && owner->ENGIND[0] == false){  owner->ENGIND[0] = true; }   
					if(owner->GetThrusterLevel(owner->th_main[3]) >= 0.65  && owner->ENGIND[2] == true){ owner->ENGIND[2] = false; } 
					if(owner->GetThrusterLevel(owner->th_main[3]) < 0.65 && owner->ENGIND[2] == false){  owner->ENGIND[2] = true; }   
					if(owner->GetThrusterLevel(owner->th_main[4]) >= 0.65  && owner->ENGIND[4] == true){ owner->ENGIND[4] = false; } 
					if(owner->GetThrusterLevel(owner->th_main[4]) < 0.65 && owner->ENGIND[4] == false){  owner->ENGIND[4] = true; }
					break;
				// S4B only
				case LAUNCH_STAGE_SIVB:
				case STAGE_ORBIT_SIVB:
					level = owner->GetThrusterLevel(owner->th_main[0]);
					if(level >= 0.65  && owner->ENGIND[0] == true){ owner->ENGIND[0] = false; } // UNLIGHT
					if(level < 0.65 && owner->ENGIND[0] == false){  owner->ENGIND[0] = true; }  // LIGHT
					break;	
				// Error
				default:
					LVDC_EI_On = false;
					break;
			}
		}else{
			owner->ENGIND[0] = false;
			owner->ENGIND[1] = false;
			owner->ENGIND[2] = false;
			owner->ENGIND[3] = false;
			owner->ENGIND[4] = false;
		}

		// End of test for LVDC_Stop
	}

	if(owner->stage == LAUNCH_STAGE_ONE && owner->MissionTime < 12.5){
		// Control contrail
		if (owner->MissionTime > 12)
			owner->contrailLevel = 0;
		else if (owner->MissionTime > 7)
			owner->contrailLevel = (12.0 - owner->MissionTime) / 100.0;
		else if (owner->MissionTime > 2)
			owner->contrailLevel = 1.38 - 0.95 / 5.0 * owner->MissionTime;
		else
			owner->contrailLevel = 1;
	}

	/* **** SATURN 5 ABORT HANDLING **** */
	// The abort PB will be pressed during prelaunch testing, but shouldn't actually trigger an abort before Mode 1 enabled.
	if(owner->bAbort && owner->MissionTime > -300){				
		owner->SetEngineLevel(ENGINE_MAIN, 0);			// Kill the engines
		owner->agc.SetInputChannelBit(030, SIVBSeperateAbort, true);	// Notify the AGC of the abort
		owner->agc.SetInputChannelBit(030, LiftOff, true);	// and the liftoff, if it's not set already
		sprintf(oapiDebugString(),"");					// Clear the LVDC debug line
		LVDC_Stop = 1;									// Stop LVDC program
		// ABORT MODE 1 - Use of LES to extract CM
		// Allowed from T - 5 minutes until LES jettison.
		if(owner->MissionTime > -300 && owner->LESAttached){			
			owner->SetEngineLevel(ENGINE_MAIN, 0);
			owner->SeparateStage(CM_STAGE);
			owner->SetStage(CM_STAGE);
			owner->StartAbort();			// Resets MT, fires LET if attached
			owner->bAbort = false;			// No further processing required
			return; 
		}
		// ABORT MODE 2/3/4 - Eject CSM from LV
		if(owner->stage == LAUNCH_STAGE_ONE){
			// The only way we will get here is if the LET was jettisoned early for some reason.
			owner->SeparateStage(LAUNCH_STAGE_TWO);
			owner->SetStage(LAUNCH_STAGE_TWO);
			return;
		}
		if(owner->stage == LAUNCH_STAGE_TWO){
			// The only way we will get here is if the LET was jettisoned early for some reason.
			owner->SeparateStage (LAUNCH_STAGE_TWO_ISTG_JET);
			owner->SetStage(LAUNCH_STAGE_TWO_ISTG_JET);
			return;
		}
		if(owner->stage == LAUNCH_STAGE_TWO_ISTG_JET){
			// This is the most likely entry point
			owner->SeparateStage(LAUNCH_STAGE_SIVB);
			owner->SetStage(LAUNCH_STAGE_SIVB);
		}
		if(owner->stage == LAUNCH_STAGE_SIVB || owner->stage == STAGE_ORBIT_SIVB){
			// Eject CSM
			owner->SeparateStage(CSM_LEM_STAGE);
			owner->SetStage(CSM_LEM_STAGE);
			// Staging finished.
			owner->StartAbort();			// Resets MT, sets abort light, resets engine lights, etc.
		}
		// Done with the abort request.
		owner->bAbort = false;
	}
}

double LVDC::SVCompare()
{
	VECTOR3 pos, newpos;
	MATRIX3 mat;
	double day;
	modf(oapiGetSimMJD(), &day);
	mat = OrbMech::Orbiter2PACSS13(day + T_L / 24.0 / 3600.0, 28.6082888*RAD, -80.6041140*RAD, Azimuth);
	owner->GetRelativePos(owner->GetGravityRef(), pos);
	newpos = mul(mat, pos);

	return length(PosS - newpos);
}

double LVDC::LinInter(double x0, double x1, double y0, double y1, double x)
{
	return y0 + (y1 - y0)*(x - x0) / (x1 - x0);
}

LVDCTLIparam LVDC::GetTLIParams()
{
	LVDCTLIparam tliparam;

	tliparam.alpha_TS = alpha_TS;
	tliparam.Azimuth = Azimuth;
	tliparam.beta = beta;
	tliparam.cos_sigma = cos_sigma;
	tliparam.C_3 = C_3;
	tliparam.e_N = e_N;
	tliparam.f = f;
	tliparam.mu = mu;
	tliparam.MX_A = MX_A;
	tliparam.omega_E = omega_E;
	tliparam.R_N = R_N;
	tliparam.TargetVector = TargetVector;
	tliparam.TB5 = TB5;
	tliparam.theta_EO = theta_EO;
	tliparam.t_D = t_D;
	tliparam.T_L = T_L;
	tliparam.T_RG = T_RG;
	tliparam.T_ST = T_ST;

	return tliparam;
}