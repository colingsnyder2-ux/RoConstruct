#include "../native-headers/CRobloxView.h"
#include "../native-headers/CRobloxDoc.h"
#include "../native-headers/CWorkspace.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include "Network/Players.h"
#include <algorithm>

void fn_00405aa0(bool, CDocument*); // activation bookkeeping, unrecovered

// 00458ea0
void CRobloxView::onEvent(const RBX::Network::Players*, RBX::SuperSafeChanged) {
    ::PostMessage(m_hWnd, 0x46b, 0, 0);
}

// 0045a030
void CRobloxView::onEvent(const RBX::ServiceProvider*, RBX::ServiceAdded event) {
    RBX::Instance* service = event.service.get();
    if (service->getClassName().toString().compare("NetworkClient") == 0 || service->getClassName().toString().compare("Players") == 0)
        ::PostMessage(m_hWnd, 0x46b, 0, 0);
    if (service->getClassName().toString().compare("Players") == 0)
        static_cast<RBX::Network::Players*>(service)->RBX::Notifier<RBX::Network::Players, RBX::SuperSafeChanged>::addListener(
            static_cast<RBX::Listener<RBX::Network::Players, RBX::SuperSafeChanged>*>(this));
}

// 00459d60
void CRobloxView::onEvent(const RBX::ServiceProvider*, RBX::ServiceRemoving event) {
    RBX::Instance* service = event.service.get();
    if (service->getClassName().toString().compare("NetworkClient") == 0)
        ::PostMessage(m_hWnd, 0x46c, 0, 0);
    if (service->getClassName().toString().compare("NetworkClient") == 0 || service->getClassName().toString().compare("Players") == 0)
        ::PostMessage(m_hWnd, 0x46b, 0, 0);
    if (service->getClassName().toString().compare("Players") == 0)
        static_cast<RBX::Network::Players*>(service)->RBX::Notifier<RBX::Network::Players, RBX::SuperSafeChanged>::removeListener(
            static_cast<RBX::Listener<RBX::Network::Players, RBX::SuperSafeChanged>*>(this));
}

// 00459210
void CRobloxView::OnSetFocus(CWnd* old) {
    CWnd::OnSetFocus(old);
    GetParentFrame()->SetActiveView(this, FALSE);
    window.SetFocus();
}

// 00459390
void CRobloxView::OnSize(UINT, int, int) {
    Default();
    layout();
}

// 004592b0: toolbox on the right (225 wide), reflector strip below (20 high), the render window fills the rest.
void CRobloxView::layout() {
    RECT client;
    ::GetClientRect(m_hWnd, &client);
    int height = client.bottom - client.top;
    int width = client.right - client.left;
    int bodyWidth = width, bodyHeight = height;
    if (slot_1d8 && slot_1d8->m_hWnd) bodyWidth -= 0xe1;
    if (reflector.m_hWnd) bodyHeight -= 0x14;
    int h = std::max(bodyHeight, 0), w = std::max(bodyWidth, 0);
    if (window.m_hWnd) window.MoveWindow(0, 0, w, h, TRUE);
    if (slot_1d8 && slot_1d8->m_hWnd) slot_1d8->MoveWindow(w, 0, 0xe1, height, TRUE);
    if (reflector.m_hWnd) reflector.MoveWindow(0, h, w, 0x14, TRUE);
}

// 004593b0
void CRobloxView::OnActivateView(BOOL activate, CView* activated, CView* deactivated) {
    CView::OnActivateView(activate, activated, deactivated);
    if (activate) {
        fn_00405aa0(true, m_pDocument);
        window.setActive(true);
    } else if (activated != deactivated) {
        fn_00405aa0(false, m_pDocument);
        window.setActive(false);
    }
}

// 004596a0
void CRobloxView::showToolbox(bool show, bool notify) {
    bool present = slot_1d8 != 0;
    if (show != present) {
        if (show) {
            CWebToolbox* toolbox = static_cast<CWebToolbox*>(RUNTIME_CLASS(CWebToolbox)->CreateObject());
            slot_1d8 = toolbox;
            IWorkspace* workspace = RobloxDocument()->workspace;
            if (toolbox->site != workspace) {
                if (workspace) workspace->AddRef();
                if (toolbox->site) toolbox->site->Release();
                toolbox->site = workspace;
            }
            slot_1d8->owner = &window;
            CRect none(0, 0, 0, 0);
            if (!slot_1d8->Create(NULL, NULL, 0x50000000, none, this, 0x413, NULL)) {
                slot_1d8 = 0;
                return;
            }
            if (notify) {
                ::SendMessage(slot_1d8->m_hWnd, 0x364, 0, 0);
                layout();
                return;
            }
        } else {
            slot_1d8->DestroyWindow();
            slot_1d8 = 0;
        }
        layout();
    }
}

// 004597c0
LRESULT CRobloxView::closeToolbox(WPARAM, LPARAM) {
    if (slot_1d8) {
        slot_1d8->DestroyWindow();
        slot_1d8 = 0;
        layout();
    }
    return 0;
}

// 004597f0
void CRobloxView::toggleToolbox() { showToolbox(slot_1d8 == 0, true); }

// 00459810
void CRobloxView::openToolboxPage() {
    showToolbox(true, true);
    slot_1d8->showPage(9);
}

// 0045a140: the reflector strip is shown for a connected client that is not in super-safe mode.
LRESULT CRobloxView::updateReflector(WPARAM, LPARAM) {
    if (m_hWnd) {
        RBX::DataModel::Lock lock(owner_170);
        bool show = false;
        RBX::Network::Players* players = RBX::ServiceProvider::find<RBX::Network::Players>(getDataModel().get());
        if (players) {
            bool on = RBX::Network::Players::clientIsPresent(getDataModel().get(), true) && !players->superSafeOn();
            if (on) show = true;
        }
        bool present = reflector.m_hWnd != 0;
        if (show != present) {
            if (show) reflector.create(this, getDataModel().get());
            else reflector.DestroyWindow();
            layout();
        }
    }
    return 0;
}

// 0045a2f0
void CRobloxView::detachDataModel() {
    RBX::DataModel::Lock lock(owner_170);
    slot_1dc.assign(static_cast<OwnedPolymorphic*>(0));
    slot_1e0.assign(static_cast<OwnedPolymorphic*>(0));
    slot_1e4.assign(static_cast<OwnedPolymorphic*>(0));
    slot_1e8.assign(static_cast<OwnedPolymorphic*>(0));
    slot_1ec.assign(static_cast<OwnedPolymorphic*>(0));
    RBX::Listener<RBX::ServiceProvider, RBX::ServiceAdded>* added = this;
    if (owner_170)
        owner_170->RBX::Notifier<RBX::ServiceProvider, RBX::ServiceAdded>::removeListener(added);
    RBX::Listener<RBX::ServiceProvider, RBX::ServiceRemoving>* removing = this;
    if (owner_170)
        owner_170->RBX::Notifier<RBX::ServiceProvider, RBX::ServiceRemoving>::removeListener(removing);
    RBX::Network::Players* players = RBX::ServiceProvider::find<RBX::Network::Players>(getDataModel().get());
    if (players)
        players->RBX::Notifier<RBX::Network::Players, RBX::SuperSafeChanged>::removeListener(
            static_cast<RBX::Listener<RBX::Network::Players, RBX::SuperSafeChanged>*>(this));
}

// 0045ac20
void CRobloxView::OnDestroy() {
    detachDataModel();
    CView::OnDestroy();
}
