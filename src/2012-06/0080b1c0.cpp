// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S { int vt; void* fn; void f(void* p); };
struct Cls { char pad[500]; int m; };
void S::f(void* p)
{
    Cls* o = p ? (Cls*)((char*)p - 0x1c) : 0;
    int* q = o ? &o->m : 0;
    typedef void (__thiscall *F)(int*);
    F g = (F)fn;
    g(q);
}
