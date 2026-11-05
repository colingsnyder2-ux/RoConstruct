// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
    void weak_release();
};

inline void Control::weak_release()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        weak_release();
    }
}

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct S {
    void helper(void*);
    void f(int, Shared);
};

void S::f(int, Shared value)
{
    reinterpret_cast<S*>(reinterpret_cast<char*>(this) - 0x178)
        ->helper(value.object);
}
