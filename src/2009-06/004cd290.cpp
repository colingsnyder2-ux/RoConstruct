// from server: 0% by colin
// from server: 5% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall SetEvent(void*);
extern "C" void __stdcall func_0089e4c0();
extern "C" void __stdcall func_0089e4c4();
extern "C" void __stdcall func_0089e418();
extern "C" void __stdcall func_0089e47c();
extern "C" void __stdcall func_0089e4b8();
extern "C" void __stdcall func_0089e3cc();
extern "C" void __stdcall func_0089e1f0(void*);
extern "C" void __stdcall func_0089e9ac();

void __cdecl func_004c7360();
void __cdecl func_004131a0();
void __cdecl func_004c85d0();
void __cdecl func_004ca9c0();
void __cdecl func_004c8df0();
void __cdecl func_004c92c0();
void __cdecl func_004c4160();
void __cdecl func_004c8050();
void __cdecl func_005cd6b0();
void __cdecl func_0061fe10();
void __cdecl func_0061f310();
void __cdecl func_005e1f70();
void __cdecl func_005e1cc0();
void __cdecl func_005e1a60();
void __cdecl func_00417fa0();
void __cdecl func_00418060();
void __cdecl func_00415960();
void __cdecl func_00414d10();
void __cdecl func_00408e30();
void* __cdecl func_00410d60();

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct S {
    void f();
};

void S::f() {
    char pad[0x200];
    (void)pad;
    func_0089e4c0();
    func_004c7360();
    func_004131a0();
    func_004c85d0();
    func_00414d10();
    func_0089e4c4();
}
