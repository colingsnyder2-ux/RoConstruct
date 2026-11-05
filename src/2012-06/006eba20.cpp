// from server: 37% by atomic.potato
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

extern char byte_E580B3;
extern void* dword_E5809C;
extern void* dword_E2F918;
extern void* dword_E2F91C;
extern long dword_E2F920;
extern void* dword_B229C8;
extern void* dword_B2230C;

struct VInstance_ {
    void* field0;
    char pad[0x100];
    void removeSlot(void*);
};

void VInstance_::removeSlot(void* slot) {
    sub_8EA4F0();
}

void target(VInstance_* self, void* arg) {
    void* ebx = arg;
    void* ebp = self;
    void* edi = 0;
    void* esi;

    if (byte_E580B3 != 0) {
        if (ebx != 0) {
            goto skip_check1;
        }
        if (dword_E5809C != 0) {
            void* fn = dword_E5809C;
            ((void(__cdecl*)(int, void*, void*))fn)(0x11b, (void*)0xb4e5a8, (void*)0xb4e9a4);
            if ((char)0 != 0) {
                goto skip_check1;
            }
        }
        sub_972290((void*)0xb4e940, (void*)(unsigned)byte_E580B3);
    }
skip_check1:
    sub_4015A0((void*)0x6d1c70, (void*)0xe2f96c);

    if ((dword_E2F920 & 1) == 0) {
        dword_E2F920 |= 1;
        dword_E2F918 = 0;
        dword_E2F91C = 0;
        sub_9831F5((void*)0xb16a90);
    }

    void* local14 = (void*)0xe2f918;
    char local18 = 0;
    sub_413890();

    esi = *(void**)ebp;
    void* local24 = 0;
    if (esi == 0) {
        sub_8EA4F0();
        goto cleanup;
    }

    edi = (char*)esi + 5;
    sub_40C750(edi);
    void* local10 = 0;
    sub_6D31D0((char*)ebx + 0xc, &local10);

    if (byte_E580B3 != 0) {
        if (esi == *(void**)ebp) {
            goto skip_check2;
        }
        if (dword_E5809C != 0) {
            void* fn = dword_E5809C;
            ((void(__cdecl*)(int, void*, void*))fn)(0x12f, (void*)0xb4e5a8, (void*)0xb4e92c);
            if ((char)0 != 0) {
                goto skip_check2;
            }
        }
        sub_972290((void*)0xb4e8c0, (void*)(unsigned)byte_E580B3);
    }
skip_check2:
    sub_8EA4F0();

    local24 = 0;
    if (edi != 0) {
        void* ecx = (char*)edi - 5;
        esi = (char*)ecx - 8;
        long old = _InterlockedExchangeAdd((volatile long*)esi, -1);
        if (old == 1) {
            void* eax = *(void**)ecx;
            void* edx = *(void**)eax;
            ((void(__cdecl*)(void*))edx)(0);
            void* eax2 = (char*)esi + 4;
            long old2 = _InterlockedExchangeAdd((volatile long*)eax2, -1);
            if (old2 == 1) {
                free(esi);
            }
        }
    }

cleanup:
    if (local18 != 0) {
        local24 = (void*)0xffffffff;
        void* ecx = local14;
        long old = _InterlockedExchangeAdd((volatile long*)ecx, (long)0x80000000);
        if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
            if (!_InterlockedExchangeAdd((volatile long*)ecx, 0)) {
                void* eax = sub_40B9C0();
                SetEvent(eax);
            }
        }
    }
}
