// from server: 100% by king_originala
extern "C" void (__stdcall *DeleteCriticalSection)(void*);
extern "C" void __stdcall releaseHandle(void*);
extern "C" void __cdecl freeObject(void*);
extern unsigned int vtableData[];

struct S {
    void* vtable;
    char padding0[16];
    void* handle;
    char padding1[20];
    char criticalSection[24];

    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags)
{
    vtable = vtableData;
    DeleteCriticalSection(criticalSection);
    if (handle)
        releaseHandle(handle);
    if (flags & 1)
        freeObject(this);
    return this;
}
