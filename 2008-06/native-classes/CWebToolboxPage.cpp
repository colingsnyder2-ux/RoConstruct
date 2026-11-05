// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
#include "CWebToolbox.h"

CString applicationBaseUrl();

void CWebToolbox::showPage(int page)
{
    CString url;
    url.Format("%s/IDE/ClientToolbox.aspx?Category=%d", static_cast<LPCSTR>(applicationBaseUrl()), page);
    Navigate(static_cast<LPCSTR>(url));
}
