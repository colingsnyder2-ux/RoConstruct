// Native ATL CWorkspace factory instantiation: 00450370 and 00401910.
// >>> native-status (generated) -- do not edit >>>
// WorkspaceFactory | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 127f9335 | roc native-status --write
#include <afxwin.h>
#include "CWorkspace.h"

typedef HRESULT (WINAPI *WorkspaceFactory)(ATL::CComObject<CWorkspace>**);
WorkspaceFactory nativeWorkspaceFactory = &ATL::CComObject<CWorkspace>::CreateInstance;
