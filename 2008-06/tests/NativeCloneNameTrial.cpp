#include "NativeCloneToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<MouseCommand, &sCloneTool>::getName() const { return NativeToolName<CloneTool>::get(); }
}
