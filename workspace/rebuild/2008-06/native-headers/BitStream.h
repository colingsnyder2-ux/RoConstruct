#pragma once
// The vendor RakNet BitStream.h exists (tools/rbxgs/Client/Network/raknet30/Source). RakPeer.h and ReliabilityLayer.h
// include "BitStream.h" from this directory first, so forward to the real header: a separate by-value-only class
// definition here redefines RakNet::BitStream in every unit that also sees the vendor header.
#include "../../../tools/rbxgs/Client/Network/raknet30/Source/BitStream.h"
