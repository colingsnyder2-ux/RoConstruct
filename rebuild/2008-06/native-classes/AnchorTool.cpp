// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/cow-noinline-read
#include "tool/ModelTools.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"

namespace RBX {
Instance* findUnanchoredPart(Instance* instance)
{
    if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
        if (!part->getAnchored()) return part;
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > children = instance->children.read();
    if (children) {
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = children->end();
        std::vector<boost::shared_ptr<Instance> >::const_iterator it = children->begin();
        for (; it != end; ++it)
            if (findUnanchoredPart(it->get())) return it->get();
    }
    return NULL;
}

void applyAnchored(Instance* instance, const bool& value)
{
    bool local = value;
    if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
        part->setAnchored(local);
    else {
        Instance::AnchorAction action = { local };
        instance->applyAnchoredToChildren(action);
    }
}

void AnchorTool::onMouseHover(const UIEvent& input)
{
    boost::shared_ptr<Instance> previous = target;
    ModelTool::onMouseHover(input);
    if (previous != target) {
        bool value = target ? findUnanchoredPart(target.get()) == NULL : false;
        anchored = value;
    }
}

MouseCommand* AnchorTool::onMouseDown(const UIEvent&)
{
    if (target && !PartInstance::getLocked(target.get())) {
        bool value = findUnanchoredPart(target.get()) != NULL;
        applyAnchored(target.get(), value);
        ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(PING_SOUND);
    }
    return this;
}
}
