// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

__forceinline void increment(volatile long* counter)
{
    _InterlockedExchangeAdd(counter, 1);
}

struct Control {
    long reserved;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        increment(&control->references);
}

struct Element {
    char storage[0x4c];

    Element();
    ~Element();
};

struct S {
    Shared owner;
    char reserved[8];
    double value;
    unsigned first;
    unsigned second;
    Element elements[8];

    S(const Shared&);
};

S::S(const Shared& source)
    : owner(source), value(0.0), first(0), second(0)
{
}
