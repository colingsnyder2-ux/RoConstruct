// from server: 31% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    virtual int f1();
    virtual int f2();
    virtual int f3();
};

struct Obj {
    char pad0[0x100];
    char pad1[0x70];
    int field170;
    char pad2[0x0c];
    int field180;
};

struct Ref {
    Inner* vt;
    long ref1;
    long ref2;
};

extern "C" int __stdcall sub_5fb830(void*, void*);

double sub_005fd030(Obj* a, Inner* b, Ref* c, double d, double* out)
{
    int local = 0;
    Inner* esi;
    if (a)
        esi = (Inner*)((char*)a + 0x100);
    else
        esi = 0;

    int r = b->f1();
    if (r == (int)esi)
    {
        double tmp = d;
        int iv = 0;
        sub_5fb830((char*)b + 0x170, &iv);
        double num = (double)iv;
        if (iv < 0)
            num += *(double*)0x8b17c8;
        *out = num;
        int den = *(int*)((char*)b + 0x180);
        double dnum = (double)den;
        if (den < 0)
            dnum += *(double*)0x8b17c8;
        *out = num / dnum;
        local = -1;
        if (c)
        {
            if (_InterlockedExchangeAdd(&c->ref1, -1) == 1)
            {
                c->vt->f2();
                if (_InterlockedExchangeAdd(&c->ref2, -1) == 1)
                    c->vt->f3();
            }
        }
    }
    else
    {
        local = -1;
        if (c)
        {
            if (_InterlockedExchangeAdd(&c->ref1, -1) == 1)
            {
                c->vt->f2();
                if (_InterlockedExchangeAdd(&c->ref2, -1) == 1)
                    c->vt->f3();
            }
        }
    }
    return 0.0;
}
