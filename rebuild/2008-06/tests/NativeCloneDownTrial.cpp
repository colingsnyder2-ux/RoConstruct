#include "NativeCloneToolTrial.h"
#include "NativePartDragToolTrial.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"
#include "util/InsertMode.h"
namespace RBX {
MouseCommand* CloneTool::onMouseDown(const UIEvent& input) {
    if (partInstance) {
        partInstance->getCoordinateFrame();
        boost::shared_ptr<PartInstance> part = boost::static_pointer_cast<PartInstance>(partInstance->clone());
        std::vector<boost::shared_ptr<Instance> > instances;
        instances.push_back(part);
        workspace->insertInstances(instances, workspace, INSERT_TO_TREE, SUPPRESS_PROMPTS);
        ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND);
        return (new PartDragTool(part.get(), part->getCoordinateFrame().translation, workspace, boost::shared_ptr<Instance>()))->onMouseDown(input);
    }
    return NULL;
}
}
