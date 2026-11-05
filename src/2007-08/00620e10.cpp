// from server: 6% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

struct RBX_Instance {
    void* vptr;
    char pad0[0xbc];
    void* field_c0;
};

struct RBX_Value {
    void* vptr;
};

struct RBX_Team {
    void* vptr;
};

struct RBX_ScoreHud {
    char pad0[4];
    void* field_4;
    void* field_8;
    char pad_c[4];
    void* field_10;
    char pad_14[8];
    void* field_1c;
    char pad_20[8];
    void* field_28;
    char pad_2c[8];
    void* field_34;
    int method_620e10();
};

extern "C" void* __cdecl sub_48dfb0(void*);
extern "C" void* __cdecl sub_5687f0(void*);
extern "C" void* __cdecl sub_5a31f0(void*, void*);
extern "C" void* __cdecl sub_492ab0(void*, void*);
extern "C" void* __cdecl sub_5a31c0(void*, void*);
extern "C" void* __cdecl sub_61f550(void*, void*);
extern "C" void* __cdecl sub_429b20(void*);
extern "C" void* __cdecl sub_53e7a0(void*, void*);
extern "C" void* __cdecl sub_487c10(void*);
extern "C" void* __cdecl sub_630d36(void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_620c90(void*);
extern "C" void* __cdecl sub_41b630(void*);
extern "C" void* __cdecl sub_6208c0(void*, void*, void*);
extern "C" void* __cdecl sub_5e2fa0(void*);
extern "C" void* __cdecl sub_6207a0(void*, void*, void*);

extern "C" void* __cdecl sub_77e698(void*, const char*);
extern "C" void* __cdecl sub_77e69c(void*, void*);
extern "C" void* __cdecl sub_77e6ac(void*);
extern "C" void __cdecl sub_77e6d8();

int RBX_ScoreHud::method_620e10()
{
    void* v1 = sub_48dfb0(field_34);
    void* v2 = sub_5687f0(field_34);
    void* v3 = sub_5a31f0(v2, 0);
    void* v4 = sub_492ab0(v1, 0);
    return 0;
}
