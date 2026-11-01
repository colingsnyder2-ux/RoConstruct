// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

__forceinline void increment(volatile long* value)
{
    _InterlockedExchangeAdd(value, 1);
}

struct Control {
    long unused;
    volatile long references;
};

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        increment(&control->references);
}

struct Vector {
    float x, y, z;

    Vector(const Vector&);
};

__forceinline Vector::Vector(const Vector& other)
    : x(other.x), y(other.y), z(other.z)
{
}

struct VectorArgument {
    const Vector& get();
};

struct SharedArgument {
    const Shared& get();
};

struct VirtualBase {
};

struct Target : virtual VirtualBase {
};

typedef void (Target::*Method)(Vector, Shared);

struct Object {
    char padding[0x150];
    Target target;
};

struct Descriptor {
    char padding[0x38];
    Method method;

    void invoke(Object*, void*, VectorArgument*, SharedArgument*);
};

void Descriptor::invoke(Object* object, void*, VectorArgument* vector,
                        SharedArgument* shared)
{
    (object->target.*method)(vector->get(), shared->get());
}
