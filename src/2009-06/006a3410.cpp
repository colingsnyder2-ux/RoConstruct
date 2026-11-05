// from server: 33% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl func_718a38(unsigned int);
extern "C" int __cdecl func_006a3090();
extern "C" void __cdecl func_0047dc00();
extern "C" void __cdecl func_006749e0();
extern "C" void __cdecl func_0068c760();
extern "C" void __cdecl func_00430530();
extern "C" void __cdecl func_0041ad60();
extern "C" void __cdecl func_0041ab20();

struct S {
    void f(int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int v8 = 0;
    void* p = func_718a38(0x48);
    if (p != 0) {
        v8 = func_006a3090();
    }
    func_0047dc00();
    func_006749e0();
    func_0068c760();
    func_00430530();
    void* (__stdcall* fn)(const char*) = *(void* (__stdcall**)(const char*))0x89e1d0;
    fn((const char*)0xa4a86c);
    func_0041ad60();
    fn((const char*)0xa3a1b8);
    func_0041ab20();
    if (v8 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)v8 + 4), -1) == 1) {
            (*(void(__thiscall**)(void*))(*(int*)v8 + 4))((void*)v8);
            if (_InterlockedExchangeAdd((volatile long*)((char*)v8 + 8), -1) == 1) {
                (*(void(__thiscall**)(void*))(*(int*)v8 + 8))((void*)v8);
            }
        }
    }
}
