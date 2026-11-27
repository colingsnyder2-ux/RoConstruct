// from server: 92% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct O { virtual ~O(); long ref; void cleanup(); };
struct F { O* p; void f(); };
void F::f() { O* o = p; if (o) { if (!InterlockedDecrement(&o->ref)) { o->cleanup(); if (o) delete o; } p = 0; } }
