// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct X { void update(); };
struct A {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void refresh();
    char padA[0x1c];
    X* x;
    char padB[0x20];
};
struct B { virtual int onEvent(); };
struct D : A, B { virtual int onEvent(); };
int D::onEvent() { x->update(); refresh(); return 0; }
