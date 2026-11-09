// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x4]; void* vp; int f() const;};
typedef int(__thiscall* Fn)(void*); extern Fn fn;
int S::f()const{return fn(*(void**)((char*)vp+0x2c));}
