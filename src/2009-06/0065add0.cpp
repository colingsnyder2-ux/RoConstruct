// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_increment(long* pw) { return _InterlockedIncrement(pw); }
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_add_ref() { atomic_increment(&weak_count_); }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count& operator=(shared_count const& r);
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
    template<class Y> weak_ptr& operator=(shared_ptr<Y> const& r) { px = r.px; pn = r.pn; return *this; }
};
}
namespace RBX {
class Instance { public: virtual ~Instance(); };
class CameraSubject { public: virtual ~CameraSubject(); };
class PropertyDescriptor;
extern PropertyDescriptor prop_CameraSubject;
template<class T> boost::shared_ptr<T> shared_from(T* p);
class Camera {
public:
    char pad[0x140];
    boost::weak_ptr<Instance> cameraSubject;
    void raisePropertyChanged(const PropertyDescriptor& d);
    void setCameraSubject(Instance* value);
};
void Camera::setCameraSubject(Instance* value)
{
    Instance* cur = cameraSubject.px;
    if (value != cur) {
        if (dynamic_cast<CameraSubject*>(value)) {
            cameraSubject = shared_from(value);
            raisePropertyChanged(prop_CameraSubject);
        }
    }
}
}
