// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    static const Vector3& zero() { static Vector3 v(0, 0, 0); return v; }
};
class Matrix3 {
public:
    float elt[3][3];
    Matrix3(const Matrix3& m);
    static const Matrix3& identity();
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const Vector3& t) : rotation(Matrix3::identity()), translation(t) {}
};
class Color3 { public: float r, g, b; static const Color3& red(); };
class Color4 {
public:
    float r, g, b, a;
    Color4(const Color3& c, float _a = 1.0f) : r(c.r), g(c.g), b(c.b), a(_a) {}
    static const Color4& clear();
};
class Sphere {
public:
    Vector3 center;
    float radius;
    Sphere(const Vector3& c, float r) : center(c), radius(r) {}
    virtual ~Sphere() {}
};
}
using namespace G3D;
namespace RBX {
class Adorn {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void setObjectToWorldMatrix(const CoordinateFrame& cf);
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual void sphere(const Sphere& s, const Color4& c, const Color4& outline);
};
class ExplosionAdorn {
public:
    char pad[0x20];
    Vector3 position;
    float radius;
    void render3dAdorn(Adorn* adorn);
};
void ExplosionAdorn::render3dAdorn(Adorn* adorn)
{
    adorn->setObjectToWorldMatrix(CoordinateFrame(position));
    float r = radius;
    adorn->sphere(Sphere(Vector3::zero(), r), Color4(Color3::red()), Color4::clear());
}
}
