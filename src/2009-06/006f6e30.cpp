// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Primitive;
struct Stage {
    void g(Primitive* a1);
    void h(Primitive* a1);
};
typedef void (Stage::*StageFn)(Primitive*);

struct Functor { StageFn fn; Stage* s; Functor(StageFn f, Stage* p) { s = p; fn = f; } };
struct Prims {
    void visit(Functor fn);
};

struct Primitive {
    char pad0[8];
    Prims prims;
    void detach(void* a1);
};

struct S {
    char pad0[8];
    Stage* m_p;
    void f(Primitive* a1);
};

void S::f(Primitive* a1)
{
    a1->prims.visit(Functor(&Stage::g, m_p));
    m_p->h(a1);
    a1->detach(this);
}
