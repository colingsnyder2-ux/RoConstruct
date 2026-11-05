// from server: 12% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall sub_77ddac();
extern "C" void* __stdcall sub_77d59c();
extern "C" void* __stdcall sub_77dd98();
extern "C" void* __stdcall sub_77ddbc();
extern "C" void* __stdcall sub_77e69c();
extern "C" void* __stdcall sub_77e698();
extern "C" void* __stdcall sub_77e6ac();

void __cdecl sub_6303f4();
void __cdecl sub_6303ee();
void __cdecl sub_6303e8();
void __cdecl sub_6303e2();
void __cdecl sub_6303dc();
void __cdecl sub_630a1e();
void __cdecl sub_41c050();
void __cdecl sub_41cb60();
void __cdecl sub_4108b0();
void __cdecl sub_410d40();
void __cdecl sub_533250();
void __cdecl sub_541630();
void __cdecl sub_573040();

struct S_0041cc20 {
    char pad0[0x20];
    void* m_p20;
    int f(void* a);
};

int S_0041cc20::f(void* a)
{
    char buf[0x228];
    void* p;
    void* q;
    int r;

    sub_77ddac();
    sub_77d59c();
    sub_77dd98();
    sub_6303f4();
    sub_6303ee();
    sub_6303e8();
    sub_77dd98();
    sub_41c050();
    sub_77ddbc();

    {
        int* vt = *(int**)this;
        void (__thiscall *fn)(void*, void*) = (void (__thiscall *)(void*, void*))vt[5];
        fn(this, buf);
    }

    sub_77e69c();
    sub_573040();
    sub_6303e2();
    sub_77dd98();
    sub_77e698();
    sub_77e6ac();
    sub_77ddbc();

    sub_41cb60();
    sub_541630();

    if (m_p20) {
        sub_410d40();
        p = (void*)1;
    } else {
        p = 0;
    }
    sub_533250();
    sub_4108b0();

    q = *(void**)(buf + 4);
    if (q) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)q + 4), -1) == 1) {
            int* vt = *(int**)q;
            void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[1];
            fn(q);
            if (_InterlockedExchangeAdd((volatile long*)((char*)q + 8), -1) == 1) {
                int* vt2 = *(int**)q;
                void (__thiscall *fn2)(void*) = (void (__thiscall *)(void*))vt2[2];
                fn2(q);
            }
        }
    }
    sub_77e6ac();
    sub_6303dc();
    sub_77ddbc();
    sub_630a1e();
    return 0;
}
