#include "tool/GroupDragTool.h"
#include "StandardVerbs.h"
namespace RBX {
template<> struct NativeToolText<GroupDragTool> { static const char* get() { return "GroupDragTool"; } };
template<> const Name& Named<MouseCommand, sGroupDragTool>::getName() const { return NativeToolName<GroupDragTool>::get(); }
}
