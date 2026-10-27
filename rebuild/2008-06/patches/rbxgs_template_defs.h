#pragma once

#include "v8world/SimJobStage.h"
#include "Network/Players.h"
#include "PluginInterface.h"

namespace RBX {
template <typename Class>
void SimJobStage::reportMechanisms(Class& callback, MechanismTracker& tracker, const Mechanism* ignore) {
    (void)callback;
    (void)tracker;
    (void)ignore;
}
}

template <>
class PluginInterfaceAdapter<RBX::Network::Players> {
public:
    virtual PluginReceiveResult OnReceive(RakPeerInterface*, Packet*);
};

template <>
PluginReceiveResult PluginInterfaceAdapter<RBX::Network::Players>::OnReceive(RakPeerInterface*, Packet*) {
    return (PluginReceiveResult)0;
}
