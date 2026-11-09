// from server: 28% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" void __stdcall SetEvent(void*);
extern "C" void __cdecl free(void*);

extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" void* __cdecl sub_40B9C0();
extern "C" void __cdecl sub_40C750(void*);
extern "C" void __cdecl sub_413890();
extern "C" void __cdecl sub_6D31D0(void*);
extern "C" void __cdecl sub_9831F5(void*);

struct FriendEventTypeSignal {
    void signal(int a, int b, int c);
};

void FriendEventTypeSignal::signal(int a, int b, int c)
{
    int* p = (int*)this;
    int* saved = (int*)p[0];

    if (saved != 0) {
        sub_40C750((char*)saved + 5);
    }

    sub_4015A0((void*)0x69af80, (void*)0xe2d1f0);

    if ((*(unsigned char*)0xe2d1d0 & 1) == 0) {
        *(unsigned int*)0xe2d1d0 |= 1;
        *(int*)0xe2d1c8 = 0;
        *(int*)0xe2d1cc = 0;
        sub_9831F5((void*)0xb16100);
    }

    int localbuf[2];
    localbuf[0] = 0xe2d1c8;
    *(unsigned char*)((char*)localbuf + 4) = 0;
    sub_413890();

    int* obj = (int*)p[0];
    *(unsigned char*)((char*)localbuf + 12) = 1;

    if (obj == 0) {
        sub_6D31D0(&a);
    } else {
        sub_6D31D0((char*)obj + 12);
    }

    *(unsigned char*)((char*)localbuf + 12) = 0;

    if (p[0] == 0) {
        if (*(unsigned char*)((char*)localbuf + 4) != 0) {
            int* ref = (int*)localbuf[0];
            long old = _InterlockedExchangeAdd((volatile long*)ref, (long)0x80000000);
            if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
                if (!_interlockedbittestandset((volatile long*)ref, 30)) {
                    void* h = sub_40B9C0();
                    SetEvent(h);
                }
            }
        }
        *(int*)((char*)localbuf + 12) = -1;
        if (saved != 0) {
            int* base;
            if ((char*)saved + 5 != 0) {
                base = (int*)((char*)saved + 5 - 5);
            } else {
                base = 0;
            }
            int* cnt = (int*)((char*)base - 8);
            long old = _InterlockedExchangeAdd((volatile long*)cnt, -1);
            if (old == 1) {
                int* vt = (int*)*base;
                void (*fn)() = (void (*)())vt[0];
                fn();
                int* cnt2 = (int*)((char*)cnt + 4);
                long old2 = _InterlockedExchangeAdd((volatile long*)cnt2, -1);
                if (old2 == 1) {
                    free(cnt);
                }
            }
        }
        return;
    }

    if (*(unsigned char*)((char*)localbuf + 4) != 0) {
        int* ref = (int*)localbuf[0];
        long old = _InterlockedExchangeAdd((volatile long*)ref, (long)0x80000000);
        if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
            if (!_interlockedbittestandset((volatile long*)ref, 30)) {
                void* h = sub_40B9C0();
                SetEvent(h);
            }
        }
    }
    *(int*)((char*)localbuf + 12) = -1;
    if (saved != 0) {
        int* base;
        if ((char*)saved + 5 != 0) {
            base = (int*)((char*)saved + 5 - 5);
        } else {
            base = 0;
        }
        int* cnt = (int*)((char*)base - 8);
        long old = _InterlockedExchangeAdd((volatile long*)cnt, -1);
        if (old == 1) {
            int* vt = (int*)*base;
            void (*fn)() = (void (*)())vt[0];
            fn();
            int* cnt2 = (int*)((char*)cnt + 4);
            long old2 = _InterlockedExchangeAdd((volatile long*)cnt2, -1);
            if (old2 == 1) {
                free(cnt);
            }
        }
    }
}
