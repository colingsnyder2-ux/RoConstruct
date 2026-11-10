#include "../../../tools/rbxgs/Client/Network/raknet30/Source/PluginInterface.h"

PluginReceiveResult PluginInterface::OnReceive(RakPeerInterface*, Packet*)
{
    return RR_CONTINUE_PROCESSING;
}

void PluginInterface::OnInternalPacket(InternalPacket*, unsigned, SystemAddress, RakNetTime, bool)
{
}
