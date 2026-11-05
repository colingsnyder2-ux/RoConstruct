// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

__forceinline void addReference(volatile long *count)
{
    _InterlockedExchangeAdd(count, 1);
}

struct Control {
    void *vtable;
    volatile long references;
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
        addReference(&control->references);
}

struct InsertResult {
    void *node;
    void *container;
    bool inserted;
};

struct Tree {
    InsertResult insert(void *const &);
};

struct Owner {
    char padding[0x2c90];
    Tree tree;
};

struct Base {
    Owner *owner;

    Base(Owner *);
};

__forceinline Base::Base(Owner *value)
    : owner(value)
{
}

struct S : Base {
    Shared shared;

    virtual ~S();
    S(Owner *, const Shared &);
};

S::S(Owner *value, const Shared &source)
    : Base(value), shared(source)
{
    void *object = source.object;
    value->tree.insert(object);
}
