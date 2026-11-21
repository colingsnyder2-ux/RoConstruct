// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// ?isChecked@ToggleFullscreenVerb@@UBE_NXZ (ToggleFullscreenVerb::isChecked) converted from the exact server analog src/2008-06/00459100.cpp; byte-exact vs 2008.
#include <afxwin.h>
#include "CMainFrame.h"
#include "ViewVerbs.h"

bool ToggleFullscreenVerb::isChecked() const
{
	return static_cast<CMainFrame*>(AfxGetApp()->m_pMainWnd)->stateF8;
}
