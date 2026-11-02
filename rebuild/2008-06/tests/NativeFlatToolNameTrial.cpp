#include "NativeFlatToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<SurfaceTool, sFlatTool>::getName() const { return NativeToolName<FlatTool>::get(); }
}
