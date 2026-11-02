#include "../native-headers/CRobloxView.h"
#include "../native-headers/CRobloxDoc.h"
#include "../native-headers/CWorkspace.h"
#include "../native-headers/ToggleToolboxVerb.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include "../native-headers/v8datamodel/ChangeHistoryService.h"

// Inline in the original, as in CRobloxDoc.cpp.
inline const RBX::Name& RBX::Verb::getName() const { return name; }

// Workspace+0x2ec holds the camera and selection verbs; member not declared yet.
inline RBX::VerbContainer* cameraVerbs(RBX::DataModel* model) {
    return reinterpret_cast<RBX::VerbContainer*>(reinterpret_cast<char*>(model->getWorkspace()) + 0x2ec);
}

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
inline void CRobloxView::bindName(UINT id, const RBX::Name& source) {
    const RBX::Name* name = &source;
    commandNames[id] = name;
}

inline void CRobloxView::bindExisting(UINT id, RBX::Verb* verb) {
    if (verb) {
        const RBX::Name* name = &verb->getName();
        commandNames[id] = name;
    } else {
        const RBX::Name* name = &RBX::Name::getNullName();
        commandNames[id] = name;
    }
}

// Null-safe base conversion; Workspace's VerbContainer base sits at +0x2ec.
inline RBX::VerbContainer* workspaceVerbs(RBX::Workspace* workspace) {
    return workspace ? reinterpret_cast<RBX::VerbContainer*>(reinterpret_cast<char*>(workspace) + 0x2ec) : 0;
}

// The original re-reads both on every use; caching them in locals changes the code.
#define DOC() RobloxDocument()
#define DM() const_cast<RBX::DataModel*>(owner_170.get())

// 0045a4a0
void CRobloxView::OnInitialUpdate() {
    try {
    detachDataModel();                       // 0045a2f0
    window.setDataModel(0);                  // 0045f7b0
    owner_170.reset();                       // 00456e80
    CView::OnInitialUpdate();                // 006a0cc2
    window.setDataModel(DOC()->workspace);
    owner_170 = DOC()->workspace->getDataModel();                  // 0046a940, 004025b0
    RBX::DataModel::Lock lock(owner_170); // 00411b40
    if (slot_1d8) {
        IWorkspace* workspace = DOC()->workspace;
        if (slot_1d8->site != workspace) {
            if (workspace) workspace->AddRef();
            if (slot_1d8->site) slot_1d8->site->Release();
            slot_1d8->site = workspace;
        }
    }
    RBX::Notifier<RBX::ServiceProvider, RBX::ServiceAdded>::connect(owner_170.get(), this);
    RBX::Notifier<RBX::ServiceProvider, RBX::ServiceRemoving>::connect(owner_170.get(), this);
    setVerbParent(workspaceVerbs(DM()->getWorkspace()));                    // 00583210
    slot_1e0.assign(new ToggleToolboxVerb(this, DM()));              // 00458ec0
    slot_1dc.assign(new HelpVerb(this, DM()));
    slot_1e4.assign(new ToggleFullScreenVerb(DM()));
    slot_1e8.assign(new Verb458fd0(DM()));
    slot_1ec.assign(new LockPlayModeVerb(DM()));
    bindExisting(0x8027, cameraVerbs(DM())->getVerb(std::string("CameraPanLeft")));
    bindExisting(0x8028, cameraVerbs(DM())->getVerb(std::string("CameraPanRight")));
    bindExisting(0x8029, cameraVerbs(DM())->getVerb(std::string("CameraTiltUp")));
    bindExisting(0x802a, cameraVerbs(DM())->getVerb(std::string("CameraTiltDown")));
    bindExisting(0x802b, cameraVerbs(DM())->getVerb(std::string("CameraZoomIn")));
    bindExisting(0x802c, cameraVerbs(DM())->getVerb(std::string("CameraZoomOut")));
    bindExisting(0x80a6, cameraVerbs(DM())->getVerb(std::string("CameraCenter")));
    bindExisting(0x802d, cameraVerbs(DM())->getVerb(std::string("CameraZoomExtents")));
    bindExisting(0x80d7, cameraVerbs(DM())->getVerb(std::string("CameraModelView")));
    bindName(0x802f, RBX::Name::lookup("FixedCamera"));
    bindName(0x8030, RBX::Name::lookup("AttachCamera"));
    bindName(0x80a3, RBX::Name::lookup("TrackCamera"));
    bindName(0x8032, RBX::Name::lookup("FollowCamera"));
    bindName(0x80a2, RBX::Name::lookup("WatchCamera"));
    bindName(0x8043, RBX::Name::lookup("SelectionRotate"));
    bindName(0x8044, RBX::Name::lookup("SelectionTilt"));
    window.finishAttach();                                            // 0045ead0
    if (RBX::ChangeHistoryService* history = DM()->create<RBX::ChangeHistoryService>()) history->initializeBase(); // 00452a00, 0058c5e0
    } catch (std::exception& error) {
        reportViewException(error);                                   // 0044aa70
    }
}

