#include "LuaHtmlBinder2008/LuaHtmlBinder2008.h"
#include "AppLeaves2008/DHTMLWindowService2008.h"
#include "security/SecurityContext.h"
#include <algorithm>
#include <stdexcept>
#include <boost/bind.hpp>
#include <G3D/format.h>
#include "v8datamodel/DataModel.h"

namespace {
bool ignoreChange()
{
    return true;
}
}

CLuaHtmlView::Binder::PropBinding::PropBinding(boost::shared_ptr<RBX::Instance> instance,
                                               const RBX::Reflection::PropertyDescriptor& descriptor, Binder* binder)
    : instance(instance), descriptor(&descriptor)
{
#ifdef NATIVE_LUAHTMLBINDER2008_PENDING
    connection = RBX::Instance::event_propertyChanged.connect(
        instance.get(), boost::bind(&Binder::onPropertyChanged, _1, boost::cref(descriptor), binder), 10);
#endif
}

std::string CLuaHtmlView::Binder::PropBinding::getValue() const
{
    RBX::Security::Impersonator impersonate(RBX::Security::GameScript);
    return descriptor->getStringValue(instance.get());
}

void CLuaHtmlView::Binder::PropBinding::setValue(const std::string* value)
{
    RBX::Security::Impersonator impersonate(RBX::Security::GameScript);
    descriptor->setStringValue(instance.get(), *value);
}

CLuaHtmlView::Binder::Binder(IHTMLInputElement* element) : updatePending(false), element(element)
{
    handler = new EventHandler(boost::bind(&Binder::onChange, this));
    CComQIPtr<IHTMLElement2> element2(element);
    VARIANT_BOOL result;
    HRESULT hr = element2->attachEvent(CComBSTR("onchange"), handler, &result);
    if (hr != S_OK)
        throw std::runtime_error("attachEvent failed");
    if (!result)
        throw std::runtime_error("attachEvent failed");
}

CLuaHtmlView::Binder::~Binder()
{
    handler->handler = &ignoreChange;
    CComQIPtr<IHTMLElement2> element2(element);
    element2->detachEvent(CComBSTR("onchange"), handler);
}

void CLuaHtmlView::Binder::bind(boost::shared_ptr<RBX::Instance> instance,
                                const RBX::Reflection::PropertyDescriptor& descriptor)
{
    bindings.push_back(boost::shared_ptr<PropBinding>(new PropBinding(instance, descriptor, this)));
    updateElement();
}

bool CLuaHtmlView::Binder::onChange()
{
    CComBSTR value;
    element->get_value(&value);
    std::string text((LPCSTR)CStringA(value));
    std::for_each(bindings.begin(), bindings.end(), boost::bind(&PropBinding::setValue, _1, &text));
    return true;
}

void CLuaHtmlView::Binder::requestUpdate()
{
    if (!updatePending)
    {
        htmlMarshaller->post(boost::bind(&Binder::updateElement, shared_from_this()));
        updatePending = true;
    }
}

void CLuaHtmlView::Binder::updateElement()
{
    updatePending = false;
    std::string text;
    std::list<boost::shared_ptr<PropBinding> >::const_iterator it = bindings.begin(), end = bindings.end();
    if (it != end)
    {
        text = (*it)->getValue();
        ++it;
    }
    for (; it != end; ++it)
    {
        if (text != (*it)->getValue())
        {
            text.clear();
            break;
        }
    }
    element->put_value(CComBSTR(text.c_str()));
}

void CLuaHtmlView::Binder::onPropertyChanged(const RBX::Reflection::PropertyDescriptor* changed,
                                             const RBX::Reflection::PropertyDescriptor& descriptor, Binder* binder)
{
    if (changed == &descriptor)
        binder->requestUpdate();
}

void CLuaHtmlView::setBody(const char* html)
{
    CComQIPtr<IHTMLDocument2> document(GetHtmlDocument());
    if (!document)
        throw std::runtime_error("The HtmlDocument is not loaded");
    CComPtr<IHTMLElement> body;
    document->get_body(&body);
    if (!body)
        throw std::runtime_error("The HtmlDocument does not contain a body");
    body->put_innerHTML(CComBSTR(html));
}

void CLuaHtmlView::unbindAll()
{
    RBX::DataModel::Lock lock(dataModel);
    binders.clear();
}

