// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
struct counted_base {
    virtual ~counted_base();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
    void add_ref() { _InterlockedIncrement(&use_count_); }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
};
struct shared_ptr_t {
    void* px;
    counted_base* pn;
    shared_ptr_t(const shared_ptr_t& r) : px(r.px), pn(r.pn) {
        if (pn) pn->add_ref();
    }
    ~shared_ptr_t() {
        if (pn) pn->release();
    }
};
struct Arg {
    int a;
    shared_ptr_t sp;
    Arg(const Arg& o) : a(o.a), sp(o.sp) {}
};
struct Storage {
    Storage(Arg a, int z);
    int pad;
};
struct List1 : Storage {
    List1(Arg a, int e);
};
List1::List1(Arg a, int e) : Storage(a, 0) {}
