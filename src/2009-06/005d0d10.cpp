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
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count();
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}
class A; class B;
struct Storage2 {
    boost::shared_ptr<A> a;
    boost::shared_ptr<B> b;
    ~Storage2();
};
struct Value {
    void (*f)(boost::shared_ptr<A>, boost::shared_ptr<B>);
    Storage2 l;
};
class Impl { public: void process(Value v); };
class Owner {
public:
    Impl* impl;
    void process(Value v);
};
void Owner::process(Value v)
{
    if (impl)
        impl->process(v);
}
