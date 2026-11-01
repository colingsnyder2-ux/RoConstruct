// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <algorithm>
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose();
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
template<class T> struct weak_ptr;
template<class T> struct shared_ptr {
    T* px;
    sp_counted_base* pn;
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn != 0) pn->add_ref_copy(); }
    ~shared_ptr() { if (pn != 0) pn->release(); }
};
template<class T> struct weak_ptr {
    T* px;
    sp_counted_base* pn;
    weak_ptr(const shared_ptr<T>& r) : px(r.px), pn(r.pn) { if (pn != 0) pn->weak_add_ref(); }
    ~weak_ptr() { if (pn != 0) pn->weak_release(); }
};
namespace RBX { class Instance; class Other; }
using RBX::Instance;
using RBX::Other;
struct Binder {
    void (*f)(weak_ptr<Other>, weak_ptr<Instance>, bool);
    shared_ptr<Other> a1;
    bool a3;
    void operator()(const shared_ptr<Instance>& p) { f(a1, p, a3); }
};
template Binder std::for_each(std::vector<shared_ptr<Instance> >::const_iterator, std::vector<shared_ptr<Instance> >::const_iterator, Binder);
