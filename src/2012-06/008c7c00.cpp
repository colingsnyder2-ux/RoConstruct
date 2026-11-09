// from server: 50% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);
extern "C" void __cdecl free(void*);

extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" void* __cdecl sub_40B9C0();
extern "C" void __cdecl sub_40C750(void*);
extern "C" void __cdecl sub_413890();
extern "C" void __cdecl sub_6D31D0(void*, void*);
extern "C" void __cdecl sub_8EA4F0();
extern "C" void __cdecl sub_972290(void*, void*);
extern "C" void __cdecl sub_9831F5(void*);

extern unsigned char byte_E580B3;
extern void* dword_E5809C;
extern long dword_E2F908;
extern void* dword_E2F900;
extern void* dword_E2F904;
extern void* dword_B229C8;
extern void* dword_B2230C;

struct VirtualUser {
    void func(void*);
};

void VirtualUser::func(void* arg)
{
    if (byte_E580B3 != 0) {
        if (arg == 0) {
            void* p = dword_E5809C;
            if (p != 0) {
                typedef char (__cdecl *fn_t)(int, void*, void*);
                fn_t fn = (fn_t)p;
                if (fn(0x11b, (void*)0xb4e5a8, (void*)0xb4e9a4) != 0) {
                    goto after;
                }
            }
            sub_972290((void*)0xb4e940, (void*)byte_E580B3);
        }
    }
after:
    sub_4015A0((void*)0x6d1a20, (void*)0xe2f930);

    if ((dword_E2F908 & 1) == 0) {
        dword_E2F908 |= 1;
        dword_E2F900 = 0;
        dword_E2F904 = 0;
        sub_9831F5((void*)0xb16a30);
    }

    void* local14 = (void*)0xe2f900;
    char local18 = 0;
    sub_413890();

    void* esi = *(void**)this;
    if (esi == 0) {
        sub_8EA4F0();
        goto cleanup;
    }

    void* edi = (char*)esi + 5;
    sub_40C750(edi);

    void* local10 = 0;
    sub_6D31D0((char*)arg + 0xc, &local10);

    if (byte_E580B3 != 0) {
        if (esi != *(void**)this) {
            void* p = dword_E5809C;
            if (p != 0) {
                typedef char (__cdecl *fn_t)(int, void*, void*);
                fn_t fn = (fn_t)p;
                if (fn(0x12f, (void*)0xb4e5a8, (void*)0xb4e92c) != 0) {
                    goto skip_check;
                }
            }
            sub_972290((void*)0xb4e8c0, (void*)byte_E580B3);
        }
    }
skip_check:
    sub_8EA4F0();

    local18 = 0;
    void* ecx;
    if (edi != 0) {
        ecx = (char*)edi - 5;
    } else {
        ecx = 0;
    }
    void* esi2 = (char*)ecx - 8;
    long old = _InterlockedExchangeAdd((volatile long*)esi2, -1);
    if (old == 1) {
        void* eax = *(void**)ecx;
        void* edx = *(void**)eax;
        typedef void (__cdecl *fn_t)(void*);
        fn_t fn = (fn_t)edx;
        fn(0);
        void* eax2 = (char*)esi2 + 4;
        long old2 = _InterlockedExchangeAdd((volatile long*)eax2, -1);
        if (old2 == 1) {
            free(esi2);
        }
    }

cleanup:
    if (local18 != 0) {
        void* ecx2 = local14;
        long old3 = _InterlockedExchangeAdd((volatile long*)ecx2, (long)0x80000000);
        if ((old3 & 0x40000000) == 0) {
            if (old3 > (long)0x80000000) {
                void* eax3 = ecx2;
                volatile long* p = (volatile long*)eax3;
                long cur = *p;
                if ((cur & (1 << 0x1e)) == 0) {
                    *p = cur | (1 << 0x1e);
                    void* eax4 = sub_40B9C0();
                    SetEvent(eax4);
                }
            }
        }
    }
}
