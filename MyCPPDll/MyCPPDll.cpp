// MyCPPDll.cpp : Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"

#include "MyCPPDll.h"

namespace MyCPPDll
{
	// Constructor
	ClassI::ClassI()
	{
		Version = "1.0.0.0";
	}

	// GetVersion
	char* ClassI::GetVersion()
	{
		return Version;
	}
}


// Methods for using in managed code
//
// ClassICrate
MyCPPDll::ClassI* ClassICrate()
{
	return new MyCPPDll::ClassI();
}

// ClassIGetVersion
char* ClassIGetVersion(MyCPPDll::ClassI* pClassI)
{
	return pClassI->GetVersion();
}

// ClassIDelete
void ClassIDelete(MyCPPDll::ClassI* pClassI)
{
	delete pClassI;
}


