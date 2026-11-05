// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void *object;
    Control *control;
    ~Shared();
};

struct Adjusted
{
    void *object;
    Control *control;
    Adjusted(const Shared &);
    Adjusted(const Adjusted &);
    ~Adjusted();
};

struct Instance
{
    void sub_489810();
};

extern "C" Instance *__stdcall sub_493760(int, const char *);
extern Shared __cdecl sub_5690f0();
extern void __cdecl sub_5aa730(void *, Adjusted);

__forceinline Shared::~Shared()
{
    Control *p = control;
    if (p)
    {
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

__forceinline Adjusted::Adjusted(const Shared &p)
{
    object = p.object ? (char *)p.object + 20 : 0;
    control = p.control;
    if (control)
        _InterlockedIncrement(&control->strong);
}

__forceinline Adjusted::Adjusted(const Adjusted &p)
{
    object = p.object;
    control = p.control;
    if (control)
        _InterlockedIncrement(&control->strong);
}

__forceinline Adjusted::~Adjusted()
{
    Control *p = control;
    if (p)
    {
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

int __cdecl f(void *state)
{
    sub_493760(1, "settings()")->sub_489810();
    sub_5aa730(state, Adjusted(sub_5690f0()));
    return 1;
}
