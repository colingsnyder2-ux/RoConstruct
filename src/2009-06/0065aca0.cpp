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
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}
struct T;
struct B0 { virtual void a(); int x[4]; };
struct B1 { virtual void b(); };
struct B2 { virtual void c(); int d; };
struct B3 { virtual void e(); char pad[0x68]; };
struct Base : B0, B1, B2, B3 { ~Base(); };
struct Mid : Base { virtual void m(); ~Mid() {} };
struct Second { virtual void s(); int a, b; ~Second(); };
struct M98 { char pad[0xa8]; ~M98(); };
struct T;
struct D : Mid, Second {
    M98 m;
    boost::shared_ptr<T> p;
    ~D();
};
D::~D() {}
