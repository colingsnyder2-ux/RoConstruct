#include <afxwin.h>
#include "CWorkspace.h"

typedef HRESULT (WINAPI *WorkspaceFactory)(ATL::CComObject<CWorkspace>**);
WorkspaceFactory nativeWorkspaceFactory = &ATL::CComObject<CWorkspace>::CreateInstance;
