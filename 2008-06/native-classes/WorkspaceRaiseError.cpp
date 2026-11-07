// >>> native-status (generated) -- do not edit >>>
// WorkspaceRaiseError | 2008-06 | linked
// 1/1 exact by name (100%) | 1/1 exact bodies | no strings | verified 2026-11-07| by colin (deepseek:deepseek-flash)
// <<< native-status | src 9e500bb6 | roc native-status --write
#include <afxwin.h>
#include <afxdisp.h>

namespace ATL {
HRESULT __stdcall AtlReportError(REFCLSID, const char*, DWORD, const char*, REFIID, HRESULT);
}

__declspec(noreturn) void __cdecl raiseWorkspaceError(HRESULT hr, REFCLSID context) {
    char buffer[1024];
    COleException* e = new COleException;
    e->m_sc = E_NOTIMPL;
    e->GetErrorMessage(buffer, 1024, 0);
    ATL::AtlReportError(context, buffer, 0, NULL, IID_NULL, hr);
    throw e;
}
