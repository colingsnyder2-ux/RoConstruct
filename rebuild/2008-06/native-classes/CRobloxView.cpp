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
