// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B { int a[6]; void init(); };
struct S { int m0; int p; B b; int m20; S* f(); };
S* S::f() { b.init(); m0 = -1; m20 = -1; return this; }