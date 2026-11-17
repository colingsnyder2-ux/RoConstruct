// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_00408870 (placeholder name for 00408870 from the identity tier): ATL module registry update for resource 0x6E (CComModule/ATL _pAtlModule); body byte-proved
#include <atlbase.h>

HRESULT __stdcall sub_00408870(BOOL bRegister)
{
	return ATL::_pAtlModule->UpdateRegistryFromResource(0x6E, bRegister, NULL);
}
