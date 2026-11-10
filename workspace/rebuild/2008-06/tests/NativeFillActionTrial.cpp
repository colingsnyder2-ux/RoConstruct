#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ToolsPart.h"
#include "util/Sound.h"
namespace RBX {
void recordCameraHistory(const char*, const Instance*);
MouseCommand* FillTool::onMouseDown(const UIEvent& input) {
    if (PartInstance* part = getPart(input, NULL)) {
        part->setColor(color.get());
        ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(SPLAT_SOUND);
        recordCameraHistory(getName().c_str(), workspace);
        workspace->getDataState().setDirty(true);
    }
    return NULL;
}
}
