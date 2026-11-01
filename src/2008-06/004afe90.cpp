// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ReferenceCount {
    volatile long value;
    void increment();
};

__forceinline void ReferenceCount::increment()
{
    _InterlockedExchangeAdd(&value, 1);
}

struct Control {
    long reserved;
    ReferenceCount references;
};

struct Shared {
    void *object;
    Control *control;

    Shared(const Shared &);
    ~Shared();
};

__forceinline Shared::Shared(const Shared &other)
    : object(other.object), control(other.control)
{
    if (control)
        control->references.increment();
}

struct InsertResult {
    unsigned int storage[3];
};

struct Tree {
    InsertResult insert(void *const &);
};

struct Owner {
    char padding[0x2cb0];
    Tree tree;
};

struct Base {
    Owner *owner;

    Base(Owner *);
};

__forceinline Base::Base(Owner *p)
    : owner(p)
{
}

struct S : Base {
    Shared shared;

    S(Owner *, const Shared &);
    virtual ~S();
};

S::S(Owner *p, const Shared &value)
    : Base(p), shared(value)
{
    void *key = value.object;
    p->tree.insert(key);
}
