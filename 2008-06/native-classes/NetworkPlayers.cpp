// 2008-06 native RBX::Network::Players (inactive); evidence in native-headers/Network/Players.h.
// Verified by tests/record_native_network_players.py. Network::Client and Network::Server do not compile
// against the 2008 const-char-array DescribedCreatable; the recorder supplies declaration-only stand-ins
// for "Client.h" / "Server.h" (tests/NativeNetworkPlayersPeers.h).
// >>> native-status (generated) -- do not edit >>>
// NetworkPlayers | 2008-06 | partial
// 3/6 exact by name (50%) | named 1 | 3/6 exact bodies | no strings | verified 2026-11-07| by tester (+2) (mixed 2)
// <<< native-status | src 81b70e08 | roc native-status --write
#include <RakPeer.h>
#include <PluginInterface.h>
#include "Client.h"
#include "Server.h"
#include "Network/Players.h"
#include "v8datamodel/ModelInstance.h"
#include "v8tree/PropertyChanged.h"
#include "security/SecurityContext.h"
#ifdef NATIVE_NETWORK_PLAYERS_PENDING
#include "v8datamodel/Teams.h"
#endif

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

// PluginInterfaceAdapter<Players>::OnReceive 0049df50: forward to owner at +4, then map bool to RakNet result.
template<class Class>
PluginReceiveResult PluginInterfaceAdapter<Class>::OnReceive(RakPeerInterface* peer, Packet* packet)
{
	return c->OnReceive(peer, packet) ? RR_CONTINUE_PROCESSING : RR_STOP_PROCESSING_AND_DEALLOCATE;
}

namespace RBX
{
	namespace Network
	{
		char sPlayers[] = "Players"; // 0093784c (.data; classDescriptor 0049a8a0)
	}

	// Template members the shared headers only declare (same definitions as Feature.cpp).
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::getClassName() const { return className(); }

	namespace Reflection
	{
		// Declared (not defined) in reflection/reflection.h; ReportAbuse 0049b3b0 is its instance.
		template<typename Class, typename Function>
		BoundFuncDesc<Class, Function, 2>::BoundFuncDesc(
			typename BoundFuncDesc<Class, Function, 2>::FunctionSig function,
			const char* name,
			const char* arg1Name,
			const char* arg2Name,
			Security security)
			: FuncDesc<Class>(name, security),
			  function(function),
			  default1(),
			  default2()
		{
			declareSignature(arg1Name, arg2Name);
		}
	}
}

using namespace RBX;
using namespace RBX::Network;

