// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE
struct F4 { float a, b, c, d; F4(float x) : a(x), b(x), c(x), d(x) {} };
const F4* f() { static F4 s(0.6f); return &s; }
