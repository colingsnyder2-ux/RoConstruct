#include "../native-headers/v8datamodel/DataModel.h"
#include <cstddef>
typedef char ModelSize[sizeof(RBX::DataModel) == 0x264 ? 1 : -1];
typedef char WorkspaceOffset[offsetof(RBX::DataModel, workspace) == 0x204 ? 1 : -1];
typedef char RunServiceOffset[offsetof(RBX::DataModel, runService) == 0x20c ? 1 : -1];
typedef char GuiRootOffset[offsetof(RBX::DataModel, guiRoot) == 0x21c ? 1 : -1];
typedef char MessageOffset[offsetof(RBX::DataModel, uiMessage) == 0x234 ? 1 : -1];
typedef char DirtyOffset[offsetof(RBX::DataModel, dirty) == 0x258 ? 1 : -1];
typedef char MutexOffset[offsetof(RBX::DataModel, mutex) == 0x25c ? 1 : -1];
typedef char LockSize[sizeof(RBX::DataModel::Lock) == 12 ? 1 : -1];
RBX::Workspace* nativeWorkspace(RBX::DataModel* model) { return model->getWorkspace(); }
