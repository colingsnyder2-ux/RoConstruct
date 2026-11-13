// >>> native-status (generated) -- do not edit >>>
// WorkspaceClose | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 7fd7e242 | roc native-status --write
#include <afxwin.h>
#include "CWorkspace.h"

HRESULT __stdcall CWorkspace::Close() {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    cleanup();
    return S_OK;
}
