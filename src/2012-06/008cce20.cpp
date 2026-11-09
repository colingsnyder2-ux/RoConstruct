// from server: 40% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_62E740();
extern "C" void* __cdecl sub_439330();
extern "C" void __cdecl sub_972290(int, const char*);

struct Vec3 { float x, y, z; };

struct RefCounted {
    void** vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Inner {
    char pad[0x30];
    int field30;
};

struct Holder {
    char pad[0x108];
    Inner* inner;
};

struct Outer {
    char pad[0x198];
    Holder* holder;
};

struct BodyMover {
    char pad0[0x138];
    void* field138;
    int method(int a, Vec3* v, int b, int c);
};

extern unsigned char byte_E580B3;
extern int dword_E5809C;
extern void* g_unk;

int BodyMover::method(int a, Vec3* v, int b, int c)
{
    if (byte_E580B3) {
        Vec3* zero = (Vec3*)sub_62E740();
        if (v->x != zero->x || v->y != zero->y || v->z != zero->z) {
            if (dword_E5809C) {
                typedef char (__cdecl *fn_t)(int, const char*, const char*);
                fn_t fn = (fn_t)dword_E5809C;
                if (fn(0x49, (const char*)0xbe7c38, (const char*)0xbe8300))
                    goto skip;
            }
            sub_972290(byte_E580B3, (const char*)0xbe8288);
        }
    }
skip:
    void* tmp;
    void* r = sub_439330();
    (void)r;
    return 0;
}
