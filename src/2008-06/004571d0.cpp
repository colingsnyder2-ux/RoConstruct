// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Holder
{
    Control* control;

    Holder& operator=(const Holder&);
    ~Holder();
};

__forceinline Holder::~Holder()
{
    if (control)
        control->release();
}

struct Pair
{
    void* object;
    Holder owner;

    Pair(const Pair&);
};

Pair __cdecl makePair(void*);

struct S
{
    unsigned long reserved;
    void* object;
    Holder owner;

    void assign(const Pair&);
    void f(void*);
};

__forceinline void S::assign(const Pair& value)
{
    object = value.object;
    owner = value.owner;
}

void S::f(void* argument)
{
    assign(makePair(argument));
}
