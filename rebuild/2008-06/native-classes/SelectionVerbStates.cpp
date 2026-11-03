#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"

namespace RBX {

inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);

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

}
