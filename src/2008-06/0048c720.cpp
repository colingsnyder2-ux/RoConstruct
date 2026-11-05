// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

__forceinline void add_reference(volatile long* count)
{
    _InterlockedExchangeAdd(count, 1);
}

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        add_reference(&control->strong);
}

__forceinline Shared::~Shared()
{
    if (control)
    {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Value
{
    void* object;
    int unused;
};

struct S
{
    void initialize(Shared first, Shared second, void* value);
    S* f(Shared first, Shared second, Value value);
};

S* S::f(Shared first, Shared second, Value value)
{
    initialize(first, second, value.object);
    return this;
}
