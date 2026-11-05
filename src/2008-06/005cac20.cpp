// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
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
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    typedef T* shared_ptr::*unspecified_bool_type;
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
    T* get() const { return px; }
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

template<class T> class weak_ptr {
public:
    T* px;
    sp_counted_base* pn;
    shared_ptr<T> lock() const;
};

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
};
class Matrix3 { public: float elt[3][3]; };
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    Vector3 pointToObjectSpace(const Vector3& v) const;
};
}

namespace RBX {
class IFirst {
public:
    virtual void first();
};
class ICoordinateFrame {
public:
    virtual G3D::CoordinateFrame getCoordinateFrame() const = 0;
};
class InstanceBase {
public:
    virtual ~InstanceBase();
    char pad[0x130];
};
class PartInstance : public InstanceBase, public virtual IFirst, public virtual ICoordinateFrame {
};

class Joint {
public:
    char pad[0x18];
    weak_ptr<PartInstance> part0;
    char pad2[0x5c - 0x20];
    weak_ptr<PartInstance> part1;
    G3D::Vector3 getOffset() const;
};

G3D::Vector3 Joint::getOffset() const
{
    G3D::Vector3 result(0.0f, 0.0f, 0.0f);
    shared_ptr<PartInstance> p0 = part0.lock();
    shared_ptr<PartInstance> p1 = part1.lock();
    if (p0 && p1)
    {
        PartInstance* a = p0.get();
        PartInstance* b = p1.get();
        G3D::CoordinateFrame c0 = a->getCoordinateFrame();
        G3D::Vector3 pos = b->getCoordinateFrame().translation;
        result = c0.pointToObjectSpace(pos);
    }
    return result;
}
}
