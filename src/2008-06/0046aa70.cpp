// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control {
    long unused;
    volatile long references;
    void addReference();
};

__forceinline void Control::addReference()
{
    volatile long* count = &references;
    _InterlockedExchangeAdd(count, 1);
}

struct Service {
    void f();
};

struct Object {
    char padding[0x204];
    Service* service;
};

struct Shared {
    Object* object;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        control->addReference();
}

struct Guard {
    unsigned long storage[3];
    Guard(Shared value);
    ~Guard();
};

struct Action {
    unsigned long storage;
    void apply(unsigned long argument, Object* object);
};

struct S {
    char padding[0x24];
    Shared value;
    void f(unsigned long argument);
};

void S::f(unsigned long argument)
{
    Guard guard(value);
    Object* target = value.object;
    Action action;
    action.apply(argument, target);
    Object* object = value.object;
    Service* service = object ? object->service : 0;
    service->f();
}
