#include <afxwin.h>
#include <stddef.h>
#include "CWorkspace.h"
#include "CContent.h"

typedef char WorkspaceWriteSize[sizeof(CWorkspace) == 0x34 ? 1 : -1];
typedef char WorkspaceWriteDataModel[offsetof(CWorkspace, dataModel) == 0x24 ? 1 : -1];
typedef char WorkspaceWriteRunService[offsetof(CWorkspace, runService) == 0x2c ? 1 : -1];
typedef char WorkspaceWriteContentSize[sizeof(ATL::CComObject<CContent>) == 0x94 ? 1 : -1];
typedef char WorkspaceWriteContentStream[offsetof(CContent, stream) == 0xc ? 1 : -1];
