#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ToolsPart.h"
#include "util/Sound.h"
namespace RBX {
MouseCommand* DropperTool::onMouseDown(const UIEvent& input) {
    if (PartInstance* part = getPart(input, NULL)) {
        FillTool::color.set(part->getColor());
        ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(CLICK_SOUND);
    }
    return NULL;
}
}
