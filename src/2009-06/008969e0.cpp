// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchange(long volatile*, long);
#pragma intrinsic(_InterlockedExchange)
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct Inner {
    char pad[0x2c];
    ~Inner();
};
struct Guarded {
    Inner inner;
    long handle;
    ~Guarded()
    {
        void* h = (void*)_InterlockedExchange(&handle, 0);
        if (h)
            CloseHandle(h);
    }
};
Guarded g_guarded;
