// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE
struct V3 { float x, y, z; V3(float a) : x(a), y(a), z(a) {} };
V3 f() { static V3 v(-10000.0f); return v; }
