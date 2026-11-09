// from server: 46% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    long ref;
};

struct VTool {
    char pad0[0x24];
    RefCounted* field24;
    void destroy();
};

void VTool::destroy()
{
    RefCounted* p = field24;
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))p->vptr[1])(p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                ((void (__thiscall*)(RefCounted*))p->vptr[2])(p);
            }
        }
    }
    ((void (__thiscall*)(VTool*))0x571ad0)(this);
}
