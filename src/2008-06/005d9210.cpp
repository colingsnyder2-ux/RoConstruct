// from server: 100% by king_originala
struct Rotation
{
    float data[9];
    Rotation(const Rotation&);
};

struct Value
{
    Rotation rotation;
    float x, y, z;

    Value* initialize();
};

struct Object
{
    const Value* getValue();
};

struct Owner
{
    Object* getObject();
};

struct S
{
    Value f();
};

Value S::f()
{
    volatile int zero = 0;
    unsigned char storage[sizeof(Value)];
    Owner* owner = reinterpret_cast<Owner*>(
        reinterpret_cast<unsigned char*>(this) - 0x228);

    const Value* source;
    if (owner->getObject())
        source = owner->getObject()->getValue();
    else
        source = reinterpret_cast<Value*>(storage)->initialize();

    return *source;
}
