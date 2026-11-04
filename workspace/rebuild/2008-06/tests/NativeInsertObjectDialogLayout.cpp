#include <stddef.h>
#include "CInsertObjectDialog.h"
// Offsets from original constructor 0041fe00 and destructor 0041ff40; size from CRuntimeClass 0080f2e0.
typedef char InsertObjectDialogSize[sizeof(CInsertObjectDialog) == 0xfc ? 1 : -1];
typedef char InsertObjectDialogParent[offsetof(CInsertObjectDialog, parent) == 0x74 ? 1 : -1];
typedef char InsertObjectDialogInstances[offsetof(CInsertObjectDialog, instances) == 0x7c ? 1 : -1];
typedef char InsertObjectDialogClassName[offsetof(CInsertObjectDialog, className) == 0x94 ? 1 : -1];
typedef char InsertObjectDialogSelected[offsetof(CInsertObjectDialog, selected) == 0x98 ? 1 : -1];
typedef char InsertObjectDialogImages[offsetof(CInsertObjectDialog, images) == 0xa0 ? 1 : -1];
typedef char InsertObjectDialogList[offsetof(CInsertObjectDialog, list) == 0xa8 ? 1 : -1];
typedef char ClassImagesSize[sizeof(CClassImages) == 8 ? 1 : -1];
