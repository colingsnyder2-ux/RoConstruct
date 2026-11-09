// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    static const Vector3& zero() { static Vector3 v(0.0f, 0.0f, 0.0f); return v; }
};
}
namespace RBX {
class Item {
public:
    G3D::Vector3 a;
    G3D::Vector3 b;
    float c;
    Item();
};
Item::Item() : a(G3D::Vector3::zero()), b(0.0f, 0.0f, 0.0f), c(1.0f) {}
}
