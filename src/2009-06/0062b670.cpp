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
namespace RBX {
class Instance { public: virtual ~Instance(); void setParent(Instance*); };
class Camera : public Instance { };
static void removeCamera(boost::shared_ptr<Instance> instance, Instance* current)
{
    if (dynamic_cast<Camera*>(instance.get()) && instance.get() != current)
        instance->setParent(0);
}
void (*keep)(boost::shared_ptr<Instance>, Instance*) = &removeCamera;
}
