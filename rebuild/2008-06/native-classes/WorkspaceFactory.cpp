// Native ATL CWorkspace factory instantiation: 00450370 and 00401910.
#include <afxwin.h>
#include "CWorkspace.h"

typedef HRESULT (WINAPI *WorkspaceFactory)(ATL::CComObject<CWorkspace>**);
WorkspaceFactory nativeWorkspaceFactory = &ATL::CComObject<CWorkspace>::CreateInstance;
