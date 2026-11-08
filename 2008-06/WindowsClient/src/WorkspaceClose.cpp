// >>> native-status (generated) -- do not edit >>>
// WorkspaceClose | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 7fd7e242 | roc native-status --write
#include <afxwin.h>
#include "CWorkspace.h"

HRESULT __stdcall CWorkspace::Close() {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    cleanup();
    return S_OK;
}
