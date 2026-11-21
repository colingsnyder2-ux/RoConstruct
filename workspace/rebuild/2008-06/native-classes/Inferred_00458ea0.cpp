// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00458ea0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "CRobloxView.h"
#include "Network/Players.h"

void CRobloxView::onEvent(const RBX::Network::Players *, RBX::SuperSafeChanged)
{
	::PostMessageA(m_hWnd, 0x46b, 0, 0);
}
