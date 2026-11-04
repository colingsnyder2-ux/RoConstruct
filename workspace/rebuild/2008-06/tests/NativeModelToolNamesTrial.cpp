#include "NativeModelToolsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<ModelTool, sAnchorTool>::getName() const { return NativeToolName<AnchorTool>::get(); }
template<> const Name& Named<ModelTool, sLockTool>::getName() const { return NativeToolName<LockTool>::get(); }
}
