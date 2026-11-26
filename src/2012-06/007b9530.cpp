// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A { char p[260]; void* o; int f(); };
int A::f(){ void* obj=o; void* vt=*(void**)obj; int (__thiscall *fn)(void*) = *(int (__thiscall**)(void*))((char*)vt+20); return fn(obj); }
