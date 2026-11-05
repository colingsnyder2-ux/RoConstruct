// from server: 38% by colin
struct S {
    int f(int a1, int a2);
};

extern "C" void __stdcall VariantClear(void* pvarg);

struct S_func_00662700 {
    int f(int a1, int a2);
};

struct Inner {
    unsigned short w;
    void ctor(unsigned short* p);
    void dtor();
};

struct Mid {
    void ctor();
    void dtor();
};

struct S2 {
    unsigned short field_7c;
    void method(void* p);
};

extern "C" void __cdecl sub_655910(void* a1, unsigned short a2, int a3);

int S::f(int a1, int a2)
{
    Inner inner;
    inner.w = 0;
    inner.ctor((unsigned short*)a2);
    int result = ((S_func_00662700*)this)->f(a1, (int)&inner);
    if (result != 0)
    {
        Mid mid;
        mid.ctor();
        unsigned short v = *(unsigned short*)((char*)this + 0x7c);
        S2* p = (S2*)((char*)this + 0x7c);
        sub_655910(&inner, v, 1);
        mid.dtor();
        p->method(&inner);
    }
    VariantClear(&inner);
    return result;
}
