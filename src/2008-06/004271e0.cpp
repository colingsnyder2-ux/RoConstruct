// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void add_ref();
    void release();
};

inline void Control::add_ref()
{
    _InterlockedIncrement(&strong);
}

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared
{
    void* object;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        control->add_ref();
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Owner;
typedef void (__thiscall *VirtualFunction)(Owner*);

struct Owner
{
    VirtualFunction* vtable;
    void apply(Shared value);
};

struct CSelectionTreeCtrl
{
    void func_004271e0(Shared first, Shared second);
};

void CSelectionTreeCtrl::func_004271e0(Shared first, Shared second)
{
    reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0xd0)->apply(first);

    Owner* owner = reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0xd0);
    owner->vtable[89](owner);
}
