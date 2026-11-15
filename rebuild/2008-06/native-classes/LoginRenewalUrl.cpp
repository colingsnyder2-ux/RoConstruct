// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#include <afx.h>
#include <string>

CString applicationBaseUrl();

std::string loginRenewalUrl()
{
    std::string url(applicationBaseUrl());
    url += "/Game/KeepAlivePinger.ashx";
    return url;
}
