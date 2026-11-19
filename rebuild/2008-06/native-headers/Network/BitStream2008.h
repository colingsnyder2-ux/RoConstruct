#pragma once
// 2008-06 native RBX::Network BitStream helper recovered from 004c9c80.
// RakNet::BitStream is declared (complete) by the vendor RakNet BitStream.h
// (src/Client/Network/raknet30/Source/BitStream.h, on the native include path
// via native-headers/RakPeer.h etc.); WriteBits is
//   ?WriteBits@BitStream@RakNet@@QAEXPBEH_N@Z  void __thiscall RakNet::BitStream::WriteBits(unsigned char const*, int, bool)
#include "BitStream.h"

namespace RakNet
{
	// sub_004c9c80 (110 bytes): lossy quantised 16-bit write of a float in [-1, 1].
	void sub_004c9c80(float value);
}
