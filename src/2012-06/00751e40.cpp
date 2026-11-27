// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE
struct V3 { float x, y, z; V3(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Buf { char d[0x30]; };
extern const float K;
void __stdcall A(Buf*);
void B(Buf* out, Buf* in, const V3* v);
void C(Buf*, Buf*, float, float);
void f() { Buf b[2]; A(&b[0]); static V3 v(1.0f, 0.1f, 1.0f); B(&b[1], &b[0], &v); C(&b[0], &b[1], K, K); }
