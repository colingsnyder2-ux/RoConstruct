// from server: 100% by colin
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace ns_ROCX000000 {
extern void* (__cdecl *GetProcessHeapPtr)();
extern int (__stdcall *HeapFreePtr)(void*, unsigned long, void*);

struct S {
    int pad0[3];
    void* p;

    void f();
};

void S::f()
{
    void* q = p;
    void** vtable = *(void***)q;
    void (__thiscall *destroy)(void*, int) =
        (void (__thiscall *)(void*, int))vtable[0];
    destroy(q, 0);
    HeapFreePtr(GetProcessHeapPtr(), 0, q);
}
}