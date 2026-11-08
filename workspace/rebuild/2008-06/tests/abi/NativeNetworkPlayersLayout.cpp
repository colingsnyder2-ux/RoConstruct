// Layout probe for the inactive native Network::Players header; tests/record_native_network_players.py
// checks each function body is `mov eax, imm32; ret` with the value from the binary:
//   sizeof(Players) 0x1b0   ServiceProvider::create<Players> 00411fd0 allocates 0x1b0
//   fields          constructor 0049bdc0 / destructor 00499630 / setConnection 00496510 / setMaxPlayers 0049d450.
// Field offsets are compile-time asserts (NativeNetworkPlayersLayout is a friend of Players). Built with
// only native headers.
#include <stddef.h>
#include "Network/Players.h"

struct NativeNetworkPlayersLayout
{
	typedef RBX::Network::Players P;
	typedef char AbuseReporter[offsetof(P, abuseReporter) == 0x174 ? 1 : -1];
	typedef char ChatHistory[offsetof(P, chatHistory) == 0x178 ? 1 : -1];
	typedef char Plugin[offsetof(P, plugin) == 0x194 ? 1 : -1];
	typedef char PlayerList[offsetof(P, players) == 0x198 ? 1 : -1];
	typedef char LocalPlayer[offsetof(P, localPlayer) == 0x1a0 ? 1 : -1];
	typedef char Peer[offsetof(P, peer) == 0x1a8 ? 1 : -1];
	typedef char MaxPlayers[offsetof(P, maxPlayers) == 0x1ac ? 1 : -1];
};

int nativePlayersSize() { return sizeof(RBX::Network::Players); }
int nativePlayersChatNotifierOffset() { return (int)(size_t)static_cast<RBX::Notifier<RBX::Network::Players, RBX::Network::ChatMessage>*>((RBX::Network::Players*)0x1000) - 0x1000; }
int nativePlayersSuperSafeNotifierOffset() { return (int)(size_t)static_cast<RBX::Notifier<RBX::Network::Players, RBX::SuperSafeChanged>*>((RBX::Network::Players*)0x1000) - 0x1000; }
int nativePlayersListenerOffset() { return (int)(size_t)static_cast<RBX::Listener<RBX::Network::Player, RBX::Network::CharacterAdded>*>((RBX::Network::Players*)0x1000) - 0x1000; }
int nativePlayersServiceOffset() { return (int)(size_t)static_cast<RBX::Service*>((RBX::Network::Players*)0x1000) - 0x1000; }
int nativeChatMessageSize() { return sizeof(RBX::Network::ChatMessage); }
int nativeChatHistorySize() { return sizeof(std::list<RBX::Network::ChatMessage>); }
