// from server: 71% by EspClaude
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
// roc 2007-08 00582200  unit: RBX::VHat::?$FactoryProduct  size: 392 bytes
// Evidence (target bytes): shared_ptr at this+0x130/0x134 reset (lock xadd, sp_counted_base slots +4/+8);
// 0x6ffa50 thiscall getter; dynamic_cast<RBX::ModelInstance*>(Instance* at +0xbc) via __RTDynamicCast;
// 0x5a56b0 cdecl predicate; ModelInstance vbptr at +0xec, 2nd virtual base slot 0 returns CoordinateFrame
// (translation at +0x24); Matrix3::getColumn 0x509640 (ret 8); constants 4.0 (0x79f2fc), -1.0 (0x7a32e8),
// 8.0 (0x7a34b8); this->0x5d1ae0, obj->0x5bae60(Vector3 by value), obj->0x578000(const Vector3&),
// tail call this->0x581fd0.
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)

class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3 operator+(const Vector3& o) const { return Vector3(x + o.x, y + o.y, z + o.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3& operator+=(const Vector3& o) { x += o.x; y += o.y; z += o.z; return *this; }
};

class Matrix3 {
public:
    float elt[3][3];
    Vector3 getColumn(int i) const;
};

class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
};

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    void swap(shared_count& r) { sp_counted_base* tmp = r.pi_; r.pi_ = pi_; pi_ = tmp; }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    void swap(shared_ptr& other) { T* tmp = px; px = other.px; other.px = tmp; pn.swap(other.pn); }
    void reset() { shared_ptr().swap(*this); }
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}

namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0xe8];
};
class IHasLocation {
public:
    virtual void v0();
};
class ILocation {
public:
    virtual CoordinateFrame getLocation() = 0;
};
class ModelInstance : public Instance, public virtual IHasLocation, public virtual ILocation {
public:
    static void* findPrimaryPart(ModelInstance* model);
};

class Container {
public:
    char pad[0xbc];
    Instance* parent;
};

class Attachment {
public:
    Container* getContainer();
    void setActive(int);
};

class Target {
public:
    void setPosition(Vector3 pos);
    void setSize(const Vector3& size);
};

class Hat {
public:
    char pad[0x130];
    boost::shared_ptr<Attachment> attachment;

    Target* getTarget();
    void update();
    void dropped();
};

void Hat::dropped()
{
    ModelInstance* model = 0;
    if (attachment.get()) {
        if (Container* c = attachment->getContainer())
            model = dynamic_cast<ModelInstance*>(c->parent);
        attachment->setActive(0);
        attachment.reset();
    }
    if (ModelInstance::findPrimaryPart(model)) {
        CoordinateFrame cf = model->getLocation();
        Vector3 pos(cf.translation.x, cf.translation.y + 4.0f, cf.translation.z);
        float s = -1.0f;
        Vector3 look = cf.rotation.getColumn(2);
        pos += look * s * 8.0f;
        if (Target* t = getTarget()) {
            t->setPosition(Vector3(pos.x, pos.y, pos.z));
            t->setSize(Vector3(1.0f, 1.0f, 1.0f));
        }
    }
    update();
}
}
