// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct A{char p[0x158]; float m; float f(){ return m*57.29578f; } }; float g(A*a){return a->f();}
