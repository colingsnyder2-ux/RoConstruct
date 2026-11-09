// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Control {
    long reserved;
    volatile long references;
    void addRef();
};

inline void Control::addRef()
{
    volatile long* count = &references;
    _ReadWriteBarrier();
    _InterlockedExchangeAdd(count, 1);
}

struct Shared {
    void* object;
    Control* control;
    Shared(const Shared&);
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        control->addRef();
}

struct Pair {
    Shared first;
    Shared second;
    ~Pair();
};

struct Data {
    int value;
    Pair pair;
};

struct S {
    S(Data, int);
    void initialize(Data, int);
};

S::S(Data data, int)
{
    initialize(data, 0);
}
