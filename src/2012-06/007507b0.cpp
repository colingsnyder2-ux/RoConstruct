// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE
struct V3 { float x, y, z; V3(float a, float b, float c) : x(a), y(b), z(c) {} };
const V3* f() { static V3 v(1.0f, 0.1f, 1.0f); return &v; }
