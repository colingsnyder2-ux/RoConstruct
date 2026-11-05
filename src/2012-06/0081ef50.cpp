// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl* imp_free)(void*);

struct Counts
{
    volatile long strong;
    volatile long weak;
};

struct Obj
{
    virtual ~Obj();
};

struct Ptr
{
    char* p;
    ~Ptr()
    {
        if (p)
        {
            char* a = p + 5;
            Obj* o = a ? (Obj*)(a - 5) : 0;
            Counts* c = (Counts*)((char*)o - 8);
            if (_InterlockedDecrement(&c->strong) == 0)
            {
                o->~Obj();
                if (_InterlockedDecrement(&c->weak) == 0)
                    imp_free(c);
            }
        }
    }
};

struct S
{
    Ptr m;
    void clear();
    ~S();
};

S::~S()
{
    clear();
}
