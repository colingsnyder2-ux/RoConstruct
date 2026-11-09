// from server: 41% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void* __stdcall sub_00575050();
extern "C" void __stdcall sub_005b2550();
extern "C" void* __stdcall sub_005b2b20();

struct S {
    void* f();
};

void* S::f()
{
    void* edi = sub_005b2b20();
    EnterCriticalSection(edi);
    void* esi = *(void**)((char*)edi + 0x18);
    void* ecx = (char*)edi + 0x18;
    if (esi != 0) {
        *(void**)ecx = *(void**)esi;
    } else {
        esi = sub_00575050();
    }
    LeaveCriticalSection(edi);
    if (esi == 0) {
        sub_005b2550();
    }
    *(void**)esi = esi;
    void* eax = (char*)esi + 4;
    if (eax != 0) {
        *(void**)eax = esi;
    }
    return esi;
}