// Dynamic initializers 007f17c0..007f1a30, in this order.
// ReportAbuse (007f18c0) and SetAbuseReportUrl (007f1980) push security level 4; the current reflection/function.h
// FunctionDescriptor::Security names only 0 and 1, so the value is cast until that header gains the 2008 enumerator.
static Reflection::PropDescriptor<Players, int> propPlayerCount("NumPlayers", "Data", &Players::numPlayers, NULL, Reflection::PropertyDescriptor::UI); // 009703a8
static Reflection::PropDescriptor<Players, int> propPlayerMaxCount("MaxPlayers", "Data", &Players::getMaxPlayers, &Players::setMaxPlayers, Reflection::PropertyDescriptor::STANDARD); // 0097029c
Reflection::RefPropDescriptor<Players, Player> Players::propLocalPlayer("LocalPlayer", "Data", &Players::getLocalPlayer, NULL, Reflection::PropertyDescriptor::STANDARD); // 00970388
static Reflection::BoundFuncDesc<Players, boost::shared_ptr<Instance>(int), 1> func_GetPlayerByID(&Players::getPlayerByID, "GetPlayerByID", "userID", Reflection::FunctionDescriptor::AnyCaller); // 00970340
static Reflection::BoundFuncDesc<Players, void(std::string), 1> funcChat(&Players::chat, "Chat", "message", Reflection::FunctionDescriptor::AnyCaller); // 009704d8
static Reflection::BoundFuncDesc<Players, void(boost::shared_ptr<Instance>, std::string), 2> funcReportAbuse(&Players::reportAbuse, "ReportAbuse", "player", "message", static_cast<Reflection::FunctionDescriptor::Security>(4)); // 00970408
static Reflection::BoundFuncDesc<Players, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(void), 0> func_players(&Players::getPlayers, "players", Reflection::FunctionDescriptor::NeedTrustedCaller); // 009702b8
static Reflection::BoundFuncDesc<Players, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(void), 0> func_GetPlayers(&Players::getPlayers, "GetPlayers", Reflection::FunctionDescriptor::NeedTrustedCaller); // 009703c8
static Reflection::BoundFuncDesc<Players, boost::shared_ptr<Instance>(int), 1> func_createLocalPlayer(&Players::createLocalPlayer, "CreateLocalPlayer", "userId", Reflection::FunctionDescriptor::AnyCaller); // 009702f8
static Reflection::BoundFuncDesc<Players, void(std::string), 1> func_setAbuseReportUrl(&Players::setAbuseReportUrl, "SetAbuseReportUrl", "url", static_cast<Reflection::FunctionDescriptor::Security>(4)); // 00970558
static Reflection::BoundFuncDesc<Players, boost::shared_ptr<Instance>(boost::shared_ptr<Instance>), 1> func_playerFromCharacterOld(&Players::playerFromCharacter, "playerFromCharacter", "character", Reflection::FunctionDescriptor::NeedTrustedCaller); // 009705a0
static Reflection::BoundFuncDesc<Players, boost::shared_ptr<Instance>(boost::shared_ptr<Instance>), 1> func_playerFromCharacter(&Players::playerFromCharacter, "GetPlayerFromCharacter", "character", Reflection::FunctionDescriptor::NeedTrustedCaller); // 00970458
static Reflection::SignalDesc<Players, void(boost::shared_ptr<Instance>)> event_PlayerAdded("PlayerAdded", "player"); // 009704a0
static Reflection::SignalDesc<Players, void(boost::shared_ptr<Instance>)> event_PlayerRemoving("PlayerRemoving", "player"); // 00970520

namespace RBX
{
	namespace Network
	{
		// Players ctor 0049bdc0 allocates 8 bytes; owner pointer is at +4 and adapter OnReceive is vtable slot 5.
		class Players::Plugin : public PluginInterfaceAdapter<Players>
		{
		public:
			Plugin(Players* players)
				: PluginInterfaceAdapter<Players>(players)
			{
			}
		};

		Players::Players()
			: players(std::vector<boost::shared_ptr<Instance> >()),
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

		bool Players::clientIsPresent(const Instance* context, bool testInDatamodel)
		{
			return Client::clientIsPresent(context, testInDatamodel);
		}

		bool Players::serverIsPresent(const Instance* context, bool testInDatamodel)
		{
			return Server::serverIsPresent(context, testInDatamodel);
		}

#ifdef NATIVE_NETWORK_PLAYERS_PENDING
		// The bodies under NATIVE_NETWORK_PLAYERS_PENDING need declarations other owners' headers lack
		// (proposals in tests/record_native_network_players.py):
		//   v8tree/Service.h   static const ServiceProvider* findServiceProvider(const Instance*) (out of line, 004898d0)
		//   Network/Player.h   void rebuildBackpack() (004925c0)
		bool Players::frontendProcessing(const Instance* context, bool testInDatamodel)
		{
			const ServiceProvider* sp = ServiceProvider::findServiceProvider(context);
			return sp && !Server::serverIsPresent(context, testInDatamodel);
		}

		bool Players::backendProcessing(const Instance* context, bool testInDatamodel)
		{
			const ServiceProvider* sp = ServiceProvider::findServiceProvider(context);
			return sp && !Client::clientIsPresent(context, testInDatamodel);
		}

		void Players::onEvent(const Player* source, CharacterAdded event)
		{
			const_cast<Player*>(source)->rebuildBackpack();
		}

		void Players::onChildAdded(Instance* child)
		{
			Player* player = dynamic_cast<Player*>(child);
			if (!player)
				return;

			if (player->getUserID() > 0)
			{
				boost::shared_ptr<Instance> otherPlayer = getPlayerByID(player->getUserID());
				if (otherPlayer)
					otherPlayer->setParent(NULL);
			}

			boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& myPlayers = players.write();
			myPlayers->push_back(shared_from(child));

			if (backendProcessing(this, true))
			{
				player->Notifier<Player, CharacterAdded>::addListener(this);
				player->rebuildBackpack();

				if (Teams* teams = ServiceProvider::find<Teams>(this))
					teams->assignNewPlayerToTeam(player);

				event_PlayerAdded.fire(this, shared_from(player));
			}
		}

