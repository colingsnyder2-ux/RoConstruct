// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source /FIwinsock2.h /GS-
#include "../native-headers/gui/WidgetChat.h"
#include "../native-headers/Network/Client2008.h"
#include "../native-headers/Network/Players.h"

namespace RBX {
bool ChatButton::isVisible() const
{
	RBX::Network::Players* p = RBX::ServiceProvider::find<RBX::Network::Players>(this);
	return p && p->getLocalPlayer() != 0 && RBX::Network::Client::clientIsPresent(this, true);
}
}
