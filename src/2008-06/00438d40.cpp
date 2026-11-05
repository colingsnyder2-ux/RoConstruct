// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Control {
    int unused;
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
    if (control) {
        volatile long* references = &control->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(references, 1);
    }
}

struct Iterator {
    void* unused;
    Shared* current;
};

struct Functor {
    int first;
    int second;
    int third;
    int fourth;

    void invoke(int*, Shared);
};

Functor apply(Iterator first, Iterator last, Functor function)
{
    Shared* current = first.current;
    Shared* end = last.current;
    for (; current != end; ++current)
        function.invoke(&function.third, *current);
    return function;
}
