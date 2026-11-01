// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

class type_info;

typedef bool (__thiscall *TypeEqual)(const type_info*, const type_info&);
extern TypeEqual type_equal;
extern type_info shared_type;

struct TypeDescriptor {
    unsigned char padding[8];
    const type_info* type;
};

struct Holder {
    virtual ~Holder();
    virtual void unused();
    virtual Holder* clone() const;
};

struct Control {
    void* table;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        _InterlockedIncrement(&control->references);
    }
}

extern Shared* __cdecl extract_shared(Holder**);

struct Value {
    TypeDescriptor* descriptor;
    Holder* holder;

    Value(const Value&);
    ~Value();
    Shared* converted();
    Shared get();
};

Value::Value(const Value& other)
{
    descriptor = other.descriptor;
    Holder* source = other.holder;
    Holder* copy;
    if (source)
        copy = source->clone();
    else
        copy = 0;
    holder = copy;
}

Value::~Value()
{
    if (holder)
        delete holder;
}

Shared Value::get()
{
    TypeDescriptor* d = descriptor;
    if (type_equal(&shared_type, *d->type))
        return *extract_shared(&holder);

    Value temporary(*this);
    return *temporary.converted();
}
