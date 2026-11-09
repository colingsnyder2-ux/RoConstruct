// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B1_006f4100 { virtual void a1(); };
struct B2_006f4100 { virtual void a2(); };
struct Base_006f4100 : B1_006f4100, B2_006f4100 { Base_006f4100(int a, int b); };
struct D_006f4100 : Base_006f4100 {
    D_006f4100(int a, int b);
    virtual void a1();
    virtual void a2();
};
D_006f4100::D_006f4100(int a, int b) : Base_006f4100(a, b) {}
