// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/CRobloxView.h"

#include "../native-headers/Network/Players.h"
#include "../native-headers/v8datamodel/DataModel.h"

class CRobloxDoc;
void setActiveDocument(bool active, CRobloxDoc* document);

IMPLEMENT_DYNCREATE(CRobloxView, CView)

BEGIN_MESSAGE_MAP(CRobloxView, CView)
END_MESSAGE_MAP()

// Constructor 00459eb0. Binder 00459890 and CRobloxWnd 0045c730 are external here.
CRobloxView::CRobloxView() : RBX::VerbContainer(0), window(0), slot_1d8(0) {
    popupMenu.Attach(::LoadMenu(AfxFindResourceHandle(MAKEINTRESOURCE(0x67), RT_MENU), MAKEINTRESOURCE(0x67)));
}

// 00459ba0: members unwind in reverse (five owned slots, reflector, menu, shared owner,
// window, container, binder map), then CView.
CRobloxView::~CRobloxView() {}

// CRobloxWnd::setActive (0070bdf0, empty shared stub) is defined outside this unit, as in the original.
// 004591e0: window state follows activation, then the base handles it.
void CRobloxView::OnActivateFrame(UINT state, CFrameWnd* frame) {
    if (state) window.setActive(true);
    else window.setActive(false);
    CView::OnActivateFrame(state, frame);
}

// 00459250
void CRobloxView::OnUpdateToolboxCheck(CCmdUI* ui) { ui->SetCheck(slot_1d8 != 0); }

// 00459270
boost::shared_ptr<const RBX::DataModel> CRobloxView::getDataModel() const { return owner_170; }

// 004593b0
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

// 00458e80-style shared stub
BOOL CRobloxView::OnPreparePrinting(CPrintInfo* pInfo) {
    return DoPreparePrinting(pInfo);
}

// slot 97
void CRobloxView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) {}

// slot 99
void CRobloxView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) {}

// slot 95 - STUB (not authentic, not rendering): the 2008 body renders through the scene renderer;
// this solid GDI fill only marks the viewport until that path is recovered.
void CRobloxView::OnDraw(CDC* pDC) {
    if (pDC) {
        CRect rect;
        GetClientRect(&rect);
        pDC->FillSolidRect(&rect, RGB(40, 60, 90)); // viewport clear color
    }
}

// 00458ea0
void CRobloxView::onEvent(const RBX::Network::Players* source, RBX::SuperSafeChanged event) {}

// 0045a030
void CRobloxView::onEvent(const RBX::ServiceProvider* source, RBX::ServiceAdded event) {}

// 00459d60
void CRobloxView::onEvent(const RBX::ServiceProvider* source, RBX::ServiceRemoving event) {}

// 0045a2f0
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
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
