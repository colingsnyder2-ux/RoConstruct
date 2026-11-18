#pragma once
// INFERRED: stub for missing RakNet PluginInterface.h; Replicator and Peer inherit from PluginInterface (RTTI vtable 00825450 / 00824898)
// Only the class declaration is needed for inheritance; virtual slot bodies are defined out-of-line in native-classes/PluginInterface.h
#include "RakNetTypes.h"

class RakPeerInterface;
struct Packet;

enum PluginReceiveResult { RR_CONTINUE_PROCESSING = 0 };

class PluginInterface {
public:
    virtual ~PluginInterface() {}
    virtual void OnAttach(RakPeerInterface*) {}
    virtual void OnDetach(RakPeerInterface*) {}
    virtual void OnStartup(RakPeerInterface*) {}
    virtual void Update(RakPeerInterface*) {}
    virtual PluginReceiveResult OnReceive(RakPeerInterface*, Packet*) { return RR_CONTINUE_PROCESSING; }
    virtual void OnShutdown(RakPeerInterface*) {}
    virtual void OnCloseConnection(RakPeerInterface*, SystemAddress) {}
    virtual void OnDirectSocketSend(const char*, const unsigned, SystemAddress) {}
    virtual void OnDirectSocketReceive(const char*, const unsigned, SystemAddress) {}
    virtual void OnInternalPacket(class InternalPacket*, unsigned, SystemAddress, unsigned long, bool) {}
};
