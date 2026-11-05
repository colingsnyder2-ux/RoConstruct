// from server: 10% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CStatsItemRecord {
    char pad0[0x54];
    void* field54;
    void* field58;
    char pad5c[0x0c];
    char field68[0x24];
    void* field8c;

    void f();
};

extern "C" char __cdecl sub_490740();
extern "C" void __cdecl sub_4284d0();
extern "C" void __cdecl sub_98211a();
extern "C" void __cdecl sub_9823f0();
extern "C" void __cdecl sub_9b9000();
extern "C" void __cdecl sub_9bac70();
extern "C" void __cdecl sub_9bac80();
extern "C" void __cdecl sub_9bb000();
extern "C" void __cdecl sub_9bb030();
extern "C" void __cdecl sub_4914c0();
extern "C" void __cdecl sub_491980();

extern void* g_e593dc;
extern void* g_e593e4;
extern void* g_e593d8;
extern void* g_b22198;
extern void* g_b222a4;

void CStatsItemRecord::f() {
    char local18[8];
    void* local1c;
    void* local10;
    char local2c;
    void* local24;
    void* local28;
    void* local20;

    local18[0] = 0;
    local1c = 0;
    local10 = 0;
    local2c = 0;

    if (!sub_490740()) {
        goto L_1af8;
    }

L_19c1:
    if (local18[0] == 0) {
        goto L_1a9d;
    }

    if (g_e593e4 == 0) {
        goto L_1a0c;
    }

    ((void (__stdcall*)(void*))g_b22198)(&g_e593dc);

    if (g_e593e4 == 0) {
        goto L_1a00;
    }

    sub_4284d0();
    ((void (__stdcall*)(void*, int, int))g_b222a4)(g_e593d8, 0, 0x98);
    goto L_1a1f;

L_1a00:
    sub_9823f0();
    goto L_1a1c;

L_1a0c:
    ((void (__stdcall*)(void*))g_b22198)(&g_e593dc);
    sub_98211a();

L_1a1c:
    local10 = (void*)0;

L_1a1f:
    local2c = 1;

    if (local10 == 0) {
        goto L_1a86;
    }

    {
        void* edx = field8c;
        void* ecx = field54;
        void* esi = &local24;
        *(void**)esi = ecx;
        void* edx2 = field58;
        local20 = esi;
        *(void**)((char*)esi + 4) = edx2;
        if (edx2 != 0) {
            _InterlockedExchangeAdd((volatile long*)((char*)edx2 + 4), 1);
        }
        void* esi2 = local28;
        void* ecx2 = local24;
        void* edx3 = &local24;
        *(void**)edx3 = ecx2;
        local28 = edx3;
        *(void**)((char*)edx3 + 4) = esi2;
        if (esi2 != 0) {
            _InterlockedExchangeAdd((volatile long*)((char*)esi2 + 4), 1);
        }
        sub_4914c0();
    }
    goto L_1a88;

L_1a86:
    local10 = 0;

L_1a88:
    sub_9b9000();
    sub_9bb000();
    goto L_1ae3;

L_1a9d:
    sub_9b9000();
    sub_9bac70();
    {
        int esi = (int)local10 - 1;
        if (esi < 0) {
            goto L_1ae3;
        }
        void* ebp = local18;
        do {
            sub_9b9000();
            sub_9bac80();
            if (*(void**)((char*)local10 + 0x90) == ebp) {
                goto L_1ad4;
            }
            esi--;
        } while (esi >= 0);
        goto L_1ae3;

L_1ad4:
        sub_9b9000();
        sub_9bb030();
    }

L_1ae3:
    if (sub_490740()) {
        goto L_19c1;
    }

L_1af8:
    sub_9b9000();
    sub_9bac70();
    {
        int esi = (int)local10 - 1;
        if (esi < 0) {
            goto L_1b2b;
        }
        do {
            sub_9b9000();
            sub_9bac80();
            sub_491980();
            esi--;
        } while (esi >= 0);
    }

L_1b2b:
    {
        void* esi = local1c;
        local2c = (char)0xff;
        if (esi == 0) {
            goto L_1b65;
        }
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            void* eax = *(void**)esi;
            void* edx = *(void**)((char*)eax + 4);
            ((void (__stdcall*)(void*))edx)(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void* edx2 = *(void**)esi;
                void* eax2 = *(void**)((char*)edx2 + 8);
                ((void (__stdcall*)(void*))eax2)(esi);
            }
        }
    }

L_1b65:
    return;
}
