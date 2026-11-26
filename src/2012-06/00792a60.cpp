// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /arch:SSE /GS- /EHsc /MD
struct S{ double d; char p[8]; int i; double f(); }; double S::f(){ if(d>0) return i/d; return 0; }
