// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
inline void* operator new(unsigned int, void* p) { return p; }
struct counted { void* vt; long use; void add_ref_copy() { _InterlockedIncrement(&use); } };
struct sp {
    void* px; counted* pn;
    sp(const sp& o) : px(o.px), pn(o.pn) { if (pn != 0) pn->add_ref_copy(); }
};
struct Base { Base(const Base&); virtual void v(); char pad[0x48]; };
struct Derived : Base {
    sp m;
    virtual void v();
};
Derived* make(void* p, const Derived& o) { return new (p) Derived(o); }
