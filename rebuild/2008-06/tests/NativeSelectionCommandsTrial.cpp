#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "Network/Players.h"
#include "util/Sound.h"
#include <stdexcept>
#include "tool/MegaDragger.h"
#include <boost/bind.hpp>
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
bool GroupSelectionVerb::isEnabled() const { if (!(selection->size() > 0)) return false; bool ok; { ServiceClient<Selection> temporary(dataModel); ok=temporary->size() > 1; } return ok; }
template<class T> T* FilteredSelection<T>::findFirst(bool (*predicate)(T*)) {
    typename std::vector<T*>::iterator found = std::find_if(filteredSelection.begin(), filteredSelection.end(), predicate);
    if (found != filteredSelection.end()) return *found;
    return NULL;
}
template ModelInstance* FilteredSelection<ModelInstance>::findFirst(bool (*)(ModelInstance*));
template PVInstance* FilteredSelection<PVInstance>::findFirst(bool (*)(PVInstance*));
static __declspec(noinline) bool hasChildren(ModelInstance* model) { return model->numChildren() > 0; }
bool UngroupSelectionVerb::isEnabled() const {
    if (!(selection->size() > 0)) return false;
    FilteredSelection<ModelInstance>* selected = ServiceProvider::create<FilteredSelection<ModelInstance> >(static_cast<const ServiceProvider*>(dataModel));
    return selected->findFirst(hasChildren) != 0;
}
static __declspec(noinline) bool controllable(PVInstance* item) { return item->isControllable(); }
bool ControllerCommand::isEnabled() const {
 if (!(selection->size() > 0)) return false;
 FilteredSelection<PVInstance>* items = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
 return items->findFirst(controllable) != NULL;
}
struct DifferentController { Controller::ControllerType value; explicit DifferentController(Controller::ControllerType v):value(v){} bool operator()(PVInstance* item) const { return item->getControllerType() != value; } };
static __declspec(noinline) void setController(Controller::ControllerType value, PVInstance* item) { item->setControllerType(value); }
struct ApplyController { void (*fn)(Controller::ControllerType, PVInstance*); Controller::ControllerType value; explicit ApplyController(Controller::ControllerType v):fn(setController),value(v){} void operator()(PVInstance* item) const { fn(value,item); } };
template<class T> T* FilteredSelection<T>::findDifferent(Controller::ControllerType value) { typename std::vector<T*>::iterator it = std::find_if(filteredSelection.begin(),filteredSelection.end(),DifferentController(value)); if (it!=filteredSelection.end()) return *it; return NULL; }
template PVInstance* FilteredSelection<PVInstance>::findDifferent(Controller::ControllerType);
void ControllerCommand::applyController(int type) {
 FilteredSelection<PVInstance>* selected=ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
 Controller::ControllerType desired = static_cast<Controller::ControllerType>(type);
 Controller::ControllerType value=selected->findDifferent(desired) ? desired : Controller::NO_CONTROLLER;
 std::for_each(selected->items().begin(),selected->items().end(),ApplyController(value));
}
void PrimaryControllerCommand::doIt(IDataState* state) { applyController(1); recordCameraHistory(getName().c_str(),workspace.get()); state->setDirty(true); }
void SecondaryControllerCommand::doIt(IDataState* state) { applyController(2); recordCameraHistory(getName().c_str(),workspace.get()); state->setDirty(true); }
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
void __cdecl cannotSelect(boost::shared_ptr<Instance> instance) { PartInstance::setLocked(instance.get(), true); }
void CanNotSelectCommand::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    FilteredSelection<PVInstance>* current = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
    std::for_each(selection->selection->begin(), selection->selection->end(), cannotSelect);
    current->rootSelection->clearSelection();
    recordCameraHistory(getName().c_str(), workspace.get());
    state->setDirty(true);
}
void AllCanSelectCommand::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    Workspace* workspace = dataModel->getWorkspace();
    PartInstance::setLocked(workspace, false);
    recordCameraHistory(getName().c_str(), workspace);
    state->setDirty(true);
}
void SelectAllCommand::doIt(IDataState*) { checkRunPermissions(dataModel); dataModel->getWorkspace()->selectAll(); }
void DeleteBase::doIt(IDataState* state) {
 checkRunPermissions(dataModel);
 Selection* current=ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
 if (current->size()>0) {
  typedef std::vector<boost::shared_ptr<Instance> > Instances;
  boost::shared_ptr<const Instances> list=current->selection.read();
  if (list) for (Instances::const_iterator i=list->begin();i!=list->end();++i) { boost::shared_ptr<Instance> child=*i; if (!dynamic_cast<Workspace*>(child.get()) && !dynamic_cast<Network::Players*>(child.get())) child->setParent(NULL); }
  Soundscape::SoundService* sound=ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel));
  sound->playSound(PAGE_SOUND);
  recordCameraHistory(getName().c_str(),workspace.get());
  state->setDirty(true);
 }
}
void weldInstance(boost::shared_ptr<Instance>);
void snapInstance(boost::shared_ptr<Instance>);
void WeldSelectionVerb::doIt(IDataState* state) {
 checkRunPermissions(dataModel);
 ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
 std::for_each(selection->selection->begin(), selection->selection->end(), boost::bind(weldInstance,_1));
 Soundscape::SoundService* sound=ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel)); sound->playSound(PING_SOUND);
 recordCameraHistory(getName().c_str(),workspace.get()); state->setDirty(true);
}
void SnapSelectionVerb::doIt(IDataState* state) {
 checkRunPermissions(dataModel);
 ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
 std::for_each(selection->selection->begin(), selection->selection->end(), boost::bind(snapInstance,_1));
 Soundscape::SoundService* sound=ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel)); sound->playSound(PING_SOUND);
 recordCameraHistory(getName().c_str(),workspace.get()); state->setDirty(true);
}
void RunCommand::doIt(IDataState*) { checkRunPermissions(dataModel); RunService* service = runService.operator->(); service->setRunState(RS_RUNNING); }
void StopCommand::doIt(IDataState*) { checkRunPermissions(dataModel); RunService* service = runService.operator->(); service->setRunState(RS_PAUSED); }
void ResetCommand::doIt(IDataState*) { checkRunPermissions(dataModel); RunService* service = runService.operator->(); service->setRunState(RS_NORMAL); }
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
bool FirstPersonCommand::isEnabled() const {
    return dataModel->getWorkspace()->getCamera()->isFirstPersonCamera();
}
bool RunCommand::isEnabled() const {
    RunState state = runService->getRunState();
    return !Network::Client::clientIsPresent(dataModel, true) && state != RS_RUNNING;
}
bool ResetCommand::isEnabled() const {
    RunState state = runService->getRunState();
    return (state == RS_RUNNING || state == RS_PAUSED) && !Network::Players::findLocalPlayer(dataModel);
}
bool StopCommand::isEnabled() const {
    return runService->getRunState() == RS_RUNNING;
}

