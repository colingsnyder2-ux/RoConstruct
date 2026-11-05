// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x10];void* fn;int b;int a; void f(int x);};
void S::f(int x){typedef void(__thiscall* Fn)(void*);((Fn)fn)((void*)(a+b));}
