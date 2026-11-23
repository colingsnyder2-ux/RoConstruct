// =============================================================================
// Players.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/include/network/Players.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
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
				std::string guid;   // +0x20 INFERRED: AbuseReport::Message size/offset from the 004971c0 area
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
			bool superSafeOn() const;                                                 // 00497600 (body: native-classes/PlayersSuperSafe.cpp)
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
