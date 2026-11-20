// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// ?doIt@HelpCommand@@UAEXPAVIDataState@RBX@@@Z (HelpCommand::doIt) converted from the exact server analog src/2008-06/00459150.cpp; byte-exact vs 2008.
#include <afxwin.h>
#include "CRobloxView.h"
#include "ViewVerbs.h"

void HelpCommand::doIt(RBX::IDataState* dataState)
{
	view->PostMessageA(0x111, 0x80fd, 0);
}
