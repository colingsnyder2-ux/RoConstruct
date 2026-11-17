// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /GS-
#define _CRT_SECURE_NO_DEPRECATE
#include <afxwin.h>
#include <stdio.h>

// Original 00456120 (open: 289 = 289 bytes, sole diff is the hidden return pointer load into esi, hoisted before push edi in the original).
// File-local timestamp "DD.MM.YYYY" (optional) followed by "HH_MM_mmm".
CString f(bool includeDate)
{
    SYSTEMTIME time;
    char buffer[256];
    GetLocalTime(&time);
    CString result;
    if (includeDate) {
        sprintf(buffer, "%02u.%02u.%u", (unsigned)time.wDay, (unsigned)time.wMonth, (unsigned)time.wYear);
        result = result + buffer;
    }
    sprintf(buffer, "%02u_%02u_%03u", (unsigned)time.wHour, (unsigned)time.wMinute, (unsigned)time.wMilliseconds);
    result = result + buffer;
    return result;
}
