// from server: 100% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
namespace G3D { class CoordinateFrame; }
namespace RBX {
class Region;
class Extents { public: float v[6]; Extents(); bool containedByFrame(const Region& r, const G3D::CoordinateFrame& cf) const; };
class Primitive { public: Extents getExtentsLocal() const; };
class Instance { public: virtual ~Instance(); };
class PartInstance : public Instance { public: char pad[0x114]; Primitive* primitive; const G3D::CoordinateFrame& getCoordinateFrame() const; };
static void testContained(boost::shared_ptr<Instance> instance, const Region& region, bool* result)
{
    if (*result) {
        if (PartInstance* part = dynamic_cast<PartInstance*>(instance.get())) {
            Primitive* prim = part->primitive;
            *result = prim->getExtentsLocal().containedByFrame(region, part->getCoordinateFrame());
        }
    }
}
void (*keep)(boost::shared_ptr<Instance>, const Region&, bool*) = &testContained;
}
