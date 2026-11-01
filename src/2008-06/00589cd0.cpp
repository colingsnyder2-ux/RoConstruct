// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

__forceinline void increment(volatile long* references)
{
    _InterlockedExchangeAdd(references, 1);
}

struct Control {
    long reserved;
    volatile long references;
};

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        increment(&control->references);
}

struct Tail {
    Tail(const Tail& other);
};

struct S {
    long first;
    Shared firstShared;
    long second;
    Shared secondShared;
    Tail tail;

    S(const S& other);
};

S::S(const S& other)
    : first(other.first),
      firstShared(other.firstShared),
      second(other.second),
      secondShared(other.secondShared),
      tail(other.tail)
{
}
