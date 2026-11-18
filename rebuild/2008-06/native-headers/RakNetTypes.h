#pragma once
// INFERRED: stub for missing RakNet RakNetTypes.h; defines SystemAddress and PacketPriority used by Replicator.h
#include <set>
// SystemAddress: RakNet network address, passed by value in PluginInterface callbacks
class SystemAddress {
public:
    SystemAddress();
    SystemAddress(const char*);
    bool operator==(const SystemAddress&) const;
    bool operator!=(const SystemAddress&) const;
protected:
    unsigned char data[16];
};

// PacketPriority: send priority levels for RakNet packets
enum PacketPriority
{
    HIGH_PRIORITY,
    MEDIUM_PRIORITY,
    LOW_PRIORITY,
    NUMBER_OF_PRIORITIES
};
