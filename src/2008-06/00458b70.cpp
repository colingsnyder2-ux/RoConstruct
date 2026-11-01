// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
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

struct Count
{
    Control* control;

    Count();
    Count(const Count&);
    ~Count();
};

inline Count::Count() : control(0)
{
}

inline Count::Count(const Count& other) : control(other.control)
{
    if (control)
        _InterlockedExchangeAdd(&control->strong, 1);
}

inline Count::~Count()
{
    if (control)
        control->release();
}

struct Shared
{
    void* object;
    Count count;

    Shared();
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared() : object(0), count()
{
}

inline Shared::Shared(const Shared& other)
    : object(other.object), count(other.count)
{
}

inline Shared::~Shared()
{
}

struct Base
{
    virtual ~Base();
    unsigned char reserved[0x374];
};

struct First
{
    virtual ~First();
    unsigned char reserved[0x20];
};

struct Second
{
    virtual ~Second();
    unsigned char reserved[0x24];
};

struct S : Base, First, Second
{
    Shared first;
    Shared second;

    virtual ~S();
    void reset(Shared);
};

S::~S()
{
    reset(Shared());
}
