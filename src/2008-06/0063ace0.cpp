// from server: 100% by king_originala
struct Vector3
{
    float x, y, z;

    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Signal
{
    void fire(char* context, Vector3 value);
};

struct Entry
{
    char padding[0x10];
    Signal signal;
};

struct Registry
{
    Entry* find(void* key);
};

extern Registry registry;

struct S
{
    char padding[0x14];
    char key[0x11c];
    float x, y, z;

    void update(void* unused);
};

void S::update(void*)
{
    void* identity = this ? key : 0;
    Vector3 value(x, y, z);
    Entry* entry = registry.find(identity);
    if (entry)
    {
        char context;
        entry->signal.fire(&context, value);
    }
}
