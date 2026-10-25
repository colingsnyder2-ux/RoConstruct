// Rebuild glue: Network::Player statics and overrides rbxgs declares but never defines. Names are the
// 2008-06 Roblox.exe strings ("Data", "CharacterAppearance", "userId", "Under13", "SuperSafeChat",
// "Chatted", "message", "recipient"). Behavioural reconstruction, not byte-verified.
#include "Network/Player.h"

namespace RBX
{
	namespace Network
	{
		Reflection::BoundProp<int, 1> Player::prop_userId("userId", "Data", &Player::userId, Reflection::PropertyDescriptor::STANDARD);
		Reflection::BoundProp<bool, 1> Player::prop_Under13("Under13", "Data", &Player::under13, Reflection::PropertyDescriptor::STANDARD);
		Reflection::BoundProp<bool, 1> Player::prop_SuperSafeChat("SuperSafeChat", "Data", &Player::superSafeChat, Reflection::PropertyDescriptor::STANDARD);
		Reflection::SignalDesc<Player, void(std::string, boost::shared_ptr<Instance>)> Player::event_Chatted("Chatted", "message", "recipient");

		// a player holds its backpack, gui and other per-player instances
		bool Player::askAddChild(const Instance* instance) const
		{
			return true;
		}

		// players are session state: they are never written to a place file
		XmlElement* Player::write()
		{
			return NULL;
		}
	}
}
