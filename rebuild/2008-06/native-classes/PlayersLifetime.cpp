// >>> native-status (generated) -- do not edit >>>
// PlayersLifetime | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src bf6d665e | roc native-status --write
#include <RakPeer.h>
#include <PluginInterface.h>
#include "Network/Players.h"

template<class Class>
class PluginInterfaceAdapter : public PluginInterface
{
private:
	Class* c;
protected:
	PluginInterfaceAdapter(Class* c)
		: PluginInterface(),
		  c(c)
	{
	}
public:
	virtual PluginReceiveResult OnReceive(RakPeerInterface* peer, Packet* packet);
};


namespace RBX
{
	namespace Network
	{
		class Players::Plugin : public PluginInterfaceAdapter<Players>
		{
		public:
			Plugin(Players* players)
				: PluginInterfaceAdapter<Players>(players)
			{
			}
		};

		Players::Players()
			: players(std::vector<boost::shared_ptr<Instance>>()),
			  peer(NULL),
			  maxPlayers(12)
		{
			setName("Players");
			plugin.reset(new Plugin(this));
		}

		Players::~Players()
		{
			if (peer)
				peer->DetachPlugin(plugin.get());

			peer = NULL;
		}

} }
