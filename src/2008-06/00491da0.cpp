// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control {
    long unused;
    volatile long count;
};

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control) {
        volatile long* count = &control->count;
        _InterlockedExchangeAdd(count, 1);
    }
}

struct Bundle {
    Shared first;
    Shared second;

    ~Bundle();
};

struct Argument {
    int value;
    Bundle bundle;
};

struct S {
    void helper(Argument argument, int flag);
    S& f(Argument argument, int flag);
};

S& S::f(Argument argument, int flag)
{
    helper(argument, 0);
    return *this;
}
