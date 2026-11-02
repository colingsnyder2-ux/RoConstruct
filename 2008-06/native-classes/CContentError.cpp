#include <afxwin.h>
#include <exception>

extern void __cdecl reportWorkspaceStatus(unsigned short, const char*);
namespace ATL {
HRESULT __stdcall AtlReportError(REFCLSID, const char*, DWORD, const char*, REFIID, HRESULT);
}

HRESULT __cdecl reportWorkspaceSiteError(REFCLSID context, const std::exception& e) {
    const char* message = e.what();
    reportWorkspaceStatus(1, message);
    return ATL::AtlReportError(context, message, 0, NULL, IID_NULL, 0);
}
