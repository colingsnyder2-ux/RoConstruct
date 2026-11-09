// from server: 47% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SysFreeString(void*);
extern "C" void* __cdecl func_00401180(int, int);
extern "C" void __cdecl func_00401000(int);
extern "C" void __cdecl func_0062fc62(void*);
extern "C" void __cdecl func_0042bad0(void*);
extern "C" void __cdecl func_0042c720(void*);

struct CLuaHtmlView
{
    void* vptr;
    int field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    void* field_14;
    void* field_18;
    void* field_1c;
    void* field_20;
    void dtor();
};

void CLuaHtmlView::dtor()
{
    this->vptr = (void*)0x78a590;
    func_0042c720(this->field_1c);

    void* p = this->field_20;
    void* local = 0;
    if (p != 0)
    {
        void** vt = *(void***)p;
        void* fn = vt[0];
        ((void (__stdcall*)(void*, void*, void*))fn)(p, (void*)0x78a224, &local);
    }

    void* bstr = local;
    void* mem = func_00401180(-1, 0x78a580);
    if (mem == 0)
    {
        func_00401000(0x8007000e);
    }

    void* p1c = this->field_1c;
    void** vt2 = *(void***)bstr;
    void* fn2 = vt2[0x10c / 4];
    ((void (__stdcall*)(void*, void*, void*))fn2)(bstr, mem, p1c);

    SysFreeString(mem);

    void* l = local;
    if (l != 0)
    {
        void** vt3 = *(void***)l;
        void* fn3 = vt3[2];
        ((void (__stdcall*)(void*))fn3)(l);
    }

    void* p20 = this->field_20;
    if (p20 != 0)
    {
        void** vt4 = *(void***)p20;
        void* fn4 = vt4[2];
        ((void (__stdcall*)(void*))fn4)(p20);
    }

    void* p1c2 = this->field_1c;
    if (p1c2 != 0)
    {
        void** vt5 = *(void***)p1c2;
        void* fn5 = vt5[2];
        ((void (__stdcall*)(void*))fn5)(p1c2);
    }

    func_0042bad0((char*)this + 0xc);
    void* q = *(void**)((char*)this + 0x10);
    func_0062fc62(q);
    *(void**)((char*)this + 0x10) = 0;

    void* r = this->field_8;
    if (r != 0)
    {
        if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1)
        {
            void** vt6 = *(void***)r;
            void* fn6 = vt6[2];
            ((void (__stdcall*)(void*))fn6)(r);
        }
    }
}
