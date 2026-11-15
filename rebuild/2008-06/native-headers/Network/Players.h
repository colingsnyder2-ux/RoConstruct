#pragma once
// 2008-06 native RBX::Network::Players (inactive). Shape after the donor tools/rbxgs Network/Players.h;
// every base, field, virtual and descriptor below is read from the 2008-06 binary:
//   RTTI       vtable 008227bc .?AVPlayers@Network@RBX@@ (25 bases) -> DescribedNonCreatable<Players,
//              Instance, sPlayers> (name mangled $1?sPlayers@23@3PADA, a non-const char array), Service
//              (empty, mdisp 0x174), Notifier<Players, ChatMessage> 0x130 (ChatMessage mangled V: a class),
//              Notifier<Players, SuperSafeChanged> 0x150, Listener<Player, CharacterAdded> 0x170.
//   size       0x1b0: ServiceProvider::create<Players> 00411fd0 allocates 0x1b0, constructor 0049bdc0.
//   fields     constructor 0049bdc0 / destructor 00499630:
//              +0x174 scoped_ptr<AbuseReporter> abuseReporter (destroyed through ~AbuseReporter 004971c0),
//              +0x178 std::list<ChatMessage> chatHistory (list ctor 004987f0, dtor 004993c0),
//              +0x194 scoped_ptr<Plugin> plugin (new(8), vtable 00822688; deleted through slot 0),
//              +0x198 CopyOnWrite<vector<shared_ptr<Instance> > > players (ctor 0049ad50),
//              +0x1a0 shared_ptr<Player> localPlayer, +0x1a8 RakPeerInterface* peer, +0x1ac int maxPlayers (12).
//   vtable     slot 2 askAddChild 00495f30, slot 7 onChildAdded 0049dc70, slot 8 onChildRemoving 0049daa0,
//              slot 15 onChildChanged 00497ec0; Listener slot 0 onEvent 00496cf0; destructor 00499630
//              (deleting 00499fb0, thunks 00499830..004998d0).
//   descriptors dynamic initializers 007f17c0..007f1a30 (atexit 007fb7c0..007fb9e0).
#include "Network/Player.h"
#include "Network/SuperSafeChanged.h"
#include "v8tree/Service.h"
#include "util/boost.hpp"
#include <list>
#include <queue>

class RakPeerInterface;
struct Packet;

struct NativeNetworkPlayersLayout;

namespace RBX
{
	class ModelInstance;

	namespace Network
	{
		class Player;

		// ChatMessage (RTTI Notifier<Players, ChatMessage> mangles V: a class), size 0x48: constructor 00496c20
		// default-constructs the string at +0x00 and passes it to 005a80d0 (fills it with the local time text;
		// field name provisional), builds message +0x1c from the const char*, copies source +0x38 and clears
		// destination +0x40. Copy constructor 00496480 and destructor 004963c0 are the implicit ones.
		class ChatMessage
		{
		public:
			std::string time;                                                         // +0x00
			const std::string message;                                                // +0x1c
			const boost::shared_ptr<Player> source;                                   // +0x38
			const boost::shared_ptr<Player> destination;                              // +0x40

		public:
			ChatMessage(const char* message, boost::shared_ptr<Player> source);       // 00496c20
		};

		struct AbuseReport
		{
		public:
			struct Message
			{
				int userID;
				std::string text;
			};

		public:
			int submitterID;
			int allegedAbuserID;
			std::string comment;
			std::list<Message> messages;

		public:
			void addMessage(const ChatMessage& cm);
		};

		class AbuseReporter
		{
		private:
			struct data
			{
				std::queue<AbuseReport> queue;
				boost::mutex requestSync;
			};

		private:
			boost::shared_ptr<data> _data;
			boost::scoped_ptr<worker_thread> requestProcessor;

		public:
			AbuseReporter(std::string abuseUrl);                                     // 0049e040
			void add(AbuseReport& r, const std::list<ChatMessage>& chatHistory);   // 0049c710

