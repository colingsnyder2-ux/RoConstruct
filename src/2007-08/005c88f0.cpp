// from server: 65% by TrollStein
struct Ctx {
    char pad0[0x68];
    void* field68;
};

struct Inner {
    char pad0[0x0c];
    int f0c;
    char pad10[0x04];
    char f14;
    char pad15[0x1f];
    char f34;
    char pad35[0x01];
    char f36;
    char f37;
    char pad38[0x30];
    void* f68;
};

struct Outer {
    char pad0[0x0c];
    int f0c;
    char f10;
    char pad11[0x03];
    char f14;
    char f15;
    char pad16[0x06];
    void* f1c;
    char pad20[0x14];
    char f34;
    char pad35[0x01];
    char f36;
    char f37;
    char pad38[0x08];
    int f40;
    int f44;
    char pad48[0x04];
    int f4c;
    int f50;
    int f54;
    char pad58[0x10];
    void* f68;
    char pad6c[0x2c];
    void* f98;
    void* f9c;
    void* fa0;
    void* fa4;
    void* fa8;
    void* fac;
    void* fb0;
    void* fb4;
    void* fb8;
};

typedef void* (__stdcall *AllocFn)(int, int, int, int);
typedef int (__stdcall *InitFn)(void*, void*, int);

extern "C" void __stdcall sub_5c58d0(void*, void*, int);
extern "C" void __stdcall sub_5c8680(void*);
extern "C" void* __stdcall sub_62fef6(int);
extern "C" void __stdcall sub_5be6b0(void*, void*);

void* __cdecl sub_5c88f0(AllocFn alloc, InitFn init)
{
    void* mem = alloc(0x184, 0, 0, 0);
    if (mem == 0)
        return 0;

    Outer* o = (Outer*)mem;
    Inner* in = (Inner*)((char*)o + 0x0c);

    o->f0c = 0;
    o->f10 = 8;

    char* base = (char*)o + 0x0c;
    char* p = base + 0x78;

    p[0x14] = 0x21;
    *(void**)(base + 0x10) = p;
    base[5] = 0x61;
    *(int*)(base + 0x20) = 0;
    *(int*)(base + 0x2c) = 0;
    *(int*)(base + 0x70) = 0;
    *(int*)(base + 0x40) = 0;
    base[0x36] = 0;
    *(int*)(base + 0x38) = 0;
    base[0x37] = 1;
    *(int*)(base + 0x3c) = 0;
    *(int*)(base + 0x68) = 0;
    *(int*)(base + 0x30) = 0;
    *(short*)(base + 0x34) = 0;
    base[6] = 0;
    *(int*)(base + 0x14) = 0;
    *(int*)(base + 0x28) = 0;
    *(int*)(base + 0x18) = 0;
    *(int*)(base + 0x74) = 0;
    *(int*)(base + 0x50) = 0;

    *(void**)(p + 0x0c) = (void*)alloc;
    *(void**)(p + 0x10) = (void*)init;
    *(void**)(p + 0x70) = base;
    *(int*)(p + 0x40) = 0;
    *(int*)(p + 8) = 0;
    *(int*)(p + 4) = 0;
    *(int*)p = 0;

    char* q = p + 0x78;
    *(void**)(p + 0x88) = q;
    *(void**)(p + 0x8c) = q;

    void* ecx = *(void**)(base + 0x10);
    *(int*)((char*)ecx + 0x68) = 0;

    *(void**)(p + 0x1c) = base;
    *(int*)(p + 0x34) = 0;
    *(int*)(p + 0x3c) = 0;
    *(int*)(p + 0x58) = 0;
    p[0x15] = 0;
    *(int*)(p + 0x18) = 0;
    *(int*)(p + 0x24) = 0;
    *(int*)(p + 0x28) = 0;
    *(int*)(p + 0x2c) = 0;
    *(int*)(p + 0x30) = 0;
    *(int*)(p + 0x44) = 0x178;
    *(int*)(p + 0x4c) = 0;
    *(void**)(p + 0x20) = p + 0x1c;
    *(int*)(p + 0x50) = 0xc8;
    *(int*)(p + 0x54) = 0xc8;

    *(int*)(p + 0x98) = 0;
    *(int*)(p + 0x9c) = 0;
    *(int*)(p + 0xa0) = 0;
    *(int*)(p + 0xa4) = 0;
    *(int*)(p + 0xa8) = 0;
    *(int*)(p + 0xac) = 0;
    *(int*)(p + 0xb0) = 0;
    *(int*)(p + 0xb4) = 0;
    *(int*)(p + 0xb8) = 0;

    sub_5c58d0(base, (void*)0x5c8600, 0);

    if (sub_5c8680(base), 0)
        return 0;

    void* r = (void*)(base - 0x0c);
    if (r != 0)
    {
        *(int*)r = 0;
        *(int*)((char*)r + 4) = 0;
        *(char*)((char*)r + 8) = 0;
        void* t = sub_62fef6(4);
        if (t != 0)
            *(int*)t = 1;
        else
            t = 0;
        sub_5be6b0(r, t);
    }

    return (void*)base;
}
