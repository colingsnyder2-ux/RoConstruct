// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// >>> native-status (generated) -- do not edit >>>
// WorkspaceHResult | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 54da7a95 | roc native-status --write
#include <afxwin.h>
#include <afxdisp.h>

extern void __cdecl reportWorkspaceStatus(unsigned short, const char*);

void __cdecl reportWorkspaceHResult(int severity, HRESULT code, const char* file, int line) {
    COleException error;
    char buffer[1024];
    error.m_sc = code;
    error.COleException::GetErrorMessage(buffer, 1024, 0);
    CStringA message;
    message.Format("HRESULT = %d: %s\n%s(%d)", code, buffer, file, line);
    reportWorkspaceStatus((unsigned short)severity, message);
}
