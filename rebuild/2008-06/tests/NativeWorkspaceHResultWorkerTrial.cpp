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
