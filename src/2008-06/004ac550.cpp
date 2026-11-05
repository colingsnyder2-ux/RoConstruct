// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    Control* c = control;
    if (c)
        _InterlockedIncrement(&c->strong);
}

inline Shared::~Shared()
{
    Control* c = control;
    if (c && _InterlockedDecrement(&c->strong) == 0)
    {
        c->dispose();
        if (_InterlockedDecrement(&c->weak) == 0)
            c->destroy();
    }
}

struct S_func_004ac550
{
    typedef bool (__thiscall *Function)(void*, Shared);

    Function function;
    int adjustment;

    bool f(char* object, Shared argument);
};

bool S_func_004ac550::f(char* object, Shared argument)
{
    return function(object + adjustment, argument);
}
