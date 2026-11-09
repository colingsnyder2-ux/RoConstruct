// from server: 29% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __cdecl f_401610();
extern "C" void __cdecl f_40a2b0();
extern "C" void __cdecl f_40ddc0(void*);
extern "C" void __cdecl f_40de50(void*);
extern "C" void __cdecl f_411500();
extern "C" void __cdecl f_6b6f40();
extern "C" void __cdecl f_6d7090();
extern "C" void __cdecl f_80b15d(void*);
extern "C" void __stdcall SetEvent(void*);

struct S_006f7a70 {
    void* m_p;
    void f_006f7a70(void* arg);
};

void S_006f7a70::f_006f7a70(void* arg)
{
    void* p = arg;
    void* old;
    void* tmp;
    char flag;
    void* obj;

    f_401610();
    if (!(*(volatile unsigned char*)0xcd2550 & 1)) {
        *(volatile unsigned long*)0xcd2550 |= 1;
        *(void**)0xcd2548 = 0;
        *(void**)0xcd254c = 0;
        f_80b15d((void*)0xa3d860);
    }
    tmp = (void*)0xcd2548;
    flag = 0;
    f_411500();
    old = 0;
    if (m_p == 0) {
        obj = p;
        if (obj != 0) {
            f_40de50((char*)obj + 5);
        }
        old = m_p;
        m_p = obj;
    } else {
        f_6d7090();
        old = 0;
        obj = p;
        f_6b6f40();
        if (obj != 0) {
            f_40de50((char*)obj + 5);
        }
        old = m_p;
        m_p = obj;
        if (old != 0) {
            f_40ddc0((char*)old + 5);
        }
        old = 0;
        flag = 0;
    }
    if (old != 0) {
        f_40ddc0((char*)old + 5);
    }
    if (flag != 0) {
        long r = _InterlockedExchangeAdd((volatile long*)tmp, (long)0x80000000);
        if (!(r & 0x40000000) && r > (long)0x80000000) {
            if (!_interlockedbittestandset((volatile long*)tmp, 0x1e)) {
                f_40a2b0();
                SetEvent((void*)0xa40374);
            }
        }
    }
}
