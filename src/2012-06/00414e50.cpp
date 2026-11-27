// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct L { void add(int k, void* p); };
struct S { char pad[0x48]; L l; void f(int a, int b); };
struct Obj { virtual void v(); int a, b; Obj(int a_, int b_) : a(a_), b(b_) {} ~Obj() {} };
void S::f(int a, int b) { Obj o(a, b); l.add(3, &o); }
