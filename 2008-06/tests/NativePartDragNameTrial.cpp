#include "tool/PartDragTool.h"
#include "StandardVerbs.h"
namespace RBX {
template<> struct NativeToolText<PartDragTool> { static const char* get() { return "PartDragTool"; } };
template<> const Name& Named<MouseCommand, sPartDragTool>::getName() const { return NativeToolName<PartDragTool>::get(); }
}
