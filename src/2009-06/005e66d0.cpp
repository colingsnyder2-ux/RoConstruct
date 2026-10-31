// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
inline void atomic_increment(long* pw) { _InterlockedIncrement(pw); }
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { atomic_increment(&use_count_); }
    void release();
};
template<class T> class shared_ptr {
public:
    T* px;
    sp_counted_base* pn;
    template<class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pn(r.pn) { if (pn != 0) pn->add_ref_copy(); }
    ~shared_ptr() { if (pn != 0) pn->release(); }
};
struct A { char pad[0x18]; };
struct Base { int b; };
struct Derived : A, Base { };
shared_ptr<Base> upcast(const shared_ptr<Derived>& d) { return d; }
