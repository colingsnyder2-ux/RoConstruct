// from server: 100% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <intrin.h>
namespace boost { namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_; long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::sp_counted_base* pi_;
    ~shared_ptr() { if (pi_) pi_->release(); }
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace G3D { class Vector3 { public: float x, y, z; Vector3() {} Vector3(float a,float b,float c):x(a),y(b),z(c){} Vector3 operator-(const Vector3& o) const { return Vector3(x-o.x,y-o.y,z-o.z); } }; }
namespace RBX {
class Extents { public: G3D::Vector3 low, high; Extents(); G3D::Vector3 size() const { return high - low; } };
class Primitive { public: Extents getExtentsWorld() const; };
class Instance { public: virtual ~Instance(); };
class PartInstance : public Instance { public: char pad[0x114]; Primitive* primitive; };
static void findLargest(boost::shared_ptr<Instance> instance, PartInstance** best, float* bestArea)
{
    if (PartInstance* part = dynamic_cast<PartInstance*>(instance.get())) {
        Primitive* prim = part->primitive;
        G3D::Vector3 size = prim->getExtentsWorld().size();
        float area = size.x * size.z;
        if (area > *bestArea) {
            *bestArea = area;
            *best = part;
        }
    }
}
void (*keep)(boost::shared_ptr<Instance>, PartInstance**, float*) = &findLargest;
}
