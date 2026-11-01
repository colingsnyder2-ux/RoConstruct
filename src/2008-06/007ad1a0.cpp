// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3(const Vector3&);
};

__forceinline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

extern const Vector3& __cdecl unitVector();

struct Pointer {
    void* value;
    Pointer();
    ~Pointer();
};

__forceinline Pointer::Pointer() : value(0)
{
}

struct Base {
    virtual ~Base();
};

struct MaterialPtr {
    void* object;
    void* count;
};

extern void (__thiscall *constructMaterialPtr)(MaterialPtr*, void*);

struct S : Base {
    bool enabled;
    Pointer object;
    Pointer count;
    Vector3 color;
    float a, b, c, d;
    MaterialPtr material;

    S();
    virtual ~S();
};

S::S()
    : enabled(true), color(unitVector()),
      a(0.0f), b(0.0f), c(0.0f), d(0.0f)
{
    constructMaterialPtr(&material, 0);
}
