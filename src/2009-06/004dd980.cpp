// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RakNet { class BitStream { int bits; }; }
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX { namespace Network {
RakNet::BitStream& operator<<(RakNet::BitStream& stream, float value);
RakNet::BitStream& operator<<(RakNet::BitStream& stream, const G3D::Vector3& value)
{
    stream << value.x;
    stream << value.y;
    stream << value.z;
    return stream;
}
} }