bool CLuaHtmlView::isSameObject(IUnknown* first, IUnknown* second)
{
    CComPtr<IUnknown> firstUnknown;
    CComPtr<IUnknown> secondUnknown;
    CComPtr<IObjectIdentity> identity;
    if (first == second)
        return true;
    if (first == NULL || second == NULL)
        return false;
    first->QueryInterface(IID_IUnknown, (void**)&firstUnknown);
    second->QueryInterface(IID_IUnknown, (void**)&secondUnknown);
    if (firstUnknown != secondUnknown)
    {
        if (firstUnknown == NULL || secondUnknown == NULL)
            return false;
        if (FAILED(firstUnknown->QueryInterface(IID_IObjectIdentity, (void**)&identity)) || identity == NULL)
            return false;
        if (identity->IsEqualObject(secondUnknown) != S_OK)
            return false;
    }
    return true;
}

void CLuaHtmlView::bindElement(boost::shared_ptr<RBX::Instance> object,
                               const RBX::Reflection::PropertyDescriptor& property, const char* htmlElementId)
{
    CComQIPtr<IHTMLDocument2> document(GetHtmlDocument());
    if (!document)
        throw std::runtime_error("The HtmlDocument is not loaded");
    CComPtr<IHTMLElementCollection> all;
    document->get_all(&all);
    CComPtr<IDispatch> dispatch;
    all->item(CComVariant(htmlElementId), CComVariant(), &dispatch);
    if (!dispatch)
        throw std::runtime_error(G3D::format("%s not found", htmlElementId));
    CComQIPtr<IHTMLInputElement> input(dispatch);
    if (!input)
        throw std::runtime_error(G3D::format("%s is not an input element", htmlElementId));

    Binder* binder = NULL;
    std::list<boost::shared_ptr<Binder> >::iterator it = binders.begin(), end = binders.end();
    for (; it != end; ++it)
        if (isSameObject((*it)->element, input))
            break;
    if (it != end)
        binder = it->get();
    if (!binder)
    {
        RBX::DataModel::Lock lock(dataModel);
        binder = new Binder(input);
        binders.push_back(boost::shared_ptr<Binder>(binder));
    }
    binder->bind(object, property);
}

#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Selection.h"
#include "util/Sound.h"

namespace RBX
{
	inline const G3D::Rect2D& RootInstance::getViewPort() { return viewPort; }
}
#include "NativeCameraCommands.h"

namespace RBX
{
	void CameraVerb::doIt(IDataState* state)
	{
		ServiceProvider::create<Soundscape::SoundService>(static_cast<Instance*>(workspace))->playSound(STEP_SOUND);
		state->setDirty(true);
	}

	void CameraPanLeftCommand::doIt(IDataState* state)
	{
		workspace->getCamera()->panUnits(-1);
		CameraVerb::doIt(state);
	}

	void CameraPanRightCommand::doIt(IDataState* state)
	{
		workspace->getCamera()->panUnits(1);
		CameraVerb::doIt(state);
	}

	void CameraTiltUpCommand::doIt(IDataState* state)
	{
		Camera* camera = workspace->getCamera();
		if (camera->tiltUnits(-1))
			CameraVerb::doIt(state);
	}

	void CameraTiltDownCommand::doIt(IDataState* state)
	{
		Camera* camera = workspace->getCamera();
		if (camera->tiltUnits(1))
			CameraVerb::doIt(state);
	}

	void CameraZoomInCommand::doIt(IDataState* state)
	{
		Camera* camera = workspace->getCamera();
		if (camera->zoom(1.0f))
			CameraVerb::doIt(state);
	}

	void CameraZoomOutCommand::doIt(IDataState* state)
	{
		Camera* camera = workspace->getCamera();
		if (camera->zoom(-1.0f))
			CameraVerb::doIt(state);
	}

	void CameraModelViewCommand::doIt(IDataState* state)
	{
		workspace->setImageServerView(workspace->getViewPort());
		CameraVerb::doIt(state);
	}

	bool CameraCenterCommand::isEnabled() const
	{
		bool hasSelection = ServiceClient<FilteredSelection<PVInstance> >(workspace)->size() >= 1;
		if (hasSelection)
		{
			Camera* camera = workspace->getCamera();
			if (camera && camera->getCameraType() == Camera::FIXED_CAMERA)
				return true;
		}
		return false;
	}

	template<> boost::shared_ptr<Workspace> shared_from<Workspace>(Workspace*);

	EditSelectionVerb::EditSelectionVerb(VerbContainer* container, std::string name, DataModel* dm)
		: Verb(container, name), workspace(shared_from(dm ? dm->create<Workspace>() : NULL)), selection(dm), dataModel(dm)
	{
	}

	DeleteBase::DeleteBase(VerbContainer* container, DataModel* dm, std::string name)
		: EditSelectionVerb(container, name, dm), rewardHopper(false)
	{
	}
}

#include "gui/Gui.h"

