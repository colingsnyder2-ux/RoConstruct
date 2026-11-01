#include "../native-headers/CRobloxView.h"

// Constructor 00459eb0. Binder 00459890 and CRobloxWnd 0045c730 are external here.
CRobloxView::CRobloxView() : RBX::VerbContainer(0), window(0) {
    popupMenu.Attach(::LoadMenu(AfxFindResourceHandle(MAKEINTRESOURCE(0x67), RT_MENU), MAKEINTRESOURCE(0x67)));
}
