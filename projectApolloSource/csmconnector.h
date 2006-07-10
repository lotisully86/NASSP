/***************************************************************************
  This file is part of Project Apollo - NASSP
  Copyright 2004-2005 Jean-Luc Rocca-Serra, Mark Grant

  ORBITER vessel module: CSM connector classes

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
  *	Revision 1.2  2006/07/09 00:07:07  movieman523
  *	Initial tidy-up of connector code.
  *	
  *	Revision 1.1  2006/07/07 19:35:04  movieman523
  *	First version.
  *	
  **************************************************************************/

#if !defined(_PA_CSMCONNECTOR_H)
#define _PA_CSMCONNECTOR_H

class Saturn;
class CSMcomputer;

///
/// \ingroup Connectors
/// \brief Saturn-class connector base class.
///
class SaturnConnector : public Connector
{
public:
	SaturnConnector();
	~SaturnConnector();

	void SetSaturn(Saturn *sat) { OurVessel = sat; };

protected:
	Saturn *OurVessel;
};

///
/// \ingroup Connectors
/// \brief CSM to IU connector type.
///
class CSMToIUConnector : public SaturnConnector
{
public:
	CSMToIUConnector(CSMcomputer &c);
	~CSMToIUConnector();

	bool ReceiveMessage(Connector *from, ConnectorMessage &m);

	bool IsTLICapable();
	void GetVesselStats(double &isp, double &thrust);
	void ChannelOutput(int channel, int value);

	double GetMass();
	double GetFuelMass();

protected:
	CSMcomputer &agc;
};

///
/// \ingroup Connectors
/// \brief CSM to SIVb connector type.
///
class CSMToSIVBControlConnector : public SaturnConnector
{
public:
	CSMToSIVBControlConnector(CSMcomputer &c);
	~CSMToSIVBControlConnector();

	bool ReceiveMessage(Connector *from, ConnectorMessage &m);

	bool IsVentable();
	bool IsVenting();

	double GetFuelMass();
	void StartVenting();
	void StopVenting();

protected:
	CSMcomputer &agc;
};

///
/// \ingroup Connectors
/// \brief Saturn to IU command connector type.
///
class SaturnToIUCommandConnector : public SaturnConnector
{
public:
	SaturnToIUCommandConnector();
	~SaturnToIUCommandConnector();

	bool ReceiveMessage(Connector *from, ConnectorMessage &m);
};

#endif // _PA_CSMCONNECTOR_H