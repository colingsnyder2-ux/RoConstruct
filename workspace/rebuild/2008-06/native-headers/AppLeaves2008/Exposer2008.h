#pragma once
// >>> native-status (generated) -- do not edit >>>
// Exposer2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 8dacdf96 | roc native-status --write
// Inactive native 2008-06 recovery: Exposer (Network/Client.cpp's translation unit), which exposes the protected
// PacketLogger::IDTOString to the client's connection-failure message.
#include <PacketLogger.h>

// RTTI of vtable 00822d3c: Exposer : PacketLogger : PluginInterface (no other bases, no members). The only object
// is the stack Exposer of IDTOString 0049f180: PacketLogger::PacketLogger 004baa10 into a 0x20c-byte frame, then
// the vptr store 00822d3c (inline constructor), then ~PacketLogger 004baa40 (inline destructor). Slot 0 is ??_G
// 0049ed90 (~PacketLogger, then operator delete); slots 1..18 are inherited PacketLogger / PluginInterface entries.
class Exposer : protected PacketLogger
{
public:
    static const char* IDTOString(int id);   // 0049f180
};
