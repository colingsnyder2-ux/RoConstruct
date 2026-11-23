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

class CRobloxDoc;
void setActiveDocument(bool active, CRobloxDoc* document);

IMPLEMENT_DYNCREATE(CRobloxView, CView)

BEGIN_MESSAGE_MAP(CRobloxView, CView)
    ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_SIZE()
    ON_WM_CREATE()
    ON_WM_ERASEBKGND()
    ON_WM_DESTROY()
    ON_MESSAGE(WM_USER + 107, &CRobloxView::updateReflector)
    ON_MESSAGE(WM_USER + 108, &CRobloxView::closeToolbox)
    ON_COMMAND(0x8020, &CRobloxView::OnInsertFromFileAt)
    ON_COMMAND(0x80d6, &CRobloxView::OnInsertFromFile)
    ON_WM_CONTEXTMENU()
    ON_WM_SETFOCUS()
    ON_COMMAND(0x80fc, &CRobloxView::OnWindowCommand)
    ON_UPDATE_COMMAND_UI(0x80fe, &CRobloxView::OnUpdateToolboxCheck)
    ON_COMMAND(0x80fe, &CRobloxView::toggleToolbox)
    ON_COMMAND(0x80fd, &CRobloxView::showHelp)
    ON_COMMAND(0x800c, &CRobloxView::openToolboxPage)
    ON_UPDATE_COMMAND_UI(0x800c, &CRobloxView::OnUpdateAlwaysEnable)
END_MESSAGE_MAP()

CRobloxView::CRobloxView() : RBX::VerbContainer(0), window(0), slot_1d8(0) {
    popupMenu.Attach(::LoadMenu(AfxFindResourceHandle(MAKEINTRESOURCE(0x67), RT_MENU), MAKEINTRESOURCE(0x67)));
}

CRobloxView::~CRobloxView() {}

void CRobloxView::OnActivateFrame(UINT state, CFrameWnd* frame) {
    if (state) window.setActive(true);
    else window.setActive(false);
    CView::OnActivateFrame(state, frame);
}

void CRobloxView::OnUpdateToolboxCheck(CCmdUI* ui) { ui->SetCheck(slot_1d8 != 0); }

boost::shared_ptr<const RBX::DataModel> CRobloxView::getDataModel() const { return owner_170; }

void CRobloxView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) {
    CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
    if (bActivate) {
        setActiveDocument(true, reinterpret_cast<CRobloxDoc*>(m_pDocument));
        window.setActive(true);
    } else if (pActivateView != pDeactiveView) {
        setActiveDocument(false, reinterpret_cast<CRobloxDoc*>(m_pDocument));
        window.setActive(false);
    }
}

BOOL CRobloxView::OnPreparePrinting(CPrintInfo* pInfo) {
    return DoPreparePrinting(pInfo);
}

// slot 97
void CRobloxView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) {}

// slot 99
void CRobloxView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) {}

void CRobloxView::OnDraw(CDC* pDC) {
}

void CRobloxView::onEvent(const RBX::ServiceProvider* source, RBX::ServiceAdded event) {}

void CRobloxView::detachDataModel() {
    RBX::DataModel::Lock lock(owner_170);
    slot_1dc.reset();
    slot_1e0.reset();
    slot_1e4.reset();
    slot_1e8.reset();
    slot_1ec.reset();
    RBX::Listener<RBX::ServiceProvider, RBX::ServiceAdded>* added = this;
    if (owner_170.get())
        owner_170->RBX::Notifier<RBX::ServiceProvider, RBX::ServiceAdded>::removeListener(added);
    RBX::Listener<RBX::ServiceProvider, RBX::ServiceRemoving>* removing =
        &static_cast<RBX::Listener<RBX::ServiceProvider, RBX::ServiceRemoving>&>(*this);
    if (owner_170.get())
        owner_170->RBX::Notifier<RBX::ServiceProvider, RBX::ServiceRemoving>::removeListener(removing);
    RBX::Network::Players* players = RBX::ServiceProvider::find<RBX::Network::Players>(getDataModel().get());
    if (players)
        players->RBX::Notifier<RBX::Network::Players, RBX::SuperSafeChanged>::removeListener(
            static_cast<RBX::Listener<RBX::Network::Players, RBX::SuperSafeChanged>*>(this));
}

template class RBX::Listener<RBX::Network::Players,RBX::SuperSafeChanged>;
template class RBX::Listener<RBX::ServiceProvider,RBX::ServiceAdded>;
template class RBX::Listener<RBX::ServiceProvider,RBX::ServiceRemoving>;
template class boost::scoped_ptr<RBX::Verb>;
template class std::map<unsigned int,RBX::Name const *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,RBX::Name const *> > >;

void CRobloxView::toggleToolbox()
{
    showToolbox(slot_1d8 == 0, true);
}

void CRobloxView::openToolboxPage()
{
    showToolbox(true, true);
    slot_1d8->showPage(9);
}

LRESULT CRobloxView::closeToolbox(WPARAM, LPARAM)
{
    if (slot_1d8) {
        slot_1d8->DestroyWindow();
        slot_1d8 = 0;
        layout();
    }
    return 0;
}

