// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct A { virtual void a(); int a1; };
struct S { int v[6]; };struct P { void* x; P() : x(0) {} }; struct B { virtual void bf(); P p; int q; int r; B(int q_) : q(q_) {} };
struct Mid : A, B { virtual void m(); Mid(int q) : B(q) {} };
struct Mid2 : Mid { S s; virtual void m(); Mid2(const S& s_, int q) : Mid(q), s(s_) {} };
struct Hat : Mid2 { virtual void m(); Hat(const S& s_, int q); };
Hat::Hat(const S& s_, int q) : Mid2(s_, q) {}
