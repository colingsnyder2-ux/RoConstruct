// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};
class Matrix3 {
public:
    Matrix3(const Matrix3& m);
    float elt[3][3];
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const CoordinateFrame& o) : rotation(o.rotation), translation(o.translation) {}
    CoordinateFrame lerp(const CoordinateFrame& other, float alpha) const;
};
}
namespace RBX {
class Velocity {
public:
    G3D::Vector3 linear;
    G3D::Vector3 rotational;
    Velocity(const Velocity& v) : linear(v.linear), rotational(v.rotational) {}
    Velocity lerp(const Velocity& other, float alpha) const;
};
class PV {
public:
    G3D::CoordinateFrame position;
    Velocity velocity;
    PV(const G3D::CoordinateFrame& p, const Velocity& v) : position(p), velocity(v) {}
    PV lerp(const PV& other, float alpha) const;
};
PV PV::lerp(const PV& other, float alpha) const
{
    return PV(position.lerp(other.position, alpha), velocity.lerp(other.velocity, alpha));
}
}
