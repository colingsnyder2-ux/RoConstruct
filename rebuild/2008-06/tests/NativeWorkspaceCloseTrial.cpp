#include <afxwin.h>
#include "CWorkspace.h"

HRESULT __stdcall CWorkspace::Close() {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    cleanup();
    return S_OK;
}
