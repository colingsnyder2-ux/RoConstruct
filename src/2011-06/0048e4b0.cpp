// from server: 0% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_5F6B90();
extern "C" void __stdcall sub_5F02D0();
extern "C" void __stdcall sub_462870();
extern "C" void __stdcall sub_469FD0();
extern "C" void __stdcall sub_5B1D80();
extern "C" void __stdcall sub_5B1B20();
extern "C" void __stdcall sub_7736F0();
extern "C" void __stdcall sub_7F9030();
extern "C" void __stdcall sub_80B0AC();
extern "C" void* __stdcall sub_639100();
extern "C" void* __stdcall sub_65AD80();
extern "C" void __stdcall sub_417A20();
extern "C" void* __stdcall sub_48E470();
extern "C" void __stdcall sub_48D600();
extern "C" void* __stdcall sub_48AFF0();
extern "C" void __stdcall sub_48A8B0();

extern "C" void* __stdcall sub_A4048C();
extern "C" void* __stdcall sub_A40490();
extern "C" void* __stdcall sub_A40494();
extern "C" void* __stdcall sub_A40498();
extern "C" void* __stdcall sub_A404D0();

struct S {
    char pad0[0x20];
    void* field20;
    char pad24[0xCC];
    void* fieldF0;
    char padF4[0xC];
    int field100;
    int field104;
    char field108;
    char field109;
    char field10A;
    char pad10B[0x1F5];
    void method();
};

void S::method()
{
    if (field20 == 0)
        return;

    field108 = 1;

    if (fieldF0 == 0)
        goto label_48e72f;

    {
        int* p = &field100;
        int v = field104;
        if (v != 0) {
            _InterlockedExchangeAdd((volatile long*)(v + 4), 1);
        }
        sub_5F6B90();
    }

    {
        void* p = fieldF0;
        if (p != 0) {
            void* q = (char*)p + 0x90;
            void* r = sub_A4048C();
            field10A = (r == 0);
            if (field10A) {
                void* s = sub_639100();
                int t = *(int*)s;
                sub_48D600();
            } else {
                void* u = sub_48E470();
                if (u != 0) {
                    void* v = (char*)fieldF0 + 0x90;
                    sub_417A20();
                    void* w = sub_65AD80();
                    int x = *(int*)w;
                    *(int*)w = 0;
                    sub_462870();
                    sub_A40490();
                    sub_469FD0();
                    sub_A40494();
                    sub_48D600();
                    sub_A404D0();
                    sub_A40498();
                    sub_462870();
                } else {
                    sub_5B1D80();
                    sub_5B1B20();
                    sub_7736F0();
                    sub_7F9030();
                    sub_80B0AC();
                }
            }
        }
    }

    {
        void* y = sub_48AFF0();
        char z = field109;
        sub_48A8B0();
    }

    sub_5F02D0();
    return;

label_48e72f:
    sub_5F02D0();
    return;
}
