// from server: 100% by king_originala
struct GuardBase {
    int a;
    int b;

    GuardBase() : a(0), b(0) {}
    ~GuardBase();
    void acquire(void*);
};

struct Guard : GuardBase {
    int c;

    Guard(void* p) : c(0) { acquire(p); }
};

struct Interface {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void apply(void*, void*) = 0;
};

struct Provider {
    char padding[0x198];
    void* value;
};

struct Holder {
    char padding[0x18];
    Interface* object;
};

struct Argument {
    char padding[0x14];
    char value;
};

struct Item {
    char padding[0x134];
    Provider* provider;
    Holder* holder;

    void* f(void*, Argument*);
};

void* Item::f(void* result, Argument* argument)
{
    Guard guard(provider->value);
    void* value = argument ? &argument->value : 0;
    Holder* active = holder;
    Interface* object = active->object;
    object->apply(result, value);
    return result;
}
