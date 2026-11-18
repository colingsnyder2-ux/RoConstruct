// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
#include "../native-headers/CRobloxView.h"

void CRobloxView::onEvent(const RBX::ServiceProvider* source, RBX::ServiceRemoving event)
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

LRESULT CRobloxView::updateReflector(WPARAM wParam, LPARAM lParam)
{
    // Update reflector visibility based on super-safe mode and connected clients
    // This is recovered from the binary at 0045a140
    if (window.m_hWnd) {
        // Logic to update reflector state based on message parameters
        // wParam and lParam control reflector visibility settings
        bool show = (BOOL)wParam;
        if (show) {
            window.showReflector(true);
        } else {
            window.showReflector(false);
        }
    }
    return 0;
}

// INFERRED: The onEvent handler for ServiceRemoving (00459d60) posts window messages
// 0x46b/0x46c to trigger client-side network UI cleanup when a service provider is removed.

// INFERRED: updateReflector (0045a140) handles reflector visibility updates.
// It takes WPARAM as a boolean to show/hide the reflector and returns 0 to indicate
// the message was handled. The function accesses the window member to control reflector state.