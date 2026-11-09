// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
};

struct Shared {
    void* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

struct Argument {
    void* value;
    Argument(const Argument&);
};

struct Triple {
    void* value;
    Shared shared;
    Triple(int, Argument, Shared);
    Triple(const Triple&);
};

struct Result {
    int key;
    Triple value;
    Result(int, const Triple&);
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

inline Argument::Argument(const Argument& other)
    : value(other.value)
{
}

inline Triple::Triple(const Triple& other)
    : value(other.value), shared(other.shared)
{
}

inline Result::Result(int k, const Triple& v)
    : key(k), value(v)
{
}

Result __cdecl makeResult(int key, int argument, Argument value, Shared shared)
{
    return Result(key, Triple(argument, value, shared));
}
