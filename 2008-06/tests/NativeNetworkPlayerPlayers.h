#pragma once
// Declaration-only stand-in for RBX::Network::Players (copied to out/native-layouts/network-player-overlay/
// Network/Players.h by tests/record_native_network_player.py; the donor Players.h does not compile with the
// 2008 const-char-array DescribedCreatable). Only the static helpers the Player unit calls; addresses are the
// call targets read in the original Player bodies. Not a recovery of Players.
namespace RBX {
class Instance;
namespace Network {
class Player;
class Players {
public:
    static bool clientIsPresent(const Instance* context, bool testInDatamodel);    // 00495e60
    static bool frontendProcessing(const Instance* context, bool testInDatamodel); // 00495e80
    static bool backendProcessing(const Instance* context, bool testInDatamodel);  // 00495eb0
private:
    Players();
};
}
}
