// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct B { __declspec(dllimport) void g(void*); };
struct A { int pad; B b; void* f(void* p); };
void* A::f(void* p){ volatile int z=0; b.g(p); return p; }
