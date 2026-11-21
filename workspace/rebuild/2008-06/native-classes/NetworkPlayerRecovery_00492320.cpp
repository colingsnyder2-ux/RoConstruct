// 2008-06 native RBX::Network::Player::onLocalPlayerNotIdle 00492320 (inactive): static idle clock reset.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /D_XTP_STATICLINK /D_XTPLIB_NOAUTOLINK /fp:fast /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "Network/Player.h"
#include "Network/Players.h"
#include "G3D/System.h"

namespace RBX
{
	namespace Network
	{
		// INFERRED: name from the 2007 donor declaration static void Player::onLocalPlayerNotIdle(ServiceProvider*);
		// the body resets the local player's idle clock (lastActivityTime +0x1d0).
		void Player::onLocalPlayerNotIdle(ServiceProvider* serviceProvider)
		{
			Players* players = serviceProvider->find<Players>();
			if (players)
			{
				Player* player = players->getLocalPlayer();
				if (player && ServiceProvider::findServiceProvider(player))
					player->lastActivityTime = G3D::System::getLocalTime();
			}
		}
	}
}
