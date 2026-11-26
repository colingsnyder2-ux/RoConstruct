// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern float K; struct S{ char p[0x10]; float v; double f(); }; double S::f(){ double t=v; return t*t*t*K; }