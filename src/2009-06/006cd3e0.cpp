// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#pragma float_control(precise, off)
struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
};
struct Color3 { float r, g, b; };
struct Matrix3 {
    float m[9];
    Matrix3(const Matrix3&);
    static const Matrix3& identity();
};
struct CoordinateFrame {
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const Matrix3& r, const Vector3& t) : rotation(r), translation(t) {}
};
struct Extents {
    Vector3 low, high;
    Extents() {}
    Vector3 center() const { return (high + low) * 0.5f; }
    Vector3 size() const { return high - low; }
};
extern const Vector3& __cdecl position();
struct Controller {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* transform();
};
extern void __cdecl apply(const Vector3&, const CoordinateFrame&, void*, void*, const Color3&, int);
struct Owner {
    char padding[0x118];
    Controller controller;
};
struct Base {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual Color3 color();
};
struct Second { virtual void update(void*); };
struct Tool : public Base, public Second {
    char padding[0x10];
    Owner* owner;
    bool adjust(Extents&);
    virtual void update(void*);
};
void Tool::update(void* argument)
{
    Extents e;
    const Vector3& a = position();
    e.low.x = a.x;
    e.low.y = a.y;
    e.low.z = a.z;
    const Vector3& b = position();
    e.high.x = -b.x;
    e.high.y = -b.y;
    e.high.z = -b.z;
    if (adjust(e)) {
        apply(e.size(), CoordinateFrame(Matrix3::identity(), e.center()), owner->controller.transform(), argument, color(), 0x3f);
    }
}
