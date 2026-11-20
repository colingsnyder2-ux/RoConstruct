// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// ?doIt@ToggleFullscreenVerb@@UAEXPAVIDataState@RBX@@@Z (ToggleFullscreenVerb::doIt) converted from the exact server analog src/2008-06/00459120.cpp; byte-exact vs 2008.
#include <afxwin.h>
#include "ViewVerbs.h"

void ToggleFullscreenVerb::doIt(RBX::IDataState* dataState)
{
	AfxGetApp()->m_pMainWnd->PostMessageA(0x111, 0x80f4, 0);
}
