#include "CRobloxView.h"
#include "Network/Players.h"

void CRobloxView::onEvent(const RBX::Network::Players *, RBX::SuperSafeChanged)
{
	::PostMessageA(m_hWnd, 0x46b, 0, 0);
}