namespace RBX {
void StatsCommand::doIt(IDataState*) {
    GuiRoot* root = dataModel->getGuiRoot();
    TopMenuBar* first = dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud1"));
    if (first) first->setVisible(!first->isVisible());
    TopMenuBar* second = dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud2"));
    if (second) second->setVisible(!second->isVisible());
}

bool StatsCommand::isEnabled() const {
    GuiRoot* root = dataModel->getGuiRoot();
    return dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud1")) != 0;
}

bool StatsCommand::isChecked() const {
    GuiRoot* root = dataModel->getGuiRoot();
    const TopMenuBar* menu = dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud1"));
    return menu && menu->isVisible();
}
}

#include "util/Math.h"

namespace RBX {
RotateAxisCommand::RotateAxisCommand(std::string name, DataModel* model) : EditSelectionVerb(name, model) {}
ControllerCommand::ControllerCommand(std::string name, DataModel* model) : EditSelectionVerb(name, model) {}
RotateSelectionVerb::RotateSelectionVerb(DataModel* model) : RotateAxisCommand("SelectionRotate", model) {}
TiltSelectionVerb::TiltSelectionVerb(DataModel* model) : RotateAxisCommand("SelectionTilt", model) {}
PrimaryControllerCommand::PrimaryControllerCommand(DataModel* model) : ControllerCommand("Controller1", model) {}
SecondaryControllerCommand::SecondaryControllerCommand(DataModel* model) : ControllerCommand("Controller2", model) {}
G3D::Matrix3 RotateSelectionVerb::getRotationAxis() { return Math::matrixRotateY(); }
}

namespace RBX {

FirstPersonCommand::FirstPersonCommand(DataModel* model) : Verb(model, "FirstPersonIndicator"), dataModel(model) {}
StatsCommand::StatsCommand(DataModel* model) : Verb(model, "Stats"), dataModel(model) {}
EngineStatsCommand::EngineStatsCommand(DataModel* model) : Verb(model, "EngineStats"), dataModel(model) {}
JoinCommand::JoinCommand(DataModel* model) : Verb(model, "JoinCommand"), dataModel(model) {}
ClearStarterpack::ClearStarterpack(DataModel* model) : Verb(model, "ClearStarterpack"), dataModel(model) {}
ClearBackpack::ClearBackpack(DataModel* model) : Verb(model, "ClearBackpack"), dataModel(model) {}
ForceAssertionCommand::ForceAssertionCommand(DataModel* model) : Verb(model, "ForceAssertion") {}
DeleteBase::DeleteBase(DataModel* model, std::string name, bool reward) : EditSelectionVerb(name, model), rewardHopper(reward) {}
inline MoveUpSelectionVerb::MoveUpSelectionVerb(DataModel* dm, const std::string& name, float height)
    : EditSelectionVerb(name, dm), moveUpHeight(height) {}
MoveUpPlateVerb::MoveUpPlateVerb(DataModel* dm)
    : MoveUpSelectionVerb(dm, "SelectionUpPlate", 0.4f)
{
}
MoveUpBrickVerb::MoveUpBrickVerb(DataModel* dm) : MoveUpSelectionVerb(dm, "SelectionUpBrick", 1.2f) {}

}

#include "util/RunStateOwner.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "Network/Players.h"

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

bool __cdecl testBooleanProperty(const Name* name, boost::shared_ptr<Instance> item) {
    Reflection::PropertyIterator iter = item->findProperty(*name);
    if (iter != item->properties_end() && dynamic_cast<const Reflection::TypedPropertyDescriptor<bool>*>(&iter.getDescriptor()))
        if ((*iter).getValue<bool>()) return true;
    return false;
}

struct SetBooleanProperty {
    const Name* name;
    bool value;
    SetBooleanProperty(const Name* n, bool v) : name(n), value(v) {}
    void operator()(boost::shared_ptr<Instance>) const;
};

void SetBooleanProperty::operator()(boost::shared_ptr<Instance> item) const {
    Reflection::PropertyIterator iter = item->findProperty(*name);
    if (iter != item->properties_end() && dynamic_cast<const Reflection::TypedPropertyDescriptor<bool>*>(&iter.getDescriptor()))
        if ((*iter).getValue<bool>() != value) (*iter).setValue<bool>(value);
}

void BoolPropertyVerb::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    bool value = !isChecked();
    std::for_each(selection->selection->begin(), selection->selection->end(), SetBooleanProperty(&propertyName, value));
    recordCameraHistory(propertyName.c_str(), dataModel);
    state->setDirty(true);
}

bool BoolPropertyVerb::isChecked() const {
    return std::find_if(selection->selection->begin(), selection->selection->end(), boost::bind(testBooleanProperty, &propertyName, _1)) != selection->selection->end();
}

}

