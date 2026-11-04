#pragma once
// Declaration-only overlay for RBX::Network::Players (copied to out/clothing-overlay/Network/Players.h by
// tests/record_native_clothing.py); not a shared header.
namespace RBX {
class Instance;
namespace Network {
class Players {
public:
    static bool backendProcessing(const Instance* context, bool testInDatamodel); // 00495eb0
private:
    Players();
};
}
}
