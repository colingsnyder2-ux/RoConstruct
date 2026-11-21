// from server: 100% by Intel_Inside
// roc-flags: /O2 /GS- /EHsc /MD

#include <vector>
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;   // vtable +4
    virtual void destroy();       // vtable +8
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

template<class T> struct shared_ptr {
    T* px;
    sp_counted_base* pn;
    ~shared_ptr() { if (pn) pn->release(); }
    operator bool() const { return px != 0; }
    T* operator->() const { return px; }
};

struct Listener {           // subobject at +0xe8 (vptr only)
    virtual void onEvent();
};

struct Owner {
    void removeListener(Listener* l);   // 0x532550, thiscall
};

struct B0 { virtual ~B0(); };
struct B1 { virtual ~B1(); int pad[2]; };
struct B2 { virtual ~B2(); };
struct B3 { virtual ~B3(); int pad[5]; };
struct B4 { virtual ~B4(); int pad[5]; };
struct B5 { virtual ~B5(); int pad[5]; };
struct B6 { virtual ~B6(); int pad[5]; };
struct B7 { virtual ~B7(); int pad[5]; };
struct B8 { virtual ~B8(); int pad[0x16]; };

struct Base : B0, B1, B2, B3, B4, B5, B6, B7, B8 {
    ~Base();   // 0x5402b0
};

struct FilteredSelection : Base, Listener {
    shared_ptr<Owner> owner;   // +0xec
    std::vector<int> items;    // +0xf4
    ~FilteredSelection();
};

FilteredSelection::~FilteredSelection()
{
    if (owner)
        owner->removeListener(this);
}
