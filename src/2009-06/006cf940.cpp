// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B1_006cf940 { virtual void a1(); };
struct B2_006cf940 { virtual void a2(); };
struct Base_006cf940 : B1_006cf940, B2_006cf940 { Base_006cf940(int a, int b); };
struct D_006cf940 : Base_006cf940 {
    D_006cf940(int a, int b);
    virtual void a1();
    virtual void a2();
};
D_006cf940::D_006cf940(int a, int b) : Base_006cf940(a, b) {}
