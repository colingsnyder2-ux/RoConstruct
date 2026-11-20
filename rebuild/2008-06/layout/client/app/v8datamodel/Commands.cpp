#include <afxwin.h>
#include <boost/scoped_ptr.hpp>
#include <stdexcept>
#include "CRobloxDoc.h"
#include "CInsertObjectDialog.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
#include "Network/Players.h"
#include "v8datamodel/Decal.h"
#include "v8datamodel/custommesh.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Selection.h"
#include "util/Sound.h"

using namespace RBX;
extern HRESULT __stdcall createNativeWorkspace(CWorkspace**) throw();
class ReportAbuseVerb : public Verb {
    CRobloxDoc* doc;
public:
    __forceinline ReportAbuseVerb(CRobloxDoc* doc,VerbContainer* container)
        : Verb(container,"ReportAbuse"),doc(doc) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
void ReportAbuseVerb::doIt(IDataState*) {
    ::PostMessage(AfxGetApp()->m_pMainWnd->m_hWnd, WM_COMMAND, 0x8100, 0);
}
bool ReportAbuseVerb::isEnabled() const {
    DataModel::Lock lock(doc->getDataModel());
    return doc->getDataModel()->create<Network::Players>()->canReportAbuse();
}
#include "NativeExitCommand.h"

namespace RBX {
inline const Name& Verb::getName() const { return name; }
inline VerbContainer* Verb::getContainer() const { return container; }
inline const G3D::Rect2D& RootInstance::getViewPort() { return viewPort; }
void recordCameraHistory(const char*, const Instance*);
}
#include "NativeCameraCommands.h"

namespace RBX {
CameraVerb::CameraVerb(std::string name, Workspace* ws)
    : Verb(ws, name), workspace(ws), selection(ws) {}
void CameraVerb::doIt(IDataState* state) {
    ServiceProvider::create<Soundscape::SoundService>(static_cast<Instance*>(workspace))->playSound(STEP_SOUND);
    state->setDirty(true);
}
void CameraPanLeftCommand::doIt(IDataState* state) {
    workspace->getCamera()->panUnits(-1);
    CameraVerb::doIt(state);
}
void CameraPanRightCommand::doIt(IDataState* state) {
    workspace->getCamera()->panUnits(1);
    CameraVerb::doIt(state);
}
void CameraTiltUpCommand::doIt(IDataState* state) {
    Camera* camera = workspace->getCamera();
    if (camera->tiltUnits(-1)) CameraVerb::doIt(state);
}
void CameraTiltDownCommand::doIt(IDataState* state) {
    Camera* camera = workspace->getCamera();
    if (camera->tiltUnits(1)) CameraVerb::doIt(state);
}
void CameraZoomInCommand::doIt(IDataState* state) {
    Camera* camera = workspace->getCamera();
    if (camera->zoom(1.0f)) CameraVerb::doIt(state);
}
void CameraZoomOutCommand::doIt(IDataState* state) {
    Camera* camera = workspace->getCamera();
    if (camera->zoom(-1.0f)) CameraVerb::doIt(state);
}
void CameraModelViewCommand::doIt(IDataState* state) {
    workspace->setImageServerView(workspace->getViewPort());
    CameraVerb::doIt(state);
}
bool FixedCameraCommand::isChecked() const {
    Camera* camera = workspace->getCamera();
    return camera->getCameraType() == Camera::FIXED_CAMERA;
}
void FixedCameraCommand::doIt(IDataState* state) {
    workspace->getCamera()->setCameraType(Camera::FIXED_CAMERA);
    recordCameraHistory(getName().c_str(), workspace);
    state->setDirty(true);
}
bool CameraPanLeftCommand::isEnabled() const { return true; }
bool CameraPanRightCommand::isEnabled() const { return true; }
bool CameraZoomExtentsCommand::isEnabled() const { return true; }
bool CameraCenterCommand::isEnabled() const {
    bool hasSelection = ServiceClient<FilteredSelection<PVInstance> >(workspace)->size() >= 1;
    if (hasSelection) {
        Camera* camera = workspace->getCamera();
        if (camera && camera->getCameraType() == Camera::FIXED_CAMERA) return true;
    }
    return false;
}
bool CameraTiltUpCommand::isEnabled() const {
    Camera* camera = workspace->getCamera();
    return camera->canTilt(-1);
}
bool CameraTiltDownCommand::isEnabled() const {
    Camera* camera = workspace->getCamera();
    return camera->canTilt(1);
}
bool CameraZoomInCommand::isEnabled() const {
    Camera* camera = workspace->getCamera();
    return camera->canZoom(1);
}
bool CameraZoomOutCommand::isEnabled() const {
    Camera* camera = workspace->getCamera();
    return camera->canZoom(-1);
}
}
#include "ClipboardVerbs.h"

namespace RBX { template<> boost::shared_ptr<Workspace> shared_from<Workspace>(Workspace*);
EditSelectionVerb::EditSelectionVerb(VerbContainer* container,std::string name,DataModel* dm)
    : Verb(container,name), workspace(shared_from(dm ? dm->create<Workspace>() : NULL)), selection(dm), dataModel(dm) {}
DeleteBase::DeleteBase(VerbContainer* container,DataModel* dm,std::string name) : EditSelectionVerb(container,name,dm), rewardHopper(false) {}
DeleteSelectionVerb::DeleteSelectionVerb(VerbContainer* container,DataModel* dm,std::string name) : DeleteBase(container,dm,name) {} }
CutVerb::CutVerb(DataModel* dm) : DeleteSelectionVerb(dm,dm,"Cut") {}
void CutVerb::doIt(IDataState* state) { getContainer()->getVerb("Copy")->doIt(state); DeleteBase::doIt(state); }
CopyVerb::CopyVerb(DataModel* dm) : EditSelectionVerb("Copy", dm) {}
bool PasteVerb::isEnabled() const {
    if (::IsClipboardFormatAvailable(getClipboardFormat()) != 1) return false;
    if (!pasteInto) return true;
    Selection* selected = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    return selected->size() == 1;
}
PasteVerb::PasteVerb(DataModel* dm, bool into) : Verb(dm, into ? "PasteInto" : "Paste"), dataModel(dm), pasteInto(into) {}
#include "InsertDecal.h"

class InsertTexture : public InsertDecal {
public:
    InsertTexture(DataModel* dm) : InsertDecal(dm,"InsertTexture") {}
protected:
    virtual boost::shared_ptr<Decal> createInstance();
};
#include "InsertObject.h"

InsertObject::InsertObject(DataModel* dm) : RunStateVerb("Insert Object", dm) {}
class InsertService : public RunStateVerb {
public:
    __declspec(noinline) InsertService(DataModel*);
    virtual void doIt(IDataState*);
};
InsertService::InsertService(DataModel* dm) : RunStateVerb("Insert Service", dm) {}
void InsertService::doIt(IDataState*) {
    boost::shared_ptr<Instance> empty;
    CInsertObjectDialog dialog(empty, NULL);
    dialog.className = AfxGetApp()->GetProfileString("InsertService", "ClassName", NULL).GetBuffer();
    if (dialog.DoModal() == IDOK) {
        const char* (CString::*convert)() const = &CString::operator const char*;
        AfxGetApp()->WriteProfileString("InsertService", "ClassName", (dialog.className.*convert)());
        boost::shared_ptr<Instance> instance = dialog.selected;
        if (!instance) {
            CString error; error.Format(133, dialog.className);
            std::string message((error.*convert)());
            throw std::runtime_error(message);
        }
        if (!ServiceProvider::create(dataModel, instance->getClassName())) {
            CString error; error.Format(137, dialog.className);
            std::string message((error.*convert)());
            throw std::runtime_error(message);
        }
    }
}
typedef char native_doc_DataModel_Lock_size[(sizeof(DataModel::Lock)==12)?1:-1];
typedef char native_doc_CameraVerb_size[(sizeof(CameraVerb)==28)?1:-1];
typedef char native_doc_ReportAbuseVerb_size[(sizeof(ReportAbuseVerb)==16)?1:-1];
typedef char native_doc_ExitCommand_size[(sizeof(ExitCommand)==16)?1:-1];
typedef char native_doc_CutVerb_size[(sizeof(CutVerb)==40)?1:-1];
typedef char native_doc_CopyVerb_size[(sizeof(CopyVerb)==36)?1:-1];
typedef char native_doc_PasteVerb_size[(sizeof(PasteVerb)==20)?1:-1];
typedef char native_doc_InsertDecal_size[(sizeof(InsertDecal)==36)?1:-1];
typedef char native_doc_InsertTexture_size[(sizeof(InsertTexture)==36)?1:-1];
typedef char native_doc_InsertObject_size[(sizeof(InsertObject)==28)?1:-1];
typedef char native_doc_InsertService_size[(sizeof(InsertService)==28)?1:-1];
void CRobloxDoc::initializeCommands() {
    HRESULT hr=createNativeWorkspace(&workspace);
    if(hr==S_OK) {}
    else throw std::runtime_error("Unable to create CWorkspace");
    reinterpret_cast<IUnknown*>(workspace)->AddRef();
    boost::shared_ptr<DataModel> dm=workspace->getDataModel();
    DataModel::Lock lock(dm);
    { const char* (CString::*convert)() const = &CString::operator const char*; std::string documentName((m_strTitle.*convert)()); dm->setName(documentName); }
    reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs).reset(new StandardVerbs(dm.get()));
    ownedVerbs.push_back(new ReportAbuseVerb(this,static_cast<VerbContainer*>(dm.get())));
    ownedVerbs.push_back(new ExitCommand(this,static_cast<VerbContainer*>(dm.get())));
    ownedVerbs.push_back(new FixedCameraCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraPanLeftCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraPanRightCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraTiltUpCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraTiltDownCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraZoomInCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraZoomOutCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraCenterCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraZoomExtentsCommand(workspace->getWorkspace()));
    ownedVerbs.push_back(new CameraModelViewCommand(workspace->getWorkspace()));
    bindExisting(0xe120,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->deleteSelection);
    bindExisting(0xe12a,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->selectAll);
    bindExisting(0x8005,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->duplicate);
    bindExisting(0x8011,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->allCanSelect);
    bindExisting(0x8010,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->canNotSelect);
    bindExisting(0x80d8,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->join);
    bindExisting(0x80d4,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->forceAssertion);
    bindExisting(0x80d5,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->engineStats);
    { const Name& name = Name::lookup("Group"); commandNames[0x8039] = &name; }
    { const Name& name = Name::lookup("UnGroup"); commandNames[0x803a] = &name; }
    { const Name& name = Name::lookup("WeldSelection"); commandNames[0x8061] = &name; }
    { const Name& name = Name::lookup("SnapSelection"); commandNames[0x80a5] = &name; }
    { const Name& name = Name::lookup("SelectionRotate"); commandNames[0x8043] = &name; }
    { const Name& name = Name::lookup("SelectionTilt"); commandNames[0x8044] = &name; }
    { const Name& name = Name::lookup("SelectionUpBrick"); commandNames[0x8057] = &name; }
    { const Name& name = Name::lookup("SelectionUpPlate"); commandNames[0x8059] = &name; }
    { const Name& name = Name::lookup("SelectionDown"); commandNames[0x8058] = &name; }
    bindExisting(0x80aa,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolModelSetFront);
    bindExisting(0x80ab,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolModelSetPrimaryPart);
    bindOwned(0xe123,new CutVerb(dm.get()));
    bindOwned(0xe122,new CopyVerb(dm.get()));
    bindOwned(0xe125,new PasteVerb(dm.get(),false));
    bindOwned(0x80f7,new PasteVerb(dm.get(),true));
    bindOwned(0x8062,new InsertDecal(dm.get(),"InsertDecal"));
    bindOwned(0x80ee,new InsertTexture(dm.get()));
    bindOwned(0x807f,new InsertObject(dm.get()));
    bindOwned(0x8107,new InsertService(dm.get()));
    bindExisting(0x800d,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->clearStarterpack);
    bindExisting(0x800e,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->clearBackpack);
    { const Name& name = Name::lookup("FillTool"); commandNames[0x8040] = &name; }
    { const Name& name = Name::lookup("DropperTool"); commandNames[0x8041] = &name; }
    bindExisting(0x8063,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolArrow);
    bindExisting(0x8065,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolResize);
    bindExisting(0x8067,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolAxisMove);
    bindExisting(0x8073,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolLock);
    bindExisting(0x8074,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolAnchor);
    bindExisting(0x8077,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolGlue);
    bindExisting(0x8078,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolFlat);
    bindExisting(0x8079,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolWeld);
    bindExisting(0x80a7,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolStuds);
    bindExisting(0x80a8,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolInlet);
    bindExisting(0x807b,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolRightMotor);
    bindExisting(0x807c,&reinterpret_cast<boost::scoped_ptr<StandardVerbs>&>(standardVerbs)->toolHinge);
}

