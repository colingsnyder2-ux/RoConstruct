// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
struct B { int d[9]; B(const B& o); ~B(); };
const B& f();
struct V3 { float x,y,z; V3(float a,float b,float c):x(a),y(b),z(c){} };
struct S { B b; V3 v; S(const B& b_, V3 v_) : b(b_), v(v_) {} };
static S s(f(), V3(0.0f, 0.0f, 0.0f));
