#include "v8datamodel/ToolsPart.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<PartTool, &sFillTool>::getName() const { return NativeToolName<FillTool>::get(); }
template<> const Name& Named<PartTool, &sDropperTool>::getName() const { return NativeToolName<DropperTool>::get(); }
template<> const Name& Named<PartTool, &sModelSetPrimaryPartTool>::getName() const { return NativeToolName<ModelSetPrimaryPartTool>::get(); }
}
