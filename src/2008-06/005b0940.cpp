// from server: 100% by tester
namespace G3D {
class Vector3
{
public:
    float x, y, z;

    Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {}
};

class Matrix3
{
    float elt[3][3];
};

class CoordinateFrame
{
public:
    Matrix3 rotation;
    Vector3 translation;
};
}

namespace RBX {
class Accoutrement
{
    char gap0[0x158];
    G3D::CoordinateFrame attachmentPoint;
public:
    const G3D::Vector3 getAttachmentPos() const;
};

const G3D::Vector3 Accoutrement::getAttachmentPos() const
{
    return attachmentPoint.translation;
}
}
