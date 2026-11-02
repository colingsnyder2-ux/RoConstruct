#include "../native-headers/CRobloxView.h"
#include "../native-headers/CRobloxDoc.h"
#include "../native-headers/CWorkspace.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include "Network/Players.h"
#include <algorithm>
#include <fstream>
#include <afxdlgs.h>

void fn_00405aa0(bool, CDocument*); // activation bookkeeping, unrecovered

// The target calls std::string::compare(const char*) through the MSVCP import; taking the member's
// address keeps the call out of line.
typedef int (std::string::*CompareCString)(const char*) const;
static const CompareCString compareName = &std::string::compare;

// 00458ea0
void CRobloxView::onEvent(const RBX::Network::Players*, RBX::SuperSafeChanged) {
    ::PostMessage(m_hWnd, 0x46b, 0, 0);
}

// 0045a030
void CRobloxView::onEvent(const RBX::ServiceProvider*, RBX::ServiceAdded event) {
    if ((event.service->getClassName().toString().*compareName)("NetworkClient") == 0 || (event.service->getClassName().toString().*compareName)("Players") == 0)
        ::PostMessage(m_hWnd, 0x46b, 0, 0);
    if ((event.service->getClassName().toString().*compareName)("Players") == 0)
    {
        RBX::Network::Players* players = static_cast<RBX::Network::Players*>(event.service.get());
        RBX::Listener<RBX::Network::Players, RBX::SuperSafeChanged>* listener = this;
        if (players) players->RBX::Notifier<RBX::Network::Players, RBX::SuperSafeChanged>::addListener(listener);
    }
}

// 00459d60
void CRobloxView::onEvent(const RBX::ServiceProvider*, RBX::ServiceRemoving event) {
    if ((event.service->getClassName().toString().*compareName)("NetworkClient") == 0)
        ::PostMessage(m_hWnd, 0x46c, 0, 0);
    if ((event.service->getClassName().toString().*compareName)("NetworkClient") == 0 || (event.service->getClassName().toString().*compareName)("Players") == 0)
        ::PostMessage(m_hWnd, 0x46b, 0, 0);
    if ((event.service->getClassName().toString().*compareName)("Players") == 0)
    {
        RBX::Network::Players* players = static_cast<RBX::Network::Players*>(event.service.get());
        RBX::Listener<RBX::Network::Players, RBX::SuperSafeChanged>* listener = this;
        if (players) players->RBX::Notifier<RBX::Network::Players, RBX::SuperSafeChanged>::removeListener(listener);
    }
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

// Helpers in the browser-view unit: 004060d0 builds the site address, 0040e160 appends a path,
// 0040f050 opens the popup window for it.
CString fn_004060d0();
CString fn_0040e160(const CString&, const char*);
void fn_0040f050(RECT, CWnd*, CString, int);

// 00459570: help popup, centred in the client area with a 12 pixel margin.
// 0040f050 takes a trailing int (0); 004060d0 takes none.
void CRobloxView::showHelp() {
    RECT client;
    ::GetClientRect(window.m_hWnd, &client);
    ::InflateRect(&client, -12, -12);
    client.right = (client.right - client.left) / 2;
    int height = client.bottom - client.top;
    client.bottom = std::min(480, height) - client.top;
    fn_0040f050(client, &window, fn_0040e160(fn_004060d0(), "/Game/Help.aspx"), 0);
}

// The target calls CString::operator PCXSTR through the MFC import, so nothing is expanded here.
#pragma inline_depth(0)
// 00459420: choose a model file and insert it into the workspace.
void CRobloxView::insertFromFile(int) {
    CString filter;
    filter.LoadString(0xb8);
    CFileDialog dialog(TRUE, "rbxm", NULL, 6, filter, this);
    if (dialog.DoModal() == IDOK) {
        std::ifstream file(dialog.GetPathName(), std::ios::in | std::ios::binary);
        CRobloxDoc* doc = reinterpret_cast<CRobloxDoc*>(m_pDocument);
        doc->workspace->insert(file, false);
    }
}

#pragma inline_depth()

// 00459560 and 00459550
void CRobloxView::OnInsertFromFile() { insertFromFile(0); }
void CRobloxView::OnInsertFromFileAt() { insertFromFile(2); }

IMPLEMENT_DYNCREATE(CRobloxView, CView)

// 0070bdf0, 00458e80, 00458e90
void CRobloxView::OnDraw(CDC*) {}
BOOL CRobloxView::OnPreparePrinting(CPrintInfo* info) { return DoPreparePrinting(info); }
void CRobloxView::OnBeginPrinting(CDC*, CPrintInfo*) {}
void CRobloxView::OnEndPrinting(CDC*, CPrintInfo*) {}

// 00459170
int CRobloxView::OnCreate(LPCREATESTRUCT create) {
    if (CView::OnCreate(create) == -1) return -1;
    RECT client;
    ::GetClientRect(m_hWnd, &client);
    return window.Create(NULL, "Roblox", 0x50000000, client, this, 1, NULL) ? 0 : -1;
}

// 006e8870 and 006ad2a0 are empty bodies shared with other views.
BOOL CRobloxView::OnEraseBkgnd(CDC*) { return TRUE; }
void CRobloxView::OnContextMenu(CWnd*, CPoint) {}

// 00459240
void CRobloxView::OnWindowCommand() { window.windowCommand(); }

// 0042e550
void CRobloxView::OnUpdateAlwaysEnable(CCmdUI* ui) { ui->Enable(TRUE); }

BEGIN_MESSAGE_MAP(CRobloxView, CView)
    ON_COMMAND(0xe107, CView::OnFilePrint)
    ON_COMMAND(0xe108, CView::OnFilePrint)
    ON_COMMAND(0xe109, CView::OnFilePrintPreview)
    ON_WM_SIZE()
    ON_WM_CREATE()
    ON_WM_ERASEBKGND()
    ON_WM_DESTROY()
    ON_MESSAGE(0x46b, updateReflector)
    ON_MESSAGE(0x46c, closeToolbox)
    ON_COMMAND(0x8020, OnInsertFromFileAt)
    ON_COMMAND(0x80d6, OnInsertFromFile)
    ON_WM_CONTEXTMENU()
    ON_WM_SETFOCUS()
    ON_COMMAND(0x80fc, OnWindowCommand)
    ON_UPDATE_COMMAND_UI(0x80fe, OnUpdateToolboxCheck)
    ON_COMMAND(0x80fe, toggleToolbox)
    ON_COMMAND(0x80fd, showHelp)
    ON_COMMAND(0x800c, openToolboxPage)
    ON_UPDATE_COMMAND_UI(0x800c, OnUpdateAlwaysEnable)
END_MESSAGE_MAP()
