// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

inline void increment(volatile long* count)
{
    _InterlockedIncrement(count);
}

struct Control {
    void* reserved;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        increment(&control->references);
}

struct S {
    void (__cdecl *callback)(Shared, Shared);
    Shared first;
    Shared second;

    void f();
};

void S::f()
{
    callback(first, second);
}
