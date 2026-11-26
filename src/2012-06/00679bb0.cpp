// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void __cdecl H(void*);
struct Obj { void m(); };
struct S { char pad[8]; Obj o; void f(int); };
void S::f(int) { Obj* p = &o; p->m(); H((char*)p + 0x804); }