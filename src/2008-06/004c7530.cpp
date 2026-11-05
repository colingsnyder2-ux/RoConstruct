// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct SourcePtr
{
    void* object;
    Control* control;
    ~SourcePtr();
};

struct Ptr
{
    void* object;
    Control* control;

    Ptr();
    Ptr(const Ptr&);
    ~Ptr();
};

__forceinline SourcePtr::~SourcePtr()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

__forceinline Ptr::Ptr() : object(0), control(0)
{
}

__forceinline Ptr::Ptr(const Ptr& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

__forceinline Ptr::~Ptr()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Source
{
    SourcePtr get() throw();
};

Ptr __cdecl convert(const SourcePtr&) throw();

Ptr __cdecl f(Source* source)
{
    return source ? convert(source->get()) : Ptr();
}
