// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// ?doIt@LockPlayModeVerb@@UAEXPAVIDataState@RBX@@@Z (LockPlayModeVerb::doIt) converted from the exact server analog src/2008-06/004590a0.cpp; byte-exact vs 2008.
#include <afxwin.h>
#include "ViewVerbs.h"

void LockPlayModeVerb::doIt(RBX::IDataState* dataState)
{
	if (isEnabled())
	{
		AfxGetApp()->m_pMainWnd->PostMessageA(0x111, 0x80f5, 0);
	}
}
