// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-net-dll roc_espeon_readpositionexternalbias4519eb6d5746f7f9.cpp

// Candidate translation unit (score above; library headers required).
extern const float horizontalPositionBias;
extern const float verticalPositionBias;
#include <BitStream.h>
#include <stdexcept>
#include <G3D/Vector3.h>

namespace RBX {
namespace Network {

RakNet::BitStream& operator>>(RakNet::BitStream& stream, bool& value);

class IPhysicsSender {
public:
    static void readPosition(RakNet::BitStream& bitStream, G3D::Vector3& position);
};

void IPhysicsSender::readPosition(RakNet::BitStream& bitStream, G3D::Vector3& position)
{
    bool compressed;
    bitStream >> compressed;
    if (compressed)
    {
        unsigned short x, y;
        unsigned int z = 0;
        if (!bitStream.ReadBits((unsigned char*)&x, 15))
            throw std::runtime_error("IPhysicsSender::readPosition failed reading x");
        if (!bitStream.ReadBits((unsigned char*)&y, 14))
            throw std::runtime_error("IPhysicsSender::readPosition failed reading y");
        if (!bitStream.ReadBits((unsigned char*)&z, 15))
            throw std::runtime_error("IPhysicsSender::readPosition failed reading z");
        position.x = x * 0.0625f - horizontalPositionBias;
        position.y = y * 0.0625f - verticalPositionBias;
        position.z = (unsigned short)z * 0.0625f - horizontalPositionBias;
    }
    else
    {
        if (!bitStream.ReadVector(position.x, position.y, position.z))
            throw std::runtime_error("IPhysicsSender::readPosition failed reading vector");
    }
}

}
}
