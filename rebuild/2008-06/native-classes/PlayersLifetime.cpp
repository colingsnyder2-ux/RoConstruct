// >>> native-status (generated) -- do not edit >>>
// PlayersLifetime | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 57698c84 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::scoped_ptr<RBX::Network::Players::Plugin>;
template class boost::shared_ptr<RBX::Network::AbuseReporter::data>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Network::Players,RBX::Network::ChatMessage> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Network::Players,RBX::SuperSafeChanged> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Network::ChatMessage> >;
template class std::allocator<RBX::Network::ChatMessage>;
template class std::allocator<std::_List_nod<RBX::Network::ChatMessage,std::allocator<RBX::Network::ChatMessage> >::_Node *>;
template class std::vector<RBX::Listener<RBX::Network::Players,RBX::SuperSafeChanged> *,std::allocator<RBX::Listener<RBX::Network::Players,RBX::SuperSafeChanged> *> >;
