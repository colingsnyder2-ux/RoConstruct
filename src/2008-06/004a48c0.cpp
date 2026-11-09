// from server: 45% by king_originala
struct Object {
    virtual ~Object();
};

struct Value {
    void* data;
    Object* owned;
    char padding[12];

    Value(const Value&);
    Object** get();
    ~Value();
};

inline Value::~Value()
{
    if (owned)
        delete owned;
}

struct __multiple_inheritance Receiver;

struct Descriptor {
    char padding[56];
    void (Receiver::*callback)(Object*);

    void invoke(Receiver*& instance, const Value& argument);
};

void Descriptor::invoke(Receiver*& instance, const Value& argument)
{
    Receiver* receiver = instance;
    Value value(argument);
    Object* object = *value.get();
    (receiver->*callback)(object);
}
