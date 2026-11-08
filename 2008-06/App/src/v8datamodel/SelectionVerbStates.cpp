// >>> native-status (generated) -- do not edit >>>
// SelectionVerbStates | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src f0c44da8 | roc native-status --write
#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/PartInstance.h"
#include "Network/Players.h"
#include "util/Sound.h"
#include <stdexcept>

namespace RBX {

inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);

namespace Network {
class Client { public: static bool clientIsPresent(const Instance*, bool); };
class Server { public: static bool serverIsPresent(const Instance*, bool); };
}

static __declspec(noinline) void checkRunPermissions(Instance* instance) {
    if (Network::Client::clientIsPresent(instance, true) && !Network::Server::serverIsPresent(instance, true)) {
        std::string message("Insufficinet permissions");
        throw std::runtime_error(message);
    }
}

void AttachCameraCommand::doIt(IDataState* state) {
    PVInstance* subject = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel))->front();
    workspace->getCamera()->setCameraType(Camera::ATTACH_CAMERA);
    workspace->getCamera()->setCameraSubject(subject);
    recordCameraHistory(getName().c_str(), workspace.get());
    state->setDirty(true);
}

void WatchCameraCommand::doIt(IDataState* state) {
    PVInstance* subject = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel))->front();
    workspace->getCamera()->setCameraType(Camera::WATCH_CAMERA);
    workspace->getCamera()->setCameraSubject(subject);
    recordCameraHistory(getName().c_str(), workspace.get());
    state->setDirty(true);
}

void TrackCameraCommand::doIt(IDataState* state) {
    PVInstance* subject = dynamic_cast<PVInstance*>(ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel))->front().get());
    if (subject) { workspace->getCamera()->setCameraSubject(subject); workspace->getCamera()->setCameraType(Camera::TRACK_CAMERA); }
    recordCameraHistory(getName().c_str(), workspace.get()); state->setDirty(true);
}

void FollowCameraCommand::doIt(IDataState* state) {
    PVInstance* subject = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel))->front();
    workspace->getCamera()->setCameraType(Camera::FOLLOW_CAMERA);
    workspace->getCamera()->setCameraSubject(subject);
    recordCameraHistory(getName().c_str(), workspace.get()); state->setDirty(true);
}

bool WeldSelectionVerb::isEnabled() const { if (!(selection->size() > 0)) return false; Selection* selected = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel)); return selected->size() > 0; }
bool SnapSelectionVerb::isEnabled() const { if (!(selection->size() > 0)) return false; Selection* selected = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel)); return selected->size() > 0; }
bool DuplicateSelectionVerb::isEnabled() const { Selection* selected = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel)); return selected->size() > 0; }
bool GroupSelectionVerb::isEnabled() const { if (!(selection->size() > 0)) return false; bool ok; { ServiceClient<Selection> temporary(dataModel); ok = temporary->size() > 1; } return ok; }

static __declspec(noinline) bool hasChildren(ModelInstance* model) { return model->numChildren() > 0; }
bool UngroupSelectionVerb::isEnabled() const {
    if (!(selection->size() > 0)) return false;
    FilteredSelection<ModelInstance>* selected = ServiceProvider::create<FilteredSelection<ModelInstance> >(static_cast<const ServiceProvider*>(dataModel));
    return selected->findFirst(hasChildren) != 0;
}

bool AttachCameraCommand::isEnabled() const {
    if (!(selection->size() > 0)) return false;
    bool ok;
    { ServiceClient<FilteredSelection<PVInstance> > temporary(dataModel); ok = temporary->size() == 1; }
    if (ok) return true;
    return false;
}
bool TrackCameraCommand::isEnabled() const {
    if (!(selection->size() > 0)) return false;
    Selection* selected = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    return selected->size() == 1;
}
bool FollowCameraCommand::isEnabled() const {
    if (!(selection->size() > 0)) return false;
    FilteredSelection<PVInstance>* selected = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
    bool result = selected->size() == 1;
    return result;
}
bool WatchCameraCommand::isEnabled() const {
    if (!(selection->size() > 0)) return false;
    FilteredSelection<PVInstance>* selected = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
    bool result = selected->size() == 1;
    return result;
}

bool AttachCameraCommand::isChecked() const { Camera* camera = workspace->getCamera(); return camera->getCameraType() == Camera::ATTACH_CAMERA; }
bool TrackCameraCommand::isChecked() const { Camera* camera = workspace->getCamera(); return camera->getCameraType() == Camera::TRACK_CAMERA; }
bool FollowCameraCommand::isChecked() const { Camera* camera = workspace->getCamera(); return camera->getCameraType() == Camera::FOLLOW_CAMERA; }
bool WatchCameraCommand::isChecked() const { Camera* camera = workspace->getCamera(); return camera->getCameraType() == Camera::WATCH_CAMERA; }

void DeleteBase::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    Selection* current = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    if (current->size() > 0) {
        typedef std::vector<boost::shared_ptr<Instance> > Instances;
        boost::shared_ptr<const Instances> list = current->selection.read();
        if (list) for (Instances::const_iterator i = list->begin(); i != list->end(); ++i) {
            boost::shared_ptr<Instance> child = *i;
            if (!dynamic_cast<Workspace*>(child.get()) && !dynamic_cast<Network::Players*>(child.get())) child->setParent(NULL);
        }
        Soundscape::SoundService* sound = ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel));
        sound->playSound(PAGE_SOUND);
        recordCameraHistory(getName().c_str(), workspace.get());
        state->setDirty(true);
    }
}

void __cdecl cannotSelect(boost::shared_ptr<Instance> instance) {
    PartInstance::setLocked(instance.get(), true);
}

void CanNotSelectCommand::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    FilteredSelection<PVInstance>* current = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
    std::for_each(selection->selection->begin(), selection->selection->end(), cannotSelect);
    current->rootSelection->clearSelection();
    recordCameraHistory(getName().c_str(), workspace.get());
    state->setDirty(true);
}

}
