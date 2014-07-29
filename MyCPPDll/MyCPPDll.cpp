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

