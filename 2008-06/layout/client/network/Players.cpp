#include <RakPeer.h>
#include <PluginInterface.h>
#include "Network/Players.h"
#include "Network/Player.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "BitStream.h"
#include <stdexcept>

namespace RBX
{
	namespace Network
	{
		void Players::chat(std::string message)
		{
			if (!localPlayer)
				throw std::runtime_error("No local Player to chat from");

			RakNet::BitStream bitStream;
			bitStream << (unsigned char)0x51; // ID_CHAT_ALL (2008 numbering: ID_DATA is 0x4e, ID_PHYSICS 0x50)

			// INFERRED: the target registers the guid (0049bba0) before reading it inline (+8 scope, +0xc index); the
			Player* player = localPlayer.get();
			player->registerGuid();
			Guid::Data data;
			player->getGuid().extract(data);

			bitStream << data.scope->toString();
			bitStream << data.index;
			bitStream << message;

			peer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 2, UNASSIGNED_SYSTEM_ADDRESS, true);

			ChatMessage event(message.c_str(), localPlayer);
			Notifier<Players, ChatMessage>::raise(event);
		}
	}
}

#include "Network/Client2008.h"
#include "Network/Server2008.h"
#include "v8datamodel/ModelInstance.h"
#include "v8tree/PropertyChanged.h"
#include "security/SecurityContext.h"
#include "v8datamodel/Teams.h"

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

namespace RBX
{
	void makeGuidString(std::string& result); // 005a80d0 (body in Guid.cpp / GuidGeneration.cpp)

	namespace Network
	{
		Player* Players::getPlayerFromCharacter(Instance* character)
		{
			Players* players = ServiceProvider::find<Players>(character);
			if (players)
			{
				boost::shared_ptr<Instance> found = players->playerFromCharacter(shared_from(character));
				return static_cast<Player*>(found.get());
			}
			else
			{
				return NULL;
			}
		}

		ChatMessage::ChatMessage(const char* message, boost::shared_ptr<Player> source)
			: message(message),
			  source(source)
		{
			makeGuidString(time);
		}
	}
}

template void std::list<RBX::Network::ChatMessage>::_Incsize(std::list<RBX::Network::ChatMessage>::size_type);

bool RBX::Network::Players::superSafeOn() const
{
    if (localPlayer)
        return Player::prop_SuperSafeChat.getValue(localPlayer.get());
    return false;
}
