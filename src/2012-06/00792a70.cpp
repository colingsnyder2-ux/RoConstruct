// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /arch:SSE /GS- /EHsc /MD
struct S{ int p; double d; int i; double f(); };
double S::f(){ if(d > 0.0) return i / d; return 0.0; }
