#include "tool/NullTool.h"
namespace RBX {
typedef char NewNullToolSize[sizeof(NewNullTool) == 0x48 ? 1 : -1];
MouseCommand* createDefaultMouseCommand(Workspace* workspace) {
    return new NewNullTool(workspace);
}
}
