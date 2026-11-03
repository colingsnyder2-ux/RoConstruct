// from server: 100% by EspClaude
// roc 2007-08 004a8d30  read a Vector3 property value from a RakNet::BitStream (Streaming.cpp shape)
// roc-flags: /O2 /GS /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; Vector3() : x(0), y(0), z(0) {} };
class Color3 { public: float r, g, b; Color3() {} };
}
namespace RakNet { class BitStream { int pad; }; }
namespace RBX {
namespace Network {
RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::Vector3& value);
RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::Color3& value);
}
namespace Reflection {
class PropertyDescriptor;
class DescribedBase;
class Property {
    const PropertyDescriptor* descriptor;
    const DescribedBase* instance;
public:
    template<typename T> void setValue(const T& value);
};
}
namespace Network {
void readValueVector3(Reflection::Property& prop, RakNet::BitStream& stream)
{
    G3D::Vector3 value;
    stream >> value;
    prop.setValue(value);
}
}
}
