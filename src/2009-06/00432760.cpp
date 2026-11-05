// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <utility>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    void swap(shared_count& r) { sp_counted_base* tmp = r.pi_; r.pi_ = pi_; pi_ = tmp; }
};
}
template<class T> class shared_ptr {
public:
    typedef shared_ptr<T> this_type;
    T* px;
    detail::shared_count pn;
    template<class Y> explicit shared_ptr(Y* p);
    template<class Y> void reset(Y* p) { this_type(p).swap(*this); }
    void swap(shared_ptr<T>& other) { std::swap(px, other.px); pn.swap(other.pn); }
};
}
namespace RBX { struct Thing; }
template void boost::shared_ptr<RBX::Thing>::reset<RBX::Thing>(RBX::Thing*);
