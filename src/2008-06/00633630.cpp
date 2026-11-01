// from server: 100% by king_originala
struct Vector3
{
    float x, y, z;

    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    ~Vector3() {}
};

struct CallError
{
    char data[40];

    CallError();
    ~CallError();
};

__declspec(noreturn) void __cdecl raiseCallError(const CallError&);

struct Operations
{
    void (__cdecl *unused)();
    void (__cdecl *invoke)(void*, Vector3);
};

struct BoundPropGetSet
{
    Operations* operations;
    unsigned int reserved;
    char storage[4];

    void set(Vector3 value);
};

void BoundPropGetSet::set(Vector3 value)
{
    if (!operations)
        raiseCallError(CallError());

    operations->invoke(storage, value);
}
