// from server: 49% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall LeaveCriticalSection(void*);

struct CRefCounted {
    long refcount;
};

struct CValue {
    void* vptr;
    unsigned char flag;
    void* ptr;
};

struct CInner {
    virtual float getA();
    virtual float getB();
};

struct CInner2 {
    virtual void* getPtr();
};

struct CObj {
    char pad0[0x68];
    void* field68;
    void* field6c;
    char pad70[0x10];
    double field80;
    char pad88[0x18];
    CInner* fieldA0;

    void method();
};

struct CSub {
    char pad0[0x188];
    void* field188;
};

struct CSub2 {
    char pad0[0x228];
    virtual void* getPtr();
};

struct CSub3 {
    char pad0[0x180];
};

struct CSub4 {
    char pad0[0xec];
    float fieldEC;
};

struct CSub5 {
    char pad0[0xe8];
    float fieldE8;
};

struct CSub6 {
    char pad0[0xf4];
    float fieldF4;
};

struct CSub7 {
    char pad0[0xf0];
    float fieldF0;
};

struct CSub8 {
    char pad0[0x10];
    virtual void method(float, float, void*);
};

struct CSub9 {
    virtual void method2();
};

extern "C" void* __cdecl sub_40F060();
extern "C" void __cdecl sub_41D870(void*);
extern "C" void __cdecl sub_40D550(void*);
extern "C" void __cdecl sub_444DD0(void*);
extern "C" void __cdecl sub_457C90(void*, void*, void*);
extern "C" void __cdecl sub_457F10(void*, void*);
extern "C" float __cdecl sub_4582E0(void*);
extern "C" void __cdecl sub_5595A0(void*);

extern double g_7934A8;
extern double g_793618;
extern double g_793610;
extern double g_793608;
extern double g_793600;
extern void* g_8BC078;
extern unsigned int g_8B5188;

void CObj::method()
{
    CValue val;
    val.vptr = &g_8BC078;
    val.flag = 0;
    sub_41D870(&val);

    if (g_7934A8 == field80) {
        if (val.flag) {
            LeaveCriticalSection(val.ptr);
        }
        return;
    }

    double old80 = field80;
    field80 = g_7934A8;

    if (val.flag) {
        LeaveCriticalSection(val.ptr);
    }

    if (fieldA0 == 0) {
        return;
    }
    if (field68 == 0) {
        return;
    }

    void* p68 = field68;
    void* p6c = field6c;
    if (p6c != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p6c + 4), 1);
    }

    sub_40D550(&p68);

    float f1 = fieldA0->getA();
    float f2 = fieldA0->getB();

    if (old80 < g_793618) {
        f1 = (float)(g_793610 * f1);
        f2 = (float)(g_793610 * f2);
    } else if (old80 > g_793608) {
        f1 = (float)(g_793600 * f1 + 1.0);
        f2 = (float)(g_793600 * f2 + 1.0);
    }

    CSub4* s4 = (CSub4*)sub_40F060();
    float v4 = s4->fieldEC;
    if (f1 == v4) {
        f1 = v4;
    }

    CSub5* s5 = (CSub5*)sub_40F060();
    float v5 = s5->fieldE8;
    if (f1 == v5) {
        f1 = v5;
    }

    CSub6* s6 = (CSub6*)sub_40F060();
    float v6 = s6->fieldF4;
    if (f2 == v6) {
        f2 = v6;
    }

    CSub7* s7 = (CSub7*)sub_40F060();
    float v7 = s7->fieldF0;
    if (f2 == v7) {
        f2 = v7;
    }

    CSub* sub = (CSub*)field68;
    if (sub->field188 != 0) {
        CSub2* sub2 = (CSub2*)sub->field188;
        if (sub2->getPtr() != 0) {
            CSub2* sub2b = (CSub2*)((CSub*)field68)->field188;
            void* r = sub2b->getPtr();
            sub_457F10(r, 0);
            CSub2* sub2c = (CSub2*)((CSub*)field68)->field188;
            void* r2 = sub2c->getPtr();
            sub_457C90((char*)r2 + 0x180, &f1, 0);
            float f3 = sub_4582E0(&f1);
            CSub8* s8 = (CSub8*)fieldA0;
            void* r3 = sub_40F060();
            sub_444DD0(r3);
            s8->method(f1, f2, r3);
        }
    }

    sub_5595A0(&val);
}
