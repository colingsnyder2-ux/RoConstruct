// from server: 7% by colin
// roc 2007-08 004f6340  unit: boost::bad_lexical_cast  size: 2811 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f6340

extern "C" {
    void* __cdecl malloc(unsigned int);
    void  __cdecl free(void*);
    void  __cdecl _invalid_parameter_noinfo();
    long  __stdcall InterlockedIncrement(long*);
    long  __stdcall InterlockedDecrement(long*);
}

struct RefCount {
    long count;
    void AddRef() { InterlockedIncrement(&count); }
    void Release() {
        if (InterlockedDecrement(&count) == 0) {
            if (this) { }
        }
    }
};

struct Obj {
    void* vtbl;
    RefCount* ref;
};

struct Vec3 { float x, y, z; };

struct Arr {
    void* data;
    int   count;
    int   cap;
};

struct Big {
    char pad0[0x4c];
    float f4c;
};

struct Ctx {
    char pad0[4];
    Arr  arr4;
    char pad10[0x3c];
    float f4c;
};

extern "C" void* __cdecl sub_62fef6(unsigned int);
extern "C" void  __cdecl sub_62fc62(void*);
extern "C" void  __cdecl sub_630e0c();
extern "C" void  __cdecl sub_50a500();
extern "C" void  __cdecl sub_50f630();
extern "C" void  __cdecl sub_4f6180();
extern "C" void  __cdecl sub_474f70();
extern "C" void  __cdecl sub_4f5020();
extern "C" void  __cdecl sub_4dd250();
extern "C" void  __cdecl sub_4f4810();
extern "C" void  __cdecl sub_4750b0();
extern "C" void  __cdecl sub_473200();
extern "C" void  __cdecl sub_4f5360();
extern "C" void  __cdecl sub_47d540();
extern "C" void  __cdecl sub_47cfc0();
extern "C" void  __cdecl sub_4f4320();
extern "C" void  __cdecl sub_4f4470();
extern "C" void  __cdecl sub_4f4920();

extern void* g_77d2ec;
extern void* g_77d2e8;
extern void* g_77e6d8;

void __cdecl target_4f6340(Ctx* ctx, void* a2, void* a3, Big* a4)
{
    void* p = sub_62fef6(0x50);
    if (p) {
        sub_4f6180();
    }
    sub_474f70();
    sub_4f5020();
    sub_50f630();
    sub_50a500();
    sub_630e0c();
    void* q = sub_62fef6(0x1c);
    if (q) {
        *(void**)q = (void*)0x797984;
        *(void**)((char*)q + 4) = 0;
        *(void**)((char*)q + 8) = 0;
        *(void**)q = (void*)0x79f304;
        *(void**)((char*)q + 0x10) = 0;
        *(void**)((char*)q + 0x14) = 0;
        *(void**)((char*)q + 0xc) = 0;
        *(int*)((char*)q + 0x18) = 5;
    }
    sub_4dd250();
    sub_4750b0();
    sub_473200();
    sub_4f5360();
    sub_47d540();
    sub_47cfc0();
    sub_4f4320();
    sub_4f4470();
    sub_4f4920();
    if (a4) {
        a4->f4c = ctx->f4c;
    }
}
