// >>> native-status (generated) -- do not edit >>>
// PluginInterface | 2008-06 | selection unverified
// 0/6 mapped addresses reported exact (subset) | no mapped strings | historical| by auto
// <<< native-status | src 327d5f8a | roc native-status --write
#include "../../../tools/rbxgs/Client/Network/raknet30/Source/PluginInterface.h"

PluginInterface::PluginInterface()
{
}

PluginInterface::~PluginInterface()
{
}

void PluginInterface::OnAttach(RakPeerInterface*)
{
}

void PluginInterface::OnDetach(RakPeerInterface*)
{
}

void PluginInterface::OnStartup(RakPeerInterface*)
{
}

void PluginInterface::Update(RakPeerInterface*)
{
}

PluginReceiveResult PluginInterface::OnReceive(RakPeerInterface*, Packet*)
{
    return RR_CONTINUE_PROCESSING;
}

void PluginInterface::OnShutdown(RakPeerInterface*)
{
}

void PluginInterface::OnCloseConnection(RakPeerInterface*, SystemAddress)
{
}

void PluginInterface::OnDirectSocketSend(const char*, const unsigned, SystemAddress)
{
}

void PluginInterface::OnDirectSocketReceive(const char*, const unsigned, SystemAddress)
{
}

void PluginInterface::OnInternalPacket(InternalPacket*, unsigned, SystemAddress, RakNetTime, bool)
{
}
