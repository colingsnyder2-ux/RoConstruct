// from server: 92% by Intel_Inside
// stl: list<16-byte value with refcounted iface member copied via vtable slot 2>
// twin pattern from 0040b710 (list<string>) and 00492e00 (list<pair<const string,G>>)
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD

struct Iface {
    virtual void s0();
    virtual void s1();
    virtual Iface* copy();
};

struct Value16 {
    void* a;
    void* b;
    void* c;
    Iface* d;
    Value16() : a(0), b(0), c(0), d(0) {}
    Value16(const Value16& o) : a(o.a), b(o.b), c(o.c), d(o.d ? o.d->copy() : 0) {}
};

inline bool operator==(const Value16&, const Value16&) { return true; }
inline bool operator<(const Value16&, const Value16&) { return false; }

#include <list>
typedef Value16 E;
template class std::list<E>;