		private:
			static worker_thread::work_result processRequests(boost::shared_ptr<data>, std::string);
		};

		extern char sPlayers[];

		class Players : public DescribedNonCreatable<Players, Instance, sPlayers>,
						public Service,
						public Notifier<Players, ChatMessage>,
						public Notifier<Players, SuperSafeChanged>,
						public Listener<Player, CharacterAdded>
		{
			friend struct ::NativeNetworkPlayersLayout; // tests/NativeNetworkPlayersLayout.cpp offset asserts
		private:
			class Plugin;

		private:
			boost::scoped_ptr<AbuseReporter> abuseReporter;                           // +0x174
			std::list<ChatMessage> chatHistory;                                       // +0x178
			boost::scoped_ptr<Plugin> plugin;                                         // +0x194
			CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > players;          // +0x198
			boost::shared_ptr<Player> localPlayer;                                    // +0x1a0
			RakPeerInterface* peer;                                                   // +0x1a8
			int maxPlayers;                                                           // +0x1ac

		public:
			static Reflection::RefPropDescriptor<Players, Player> propLocalPlayer;    // 00970388

		private:
			virtual void onEvent(const Player* source, CharacterAdded event);         // 00496cf0
			virtual void onChildChanged(Instance* instance, const PropertyChanged& event); // 00497ec0
		public:
			Players();                                                                // 0049bdc0
			virtual ~Players();                                                       // 00499630
		public:
			bool superSafeOn() const;                                                 // donor declaration; 2008 body not located
			boost::shared_ptr<Instance> createLocalPlayer(int userId);                // 0049d480
			Player* getLocalPlayer() const                                            // 0048a660 (ICF)
			{
				return localPlayer.get();
			}
			int getNumPlayers() const;                                                // donor declaration; 2008 body not located
			int numPlayers() const                                                    // 00496c10
			{
				return (int)players->size();
			}
			int getMaxPlayers() const                                                 // 00495e50
			{
				return maxPlayers;
			}
			void setMaxPlayers(int value);                                            // 0049d450
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > getPlayers() // 004974c0
			{
				return players.read();
			}
			void chat(std::string message);                                           // 0049cb30
			void reportAbuse(boost::shared_ptr<Instance> player, std::string comment); // 0049ca70
			void reportAbuse(Player* player, std::string comment);                    // 0049c7b0
			std::list<ChatMessage>::const_iterator chatHistory_begin();               // donor declaration; 2008 body not located
			std::list<ChatMessage>::const_iterator chatHistory_end();                 // donor declaration; 2008 body not located
			bool canReportAbuse() const;                                              // 00496390
			void setAbuseReportUrl(std::string value);                                // 0049e1d0
			bool OnReceive(RakPeerInterface*, Packet*);                               // 0049d770
			void setConnection(RakPeerInterface* peer);                               // 00496510
			boost::shared_ptr<Instance> playerFromCharacter(boost::shared_ptr<Instance> character); // 00498030
			boost::shared_ptr<Instance> getPlayerByID(int userID);                    // 00497f40
		protected:
			virtual bool askAddChild(const Instance* instance) const;                 // 00495f30
			virtual void onChildAdded(Instance* child);                               // 0049dc70
			virtual void onChildRemoving(Instance* child);                            // 0049daa0
		private:
			void addChatMessage(const ChatMessage& message);                          // donor declaration; 2008 body not located

		public:
			static Player* getPlayerFromCharacter(Instance* character);               // donor declaration; 2008 body not located
			static ModelInstance* findLocalCharacter(const Instance* context);        // 0049aca0
			static Player* findLocalPlayer(const Instance* context);                  // inlined into 0049aca0
			static bool clientIsPresent(const Instance* context, bool testInDatamodel);   // 00495e60
			static bool serverIsPresent(const Instance*, bool);                       // 00495e70
			static bool frontendProcessing(const Instance* context, bool testInDatamodel); // 00495e80
			static bool backendProcessing(const Instance* context, bool testInDatamodel);  // 00495eb0
		};
	}
}
