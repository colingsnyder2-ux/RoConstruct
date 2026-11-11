// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// >>> native-status (generated) -- do not edit >>>
// CWebToolboxPage | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (deepseek:deepseek-flash)
// <<< native-status | src fe58455f | roc native-status --write
#include "CWebToolbox.h"

CString applicationBaseUrl();

void CWebToolbox::showPage(int page)
{
    CString url;
    url.Format("%s/IDE/ClientToolbox.aspx?Category=%d", static_cast<LPCSTR>(applicationBaseUrl()), page);
    Navigate(static_cast<LPCSTR>(url));
}
