#include "NativeHammerWorkerTrial.h"
#include "v8datamodel/PartInstance.h"
#include "StandardVerbs.h"
namespace RBX {
static G3D::Vector3 idlePoint;
void HammerTool::onMouseIdle(const UIEvent& input) { partInstance = shared_from(getUnlockedPartByLocalCharacter(input, idlePoint)); }
void HammerTool::render3dAdorn(Adorn* adorn) { if (partInstance) partInstance->render3dSelect(adorn, static_cast<SelectState>(1)); }
const std::string HammerTool::getCursorName() const { return partInstance ? "HammerOverCursor" : "HammerCursor"; }
MouseCommand* HammerTool::isSticky() const { return new HammerTool(workspace); }
// Named<..., sHammerTool>::getName lives in native-classes/ToolVerbFactories.cpp
}
