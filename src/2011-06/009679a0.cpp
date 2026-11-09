// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0xc]; void* fn; void* ctx; void f();};
void S::f(){typedef void(__thiscall* Fn)(void*);((Fn)fn)(ctx);}
