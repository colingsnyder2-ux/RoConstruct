#ifndef NATIVE_NETWORK_PLAYERS_PEERS_H // included as both "Client.h" and "Server.h"
#define NATIVE_NETWORK_PLAYERS_PEERS_H
// Declaration-only stand-in for RBX::Network::Client and RBX::Network::Server (copied to
// out/native-network-players/overlay/Client.h and Server.h by tests/record_native_network_players.py).
// The donor tools/rbxgs Client.h / Server.h do not compile against the 2008 const-char-array
// DescribedCreatable. Only the static helpers the Players unit calls; addresses are the call targets
// read in the original Players bodies (00495e60, 00495e70, 00495eb0, 00496390). Not a recovery of Client/Server.
namespace RBX {
class Instance;
namespace Network {
class Client {
public:
    static bool clientIsPresent(const Instance* context, bool testInDatamodel); // 0049fe20
private:
    Client();
};
class Server {
public:
    static bool serverIsPresent(const Instance* context, bool testInDatamodel); // 004a40d0
private:
    Server();
};
}
}
#endif
