// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct Pointer
{
    void* object;
    Control* control;

    ~Pointer();
};

inline Pointer::~Pointer()
{
    if (control)
    {
        Control* c = control;
        if (_InterlockedDecrement(&c->strong) == 0)
        {
            c->dispose();
            if (_InterlockedDecrement(&c->weak) == 0)
                c->destroy();
        }
    }
}

struct S
{
    void* object;
    Control* control;
    void* extra;

    S(Pointer p, void* e);
};

S::S(Pointer p, void* e)
{
    object = p.object;
    control = p.control;
    if (p.control)
        _InterlockedIncrement(&p.control->strong);
    extra = e;
}
