// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// RotateAxisAction | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 8efbaf47 | roc native-status --write
#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "util/Sound.h"
#include "tool/MegaDragger.h"
#include <stdexcept>

namespace RBX {
inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);
namespace Network {
class Client { public: static bool clientIsPresent(const Instance*, bool); };
class Server { public: static bool serverIsPresent(const Instance*, bool); };
}

static __declspec(noinline) void checkRunPermissions(Instance* instance)
{
    if (Network::Client::clientIsPresent(instance, true) && !Network::Server::serverIsPresent(instance, true)) {
        std::string message("Insufficinet permissions");
        throw std::runtime_error(message);
    }
}

void RotateAxisCommand::rotateAboutAxis(const G3D::Matrix3& axis, const std::vector<PVInstance*>& items)
{
    if (!items.empty()) {
        MegaDragger dragger(NULL, items, workspace.get());
        dragger.startDragging();
        dragger.safeRotate(axis);
        dragger.finishDragging();
        workspace->raiseDrawChanged();
    }
}

void RotateAxisCommand::doIt(IDataState* state)
{
    checkRunPermissions(dataModel);
    FilteredSelection<PVInstance>* selected = ServiceProvider::create<FilteredSelection<PVInstance> >(
        static_cast<const ServiceProvider*>(dataModel));
    rotateAboutAxis(getRotationAxis(), selected->items());
    ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel))->playSound(CLICK_SOUND);
    workspace->raiseDrawChanged();
    recordCameraHistory(getName().c_str(), dataModel);
    state->setDirty(true);
}
}
