// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

bool __cdecl func_0060a2f0();
extern unsigned char table_00845de4[];

inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;

    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Pair
{
    void* object;
    Control* control;

    Pair(void* p, Control* c);
    void release();
};

inline Pair::Pair(void* p, Control* c) : object(p), control(c)
{
    if (c)
        _InterlockedIncrement(&c->strong);
}

inline void Pair::release()
{
    if (control)
        control->release();
}

struct S
{
    void* table;
    unsigned int reserved;
    Pair value;

    S* f(Pair p, unsigned int unused);
};

S* S::f(Pair p, unsigned int)
{
    table = 0;

    if (!reinterpret_cast<bool (__cdecl *)(Pair*)>(func_0060a2f0)(&p))
    {
        new (&value) Pair(p.object, p.control);
        table = table_00845de4;
    }
    else
    {
        table = 0;
    }

    p.release();
    return this;
}
