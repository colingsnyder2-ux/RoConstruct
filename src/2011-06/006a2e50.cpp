// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x4];float f2;float f1;float f0; double f();};
double S::f(){return f0*f1*f2;}
