// from server: 37% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_403800(void*);
extern "C" void __stdcall sub_40D550(void*);
extern "C" void __stdcall sub_44D890(void*);
extern "C" void __stdcall sub_5595A0(void*);
extern "C" void __stdcall sub_630A1E(void);

extern "C" void* __stdcall sub_77E6A4();
extern "C" void* __stdcall sub_77E6A8();
extern "C" void* __stdcall sub_77E6AC();
extern "C" void* __stdcall sub_77DD98();
extern "C" void* __stdcall sub_77DDAC();
extern "C" void* __stdcall sub_77DDBC();
extern "C" void* __stdcall sub_77D5A4(void*, int, void*);

struct RefCounted
{
    void* vtable;
    volatile long refcount1;
    volatile long refcount2;
};

struct String
{
    void* data[4];
};

struct CRobloxDoc
{
    char pad[0x78];
    void* field_78;
    void method(void*);
};

void CRobloxDoc::method(void* arg)
{
    String s1;
    String s2;
    RefCounted* rc;
    void* local;

    sub_403800(&s1);
    sub_77E6A4();
    rc = *(RefCounted**)&s1;
    local = *(void**)&s1;
    if (rc)
    {
        _InterlockedExchangeAdd(&rc->refcount1, 1);
    }
    sub_40D550(&s2);
    void* vt = *(void**)arg;
    sub_44D890((char*)local + 0x160);
    unsigned char b = 0;
    void* fn = *(void**)vt;
    ((void (__thiscall*)(void*, unsigned char))fn)(arg, b);
    sub_5595A0(&s1);
    sub_77DDAC();
    sub_77E6A8();
    sub_77D5A4(&s2, 0x83, 0);
    void* vt2 = *(void**)arg;
    sub_77DD98();
    void* fn2 = *(void**)((char*)vt2 + 0xc);
    ((void (__thiscall*)(void*, void*))fn2)(arg, 0);
    sub_77DDBC();
    sub_77E6AC();
    if (rc)
    {
        if (_InterlockedExchangeAdd(&rc->refcount1, -1) == 1)
        {
            void* vt3 = *(void**)rc;
            void* fn3 = *(void**)((char*)vt3 + 4);
            ((void (__thiscall*)(void*))fn3)(rc);
            if (_InterlockedExchangeAdd(&rc->refcount2, -1) == 1)
            {
                void* vt4 = *(void**)rc;
                void* fn4 = *(void**)((char*)vt4 + 8);
                ((void (__thiscall*)(void*))fn4)(rc);
            }
        }
    }
}
