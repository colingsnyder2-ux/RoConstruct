#include "NativeGrabToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<MouseCommand, &sGrabTool>::getName() const { return NativeToolName<GrabTool>::get(); }
}
