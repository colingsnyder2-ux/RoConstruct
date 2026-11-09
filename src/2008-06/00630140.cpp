// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* get() const { return px; }
    T* operator->() const { return px; }
    void reset();
    operator bool() const { return px != 0; }
};

class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator*(float s) const { return Vector3(s * x, s * y, s * z); }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3& operator+=(const Vector3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    Vector3 clamp(const Vector3& low, const Vector3& high) const;
};

namespace RBX {
struct CoordinateFrame { float rotation[9]; Vector3 translation; };
struct Velocity { Vector3 linear; Vector3 rotational; };
struct PV { CoordinateFrame position; Velocity velocity; };

class Cofm {
public:
    float getMass();
};

class Clump {
public:
    char pad[8];
    bool dirty;
    void update();
    char pad2[0x84 - 9];
    Vector3 force;
};

class Body;
class Assembly {
public:
    char pad[0x2c];
    Clump* clump;
};

class Body {
public:
    char pad[0x10];
    Body* root;
    char pad2[0x28 - 0x14];
    Cofm* cofm;
    char pad3[0x8c - 0x2c];
    float mass;
    char pad4[0x94 - 0x90];
    PV pv;
    void updatePV();
    const PV& getPV() { updatePV(); return pv; }
    Body* getRoot() { return root; }
    float getBranchMass() { return cofm ? cofm->getMass() : mass; }
    void accumulateForceAtBranchCofm(const Vector3& force)
    {
        Clump* c = ((Assembly*)root)->clump;
        if (c)
        {
            if (c->dirty)
                c->update();
            c->force.x = force.x + c->force.x; c->force.y = force.y + c->force.y; c->force.z = force.z + c->force.z;
        }
    }
};

class Primitive {
public:
    Body* getBody() { return (Body*)this; }
};

class PartInstance {
public:
    char pad[0x2c8];
    Primitive* primitive;
    Primitive* getPrimitive() { return primitive; }
};

template<class T> class weak_ptr {
public:
    T* px;
    shared_count pn;
    shared_ptr<T> lock() const;
};

class BodyPosition {
public:
    char pad[0x10];
    weak_ptr<PartInstance> part;
    float kP;
    float kD;
    Vector3 maxForce;
    Vector3 position;
    Vector3 lastForce;
    void computeForce(float dt, bool throttling);
};

void BodyPosition::computeForce(float dt, bool throttling)
{
    Body* body = part.lock()->getPrimitive()->getBody();

    Vector3 positionForce = (position - body->getPV().position.translation) * kP;

    Vector3 v = body->getPV().velocity.linear * -kD;
    Vector3 goalForce;
    goalForce.x = positionForce.x + v.x;
    float m;
    goalForce.y = positionForce.y + v.y;
    goalForce.z = positionForce.z + v.z;
    m = body->getRoot()->getBranchMass();
    lastForce = goalForce * m;

    lastForce = lastForce.clamp(-maxForce, maxForce);

    body->getRoot()->accumulateForceAtBranchCofm(lastForce);
}
}
