#include "CRobloxView.h"
#include "CRobloxDoc.h"
#include "CWorkspace.h"
#include "InsertModelFromRobloxVerb.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ChangeHistoryService.h"

// Inline in the original, as in CRobloxDoc.cpp.
inline const RBX::Name& RBX::Verb::getName() const { return name; }

void reportViewException(const std::exception&);

#include "ViewVerbs.h"

// Inline in the original; same shape as CRobloxDoc::bindExisting.
inline void CRobloxView::bindName(UINT id, const RBX::Name& source) {
    const RBX::Name* name = &source;
    commandNames[id] = name;
}

inline void CRobloxView::bindExisting(UINT id, RBX::Verb* verb) {
    if (verb) bindName(id, verb->getName());
    else bindName(id, RBX::Name::getNullName());
}

inline RBX::VerbContainer* workspaceVerbs(RBX::Workspace* workspace) {
    return static_cast<RBX::VerbContainer*>(workspace);
}

// The original re-reads both on every use; caching them in locals changes the code.
#define DOC() RobloxDocument()
#define DM() const_cast<RBX::DataModel*>(owner_170.get())

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
        IDispatch** site = &slot_1d8->external.p;
        IWorkspace* workspace = DOC()->workspace;
        if (*site != workspace) {
            if (workspace) workspace->AddRef();
            if (*site) (*site)->Release();
            *site = workspace;
        }
    }
    RBX::Notifier<RBX::ServiceProvider, RBX::ServiceAdded>::connect(owner_170.get(), this);
    RBX::Notifier<RBX::ServiceProvider, RBX::ServiceRemoving>::connect(owner_170.get(), this);
    setVerbParent(workspaceVerbs(DM()->getWorkspace()));                    // 00583210
    slot_1e0.reset(new InsertModelFromRobloxVerb(this, DM()));              // 00458ec0
    slot_1dc.reset(new HelpCommand(this, DM()));
    slot_1e4.reset(new ToggleFullscreenVerb(DM()));
    slot_1e8.reset(new ToggleIDEModeVerb(DM()));
    slot_1ec.reset(new LockPlayModeVerb(DM()));
    bindExisting(0x8027, DM()->getWorkspace()->getVerb(std::string("CameraPanLeft")));
    bindExisting(0x8028, DM()->getWorkspace()->getVerb(std::string("CameraPanRight")));
    bindExisting(0x8029, DM()->getWorkspace()->getVerb(std::string("CameraTiltUp")));
    bindExisting(0x802a, DM()->getWorkspace()->getVerb(std::string("CameraTiltDown")));
    bindExisting(0x802b, DM()->getWorkspace()->getVerb(std::string("CameraZoomIn")));
    bindExisting(0x802c, DM()->getWorkspace()->getVerb(std::string("CameraZoomOut")));
    bindExisting(0x80a6, DM()->getWorkspace()->getVerb(std::string("CameraCenter")));
    bindExisting(0x802d, DM()->getWorkspace()->getVerb(std::string("CameraZoomExtents")));
    bindExisting(0x80d7, DM()->getWorkspace()->getVerb(std::string("CameraModelView")));
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

template class std::_Vector_const_iterator<RBX::Listener<RBX::ServiceProvider,RBX::ServiceAdded> *,std::allocator<RBX::Listener<RBX::ServiceProvider,RBX::ServiceAdded> *> >;
template class std::_Vector_const_iterator<RBX::Listener<RBX::ServiceProvider,RBX::ServiceRemoving> *,std::allocator<RBX::Listener<RBX::ServiceProvider,RBX::ServiceRemoving> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::ServiceProvider,RBX::ServiceAdded> *,std::allocator<RBX::Listener<RBX::ServiceProvider,RBX::ServiceAdded> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::ServiceProvider,RBX::ServiceRemoving> *,std::allocator<RBX::Listener<RBX::ServiceProvider,RBX::ServiceRemoving> *> >;
template class std::vector<RBX::Listener<RBX::ServiceProvider,RBX::ServiceAdded> *,std::allocator<RBX::Listener<RBX::ServiceProvider,RBX::ServiceAdded> *> >;
template class std::vector<RBX::Listener<RBX::ServiceProvider,RBX::ServiceRemoving> *,std::allocator<RBX::Listener<RBX::ServiceProvider,RBX::ServiceRemoving> *> >;

#include "Network/Players.h"

void CRobloxView::onEvent(const RBX::Network::Players *, RBX::SuperSafeChanged)
{
	::PostMessageA(m_hWnd, 0x46b, 0, 0);
}

#include <afxwin.h>
#include <G3D/System.h>

namespace RBX { namespace Network {
class Client { public: static bool clientIsPresent(const Instance*, bool); };
} }

InsertModelFromRobloxVerb::InsertModelFromRobloxVerb(CRobloxView* view, RBX::DataModel* model)
    : RBX::Verb(model, "ToggleToolbox"), view(view), model(model), createdAt(G3D::System::getTick()) {}

bool InsertModelFromRobloxVerb::isEnabled() const
{
    double now = G3D::System::getTick();
    if (createdAt + 10.0 > now)
        return false;
    return !RBX::Network::Client::clientIsPresent(model, true);
}

bool InsertModelFromRobloxVerb::isChecked() const
{
    return view->slot_1d8 != 0;
}

void InsertModelFromRobloxVerb::doIt(RBX::IDataState*)
{
    view->PostMessage(WM_COMMAND, 0x80fe);
}

void LockPlayModeVerb::doIt(RBX::IDataState* dataState)
{
	if (isEnabled())
	{
		AfxGetApp()->m_pMainWnd->PostMessageA(0x111, 0x80f5, 0);
	}
}

void ToggleFullscreenVerb::doIt(RBX::IDataState* dataState)
{
	AfxGetApp()->m_pMainWnd->PostMessageA(0x111, 0x80f4, 0);
}

void HelpCommand::doIt(RBX::IDataState* dataState)
{
	view->PostMessageA(0x111, 0x80fd, 0);
}