void CRobloxView::OnSetFocus(CWnd* pOldWnd)
{
    CView::OnSetFocus(pOldWnd);
    GetParentFrame()->SetActiveView(this, 0);
    window.SetFocus();
}

void CRobloxView::layout()
{
    RECT rect;
    GetClientRect(&rect);
    int height = rect.bottom - rect.top;
    int width = rect.right - rect.left;
    int viewHeight = height;

    if (slot_1d8 && slot_1d8->m_hWnd)
        width -= 0xe1;
    if (reflector.m_hWnd)
        viewHeight = height - 0x14;

    int h = std::max(viewHeight, 0);
    int w = std::max(width, 0);

    if (window.m_hWnd)
        window.MoveWindow(0, 0, w, h, 1);
    if (slot_1d8 && slot_1d8->m_hWnd)
        slot_1d8->MoveWindow(w, 0, 0xe1, height, 1);
    if (reflector.m_hWnd)
        reflector.MoveWindow(0, h, w, 0x14, 1);
}

void CRobloxView::showHelp()
{
    CStringA applicationBaseUrl();
    class CBrowserView* showBrowserPopup(tagRECT, CWnd*, CStringA, IDispatch*);

    tagRECT rect;
    ::GetClientRect(window.m_hWnd, &rect);
    ::InflateRect(&rect, -12, -12);

    rect.right = (rect.right - rect.left) / 2;
    int height = rect.bottom - rect.top;
    int limit = 480;
    const int& m = height < limit ? height : limit;
    rect.bottom = m - rect.top;

    showBrowserPopup(rect, &window, applicationBaseUrl() + "/Game/Help.aspx", 0);
}

int CRobloxView::OnCreate(LPCREATESTRUCT lpCreateStruct) {
    RECT rect;
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    ::GetClientRect(m_hWnd, &rect);
    return (window.Create(0, "Roblox", 0x50000000, rect, this, 1, 0) != 0) - 1;
}

void CRobloxView::OnSize(UINT nType, int cx, int cy) {
    CView::OnSize(nType, cx, cy);
    layout();
}

void CRobloxView::OnDestroy() {
    detachDataModel();
    CView::OnDestroy();
}

BOOL CRobloxView::OnEraseBkgnd(CDC*) {
    return TRUE;
}

void CRobloxView::OnContextMenu(CWnd*, CPoint) {
}

void CRobloxView::OnWindowCommand() {
    window.windowCommand();
}

void CRobloxView::OnInsertFromFile() {
    insertFromFile(0);
}

void CRobloxView::OnInsertFromFileAt() {
    insertFromFile(1);
}

LRESULT CRobloxView::updateReflector(WPARAM, LPARAM) {
    return 0;
}

void CRobloxView::OnUpdateAlwaysEnable(CCmdUI* pCmdUI) {
    pCmdUI->Enable(TRUE);
}

void CRobloxView::insertFromFile(int mode) {
}

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

#ifdef VIEWVERBS_MAINFRAME_HEADER_COMPILES
#include "CMainFrame.h"

static CMainFrame* mainFrame() { return static_cast<CMainFrame*>(AfxGetApp()->m_pMainWnd); }
#endif

#ifdef VIEWVERBS_OWNS_SHARD_BODIES
void HelpCommand::doIt(RBX::IDataState*)
{
    view->PostMessage(WM_COMMAND, 0x80fd);
}

#ifdef VIEWVERBS_MAINFRAME_HEADER_COMPILES
bool ToggleFullscreenVerb::isChecked() const
{
    return mainFrame()->stateF8;
}
#endif

void ToggleFullscreenVerb::doIt(RBX::IDataState*)
{
    AfxGetApp()->m_pMainWnd->PostMessage(WM_COMMAND, 0x80f4);
}
#endif

void LockPlayModeVerb::doIt(RBX::IDataState*)
{
    AfxGetApp()->m_pMainWnd->PostMessage(WM_COMMAND, 0x80ff);
}

ToggleIDEModeVerb::ToggleIDEModeVerb(RBX::VerbContainer* c)
    : RBX::Verb(c, std::string("TogglePlayMode")), createdAt(G3D::System::getTick()) {}

#ifdef VIEWVERBS_MAINFRAME_HEADER_COMPILES
bool ToggleIDEModeVerb::isEnabled() const
{
    double now = G3D::System::getTick();
    if (createdAt + 10.0 > now)
        return false;
    return !mainFrame()->state105;
}

bool ToggleIDEModeVerb::isChecked() const
{
    return !mainFrame()->state104;
}
#endif

void ToggleIDEModeVerb::doIt(RBX::IDataState*)
{
    if (isEnabled())
        AfxGetApp()->m_pMainWnd->PostMessage(WM_COMMAND, 0x80f5);
}

void ToggleFullscreenVerb::doIt(RBX::IDataState* dataState)
{
	AfxGetApp()->m_pMainWnd->PostMessageA(0x111, 0x80f4, 0);
}

void HelpCommand::doIt(RBX::IDataState* dataState)
{
	view->PostMessageA(0x111, 0x80fd, 0);
}
