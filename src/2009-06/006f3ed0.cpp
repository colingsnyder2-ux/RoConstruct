// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B1_006f3ed0 { virtual void a1(); };
struct B2_006f3ed0 { virtual void a2(); };
struct Base_006f3ed0 : B1_006f3ed0, B2_006f3ed0 { Base_006f3ed0(int a, int b); };
struct D_006f3ed0 : Base_006f3ed0 {
    D_006f3ed0(int a, int b);
    virtual void a1();
    virtual void a2();
};
D_006f3ed0::D_006f3ed0(int a, int b) : Base_006f3ed0(a, b) {}
