// from server: 13% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl func_718a38(unsigned int);
extern "C" void __cdecl func_6749e0();
extern "C" void __cdecl func_706560();
extern "C" void __cdecl func_707d60();

struct S {
    void* field0;
    void* field4;
    char pad8[0x30];
    void* method();
};

void* S::method()
{
    void* p = func_718a38(0x38);
    void* esi = 0;
    if (p) {
        esi = ((void* (__thiscall*)(void*))0x707450)(p);
    }
    field0 = esi;
    ((void (__thiscall*)(void*, void*))0x7078d0)(&field4, esi);
    func_6749e0();
    func_706560();
    ((void (__thiscall*)(void*))0x707740)((char*)this + 0x48);
    ((void (__thiscall*)(void*))0x4c8090)((char*)this + 8);

    return this;
}
