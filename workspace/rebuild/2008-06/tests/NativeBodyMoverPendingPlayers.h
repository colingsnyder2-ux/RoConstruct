#pragma once
// Declaration-only overlay for RBX::Network::Players (copied to out/native-body-movers-pending/Network/Players.h by
// tests/record_native_body_movers.py); not a shared header. Same form as tests/NativeClothingPlayers.h.
namespace RBX {
class Instance;
namespace Network {
class Players {
public:
    static bool clientIsPresent(const Instance* context, bool testInDatamodel); // 00495e60 (Rocket::fire 0062e1c0)
private:
    Players();
};
}
}
