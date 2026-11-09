// from server: 37% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

extern void __cdecl f_401630();
extern void __cdecl f_4020a0(void*);
extern void __cdecl f_636d80(void*);
extern void __cdecl f_657950(void*);
extern int __cdecl f_665c70();
extern int __cdecl f_66b1a0();

struct S {
    char pad0[0xa0];
    void* begin;
    void* end;
    int f();
};

int S::f()
{
    if (f_66b1a0() != 0)
        return 0;

    void* local = 0;
    f_657950(&local);

    void* ebx = local;

    f_401630();
    int idx = f_665c70();

    int count = ((char*)end - (char*)begin) >> 3;
    if ((unsigned)idx >= (unsigned)count)
        _invalid_parameter_noinfo();

    char* slot = (char*)begin + idx * 8;
    *(void**)slot = local;
    f_4020a0(slot + 4);

    f_636d80(ebx);

    if (local) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)local + 4), -1) == 1) {
            (*(void(__thiscall**)(void*))local)(local);
            if (_InterlockedExchangeAdd((volatile long*)((char*)local + 8), -1) == 1)
                (*(void(__thiscall**)(void*))local)(local);
        }
    }

    return (int)ebx;
}
