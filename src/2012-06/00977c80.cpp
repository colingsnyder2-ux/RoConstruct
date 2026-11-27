// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE
struct S { double* g(double*); };
struct C { char pad[0x120]; S s; double f(); };
double C::f() { double t; double v = *s.g(&t); return v > 0.0 ? 1.0 / v : 0.0; }
