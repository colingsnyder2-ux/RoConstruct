// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net-dll roc_unit_5ed0a23e3dfcf700.cpp

// Candidate translation unit (score above; library headers required).
#include <BitStream.h>
#include "Streaming.h"
#include <stdexcept>
namespace RBX {namespace Network {
RakNet::BitStream& operator>>(RakNet::BitStream& stream, bool& value) { if (!stream.Read(value)) throw std::runtime_error("BitStream >> bool failed"); return stream; }
RakNet::BitStream& operator>>(RakNet::BitStream& stream, long& value) { if (!stream.Read(value)) throw std::runtime_error("BitStream >> long failed"); return stream; }
RakNet::BitStream& operator>>(RakNet::BitStream& stream, int& value) { if (!stream.Read(value)) throw std::runtime_error("BitStream >> int failed"); return stream; }
RakNet::BitStream& operator>>(RakNet::BitStream& stream, unsigned int& value) { if (!stream.Read(value)) throw std::runtime_error("BitStream >> size_t failed"); return stream; }
RakNet::BitStream& operator>>(RakNet::BitStream& stream, unsigned char& value) { if (!stream.Read(value)) throw std::runtime_error("BitStream >> unsigned char failed"); return stream; }
RakNet::BitStream& operator>>(RakNet::BitStream& stream, float& value) { if (!stream.Read(value)) throw std::runtime_error("BitStream >> float failed"); return stream; }
}}
