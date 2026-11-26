// from server: 100% by Xemicl
// copied from an identical function in another client (function ?f@S@ns_ROCX00000b@@QAEXPAUPrimitive@2@@Z)

namespace ns_ROCX00000b {
// from server: 100% by EspClaude
struct Primitive;
struct Stage {
    void f(Primitive* a1);
};
typedef void (Stage::*StageFn)(Primitive*);

struct Functor { StageFn fn; Stage* s; Functor(StageFn f, Stage* p) : fn(f), s(p) {} };
struct Prims {
    void visit(Functor fn);
};

struct Primitive {
    char pad0[8];
    Prims prims;
    void attach(void* a1);
};

struct S {
    char pad0[8];
    Stage* m_p;
    void f(Primitive* a1);
};

void S::f(Primitive* a1)
{
    a1->attach(this);
    m_p->f(a1);
    a1->prims.visit(Functor(&Stage::f, m_p));
}
}
