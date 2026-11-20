// from server: 100% by Intel_Inside
// roc 2007-08 00460de0  variant l  size: 146 bytes
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

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
    void* pointer;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
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

struct S;
struct Owner { void detach(S*); };
struct Base { virtual ~Base(); };
inline Base::~Base() {}
struct S : Base { Shared connection; Owner* owner; virtual ~S(); };
S::~S() { if (owner) owner->detach(this); }
