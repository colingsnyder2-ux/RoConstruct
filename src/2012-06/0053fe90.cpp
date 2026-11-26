// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A{char p[0x1bc]; int v; bool f(){ return v==0||v==2; }}; bool g(A*a){return a->f();}
