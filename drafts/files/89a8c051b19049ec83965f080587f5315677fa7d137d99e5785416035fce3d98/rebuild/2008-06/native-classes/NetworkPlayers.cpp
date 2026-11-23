// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Players (inactive); evidence in native-headers/Network/Players.h.
// Verified by tests/record_native_network_players.py. Network::Client / Network::Server come from the native 2008
// headers Network/Client2008.h / Network/Server2008.h (clientIsPresent 0049fe20, serverIsPresent 004a40d0); they
// replace the earlier declaration-only stand-ins "Client.h" / "Server.h" (tests/NativeNetworkPlayersPeers.h).
#include <RakPeer.h>
#include <PluginInterface.h>
#include "Network/Client2008.h"
#include "Network/Server2008.h"
#include "Network/Players.h"
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

		// 00495e60 / 00495e70: 5-byte tail jumps (jmp 0049fe20 Client::clientIsPresent / jmp 004a40d0
		// Server::serverIsPresent) in the Players unit. backendProcessing 00495eb0, frontendProcessing 00495e80,
		// canReportAbuse 00496390 and onChildAdded 0049dc70 / onChildRemoving 0049daa0 call 0049fe20 / 004a40d0
		// directly, as this source does.
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
		// 00496c20 (registry placeholder func_00496c20): callers Players::chat 0049cb30 and 0049d770; default-constructs
		// time +0x00, message +0x1c from the const char*, copies source +0x38, clears destination +0x40, then
		// makeGuidString 005a80d0 fills +0x00 (EH states 1..4 follow the member order).
		// 0049acd0 (registry placeholder func_0049acd0): static Players::getPlayerFromCharacter (callers include
		// SpawnLocation touched 005d1ec0 and Inferred_006195b0): find<Players> 00491d50, shared_from 00618a40,
		// playerFromCharacter 00498030. Donor tools/rbxgs Players.cpp shape.
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

// 0049d630 (registry placeholder func_0049d630): Players::addChatMessage (Players.h donor declaration). Identity: callers
// OnReceive 0049d770 (ID_CHAT_ALL branch) only; thiscall ret 4 (const ChatMessage&). Body read from the target: list
// insert at begin (_Buynode 00497860, _Incsize 00496ff0) = chatHistory.push_front (+0x178), then while size (+0x190) >
// (unsigned) GameSettings::singleton() 0044bee0 ->chatHistory (+0x130) erase(--end()) 00498870 (= pop_back), then a
// by-value copy 00496480 for Notifier<Players, ChatMessage>::raise 00496d90 (+0x130), then the Player "Chatted" signal
// 0096fca0 fire 0049d2b0 (source.get() as SignalSource, message, destination). Shape: donor tools/rbxgs Players.cpp.
// BLOCKED (guard): native Network/Player.h (not this batch's file) does not declare the signal; NetworkPlayer.cpp
// defines it as a file-static `event_Chatted` (0096fca0). Proposal: declare
// `static Reflection::SignalDesc<Player, void(std::string, boost::shared_ptr<Instance>)> event_Chatted; // 0096fca0`
// in Player (public) with the NetworkPlayer.cpp definition made the member's, and define
// PLAYER_HEADER_DECLARES_EVENT_CHATTED. Measured (batch 45, scratch copy of Network/Player.h with that declaration):
// 318 B, byte-identical to 0049d630 (relocs masked).
//
// 0049d770 Players::OnReceive (Players.h; caller PluginInterfaceAdapter<Players>::OnReceive 0049df50). Body read from
// the target (805 B): switch on packet->data[0]: 0x52 (abuse report; tested second) and 0x51 (ID_CHAT_ALL), any other id
// returns true. Both cases are try/catch(std::exception&) blocks printing "Players::OnReceive packet %d: %s" (00822b38,
// MESSAGE_ERROR) through StandardOut::singleton() 00569620 / print 005693a0, and return false. Chat: BitStream(data,
// length, false) 004a5120, IgnoreBits(8) 004a5470, >> string 004a6610, Name::lookup 00554180, >> int 004a6250, the
// GuidItem<Instance> registry lookup 0049ba80, >> message; unknown player: MESSAGE_WARNING "Chat message from unknown
// Player %s %s" (00822b10) with systemAddress.ToString(true) 004a98b0; player->getParent() (+0x104) == this: ChatMessage
// (message.c_str(), shared_from_polymorphic_downcast<Player>) 00496c20, addChatMessage 0049d630, peer slot 0x38
// Send(data, length, HIGH_PRIORITY, RELIABLE, 2, systemAddress, true). Abuse report: if (abuseReporter) BitStream,
// IgnoreBits(8), AbuseReport 00499320, >> submitterID, >> allegedAbuserID, >> comment, AbuseReporter::add 0049c710.
// Shape: openrbx Client/Network/Players.cpp Players::OnReceive (ROBLOX 0x004b6fc0).
// BLOCKED (guard): additionally needs the 0049ba80 declaration in core util/GuidItem.h (the NATIVE_GUID_REGISTRY_LOOKUP
// proposal of AppUnit49C_2008IdSerializerTemplates.cpp: `static bool sub_0049ba80(const Guid::Data& id, T*& item);`).
// Measured (batch 45, scratch Player.h + GuidItem.h): 805 B, same instructions; only the frame differs (sub esp 0x68 vs
// 0x64, one extra 4-byte slot: the original reuses the dead `player` slot +0x60 for the ChatMessage argument's esp save,
// and the catch-block StandardOut temporaries sit at +0x28/+0x20/+0x34 instead of +0x38/+0x30/+0x1c). Near miss.
#ifdef PLAYER_HEADER_DECLARES_EVENT_CHATTED
#include "v8datamodel/GameSettings.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "BitStream.h"
#include "util/standardout.h"

