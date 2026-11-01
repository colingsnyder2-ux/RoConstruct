// from server: 100% by king_originala
struct Vector {
    float x, y, z;
    Vector(const Vector&);
};

inline Vector::Vector(const Vector& v)
    : x(v.x), y(v.y), z(v.z) {}

struct Result {};

struct Signal {
    Result invoke(Vector);
};

struct Object {
    char padding[16];
    Signal signal;
};

struct Base {};

struct Registry {
    Object* find(Base*);
};

extern Registry registry;

struct S {
    char padding0[20];
    Base base;
    char padding1[283];
    Vector position;

    void update(int);
};

void S::update(int)
{
    Base* key = this ? &base : 0;
    Vector value(position);
    Object* object = registry.find(key);
    if (object)
        object->signal.invoke(value);
}
