// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

inline void add_reference(volatile long* count)
{
    _InterlockedExchangeAdd(count, 1);
}

struct Control {
    long reserved;
    volatile long references;
};

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        add_reference(&control->references);
}

struct Ref {
    unsigned long data[4];

    Ref(const Ref&);
    ~Ref();
};

struct S {
    Shared shared;
    Ref first;
    Ref second;
    unsigned char flag;

    S(const S&);
};

S::S(const S& other)
    : shared(other.shared),
      first(other.first),
      second(other.second),
      flag(other.flag)
{
}