namespace RBX
{
	namespace Network
	{
		void Players::addChatMessage(const ChatMessage& message)
		{
			chatHistory.push_front(message);

			while (chatHistory.size() > (size_t)GameSettings::singleton().chatHistory)
				chatHistory.pop_back();

			Notifier<Players, ChatMessage>::raise(message);
			Player::event_Chatted.fire(message.source.get(), message.message, message.destination);
		}

#ifdef NATIVE_GUID_REGISTRY_LOOKUP
		bool Players::OnReceive(RakPeerInterface* peer, Packet* packet)
		{
			switch (packet->data[0])
			{
			case 0x51: // ID_CHAT_ALL (2008 numbering)
				try
				{
					RakNet::BitStream inBitstream(packet->data, packet->length, false);
					inBitstream.IgnoreBits(8);

					std::string foo;
					inBitstream >> foo;

					Guid::Data id;
					id.scope = &Name::lookup(foo);
					inBitstream >> id.index;

					Instance* player = NULL;
					GuidItem<Instance>::sub_0049ba80(id, player);

					std::string message;
					inBitstream >> message;

					if (!player)
					{
						StandardOut::singleton()->print(MESSAGE_WARNING, "Chat message from unknown Player %s %s",
							packet->systemAddress.ToString(true), message.c_str());
					}
					else if (player->getParent() == this)
					{
						ChatMessage event(message.c_str(), shared_from_polymorphic_downcast<Player>(player));
						addChatMessage(event);

						peer->Send(reinterpret_cast<const char*>(packet->data), packet->length, HIGH_PRIORITY, RELIABLE, 2,
							packet->systemAddress, true);
					}
				}
				catch (std::exception& e)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Players::OnReceive packet %d: %s", packet->data[0], e.what());
				}
				return false;

			case 0x52: // abuse report (2008 numbering)
				try
				{
					if (abuseReporter)
					{
						RakNet::BitStream inBitstream(packet->data, packet->length, false);
						inBitstream.IgnoreBits(8);

						AbuseReport r;
						inBitstream >> r.submitterID;
						inBitstream >> r.allegedAbuserID;
						inBitstream >> r.comment;

						abuseReporter->add(r, chatHistory);
					}
				}
				catch (std::exception& e)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Players::OnReceive packet %d: %s", packet->data[0], e.what());
				}
				return false;

			default:
				return true;
			}
		}
#endif
	}
}
#endif

// 00496ff0 (registry placeholder func_00496ff0): std::list<ChatMessage>::_Incsize (max_size 0x38e38e3 = ~0u / 0x48,
// "list<T> too long"); its only caller is the chatHistory push 0049d630 (Players::addChatMessage, not built here).
template void std::list<RBX::Network::ChatMessage>::_Incsize(std::list<RBX::Network::ChatMessage>::size_type);
