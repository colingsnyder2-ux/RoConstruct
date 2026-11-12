// from server: 68% by EspClaude
// from server: 57% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_9b011c6c49b700fe.cpp

// Candidate translation unit (score above; library headers required).
// stl: list<E>::_Buynode, VS2005 <list>.  E's layout is read from the out-of-line
// _Construct<E> at 00413e30: words +0,+4,+8 copied, +0xc cloned through vtable slot +8 (or null).
#include <list>
struct Clonable {
    virtual ~Clonable();
    virtual void unused();
    virtual Clonable* clone() const;
};
struct E {
    int a;
    int b;
    int c;
    Clonable* p;
    E();
    E(const E& o) : a(o.a), b(o.b), c(o.c), p(o.p ? o.p->clone() : 0) {}
    bool operator==(const E&) const;
    bool operator<(const E&) const;
};
template class std::list<E>;
