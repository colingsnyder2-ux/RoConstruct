#include "../native-headers/CRobloxView.h"
#include "../native-headers/CRobloxDoc.h"
#include "../native-headers/CWorkspace.h"
#include "../native-headers/ToggleToolboxVerb.h"
#include "../native-headers/v8datamodel/DataModel.h"

// Scaffolding, not recovered declarations: DataModel+0x150 and +0x170 are Notifier
// bases the native DataModel.h does not declare yet; 004218a0 is their addListener.
struct ListenerSite { void addListener(void*); };
inline ListenerSite* notifierAt(RBX::DataModel* model, unsigned offset) {
    return reinterpret_cast<ListenerSite*>(reinterpret_cast<char*>(model) + offset);
}
// Workspace+0x2ec holds the camera and selection verbs; member not declared yet.
inline RBX::VerbContainer* cameraVerbs(RBX::DataModel* model) {
    return reinterpret_cast<RBX::VerbContainer*>(reinterpret_cast<char*>(model->getWorkspace()) + 0x2ec);
}

// Scaffolding for tail calls: 00452a00 is a DataModel method returning a service with
// method 0058c5e0 (ChangeHistoryService per the mined label); 0044aa70 reports a caught exception.
struct HistorySite { void touch(); };
struct ModelSite { HistorySite* history(); };
void reportViewException(const std::exception&);

// Inline derived verbs from 0045a4a0. Sizes come from operator new in the original.
class HelpVerb : public RBX::Verb {            // 0x10, vtable 00819140
    CRobloxView* view;
public:
    HelpVerb(CRobloxView* view, RBX::VerbContainer* c) : RBX::Verb(c, "Help"), view(view) {}
    virtual void doIt(RBX::IDataState*);
};
class ToggleFullScreenVerb : public RBX::Verb { // 0xc, vtable 00819114
public:
    explicit ToggleFullScreenVerb(RBX::VerbContainer* c) : RBX::Verb(c, "ToggleFullScreen") {}
    virtual void doIt(RBX::IDataState*);
};
class LockPlayModeVerb : public RBX::Verb {     // 0xc, vtable 008190ec
public:
    explicit LockPlayModeVerb(RBX::VerbContainer* c) : RBX::Verb(c, "LockPlayMode") {}
    virtual void doIt(RBX::IDataState*);
};
class Verb458fd0 : public RBX::Verb {           // 0x18, constructor 00458fd0 unrecovered
    void* fields_0c[3];
public:
    explicit Verb458fd0(RBX::VerbContainer*);
    virtual void doIt(RBX::IDataState*);
};

// Inline in the original; same shape as CRobloxDoc::bindExisting.
inline void CRobloxView::bindExisting(UINT id, RBX::Verb* verb) {
    commandNames[id] = verb ? &verb->getName() : &RBX::Name::getNullName();
}

// 0045a4a0
void CRobloxView::OnInitialUpdate() {
    try {
    detachDataModel();                       // 0045a2f0
    window.setDataModel(0);                  // 0045f7b0
    owner_170.reset();                       // 00456e80
    CView::OnInitialUpdate();                // 006a0cc2
    CRobloxDoc* document = static_cast<CRobloxDoc*>(GetDocument());   // View+0x54
    window.setDataModel(document->workspace);
    owner_170 = document->workspace->getDataModel();                  // 0046a940, 004025b0
    RBX::DataModel::Lock lock(boost::const_pointer_cast<const RBX::DataModel>(owner_170)); // 00411b40
    if (slot_1d8) { // object at +0x1d8 keeps a counted workspace pointer at its +0xfc
        IWorkspace** site = reinterpret_cast<IWorkspace**>(static_cast<char*>(slot_1d8) + 0xfc);
        IWorkspace* workspace = document->workspace;
        if (*site != workspace) {
            if (workspace) workspace->AddRef();
            if (*site) (*site)->Release();
            *site = workspace;
        }
    }
    RBX::DataModel* model = owner_170.get();
    if (model) notifierAt(model, 0x150)->addListener(static_cast<RBX::Listener<RBX::ServiceProvider, RBX::ServiceAdded>*>(this));
    if (model) notifierAt(model, 0x170)->addListener(static_cast<RBX::Listener<RBX::ServiceProvider, RBX::ServiceRemoving>*>(this));
    setVerbParent(model ? cameraVerbs(model) : 0);                    // 00583210
    slot_1e0.assign(new ToggleToolboxVerb(this, model));              // 00458ec0
    slot_1dc.assign(new HelpVerb(this, model));
    slot_1e4.assign(new ToggleFullScreenVerb(model));
    slot_1e8.assign(new Verb458fd0(model));
    slot_1ec.assign(new LockPlayModeVerb(model));
    bindExisting(0x8027, cameraVerbs(owner_170.get())->getVerb(std::string("CameraPanLeft")));
    bindExisting(0x8028, cameraVerbs(owner_170.get())->getVerb(std::string("CameraPanRight")));
    bindExisting(0x8029, cameraVerbs(owner_170.get())->getVerb(std::string("CameraTiltUp")));
    bindExisting(0x802a, cameraVerbs(owner_170.get())->getVerb(std::string("CameraTiltDown")));
    bindExisting(0x802b, cameraVerbs(owner_170.get())->getVerb(std::string("CameraZoomIn")));
    bindExisting(0x802c, cameraVerbs(owner_170.get())->getVerb(std::string("CameraZoomOut")));
    bindExisting(0x80a6, cameraVerbs(owner_170.get())->getVerb(std::string("CameraCenter")));
    bindExisting(0x802d, cameraVerbs(owner_170.get())->getVerb(std::string("CameraZoomExtents")));
    bindExisting(0x80d7, cameraVerbs(owner_170.get())->getVerb(std::string("CameraModelView")));
    commandNames[0x802f] = &RBX::Name::lookup("FixedCamera");
    commandNames[0x8030] = &RBX::Name::lookup("AttachCamera");
    commandNames[0x80a3] = &RBX::Name::lookup("TrackCamera");
    commandNames[0x8032] = &RBX::Name::lookup("FollowCamera");
    commandNames[0x80a2] = &RBX::Name::lookup("WatchCamera");
    commandNames[0x8043] = &RBX::Name::lookup("SelectionRotate");
    commandNames[0x8044] = &RBX::Name::lookup("SelectionTilt");
    window.finishAttach();                                            // 0045ead0
    if (HistorySite* history = reinterpret_cast<ModelSite*>(owner_170.get())->history()) history->touch();  // 00452a00, 0058c5e0
    } catch (std::exception& error) {
        reportViewException(error);                                   // 0044aa70
    }
}
