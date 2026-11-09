// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-net-dll roc_unit_8d3c72e65ee3d2c3.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include <BitStream.h>
#include "Streaming.h"
#include <stdexcept>
namespace RBX { namespace Network {
void readBrickVector(RakNet::BitStream& stream, G3D::Vector3& value) {
    bool compressed;
    stream >> compressed;
    if (compressed) {
        unsigned int x = 0, y = 0, z = 0;
        if (!stream.ReadBits((unsigned char*)&x,11)) throw std::runtime_error("readBrickVector x failed");
        if (!stream.ReadBits((unsigned char*)&y,11)) throw std::runtime_error("readBrickVector y failed");
        if (!stream.ReadBits((unsigned char*)&z,11)) throw std::runtime_error("readBrickVector z failed");
        if (x & 0x400) x |= 0xfffffc00;
        if (z & 0x400) z |= 0xfffffc00;
        value.x = (short)x * 0.5f;
        value.y = (unsigned short)y * 0.1f;
        value.z = (short)z * 0.5f;
    } else {
        stream >> value.x;
        stream >> value.y;
        stream >> value.z;
    }
}
}}
