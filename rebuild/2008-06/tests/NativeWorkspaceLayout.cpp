#include <afxwin.h>
#include "../native-classes/CWorkspace.cpp"
#include <cstddef>

typedef char WorkspaceSize[sizeof(CWorkspace) == 0x34 ? 1 : -1];
typedef char DataModelOffset[offsetof(CWorkspace, dataModel) == 0x24 ? 1 : -1];
typedef char RunServiceOffset[offsetof(CWorkspace, runService) == 0x2c ? 1 : -1];
typedef char SafetySize[sizeof(IObjectSafetyRobloxImpl<CWorkspace, 1>) == 8 ? 1 : -1];
