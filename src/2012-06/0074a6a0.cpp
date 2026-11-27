// from server: 98% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct VT { void (*manager)(const void*, void*, int); };
struct B { char d[0x1c]; __declspec(dllimport) B(const B&); ~B(); };
struct Fn { VT* vt; int pad; char buf[16]; Fn(const Fn& o) { vt = 0; if (o.vt) { vt = o.vt; o.vt->manager(o.buf, buf, 0); } } ~Fn(); };
struct F : B { int x; Fn f; F(const F& o); };
F::F(const F& o) : B(o), x(o.x), f(o.f) {}
