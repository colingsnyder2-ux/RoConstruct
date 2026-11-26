// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S; struct Q{void g(S*);}; struct S{char pad[8]; Q* q; void f();}; void S::f(){ if(q) q->g(this); }
