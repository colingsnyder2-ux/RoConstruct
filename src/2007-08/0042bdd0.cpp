// from server: 48% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    volatile long ref1;
    volatile long ref2;
};

struct S
{
    char pad0[0xf4];
    void* field_f4;
    void* field_f8;
    int field_fc;
    void* field_100;
    void* field_104;
    void* field_108;
    void method(void* arg1, void* arg2);
};

extern "C" void __stdcall sub_402a60(void* dst, void* src);
extern "C" void* __stdcall sub_42a4e0(void* p);
extern "C" void __stdcall sub_42b620(void* dst, void* src);
extern "C" void* __stdcall sub_42bc60(void* a, int b);
extern "C" void __stdcall sub_412dc0(void* dst, void* src);
extern "C" void __stdcall sub_630b9e(void* a, void* b);
extern "C" void* __stdcall sub_77e698(const char* s);

void S::method(void* arg1, void* arg2)
{
    void* p = arg1;
    void* q = arg2;

    sub_402a60(&field_108, &q);
    field_104 = p;

    void* r;
    if (*(void**)((char*)p + 0xbc) != 0)
        r = sub_42a4e0(*(void**)((char*)p + 0xbc));
    else
        r = p;

    if (r != 0)
        r = (char*)r + 0xa4;
    else
        r = 0;

    void* tmp;
    sub_42b620(&tmp, r);
    int v = *(int*)tmp;
    tmp = (char*)tmp + 4;
    sub_402a60(&field_100, tmp);
    field_fc = v;

    if (tmp != 0)
    {
        RefCounted* obj = (RefCounted*)tmp;
        if (_InterlockedExchangeAdd(&obj->ref1, -1) == 1)
        {
            obj->v1();
            if (_InterlockedExchangeAdd(&obj->ref2, -1) == 1)
                obj->v2();
        }
    }

    if (sub_42bc60(&field_f8, 0) != 0)
    {
        sub_77e698("CLuaHtmlView failed to create CLuaFunction");
        int local14 = 0;
        int local34 = 0;
        sub_412dc0(&local14, &local34);
        sub_630b9e(&local34, (void*)0x8410c0);
    }

    int* e = (int*)field_f8;
    int fc = field_fc;
    e = (int*)((char*)e + 0xc);
    e[0] = fc;
    sub_402a60(&field_100, e + 1);

    void* newPtr;
    if (field_f8 != 0)
        newPtr = (char*)field_f8 + 4;
    else
        newPtr = 0;

    if (field_f4 != newPtr)
    {
        if (newPtr != 0)
        {
            RefCounted* r2 = (RefCounted*)newPtr;
            r2->v1();
        }
        if (field_f4 != 0)
        {
            RefCounted* r3 = (RefCounted*)field_f4;
            r3->v2();
        }
        field_f4 = newPtr;
    }

    if (q != 0)
    {
        RefCounted* r4 = (RefCounted*)q;
        if (_InterlockedExchangeAdd(&r4->ref1, -1) == 1)
        {
            r4->v1();
            if (_InterlockedExchangeAdd(&r4->ref2, -1) == 1)
                r4->v2();
        }
    }
}
