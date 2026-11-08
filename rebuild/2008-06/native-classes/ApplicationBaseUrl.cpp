#include <afxwin.h>

// Original 0096dcf0, populated by application registry/settings startup.
CString applicationBaseUrlText;

CString applicationBaseUrl()
{
    return applicationBaseUrlText;
}
