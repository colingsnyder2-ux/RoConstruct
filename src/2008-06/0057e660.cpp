// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

inline long exchangeAdd(volatile long* p, long value)
{
    return _InterlockedExchangeAdd(p, value);
}

inline long decrement(volatile long* p)
{
    return _InterlockedDecrement(p);
}

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;

    void weakRelease();
};

inline void Control::weakRelease()
{
    if (decrement(&weak) == 0)
        destroy();
}

struct Shared
{
    void* px;
    Control* pn;

    Shared();
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared() : px(0), pn(0)
{
}

inline Shared::Shared(const Shared& other) : px(other.px), pn(other.pn)
{
    if (pn)
        exchangeAdd(&pn->strong, 1);
}

inline Shared::~Shared()
{
    if (pn && decrement(&pn->strong) == 0)
    {
        pn->dispose();
        pn->weakRelease();
    }
}

struct List
{
    char padding[12];
    Shared* first;
    Shared* last;

    unsigned int size() const;
    Shared& front();
};

inline unsigned int List::size() const
{
    return static_cast<unsigned int>(last - first);
}

struct S
{
    char padding[340];
    List* children;

    Shared f();
};

Shared S::f()
{
    return children->size() > 0 ? children->front() : Shared();
}
