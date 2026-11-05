// from server: 61% by colin
struct RBXBase {
    char pad0[0x54];
};

struct NonFactoryProduct : RBXBase {
    char pad54[8];
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    char f70;
    char pad71[3];
    int f74;
    char pad78[8];
    double f80;
    int f88;
    char f8c;
    char pad8d[3];
    int f90;
    int f94;
    char f98;
    char pad99[3];
    int f9c;
    int fa0;
    int fa4;
    int f58;
    NonFactoryProduct(char);
};

extern "C" void __cdecl sub_6305DA();
extern "C" void* __cdecl sub_62FEF6(int);
extern "C" void __cdecl sub_591C60(void*, const void*);

NonFactoryProduct::NonFactoryProduct(char arg) {
    sub_6305DA();
    *(void**)((char*)this + 0x54) = (void*)0x793210;
    *(void**)this = (void*)0x7934C4;
    *(void**)((char*)this + 0x54) = (void*)0x7934B4;
    f5c = 0;
    f60 = 0;
    f64 = 0;
    f68 = 0;
    f6c = 0;
    f70 = 1;
    f74 = 0;
    f80 = *(double*)0x7934A8;
    *(char*)((char*)this + 0x78) = arg;
    *(char*)((char*)this + 0x79) = 0;
    *(char*)((char*)this + 0x7a) = 0;
    *(char*)((char*)this + 0x7b) = 1;
    void* p = sub_62FEF6(0x20040);
    if (p == 0) {
        sub_591C60(p, (const void*)0x79349C);
    } else {
        p = 0;
    }
    f88 = (int)p;
    f8c = 0;
    f90 = 0;
    f94 = 0;
    f98 = 0;
    f9c = 0;
    fa0 = 0;
    fa4 = 0;
    f58 = 2;
}
