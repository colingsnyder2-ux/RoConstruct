// from server: 100% by king_originala
struct Matrix {
    float elements[9];
};

struct Frame {
    Matrix rotation;
    float x, y, z;

    bool different(const Frame& value);
};

struct Object {
    char prefix[20];
    void notify(void* property);
};

struct Interface {
    char data;
};

struct Concrete : Object, Interface {
};

typedef void (__thiscall *Callback)(void*, void*);

struct S {
    void* reserved0;
    void* property;
    int valueOffset;
    int reserved12;
    Callback callback;
    int callbackOffset;

    void set(Interface* object, const Frame& value);
};

void S::set(Interface* object, const Frame& value)
{
    Concrete* owner = static_cast<Concrete*>(object);
    char* base = reinterpret_cast<char*>(owner);

    if (reinterpret_cast<Frame*>(base + valueOffset)->different(value)) {
        Frame* destination = reinterpret_cast<Frame*>(base + valueOffset);
        destination->rotation = value.rotation;
        destination->x = value.x;
        destination->y = value.y;
        destination->z = value.z;

        if (callback)
            callback(base + callbackOffset, property);

        owner->notify(property);
    }
}
