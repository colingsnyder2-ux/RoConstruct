// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// DocumentInsertModel | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by EspClaude (deepseek:deepseek-flash)
// <<< native-status | src 0b724cd1 | roc native-status --write
#include <afxwin.h>
#include <afxdlgs.h>
#include "CRobloxDoc.h"

void CRobloxDoc::handle_455c30()
{
    CString filter;
    filter.LoadString(0xd0);
    CFileDialog dialog(TRUE, "lua", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter);
    if (dialog.DoModal() == IDOK)
        loadFile((const char*)dialog.GetPathName());
}
