// from server: 22% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    volatile long ref1;
    volatile long ref2;
};

struct Inner {
    char pad[0x28];
    int field_28;
    char pad2[0x38 - 0x2c];
    int field_38;
};

struct Outer {
    char pad[0x178];
    Inner inner;
};

struct Holder {
    RefCounted* ptr;
};

extern "C" Holder* __cdecl sub_79bc80(Holder* out, void* arg);

extern "C" void __cdecl sub_5cd0f0(void* self, int* out);

void __cdecl sub_5cf6c0(void* a, void* b, double d, double* out) {
    RefCounted* esi;
    if (a) {
        esi = (RefCounted*)((char*)a + 0x108);
    } else {
        esi = 0;
    }
    Holder h;
    Holder* r = sub_79bc80(&h, b);
    bool bl = (*((RefCounted**)r) != esi);
    RefCounted* eax = h.ptr;
    if (eax) {
        if (_InterlockedExchangeAdd(&eax->ref1, -1) == 0) {
            eax->unknown1();
            if (_InterlockedExchangeAdd(&eax->ref2, -1) == 0) {
                eax->unknown2();
            }
        }
    }
    if (bl) {
        RefCounted* p = (RefCounted*)b;
        if (p) {
            if (_InterlockedExchangeAdd(&p->ref1, -1) == 0) {
                p->unknown1();
                if (_InterlockedExchangeAdd(&p->ref2, -1) == 0) {
                    p->unknown2();
                }
            }
        }
    } else {
        Outer* o = (Outer*)b;
        int tmp = 0;
        sub_5cd0f0(&o->inner.field_28, &tmp);
        double v = (double)tmp;
        if (tmp < 0) v += 4294967296.0;
        *out = v;
        int f38 = o->inner.field_38;
        double v2 = (double)f38;
        if (f38 < 0) v2 += 4294967296.0;
        *out = v / v2;
        RefCounted* p = (RefCounted*)b;
        if (p) {
            if (_InterlockedExchangeAdd(&p->ref1, -1) == 0) {
                p->unknown1();
                if (_InterlockedExchangeAdd(&p->ref2, -1) == 0) {
                    p->unknown2();
                }
            }
        }
    }
}
