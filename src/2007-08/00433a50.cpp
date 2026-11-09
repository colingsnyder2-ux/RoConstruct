// from server: 42% by colin
struct S {
    int f();
};

extern "C" unsigned long __stdcall GetCurrentThreadId();
extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void __cdecl _invalid_parameter_noinfo();

extern void* g_8bb93c;
extern void* g_8bb930;
extern void* g_8bb934;
extern void* g_8b5188;

extern void __cdecl sub_41d870(void*);
extern void* __cdecl sub_44f4c0(void*, void*, void*);
extern void* __cdecl sub_433930(void*, void*);
extern void* __cdecl sub_4339d0(void*, void*);
extern void* __cdecl sub_62fef6(unsigned int);

int S::f()
{
    void* local20;
    unsigned char local24;
    void* local28;
    void* local30;
    void* local14;
    void* local18;
    void* local1c;
    void* local34;
    void* local38;

    local20 = &g_8bb93c;
    local24 = 0;
    sub_41d870(&local20);

    local30 = 0;
    unsigned long tid = GetCurrentThreadId();
    void* ebx = (void*)tid;

    local14 = ebx;
    sub_44f4c0(&g_8bb930, &local1c, &local14);

    void* esi = local18;
    void* ebp = g_8bb934;

    if (esi != 0 && esi != &g_8bb930) {
        LeaveCriticalSection(0);
    }

    void* edi = local1c;
    if (edi != ebp) {
        if (esi == 0) {
            LeaveCriticalSection(0);
        }
        if (edi == *(void**)((char*)esi + 4)) {
            LeaveCriticalSection(0);
        }
        void* eax = *(void**)((char*)edi + 0x10);
        *(int*)((char*)eax + 0x24) += 1;
        if (edi == *(void**)((char*)esi + 4)) {
            LeaveCriticalSection(0);
        }
        if (local24 != 0) {
            LeaveCriticalSection(local20);
        }
        edi = *(void**)((char*)edi + 0x10);
        return (int)edi;
    }

    void* mem = sub_62fef6(0x44);
    local18 = mem;
    if (mem != 0) {
        esi = sub_433930(mem, ebx);
    } else {
        esi = 0;
    }

    local34 = 0;
    void* p = sub_4339d0(&g_8bb930, &local14);
    *(void**)p = esi;
    *(int*)((char*)esi + 0x24) += 1;

    if (local24 != 0) {
        LeaveCriticalSection(local20);
    }

    return (int)esi;
}
