// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Q{char p[0x116]; bool b;}; struct A{ char p[0x198]; Q* q; bool f(){ return !q->b; } }; bool k(A*x){return x->f();}
