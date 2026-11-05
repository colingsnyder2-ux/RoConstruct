// from server: 100% by atomic.potato
extern "C" void* __cdecl GetProcessHeap();
extern "C" int __stdcall HeapFree(void*, unsigned long, void*);

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
