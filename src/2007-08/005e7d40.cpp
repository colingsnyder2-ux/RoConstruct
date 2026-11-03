// from server: 100% by EspClaude
// roc 2007-08 005e7d40  RBX::Explosion::render3dAdorn (entered with this = IRenderable subobject:
// age @+0x10, position @+0x14, blastRadius @+0x20 relative to it). Roblox G3D fork: Sphere is polymorphic.
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {}
    inline static const Vector3& zero() { static Vector3 v(0, 0, 0); return v; }
};
class Matrix3 {
public:
    float elt[3][3];
    Matrix3(const Matrix3& rkMatrix);
    static const Matrix3& identity();
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const Vector3& _translation) : rotation(Matrix3::identity()), translation(_translation) {}
};
class Color3 {
public:
    float r, g, b;
    static const Color3& red();
};
class Color4 {
public:
    float r, g, b, a;
    Color4(const Color3& c3, float a = 1.0f) : r(c3.r), g(c3.g), b(c3.b), a(a) {}
    static const Color4& zero();
};
class Sphere {
public:
    Vector3 center;
    float radius;
    Sphere(const Vector3& c, float r) : center(c), radius(r) {}
    virtual ~Sphere() {}
    virtual void unused();
};
}
namespace RBX {
class Adorn {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& c);
    virtual void v14(); virtual void v15();
    virtual void sphere(const G3D::Sphere& sphere, const G3D::Color4& solidColor, const G3D::Color4& wireColor = G3D::Color4::zero());
};
class IRenderable {
public:
    virtual void render3dAdorn(Adorn* adorn);
    int pad[3];
};
class Explosion : public IRenderable {
    float age;
    G3D::Vector3 position;
    float blastRadius;
public:
    virtual void render3dAdorn(Adorn* adorn);
};

void Explosion::render3dAdorn(Adorn* adorn)
{
    adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(position));
    float radius = blastRadius;
    adorn->sphere(G3D::Sphere(G3D::Vector3::zero(), radius), G3D::Color4(G3D::Color3::red()));
}
}
