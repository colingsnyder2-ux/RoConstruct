// from server: 82% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern void (__cdecl *free_import)(void*);

struct Counts
{
    volatile long strong;
    volatile long weak;
};

struct Obj
{
    virtual void destroy(int flags);
    virtual void slot1();
    virtual bool check();
};

struct Ptr
{
    Obj* p;
    ~Ptr()
    {
        if (p)
        {
            char* a = (char*)p + 5;
            Obj* o = a ? (Obj*)(a - 5) : 0;
            Counts* c = (Counts*)((char*)o - 8);
            if (_InterlockedDecrement(&c->strong) == 0)
            {
                o->destroy(0);
                if (_InterlockedDecrement(&c->weak) == 0)
                    free_import(c);
            }
        }
    }
};

extern Ptr __stdcall func_0070fde0();

bool func_00972eb0()
{
    Ptr sp = func_0070fde0();
    Obj* q = sp.p;
    bool result;
    if (q && q->check())
        result = true;
    else
        result = false;
    return result;
}
