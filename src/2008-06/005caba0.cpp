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
    long strong;
    long weak;
};

struct Object
{
    char padding[0x130];
    int value;
};

struct Shared
{
    Object* object;
    Control* control;
    ~Shared();
};

__forceinline Shared::~Shared()
{
    Control* p = control;
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

struct Weak
{
    Object* object;
    Control* control;
    Shared lock() const;
};

struct S
{
    char padding[0x20];
    Weak weak;
    int f();
};

int S::f()
{
    return (weak.control ? weak.control->strong : 0) == 0
        ? 0
        : weak.lock().object->value;
}
