#include "NativeLaserTrial.h"
#include "StandardVerbs.h"
namespace RBX {
const std::string LaserTool::getCursorName() const { return "GunCursor"; }
MouseCommand* LaserTool::isSticky() const { return new LaserTool(workspace); }
template<> const Name& Named<MouseCommand, sLaserTool>::getName() const { return NativeToolName<LaserTool>::get(); }
}
