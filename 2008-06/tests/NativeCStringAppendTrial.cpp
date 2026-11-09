// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-import-length
#include <afxwin.h>
CString appendBrowserPath(const CString& source, const char* suffix)
{
    return source + suffix;
}
