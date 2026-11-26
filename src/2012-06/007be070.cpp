// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
float __cdecl g1(double);
float __cdecl g2(float);
float f(float x) { return g2(g1((double)x)); }
