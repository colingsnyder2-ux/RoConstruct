// Layout probe for the inactive native Network::Player header; tests/record_native_network_player.py
// checks each function body is `mov eax, imm32; ret` with the value from the binary:
//   sizeof(Player) 0x1d8  Creatable<Instance>::create<Player> 004093b0 allocates 0x1d8
//   fields         constructor 00493da0 / destructor 00494c60 / setters 00494600, 00494620, 00494830,
//                  00495d00; BoundProp member offsets pushed by the initializers 007f10c0..007f1210.
// Field offsets are compile-time asserts (NativeNetworkPlayerLayout is a friend of Player). Built with
// only native headers (the Player header needs neither Players.h nor ModelInstance.h).
#include <stddef.h>
#include "Network/Player.h"

struct NativeNetworkPlayerLayout
{
	typedef RBX::Network::Player P;
	typedef char Character[offsetof(P, character) == 0x170 ? 1 : -1];
	typedef char TeamColor[offsetof(P, teamColor) == 0x178 ? 1 : -1];
	typedef char Neutral[offsetof(P, neutral) == 0x17c ? 1 : -1];
	typedef char DiedConnection[offsetof(P, characterDiedConnection) == 0x180 ? 1 : -1];
	typedef char Appearance[offsetof(P, characterAppearance) == 0x194 ? 1 : -1];
	typedef char Under13[offsetof(P, under13) == 0x1b0 ? 1 : -1];
	typedef char SuperSafeChat[offsetof(P, superSafeChat) == 0x1b1 ? 1 : -1];
	typedef char UserId[offsetof(P, userId) == 0x1b4 ? 1 : -1];
	typedef char ServerRequestLow[offsetof(P, serverRequestLow) == 0x1b8 ? 1 : -1];
	typedef char ServerRequestHigh[offsetof(P, serverRequestHigh) == 0x1bc ? 1 : -1];
	typedef char ServerDemandLow[offsetof(P, serverDemandLow) == 0x1c0 ? 1 : -1];
	typedef char ServerDemandHigh[offsetof(P, serverDemandHigh) == 0x1c4 ? 1 : -1];
	typedef char ClientSimulateLow[offsetof(P, clientSimulateLow) == 0x1c8 ? 1 : -1];
	typedef char ClientSimulateHigh[offsetof(P, clientSimulateHigh) == 0x1cc ? 1 : -1];
	typedef char LastActivity[offsetof(P, lastActivityTime) == 0x1d0 ? 1 : -1];
};

size_t nativeNetworkPlayerSize() { return sizeof(RBX::Network::Player); }
size_t nativeScopedConnectionSize() { return sizeof(boost::signals::scoped_connection); }
size_t nativeNotifierAddedOffset() { return (size_t)static_cast<RBX::Notifier<RBX::Network::Player, RBX::Network::CharacterAdded>*>((RBX::Network::Player*)0x1000) - 0x1000; }
size_t nativeNotifierRemovingOffset() { return (size_t)static_cast<RBX::Notifier<RBX::Network::Player, RBX::Network::CharacterRemoving>*>((RBX::Network::Player*)0x1000) - 0x1000; }
