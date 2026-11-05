// from server: 51% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void __stdcall func_00a40968();
extern "C" void __cdecl func_0080b0ac(void*, void*);
extern "C" void __cdecl func_004ca650();
extern "C" void __cdecl func_007faa40();
extern "C" void* __cdecl func_0045f690();

struct S {
    void f();
};

void S::f()
{
    void* esi = func_0045f690();
    EnterCriticalSection(esi);
    void* eax = *(void**)((char*)esi + 0x18);
    void** ecx = (void**)((char*)esi + 0x18);
    if (eax != 0) {
        *(void**)ecx = *(void**)eax;
    } else {
        func_004ca650();
    }
    void* edi = eax;
    LeaveCriticalSection(esi);
    if (edi == 0) {
        if (*(unsigned char*)0xc956d0 != 0) {
            func_007faa40();
        }
        func_00a40968();
        *(void**)0xa5b5b4 = (void*)0xa5b5b4;
        func_0080b0ac((void*)0xb872c4, (void*)0xa5b5b4);
    }
}
