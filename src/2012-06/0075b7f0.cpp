// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T { char d[0x44]; };
struct V { int pad; T* b; T* e; };
struct S { void g(T*); void f(const V& v); };
void S::f(const V& v) { T* p = v.b; T* e = v.e; for (; p != e; ++p) g(p); }
