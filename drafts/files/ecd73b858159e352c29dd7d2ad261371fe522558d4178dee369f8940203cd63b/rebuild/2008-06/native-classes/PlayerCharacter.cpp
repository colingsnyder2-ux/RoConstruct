// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Network::Player character/backpack methods (inactive; Network/Player.cpp unit). Not in any
// build list. Layout and the other Player rows: native-headers/Network/Player.h, native-classes/NetworkPlayer.cpp and
// AppUnit480_2008Player*.cpp. Player::getTeamColor 00445260 is the Network/Player.h in-class inline (ICF), not here.
//
// Evidence (2008-06 Roblox.exe):
// - rebuildBackpack 004925c0: Players::backendProcessing 00495eb0 (this, true), else std::runtime_error 00409d50
//   with the literal 00821cac "rebuildBackpack can only be called by the backend server"; Instance::
//   findFirstChildOfType<Backpack> 0048bb80 out of line, setParent 0055a8f0 (NULL); Creatable<Instance>::
//   create<Backpack> 0048bc20 copied into a shared_ptr<Instance>; setParent(this); ServiceProvider::
//   create<StarterPackService>(const Instance*) 00491ef0; Instance::numChildren 0048ae20 (out of line) and the
//   children vector (+0x108, checked operator[]); Instance::clone 00559350; setParent(backpack).
#include "Network/Player.h"
#include "Network/Players.h"
#include "v8tree/Service.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/Hopper.h"
#include <stdexcept>

namespace RBX
{
	namespace Network
	{
		// 004925c0
		void Player::rebuildBackpack()
		{
			if (!Players::backendProcessing(this, true))
				throw std::runtime_error("rebuildBackpack can only be called by the backend server");

			while (Backpack* r = findFirstChildOfType<Backpack>())
			{
				r->setParent(NULL);
			}

			boost::shared_ptr<Instance> backpack = Creatable<Instance>::create<Backpack>();
			backpack->setParent(this);

			if (StarterPackService* starterPack = ServiceProvider::create<StarterPackService>(this))
			{
				for (size_t i = 0; i < starterPack->numChildren(); i++)
				{
					starterPack->getChild(i)->clone()->setParent(backpack.get());
				}
			}
		}
	}
}
