// from server: 32% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CStandardOutputView_Sub
{
    void* vptr;
    int refcount1;
    int refcount2;
};

struct CStandardOutputView_Base
{
    void* vptr;
};

struct CStandardOutputView
{
    void* vptr;
    char pad[0xf0 - 4];
    unsigned char flag_f0;
    char pad2[0xf8 - 0xf1];
    void* field_f8;
    void* field_fc;
    void* field_100;
    void* field_104;
    void* field_108;
    void* field_10c;
    CStandardOutputView_Sub* field_110;

    CStandardOutputView* construct();
};

extern "C" void __cdecl func_00461c60();
extern "C" void __cdecl func_004375d0();
extern "C" void __cdecl func_0056c3b0();
extern "C" void __cdecl func_00725750();
extern "C" void __cdecl func_00725770();
extern "C" void __cdecl func_00423240();

CStandardOutputView* CStandardOutputView::construct()
{
    func_00461c60();

    this->vptr = (void*)0x78ce1c;
    this->field_f8 = 0;
    this->field_fc = 0;
    this->field_100 = 0;
    this->field_104 = 0;
    this->field_108 = 0;
    this->field_10c = 0;

    CStandardOutputView_Sub* sub = (CStandardOutputView_Sub*)((char*)this + 0x110);
    this->field_110 = sub;

    func_004375d0();

    this->vptr = (void*)0x78d05c;
    *(void**)((char*)this + 0x110) = (void*)0x78d048;
    this->flag_f0 = 1;

    void* tmp = 0;
    func_0056c3b0();
    void* obj = *(void**)tmp;
    void* obj2 = (char*)obj + 0x20;

    func_00725750();

    if (obj2 != 0)
    {
        if (_InterlockedExchangeAdd((volatile long*)((char*)obj2 + 4), -1) == 1)
        {
            void** vt = *(void***)obj2;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(obj2);
            if (_InterlockedExchangeAdd((volatile long*)((char*)obj2 + 8), -1) == 1)
            {
                void** vt2 = *(void***)obj2;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(obj2);
            }
        }
    }

    void* tmp2 = 0;
    func_0056c3b0();
    void* obj3 = *(void**)tmp2;
    if (obj3 != 0)
    {
        func_00423240();
    }

    if (obj2 != 0)
    {
        if (_InterlockedExchangeAdd((volatile long*)((char*)obj2 + 4), -1) == 1)
        {
            void** vt = *(void***)obj2;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(obj2);
            if (_InterlockedExchangeAdd((volatile long*)((char*)obj2 + 8), -1) == 1)
            {
                void** vt2 = *(void***)obj2;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(obj2);
            }
        }
    }

    func_00725770();

    return this;
}
