// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

void* __cdecl operator new(unsigned int);
extern void* __cdecl getType();

struct Control {
    void* table;
    volatile long references;
};

struct Argument {
    void* object;
    Control* control;
    Argument(const Argument&);
};

inline Argument::Argument(const Argument& other)
    : object(other.object), control(other.control) {
    if (control) {
        volatile long* count = &control->references;
        _InterlockedIncrement(count);
    }
}

struct Arguments {
    const Argument& get();
};

struct Value {
    virtual ~Value();
};

struct BooleanValue : Value {
    bool value;
    BooleanValue(bool);
    virtual ~BooleanValue();
};

inline BooleanValue::BooleanValue(bool v) : value(v) {}

struct Owner {
    Value* pointer;
    explicit Owner(Value*);
    ~Owner();
    void transfer(Owner&);
};

inline Owner::Owner(Value* p) : pointer(p) {}

inline Owner::~Owner() {
    if (pointer)
        delete pointer;
}

inline void Owner::transfer(Owner& other) {
    if (&other != this) {
        Value* previous = pointer;
        pointer = other.pointer;
        other.pointer = previous;
    }
}

struct Result {
    void* type;
    Owner value;
};

struct Descriptor {
    unsigned char padding[56];
    bool (__thiscall* callback)(void*, Argument);
    int adjustment;
    void invoke(void*, Result*, Arguments*);
};

void Descriptor::invoke(void* object, Result* result, Arguments* arguments) {
    bool value = callback(
        static_cast<char*>(object) + adjustment,
        arguments->get());
    result->type = getType();
    Owner& destination = result->value;
    Owner temporary(new BooleanValue(value));
    destination.transfer(temporary);
}