template class boost::_bi::value<RBX::Name const *>;

namespace RBX {
static __declspec(noinline) bool controllable(PVInstance* item)
{
    return item->isControllable();
}

bool ControllerCommand::isEnabled() const
{
    if (!(selection->size() > 0)) return false;
    FilteredSelection<PVInstance>* items = ServiceProvider::create<FilteredSelection<PVInstance> >(
        static_cast<const ServiceProvider*>(dataModel));
    return items->findFirst(controllable) != NULL;
}
}

#include "v8xml/SerializerV2.h"

void __cdecl collectSelection(XmlElement*, boost::shared_ptr<RBX::Instance>);

namespace RBX {

void DuplicateSelectionVerb::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    std::auto_ptr<XmlElement> root(SerializerV2::newRootElement());
    ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    std::for_each(selection->selection->begin(), selection->selection->end(), boost::bind(collectSelection, root.get(), _1));
    SerializerV2::isolateHandles(root.get());
    std::vector<boost::shared_ptr<Instance> > instances;
    workspace->insertItems(root.get(), instances, INSERT_TO_3D_VIEW, ALLOW_PROMPTS);
    selection->setSelection(instances.begin(), instances.end());
    ServiceProvider::create<Soundscape::SoundService>(static_cast<const ServiceProvider*>(dataModel))->playSound(PING_SOUND);
    recordCameraHistory(getName().c_str(), dataModel);
    state->setDirty(true);
}

}

namespace RBX {
template<> boost::shared_ptr<Workspace> shared_from<Workspace>(Workspace*);

EditSelectionVerb::EditSelectionVerb(std::string name, DataModel* model)
    : Verb(model, name), workspace(shared_from(model->getWorkspace())), selection(model), dataModel(model) {}
}

namespace RBX {

class MotorFeature {
public:
    static bool canJoin(Instance*, Instance*);
    static void join(Instance*, Instance*);
};

bool JoinCommand::isEnabled() const
{
    Selection* selection = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    if (selection->size() == 2) {
        boost::shared_ptr<Instance> first = selection->front();
        boost::shared_ptr<Instance> last = selection->back();
        if (MotorFeature::canJoin(first.get(), last.get())) return true;
    }
    return false;
}

void JoinCommand::doIt(IDataState*)
{
    checkRunPermissions(dataModel);
    Selection* selection = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    if (selection->size() == 2) {
        boost::shared_ptr<Instance> first = selection->front();
        boost::shared_ptr<Instance> last = selection->back();
        MotorFeature::join(first.get(), last.get());
    }
}

}

#include "v8datamodel/PartInstance.h"

namespace RBX {

void SelectAllCommand::doIt(IDataState*) {
    checkRunPermissions(dataModel);
    dataModel->getWorkspace()->selectAll();
}

void AllCanSelectCommand::doIt(IDataState* state) {
    checkRunPermissions(dataModel);
    Workspace* workspace = dataModel->getWorkspace();
    PartInstance::setLocked(workspace, false);
    recordCameraHistory(getName().c_str(), workspace);
    state->setDirty(true);
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

bool FirstPersonCommand::isEnabled() const {
    return dataModel->getWorkspace()->getCamera()->isFirstPersonCamera();
}

void RunCommand::doIt(IDataState*) {
    checkRunPermissions(dataModel);
    RunService* service = runService.operator->();
    service->setRunState(RS_RUNNING);
}

void StopCommand::doIt(IDataState*) {
    checkRunPermissions(dataModel);
    RunService* service = runService.operator->();
    service->setRunState(RS_PAUSED);
}

void ResetCommand::doIt(IDataState*) {
    checkRunPermissions(dataModel);
    RunService* service = runService.operator->();
    service->setRunState(RS_NORMAL);
}

}

namespace RBX {
RunStateVerb::RunStateVerb(std::string name, DataModel* model)
    : Verb(model, name), dataModel(model), runService(model) {}
}

namespace RBX {

BoolPropertyVerb::BoolPropertyVerb(const std::string& name, DataModel* model, const char* property)
    : EditSelectionVerb(name, model), propertyName(Name::declare(property, -1)) {}

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

}

namespace RBX {

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

#include "v8datamodel/ICameraOwner.h"

namespace RBX {
G3D::Matrix3 TiltSelectionVerb::getRotationAxis()
{
    return Math::matrixTiltQuadrant(Math::toYAxisQuadrant(workspace->getGCamera().getCoordinateFrame()));
}
}

bool RBX::Verb::isEnabled() const { return true; }
bool RBX::Verb::isChecked() const { return false; }
bool RBX::EditSelectionVerb::isEnabled() const { return selection->size() > 0; }