InsertDecal::InsertDecal(DataModel* dm, const char* name)
    : EditSelectionVerb(std::string(name), dm) {}
boost::shared_ptr<Decal> InsertDecal::createInstance() {
    return Creatable<Instance>::create<Decal>();
}
boost::shared_ptr<Decal> InsertTexture::createInstance() {
    return Creatable<Instance>::create<Texture>();
}
Instance* InsertDecal::getTarget() const {
    Selection* selected = ServiceProvider::create<Selection>(dataModel);
    if (selected->size() == 1) {
        Instance* item = selected->front().get();
        if (dynamic_cast<PartInstance*>(item)) return item;
        if (dynamic_cast<SpecialShape*>(item)) return item;
    }
    return NULL;
}
bool InsertDecal::isEnabled() const {
    return EditSelectionVerb::isEnabled() && getTarget() != NULL;
}

template class boost::scoped_ptr<RBX::StandardVerbs>;

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

namespace RBX {
EngineStatsCommand::EngineStatsCommand(RBX::DataModel* dm)
    : Verb(dm ? reinterpret_cast<RBX::VerbContainer*>(reinterpret_cast<char*>(dm) + 0x1c8) : 0,
           std::string("EngineStats")),
      dataModel(dm)
{
}
}

#include "gui/Gui.h"

namespace RBX {
bool StatsCommand::isChecked() const
{
    GuiRoot* root = dataModel->getGuiRoot();
    TopMenuBar* menu = dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud1"));
    return (menu && menu->isVisible()) ? 1 : 0;
}
}

namespace RBX {
StatsCommand::StatsCommand(RBX::DataModel* dm)
    : Verb(static_cast<RBX::VerbContainer*>(dm), std::string("Stats")),
      dataModel(dm)
{
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

#include "util/Math.h"
#include "v8datamodel/ICameraOwner.h"

namespace RBX {
G3D::Matrix3 TiltSelectionVerb::getRotationAxis()
{
    return Math::matrixTiltQuadrant(Math::toYAxisQuadrant(workspace->getGCamera().getCoordinateFrame()));
}
}
