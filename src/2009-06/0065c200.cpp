// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    ~shared_ptr() { if (pn) pn->release(); }
    T* operator->() const { return px; }
    T* get() const { return px; }
    typedef T* (shared_ptr::*unspecified_bool_type)() const;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::get; }
};
}
namespace RBX {
class World;
class PartInstance {
public:
    char pad[0x168];
    World* world;
    World* getWorld() const { return world; }
    static bool nonNullInWorkspace(boost::shared_ptr<PartInstance> part);
};
bool PartInstance::nonNullInWorkspace(boost::shared_ptr<PartInstance> part)
{
    return part.get() && part->getWorld();
}
}
