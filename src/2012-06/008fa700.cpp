// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __cdecl f_40c750(void*);
extern "C" void __cdecl f_4015a0(void*, void*);
extern "C" void __cdecl f_9831f5(void*);
extern "C" void __cdecl f_413890(void*);
extern "C" void __cdecl f_6d31d0(void*, void*);
extern "C" void* __cdecl f_40b9c0();
extern "C" void __stdcall f_b2230c(void*);
extern "C" void __stdcall f_b229c8(void*);

struct T4_008fa700 {
    void* m_p;
    char m_pad[4];
    void f_008fa700(void*);
};

void T4_008fa700::f_008fa700(void* arg)
{
    void* p = m_p;
    void* saved = p;
    if (p != 0) {
        f_40c750((char*)p + 5);
    }
    f_4015a0((void*)0x8f80b0, (void*)0xe565d8);
    if ((*(unsigned char*)0xe565a0 & 1) == 0) {
        *(unsigned long*)0xe565a0 |= 1;
        *(void**)0xe56598 = 0;
        *(void**)0xe5659c = 0;
        f_9831f5((void*)0xb20ef0);
    }
    void* local10 = (void*)0xe56598;
    char local14 = 0;
    f_413890(&local10);
    void* eax = m_p;
    char local20 = 1;
    if (eax == 0) {
        f_6d31d0(this, arg);
    } else {
        f_6d31d0(this, (char*)eax + 0xc);
    }
    local20 = 0;
    if (m_p == 0) {
        if (local14 != 0) {
            long old = _InterlockedExchangeAdd((volatile long*)local10, (long)0x80000000);
            if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
                if (!_interlockedbittestandset((volatile long*)local10, 0x1e)) {
                    f_b2230c(f_40b9c0());
                }
            }
        }
        local20 = -1;
        if (saved != 0) {
            void* ecx = (char*)saved + 5;
            if (ecx != 0) {
                ecx = (char*)ecx - 5;
            } else {
                ecx = 0;
            }
            void* esi = (char*)ecx - 8;
            long old = _InterlockedExchangeAdd((volatile long*)esi, -1);
            if (old == 0) {
                void* edx = *(void**)ecx;
                void* eax2 = *(void**)edx;
                f_b2230c(0);
                (*(void(__thiscall*)(void*, int))eax2)(edx, 0);
                long old2 = _InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1);
                if (old2 == 0) {
                    f_b229c8(esi);
                }
            }
        }
        return;
    }
    if (local14 != 0) {
        long old = _InterlockedExchangeAdd((volatile long*)local10, (long)0x80000000);
        if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
            if (!_interlockedbittestandset((volatile long*)local10, 0x1e)) {
                f_b2230c(f_40b9c0());
            }
        }
    }
    local20 = -1;
    if (saved != 0) {
        void* ecx = (char*)saved + 5;
        if (ecx != 0) {
            ecx = (char*)ecx - 5;
        } else {
            ecx = 0;
        }
        void* esi = (char*)ecx - 8;
        long old = _InterlockedExchangeAdd((volatile long*)esi, -1);
        if (old == 0) {
            void* edx = *(void**)ecx;
            void* eax2 = *(void**)edx;
            f_b2230c(0);
            (*(void(__thiscall*)(void*, int))eax2)(edx, 0);
            long old2 = _InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1);
            if (old2 == 0) {
                f_b229c8(esi);
            }
        }
    }
}
