// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Count {
    Control* p;
    Count& operator=(const Count&);
    ~Count();
};

inline Count::~Count()
{
    if (p)
        p->release();
}

struct Pair {
    void* object;
    Count count;
    Pair(const Pair&);
    Pair& operator=(const Pair&);
};

inline Pair& Pair::operator=(const Pair& other)
{
    object = other.object;
    count = other.count;
    return *this;
}

Pair __cdecl acquire(void*);

struct Input {
    char padding[0x148];
    void* source;
};

struct S {
    char padding[0x1a0];
    Pair value;
    void f(Input*);
};

void S::f(Input* input)
{
    void* source = input->source;
    value = acquire(source);
}
