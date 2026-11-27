// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct IX { virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0; virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0; virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0; virtual void v15() = 0; virtual void v16() = 0; virtual void v17() = 0; virtual long __stdcall m(int a, int b, int c, int d2, double e) = 0; };
struct S {
    char pad[0x18];
    IX* p;
    long f(int a, int b, int c, int d, double e);
};
long S::f(int a, int b, int c, int d, double e) {
    if (!p) return 0x80040209;
    return p->m(a, b, c, d, e);
}
