// from server: 100% by king_originala
struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    int owner;
    float timer;

    Base(void*);
    virtual ~Base();
    int f();
};

struct Property {
    void set(void**, int);
};

struct Object {
    char padding[16];
    Property property;
};

struct Registry {
    Object* find(void*);
};

extern Registry registry;
extern const float initialTimer;

struct FallingDown : Base {
    FallingDown(void*);
    virtual ~FallingDown();
};

FallingDown::FallingDown(void* argument)
    : Base(argument)
{
    int value = f();
    void* key = value ? reinterpret_cast<void*>(value + 20) : 0;
    Object* object = registry.find(key);
    if (object)
        object->property.set(&argument, 1);
    timer = initialTimer;
}
