// from server: 35% by atomic.potato
extern "C" void __stdcall sub_6d5c00(int);
extern "C" void* __cdecl sub_80a05e(unsigned int);
extern "C" void __stdcall sub_7aec90(int);
extern "C" float __stdcall sub_7aefc0();
extern "C" float __stdcall sub_7ade70();
extern "C" void __stdcall sub_79b8d0(void*, void*, void*, void*, float, float);
extern "C" void __stdcall sub_74b950();

struct S {
    char pad0[0xc];
    void* p0c;
    void* p10;
    char pad14[0x20];
    char buf34[0x30];
    char buf64[0x68];
    float fcc;
    char padd0[4];
    void* pd0;
    void f(int);
};

void S::f(int a)
{
    sub_7aec90(a);
    void* p = sub_80a05e(0x84);
    void* r = 0;
    if (p != 0) {
        void* e1 = *(void**)((char*)p10 + 0x108);
        void* e2 = *(void**)((char*)p0c + 0x108);
        float f1 = sub_7aefc0();
        float f2 = sub_7ade70();
        sub_79b8d0(e2, e1, buf34, buf64, fcc, f2);
        r = p;
    }
    pd0 = r;
    sub_6d5c00(0xf);
}
