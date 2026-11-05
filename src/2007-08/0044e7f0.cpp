// from server: 28% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall func_0062ff7a(const char*);
extern "C" void* __stdcall func_0077e698();
extern "C" void __stdcall func_0077e6ac(void*);
extern "C" void* __cdecl func_00403800(void*);

struct RefCounted
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    long refcount;
    long weakcount;
};

struct CRobloxDoc
{
    char pad[0x78];
    void* field_78;
    void sub_44e7f0(const char*);
};

void CRobloxDoc::sub_44e7f0(const char* name)
{
    func_0062ff7a(name);
    if (field_78 != 0)
    {
        void* local = func_0077e698();
        void* out = 0;
        func_00403800(&out);
        RefCounted* p = *(RefCounted**)&out;
        p->slot2();
        if (p != 0)
        {
            if (_InterlockedExchangeAdd(&p->refcount, -1) == 1)
            {
                p->slot1();
                if (_InterlockedExchangeAdd(&p->weakcount, -1) == 1)
                {
                    p->slot2();
                }
            }
        }
        func_0077e6ac(&local);
    }
}
