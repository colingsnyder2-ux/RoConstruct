// from server: 29% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Obj {
    char pad0[0x94];
    unsigned char f94;
    float f98;
    float f9c;
    float fa0;
    float fa4;
    float fa8;
    float fac;
};

struct Ref {
    void** vtbl;
    volatile long ref1;
    volatile long ref2;
};

struct Adapter {
    void method1(Obj* o, int a);
    void method2(Obj* o, int a);
    void method3(Obj* o, int a);
    void method4(Obj* o, int a);
    void run(int a, int b, int c);
};

extern "C" void __cdecl sub_95e840(void*, void*);
extern "C" void __cdecl sub_95e870(void*, void*);
extern "C" void __cdecl sub_95e8a0(void*, void*);
extern "C" float __cdecl sub_7136a0(Obj*);
extern "C" float __cdecl sub_7136e0(Obj*);
extern "C" float __cdecl sub_713720(Obj*);
extern "C" float __cdecl sub_6fb660(Obj*);
extern "C" float __cdecl sub_6fb620(Obj*);

void Adapter::run(int a, int b, int c)
{
    Ref* r1 = 0;
    Ref* r2 = 0;
    Ref* r3 = 0;
    Ref* r4 = 0;

    sub_95e840(&r1, &r4);
    if (r1) {
        Obj* o = (Obj*)r1;
        float x = o->f98;
        float y = o->f9c;
        float z = o->fa0;
        float w = sub_7136a0(o);
        float u = sub_7136e0(o);
        float v = sub_713720(o);
        unsigned char b94 = o->f94;
        method1(o, a);
    } else {
        sub_95e870(&r2, &r4);
        if (r2) {
            Obj* o = (Obj*)r2;
            float x = o->fa4;
            float y = o->fa8;
            float z = o->fac;
            unsigned char b94 = o->f94;
            float x2 = o->f98;
            float y2 = o->f9c;
            float z2 = o->fa0;
            float w = sub_6fb660(o);
            float u = sub_6fb620(o);
            method2(o, a);
        } else {
            sub_95e8a0(&r3, &r4);
            if (r3) {
                Obj* o = (Obj*)r3;
                unsigned char b94 = o->f94;
                float x = o->f98;
                float y = o->f9c;
                float z = o->fa0;
                method3(o, a);
            }
            if (r3) {
                if (_InterlockedExchangeAdd(&r3->ref1, -1) == 1) {
                    ((void (__thiscall*)(Ref*))r3->vtbl[1])(r3);
                    if (_InterlockedExchangeAdd(&r3->ref2, -1) == 1) {
                        ((void (__thiscall*)(Ref*))r3->vtbl[2])(r3);
                    }
                }
            }
        }
        if (r2) {
            if (_InterlockedExchangeAdd(&r2->ref1, -1) == 1) {
                ((void (__thiscall*)(Ref*))r2->vtbl[1])(r2);
                if (_InterlockedExchangeAdd(&r2->ref2, -1) == 1) {
                    ((void (__thiscall*)(Ref*))r2->vtbl[2])(r2);
                }
            }
        }
    }
    if (r1) {
        if (_InterlockedExchangeAdd(&r1->ref1, -1) == 1) {
            ((void (__thiscall*)(Ref*))r1->vtbl[1])(r1);
            if (_InterlockedExchangeAdd(&r1->ref2, -1) == 1) {
                ((void (__thiscall*)(Ref*))r1->vtbl[2])(r1);
            }
        }
    }
    if (r4) {
        if (_InterlockedExchangeAdd(&r4->ref1, -1) == 1) {
            ((void (__thiscall*)(Ref*))r4->vtbl[1])(r4);
            if (_InterlockedExchangeAdd(&r4->ref2, -1) == 1) {
                ((void (__thiscall*)(Ref*))r4->vtbl[2])(r4);
            }
        }
    }
}