		void Players::onChildRemoving(Instance* child)
		{
			Player* player = dynamic_cast<Player*>(child);
			if (!player)
				return;

			boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& myPlayers = players.write();
			myPlayers->erase(std::find(myPlayers->begin(), myPlayers->end(), shared_from(child)));

			if (backendProcessing(this, false))
				event_PlayerRemoving.fire(this, shared_from(player));

			Notifier<Player, CharacterAdded>::disconnect(player, this);
		}
#endif

		bool Players::askAddChild(const Instance* instance) const
		{
			return dynamic_cast<const Player*>(instance) != NULL;
		}

		bool Players::canReportAbuse() const
		{
			return abuseReporter || clientIsPresent(this, true);
		}

		void Players::setConnection(RakPeerInterface* peer)
		{
			if (this->peer)
				this->peer->DetachPlugin(plugin.get());

			this->peer = peer;

			if (peer)
				peer->AttachPlugin(plugin.get());
		}

		Player* Players::findLocalPlayer(const Instance* context)
		{
			Players* players = ServiceProvider::find<Players>(context);
			return players ? players->getLocalPlayer() : NULL;
		}

		ModelInstance* Players::findLocalCharacter(const Instance* context)
		{
			Player* player = Players::findLocalPlayer(context);
			return player ? player->getCharacter() : NULL;
		}

		void Players::setAbuseReportUrl(std::string value)
		{
			if (value.empty())
				abuseReporter.reset(NULL);
			else
				abuseReporter.reset(new AbuseReporter(value));
		}

		void Players::setMaxPlayers(int value)
		{
			if (value != maxPlayers)
			{
				maxPlayers = value;
				raisePropertyChanged(propPlayerMaxCount);
			}
		}

		void Players::reportAbuse(boost::shared_ptr<Instance> player, std::string comment)
		{
			reportAbuse(dynamic_cast<Player*>(player.get()), comment);
		}

		boost::shared_ptr<Instance> Players::playerFromCharacter(boost::shared_ptr<Instance> character)
		{
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > myPlayers = getPlayers();

			std::vector<boost::shared_ptr<Instance> >::const_iterator iter = myPlayers->begin();
			std::vector<boost::shared_ptr<Instance> >::const_iterator end = myPlayers->end();

			for (; iter != end; iter++)
			{
				if (static_cast<Player*>(iter->get())->getCharacter() == static_cast<ModelInstance*>(character.get()))
					return *iter;
			}

			return boost::shared_ptr<Instance>();
		}

		boost::shared_ptr<Instance> Players::getPlayerByID(int userID)
		{
			std::vector<boost::shared_ptr<Instance> >::const_iterator iter = players->begin();
			std::vector<boost::shared_ptr<Instance> >::const_iterator end = players->end();

			for (; iter != end; iter++)
			{
				if (static_cast<Player*>(iter->get())->getUserID() == userID)
					return *iter;
			}

			return boost::shared_ptr<Instance>();
		}

		void Players::onChildChanged(Instance* instance, const PropertyChanged& event)
		{
			if (instance == localPlayer.get() && &event.getProperty().getDescriptor() == &Player::prop_SuperSafeChat)
			{
				bool s = localPlayer ? Player::prop_SuperSafeChat.getValue(localPlayer.get()) : false;
				Notifier<Players, SuperSafeChanged>::raise(SuperSafeChanged(s));
			}
		}

		boost::shared_ptr<Instance> Players::createLocalPlayer(int userId)
		{
			if (localPlayer)
				throw std::runtime_error("Local player already exists");

			{
				Security::Impersonator impersonate(Security::Replicator);
				localPlayer = Creatable<Instance>::create<Player>();
			}
			localPlayer->setUserID(userId);
			localPlayer->setParent(this);
			raisePropertyChanged(propLocalPlayer);

			bool s = localPlayer ? Player::prop_SuperSafeChat.getValue(localPlayer.get()) : false;
			Notifier<Players, SuperSafeChanged>::raise(SuperSafeChanged(s));

			return localPlayer;
		}
	}
}
