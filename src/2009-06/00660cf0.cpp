// from server: 100% by EspClaude
// roc 2009-06 00660cf0  unit: RBX::PartInstance::setCoordinateFrame  size: 204 bytes
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Matrix3 {
public:
    float elt[3][3];
    Matrix3(const Matrix3&);
    static const Matrix3& identity();
};
class Vector3 {
public:
    float x, y, z;
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const Matrix3& r, const Vector3& t) : rotation(r), translation(t) {}
    bool operator!=(const CoordinateFrame& o) const;
};
}
namespace RBX {
namespace Reflection { class PropertyDescriptor { int x; }; }
namespace Math {
    bool isNanInf(const G3D::CoordinateFrame& c);
    void orthonormalizeIfNecessary(G3D::Matrix3& m);
}
class Primitive {
public:
    const G3D::CoordinateFrame& getCoordinateFrame() const;
};
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
};
class PartInstance : public Instance {
public:
    char pad[0x118];
    Primitive* primitive;
    static const Reflection::PropertyDescriptor prop_CFrame;
    static const Reflection::PropertyDescriptor prop_PositionUi;
    void setPhysics(const G3D::CoordinateFrame& c);
    void safeMove();
    void setCoordinateFrame(const G3D::CoordinateFrame& value);
};
void PartInstance::setCoordinateFrame(const G3D::CoordinateFrame& value)
{
    if (value != primitive->getCoordinateFrame())
    {
        G3D::CoordinateFrame newValue = value;
        if (Math::isNanInf(newValue))
            newValue = G3D::CoordinateFrame(G3D::Matrix3::identity(), G3D::Vector3(0.0f, -1e15f, 0.0f));
        else
            Math::orthonormalizeIfNecessary(newValue.rotation);
        setPhysics(newValue);
        safeMove();
        raisePropertyChanged(prop_CFrame);
        raisePropertyChanged(prop_PositionUi);
    }
}
}
