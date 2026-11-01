// from server: 97% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3 clamp(const Vector3& low, const Vector3& high) const;
    static const Vector3& zero() { static Vector3 v(0, 0, 0); return v; }
};
class Matrix3 {
public:
    float elt[3][3];
    Matrix3(const Matrix3&);
};
}
namespace RBX {
using G3D::Vector3; using G3D::Matrix3;
class Velocity {
public:
    Vector3 linear;
    Vector3 rotational;
    Velocity() : linear(Vector3::zero()), rotational(Vector3::zero()) {}
    static const Velocity& zero() { static Velocity v; return v; }
};
namespace Math { Vector3 toDiagonal(const Matrix3&); }
struct Cofm {
    char prefix[0x14]; float mass; Matrix3 moment;
    void updateIfDirty();
    const Matrix3& getMoment() { updateIfDirty(); return moment; }
    float getMass() { updateIfDirty(); return mass; }
};
struct SimBody { char prefix[0x3c]; Velocity velocity; char reserved[0x90 - 0x54]; Vector3 torque; };
struct Body {
    char prefix[0x2c]; Body* root; Cofm* cofm; SimBody* simBody; char reserved38[0x70 - 0x38];
    Matrix3 moment; float mass; char reserved98[0xcc - 0x98]; Velocity velocity;
    Matrix3 getBranchIBody() const { return cofm ? cofm->getMoment() : moment; }
    float getBranchMass() const { return cofm ? cofm->getMass() : mass; }
    void updatePV() const;
    const Velocity& getVelocity() const { updatePV(); return velocity; }
    const Velocity& getBranchVelocity() const { return root->simBody ? root->simBody->velocity : Velocity::zero(); }
    const Vector3& getBranchTorque() const { return root->simBody ? root->simBody->torque : Vector3::zero(); }
    void accumulateTorque(const Vector3&);
    void accumulateForceAtBranchCofm(const Vector3&);
};
struct Humanoid { Body* getTorsoBody() const; };
Vector3 __cdecl lowerAcceleration(); Vector3 __cdecl upperAcceleration();
extern float maxYawTorque;
inline float clampValue(float v, float lo, float hi) { return v <= lo ? lo : (v >= hi ? hi : v); }
struct Freefall {
    char prefix[0x4c]; float desiredYaw; char reserved[8]; Vector3 desiredVelocity;
    void baseComputeForce(); Humanoid* getHumanoid() const; void onComputeForce();
};
__forceinline Vector3 clampAcceleration(const Vector3& low, const Vector3& high, const Vector3& value) { return value.clamp(low, high); }
void Freefall::onComputeForce() {
    baseComputeForce();
    Body* body = getHumanoid()->getTorsoBody();
    if (body) {
        float requested; { Vector3 inertia = Math::toDiagonal(body->getBranchIBody());
        requested = (desiredYaw - body->getVelocity().rotational.y) * inertia.y * 7500.0f; }
        float torque = requested - body->getBranchTorque().y;
        float limit; { Vector3 limitInertia = Math::toDiagonal(body->getBranchIBody());
        limit = limitInertia.y * maxYawTorque; }
        torque = clampValue(torque, -limit, limit);
        body->accumulateTorque(Vector3(0, torque, 0));
        Vector3 accel = (desiredVelocity - body->getBranchVelocity().linear) * 1250.0f;
        Vector3 bounded = clampAcceleration(lowerAcceleration(), upperAcceleration(), accel);
        { Vector3 force = bounded * body->getBranchMass();
        force.y = 0;
        body->accumulateForceAtBranchCofm(force); }
    }
}
}
