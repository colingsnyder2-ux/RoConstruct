// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
struct S{float f1(); float f2(); double f();}; double S::f(){float a=f1(); return a+f2();}
