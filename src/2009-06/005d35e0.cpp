// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    long use_count_; long weak_count_;
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
};
}
namespace RBX {
class Instance;
struct Tag {};
struct Pair {
    boost::shared_ptr<Instance> a;
    boost::shared_ptr<Instance> b;
    ~Pair();
};
struct Inner { Pair p; Inner(Pair e) : p(e) {} };
struct Outer : Inner { Outer(Tag t, Pair e); };
Outer::Outer(Tag t, Pair e) : Inner(e) {}
}
