// from server: 100% by king_originala
struct GuardData {
    int first;
    int second;
    int third;

    GuardData();
    void acquire(void*);
    ~GuardData();
};

inline GuardData::GuardData()
{
    first = 0;
    second = 0;
}

struct Guard {
    GuardData data;
    Guard(void*);
};

inline Guard::Guard(void* value)
{
    data.third = 0;
    data.acquire(value);
}

struct Argument {
    char padding[0x14];
    int value;
};

struct Interface {
    virtual void first();
    virtual void second();
    virtual int invoke(int*);
};

struct Context {
    char padding[0x198];
    void* value;
};

struct Owner {
    char padding[0x18];
    Interface* object;
};

struct Item {
    char padding[0x128];
    Context* context;
    Owner* owner;

    int f(Argument*);
};

int Item::f(Argument* argument)
{
    Guard guard(context->value);
    int* value = argument ? &argument->value : 0;
    Owner* currentOwner = owner;
    return currentOwner->object->invoke(value);
}
