// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl __stdcall_placeholder();

struct RBXName {
    void* p;
};

struct RefCounted {
    long refs;
};

struct VSeat {
    char pad0[0x2a8];
    void* field_2a8;
    char pad2ac[4];
    char field_2b0;
    void construct();
};

struct String {
    char buf[0x1c];
    String(const char*);
    ~String();
};

extern "C" {
    void __cdecl sub_4aeb70(void*);
    void __cdecl sub_402a60(void*);
    void __cdecl sub_5a5c60(void*);
    void __cdecl sub_573f80(void*);
    void __cdecl sub_5b0f00(void*, void*);
    void __cdecl sub_5b0f20(void*, void*);
    void __cdecl sub_475050(void*);
    void __cdecl sub_51dbe0(void*, void*);
    void __cdecl sub_5b0ff0(void*, void*);
    void __cdecl sub_5b1020(void*, void*);
    void __cdecl sub_541630(void*, void*);
    void* __stdcall sub_77e698(const char*);
    void __stdcall sub_77e6ac(void*);
}

extern float g_79646c;
extern float g_797b38;
extern float g_7a8340;

void VSeat::construct()
{
    char local0[0x94];
    void* p;
    void* q;
    void* r;
    String s("@@GImage has an unexpected number of channels (%d)");

    sub_4aeb70(local0);
    field_2a8 = *(void**)local0;
    sub_402a60(local0 + 4);

    if (p) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            (*(void(__thiscall**)(void*))p)(p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                (*(void(__thiscall**)(void*))(*(void**)p))(p);
            }
        }
    }

    sub_5a5c60(local0);
    q = (void*)0;
    sub_573f80(q);

    sub_77e698("@@GImage has an unexpected number of channels (%d)");

    (*(void(__thiscall**)(void*, void*))(*(void**)field_2a8))(field_2a8, local0 + 0x80);

    sub_77e6ac(local0 + 0x80);

    sub_5b0f00(field_2a8, this);
    sub_5b0f20(field_2a8, q);

    sub_475050(local0 + 0x50);

    float f0 = 0.0f;
    float f1 = g_79646c;
    float f2 = g_79646c;
    float f3 = g_79646c;

    sub_51dbe0(local0 + 0x50, local0 + 0x14);

    sub_475050(local0 + 0x20);

    float f4 = 0.0f;
    float f5 = g_797b38;
    float f6 = g_797b38;

    sub_51dbe0(local0 + 0x20, local0 + 0x14);

    float f7 = 0.0f;
    float f8 = g_7a8340;
    float f9 = g_7a8340;

    sub_5b0ff0(field_2a8, local0 + 0x50);
    sub_5b1020(field_2a8, local0 + 0x20);
    sub_541630(field_2a8, this);

    field_2b0 = 1;
}
