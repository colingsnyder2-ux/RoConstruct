// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct C { char pad[0xa8]; double a; double b; double c; double d; void f(float x, float y); };
__declspec(noinline) static double __stdcall h(double x) { return (x * 3.0 + 1.0) / (x - 1.0); }
void C::f(float x, float y) { a = x; b = h(x); c = x + y; d = 0.0; }