BoolPropertyVerb::BoolPropertyVerb(const std::string& name, DataModel* model, const char* property) : EditSelectionVerb(name, model), propertyName(Name::declare(property, -1)) {}
AnchorVerb::AnchorVerb(DataModel* model) : BoolPropertyVerb("AnchorVerb", model, "Anchored") {}
TranslucentVerb::TranslucentVerb(DataModel* model) : BoolPropertyVerb("TranslucentVerb", model, "Transparent") {}
CanCollideVerb::CanCollideVerb(DataModel* model) : BoolPropertyVerb("CanCollideVerb", model, "CanCollide") {}
GroupSelectionVerb::GroupSelectionVerb(DataModel* model) : EditSelectionVerb("Group", model) {}
WeldSelectionVerb::WeldSelectionVerb(DataModel* model) : EditSelectionVerb("WeldSelection", model) {}
SnapSelectionVerb::SnapSelectionVerb(DataModel* model) : EditSelectionVerb("SnapSelection", model) {}
UngroupSelectionVerb::UngroupSelectionVerb(DataModel* model) : EditSelectionVerb("UnGroup", model) {}
DuplicateSelectionVerb::DuplicateSelectionVerb(DataModel* model) : EditSelectionVerb("Duplicate", model) {}
AttachCameraCommand::AttachCameraCommand(DataModel* model) : EditSelectionVerb("AttachCamera", model) {}
TrackCameraCommand::TrackCameraCommand(DataModel* model) : EditSelectionVerb("TrackCamera", model) {}
FollowCameraCommand::FollowCameraCommand(DataModel* model) : EditSelectionVerb("FollowCamera", model) {}
WatchCameraCommand::WatchCameraCommand(DataModel* model) : EditSelectionVerb("WatchCamera", model) {}
MoveDownSelectionVerb::MoveDownSelectionVerb(DataModel* model) : EditSelectionVerb("SelectionDown", model) {}
bool AttachCameraCommand::isChecked() const {
    Camera* camera = workspace->getCamera();
    return camera->getCameraType() == Camera::ATTACH_CAMERA;
}
bool TrackCameraCommand::isChecked() const {
    Camera* camera = workspace->getCamera();
    return camera->getCameraType() == Camera::TRACK_CAMERA;
}
bool FollowCameraCommand::isChecked() const {
    Camera* camera = workspace->getCamera();
    return camera->getCameraType() == Camera::FOLLOW_CAMERA;
}
bool WatchCameraCommand::isChecked() const {
    Camera* camera = workspace->getCamera();
    return camera->getCameraType() == Camera::WATCH_CAMERA;
}
void MoveDownSelectionVerb::doIt(IDataState* state) {
 checkRunPermissions(dataModel);
 FilteredSelection<PVInstance>* selected = ServiceProvider::create<FilteredSelection<PVInstance> >(static_cast<const ServiceProvider*>(dataModel));
 if (selected->size() > 0) {
  MegaDragger dragger(NULL, selected->items(), workspace.get());
  dragger.startDragging();
  G3D::Vector3 moved = dragger.safeMoveNoDrop(G3D::Vector3(0.0f, -1.2f, 0.0f));
  dragger.finishDragging();
  ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel))->playSound(moved.y != 0 ? CLICK_SOUND : BOING_SOUND);
  workspace->raiseDrawChanged();
  recordCameraHistory(getName().c_str(), workspace.get());
  state->setDirty(true);
 }
}
}
