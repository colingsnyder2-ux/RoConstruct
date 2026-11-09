// from server: 100% by king_originala
struct Vector3
{
    float value[3];
};

struct Storage
{
    unsigned int first;
    unsigned int second;

    Storage();
    ~Storage();
};

inline Storage::Storage() : first(0), second(0) {}

struct Handle : Storage
{
    unsigned int third;

    Handle(void* value);
    void initialize(void* value);
};

inline Handle::Handle(void* value) : third(0)
{
    initialize(value);
}

struct Instance
{
    char padding[0x14];
    char object;
};

struct Accessor
{
    virtual void unused0() = 0;
    virtual void unused1() = 0;
    virtual Vector3 get(void* object) = 0;
    virtual void set(void* object, const Vector3& value) = 0;
};

struct Property
{
    char padding[0x18];
    Accessor* accessor;

    Vector3 get(void* object);
    void set(void* object, const Vector3& value);
};

inline Vector3 Property::get(void* object)
{
    return accessor->get(object);
}

inline void Property::set(void* object, const Vector3& value)
{
    accessor->set(object, value);
}

struct Owner
{
    char padding[0x198];
    void* value;
};

struct Vector3ComponentItem
{
    char padding[0x128];
    Owner* owner;
    Property* property;
    unsigned int component;

    void update(Instance* instance, const Vector3& value);
};

void Vector3ComponentItem::update(Instance* instance, const Vector3& value)
{
    Handle handle(owner->value);
    Vector3 result = property->get(instance ? &instance->object : 0);
    result.value[component] = value.value[component];
    property->set(instance ? &instance->object : 0, result);
}
