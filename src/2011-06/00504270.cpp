// from server: 26% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __stdcall SetEvent(void*);

extern "C" void* __cdecl sub_401610();
extern "C" void* __cdecl sub_40A2B0();
extern "C" void __cdecl sub_40DDC0(void*);
extern "C" void __cdecl sub_411500();
extern "C" void __cdecl sub_6B6F40(void*);
extern "C" void __cdecl sub_80B15D();

struct S {
    char pad0[0xc];
    void* field_c;
    bool f(void* arg);
};

bool S::f(void* arg) {
    void* edi = *(void**)arg;
    void* ebx = 0;
    void* ebp = this;
    void* local20 = edi;
    if (edi != ebx) {
        char* eax = (char*)edi + 5;
        if (eax != ebx) {
            eax -= 5;
        } else {
            eax = 0;
        }
        char* ecx = eax - 4;
        short one = 1;
        volatile short* edx = (volatile short*)ecx;
        short old = (short)_InterlockedExchangeAdd((volatile long*)edx, (long)one);
        (void)old;
    }
    sub_401610();
    if (!(*(unsigned char*)0xcb82e8 & 1)) {
        *(unsigned long*)0xcb82e8 |= 1;
        *(void**)0xcb82e0 = ebx;
        *(void**)0xcb82e4 = ebx;
        sub_80B15D();
    }
    sub_411500();
    void* eax2 = *(void**)arg;
    if (eax2 == ebx) {
        sub_6B6F40(ebp);
    } else {
        sub_6B6F40((char*)eax2 + 0xc);
    }
    if (*(void**)arg == ebx) {
        if (*(unsigned char*)0xcb82e8 & 1) {
            volatile long* ecx2 = (volatile long*)0xcb82e0;
            long old2 = _InterlockedExchangeAdd(ecx2, (long)0x80000000);
            if (!(old2 & 0x40000000) && old2 > (long)0x80000000) {
                if (!_interlockedbittestandset((volatile long*)ecx2, 0x1e)) {
                    SetEvent(sub_40A2B0());
                }
            }
        }
        if (edi != ebx) {
            sub_40DDC0((char*)edi + 5);
        }
        return false;
    } else {
        if (*(unsigned char*)0xcb82e8 & 1) {
            volatile long* ecx3 = (volatile long*)0xcb82e0;
            long old3 = _InterlockedExchangeAdd(ecx3, (long)0x80000000);
            if (!(old3 & 0x40000000) && old3 > (long)0x80000000) {
                if (!_interlockedbittestandset((volatile long*)ecx3, 0x1e)) {
                    SetEvent(sub_40A2B0());
                }
            }
        }
        if (edi != ebx) {
            sub_40DDC0((char*)edi + 5);
        }
        return true;
    }
}
