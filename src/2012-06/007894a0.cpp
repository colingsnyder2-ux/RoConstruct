// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct R{double v; bool b;}; struct V{double v;}; struct A{char p[0x218]; double m; R f(const V& x){ R r; r.b=false; r.v=m*x.v; return r;} }; R g(A*a,const V&x){return a->f(x);}
