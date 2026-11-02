#include "NativeHammerWorkerTrial.h"
#include "v8datamodel/PartInstance.h"
#include "StandardVerbs.h"
namespace RBX {
void HammerTool::onMouseIdle(const UIEvent& input) { partInstance = shared_from(getUnlockedPartByLocalCharacter(input)); }
void HammerTool::render3dAdorn(Adorn* adorn) { if (partInstance) partInstance->render3dSelect(adorn, static_cast<SelectState>(1)); }
const std::string HammerTool::getCursorName() const { return partInstance ? "HammerOverCursor" : "HammerCursor"; }
MouseCommand* HammerTool::isSticky() const { return new HammerTool(workspace); }
template<> const Name& Named<MouseCommand, sHammerTool>::getName() const { return NativeToolName<HammerTool>::get(); }
}
