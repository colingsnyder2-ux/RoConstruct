// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// >>> native-status (generated) -- do not edit >>>
// CWebToolboxPage | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src fe58455f | roc native-status --write
#include "CWebToolbox.h"

CString applicationBaseUrl();

void CWebToolbox::showPage(int page)
{
    CString url;
    url.Format("%s/IDE/ClientToolbox.aspx?Category=%d", static_cast<LPCSTR>(applicationBaseUrl()), page);
    Navigate(static_cast<LPCSTR>(url));
}
