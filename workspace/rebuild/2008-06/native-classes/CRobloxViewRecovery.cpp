// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
#include "../native-headers/CRobloxView.h"
#include "../native-headers/CRobloxDoc.h"
#include "../native-headers/CWorkspace.h"
#include "../native-headers/Network/Players.h"

void CRobloxView::showToolbox(bool show, bool notify)
{
    if (show == (slot_1d8 != 0)) return;
    if (show) {
        slot_1d8 = static_cast<CWebToolbox*>(CWebToolbox::GetThisClass()->CreateObject());
        slot_1d8->external = RobloxDocument()->workspace;
        slot_1d8->owner = &window;
        CRect rect(0, 0, 0, 0);
        if (!slot_1d8->Create(0, 0, WS_CHILD | WS_VISIBLE, rect, this, 0x413, 0)) {
            slot_1d8 = 0;
            return;
        }
        if (notify) ::SendMessageA(slot_1d8->m_hWnd, 0x364, 0, 0);
    } else {
        slot_1d8->DestroyWindow();
        slot_1d8 = 0;
    }
    layout();
}

void CRobloxView::onEvent(const RBX::ServiceProvider*, RBX::ServiceRemoving event)
{
    if (event.service->getClassName() == "NetworkClient")
        ::PostMessageA(m_hWnd, 0x46c, 0, 0);
    if (event.service->getClassName() == "NetworkClient" || event.service->getClassName() == "Players")
        ::PostMessageA(m_hWnd, 0x46b, 0, 0);
    if (event.service->getClassName() == "Players") {
        RBX::Listener<RBX::Network::Players, RBX::SuperSafeChanged>* listener = this;
        RBX::Network::Players* players = static_cast<RBX::Network::Players*>(event.service.get());
        if (players) players->RBX::Notifier<RBX::Network::Players, RBX::SuperSafeChanged>::removeListener(listener);
    }
}
