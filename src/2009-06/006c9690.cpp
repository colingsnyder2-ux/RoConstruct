// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    const float& operator[](int i) const { return ((float*)this)[i]; }
    float& operator[](int i) { return ((float*)this)[i]; }
    static const Vector3& zero() { static Vector3 v(0, 0, 0); return v; }
};
class Matrix3 {
public:
    float elt[3][3];
    Matrix3(const Matrix3& m);
};
inline Vector3 operator*(const Vector3& rkPoint, const Matrix3& rkMatrix) {
    Vector3 kProd;
    for (int r = 0; r < 3; ++r) {
        kProd[r] =
            rkPoint[0] * rkMatrix.elt[0][r] +
            rkPoint[1] * rkMatrix.elt[1][r] +
            rkPoint[2] * rkMatrix.elt[2][r];
    }
    return kProd;
}
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
};
}
namespace RBX {
class Velocity { public: G3D::Vector3 linear; G3D::Vector3 rotational; };
class PV {
public:
    G3D::CoordinateFrame position;
    Velocity velocity;
    PV pvAtLocalOffset(const G3D::Vector3& localCoord) const;
};
class Quaternion {
public:
    float x, y, z, w;
    Quaternion(const G3D::Matrix3& rot);
    Quaternion& operator=(const Quaternion& other);
    float magnitude() const { return sqrtf(x * x + y * y + z * z + w * w); }
    Quaternion& operator*=(float fNum) { x = fNum * x; y = fNum * y; z = fNum * z; w = fNum * w; return *this; }
    void normalize();
};
inline void Quaternion::normalize() { *this *= 1.0f / magnitude(); }
class Math {
public:
    static G3D::Vector3 toDiagonal(const G3D::Matrix3& m);
    static G3D::Matrix3 momentToWorldSpace(const G3D::Matrix3& iBody, const G3D::Matrix3& bodyRotation);
};
class Units { public: static G3D::Vector3 kmsAccelerationToRbx(const G3D::Vector3& v); };
class Constants { public: static const G3D::Vector3& getKmsGravity() { static G3D::Vector3 g(0.0f, -9.81f, 0.0f); return g; } };
class Body;
class Cofm {
    Body* body;
    mutable bool dirty;
    mutable G3D::Vector3 cofmInBody;
    mutable float mass;
    mutable G3D::Matrix3 moment;
    void updateIfDirty() const;
public:
    const G3D::Vector3& getCofmInBody() const { updateIfDirty(); return cofmInBody; }
    const float getMass() const { updateIfDirty(); return mass; }
    const G3D::Matrix3& getMoment() const { updateIfDirty(); return moment; }
};
class Body {
public:
    char pad0[0x30];
    Cofm* cofm;
    char pad1[0x70 - 0x34];
    G3D::Matrix3 moment;
    float mass;
    char pad2[0x9c - 0x98];
    mutable PV pv;
    void updatePV() const;
    const G3D::Vector3& getCofmOffset() const { if (cofm) return cofm->getCofmInBody(); else return G3D::Vector3::zero(); }
    const PV& getPV() const { updatePV(); return pv; }
    float getBranchMass() const { return (cofm ? cofm->getMass() : mass); }
    G3D::Matrix3 getBranchIBody() const { return cofm ? cofm->getMoment() : moment; }
    G3D::Matrix3 getBranchIWorld() const { updatePV(); return Math::momentToWorldSpace(getBranchIBody(), pv.position.rotation); }
};
inline G3D::Vector3 vecUnkPercent(G3D::Vector3& input)
{
    return G3D::Vector3(1.0f / input.x, 1.0f / input.y, 1.0f / input.z);
}
class SimBody {
public:
    Body* body;
    float scalarAt4;
    bool dirty;
    PV pv;
    Quaternion qOrientation;
    G3D::Vector3 angMomentum;
    G3D::Vector3 momentRecip;
    float massRecip;
    float constantForceY;
    void unkSimInline(float fNum);
    void update();
};
__forceinline void SimBody::unkSimInline(float fNum)
{
    massRecip = 1.0f / fNum;
    momentRecip = vecUnkPercent(Math::toDiagonal(body->getBranchIBody()));
}
void SimBody::update()
{ float roc_dd0 = 0; float roc_dd1 = 0; float roc_dd2 = 0;
    {
        const G3D::Vector3 cofmOffset = body->getCofmOffset();
        pv = body->getPV().pvAtLocalOffset(cofmOffset);
    }
    qOrientation = Quaternion(pv.position.rotation);
    qOrientation.normalize();
    angMomentum = pv.velocity.rotational * body->getBranchIWorld();
    float _mass = body->getBranchMass();
    unkSimInline(_mass);
    constantForceY = body->getBranchMass() * Units::kmsAccelerationToRbx(Constants::getKmsGravity()).y;
    dirty = false;
}
}
