// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
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
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn) pn->add_ref_copy(); }
    ~shared_ptr() { if (pn) pn->release(); }
};
}
namespace RBX {
struct Str { std::string s; };
class Base {
public:
    Str name;
    Base(int a, Str s);
};
class Target;
class Derived : public Base {
public:
    boost::shared_ptr<Target> target;
    Derived(int a, Str s, boost::shared_ptr<Target> t);
};
Derived::Derived(int a, Str s, boost::shared_ptr<Target> t) : Base(a, s), target(t) {}
}
