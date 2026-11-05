// ChemCPP.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "ChemCPP.h"
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

// This is an example of an exported variable
CHEMCPP_API int nChemCPP=0;

// This is an example of an exported function.
CHEMCPP_API int fnChemCPP(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see ChemCPP.h for the class definition
CChemCPP::CChemCPP()
{ 
	return; 
}
