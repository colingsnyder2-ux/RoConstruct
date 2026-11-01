// from server: 100% by colin
struct Resource {
    virtual ~Resource();
};

struct Value {
    void* type;
    Resource* data;

    Value();
    ~Value();
};

inline Value::~Value()
{
    if (data)
        delete data;
}

struct Property {
    virtual void slot0();
    virtual bool excluded();
    virtual bool readOnly();
    virtual void slot3();
    virtual void read(void* object, Value* value);
};

struct Result {
    void finish();
};

struct Container {
    Result* store(Property** property, Value* value);
};

struct S {
    unsigned long reserved;
    char* object;
    char padding[16];
    Container values;

    void f(Property* property);
};

void S::f(Property* property)
{
    if (property->excluded())
        return;
    if (property->readOnly())
        return;

    Value value;
    property->read(object ? object + 20 : 0, &value);
    Property* p = property;
    values.store(&p, &value)->finish();
}
