// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// LoginRenewalUrl | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src f1105bc8 | roc native-status --write
#include <afx.h>
#include <string>

CString applicationBaseUrl();

std::string loginRenewalUrl()
{
    std::string url(applicationBaseUrl());
    url += "/Game/KeepAlivePinger.ashx";
    return url;
}
