// >>> native-status (generated) -- do not edit >>>
// WorkspaceSiteError | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 6273af49 | roc native-status --write
#include <windows.h>

extern void __cdecl reportWorkspaceStatus(unsigned short, const char*);

namespace ATL {
HRESULT __stdcall AtlReportError(REFCLSID, const char*, DWORD, const char*, REFIID, HRESULT);
}

extern const CLSID workspaceSiteErrorContext = {0xabb1fabf, 0xe42e, 0x45b8, {0x81, 0xb4, 0x39, 0xb1, 0xcf, 0x16, 0x01, 0x42}};

HRESULT __cdecl reportWorkspaceSiteError(REFCLSID context, const char* message, HRESULT result) {
    reportWorkspaceStatus(1, message);
    return ATL::AtlReportError(context, message, 0, NULL, IID_NULL, result);
}
