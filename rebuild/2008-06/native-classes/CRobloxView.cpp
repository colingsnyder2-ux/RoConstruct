// >>> native-status (generated) -- do not edit >>>
// CRobloxView | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src e3537d7c | roc native-status --write
#include "../native-headers/CRobloxView.h"

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
    if (bActivate) window.setActive(true);
    else window.setActive(false);
    CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
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
    owner_170.reset();
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Listener<RBX::Network::Players,RBX::SuperSafeChanged>;
template class RBX::Listener<RBX::ServiceProvider,RBX::ServiceAdded>;
template class RBX::Listener<RBX::ServiceProvider,RBX::ServiceRemoving>;
template class boost::scoped_ptr<RBX::Verb>;
template class std::map<unsigned int,RBX::Name const *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,RBX::Name const *> > >;
