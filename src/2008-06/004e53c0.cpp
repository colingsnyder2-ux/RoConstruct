// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
};
class AABox { public: G3D::Vector3 lo, hi; };
}

namespace RBX {
namespace RenderBase {
class Mesh {
public:
    Mesh();
    virtual ~Mesh();
    char data0[0x4c];
    G3D::AABox boxA;
    G3D::AABox boxB;
    int first;
    int second;
};
}

extern bool showBevels;
extern int lowQuality;

namespace ViewNew {
class BrickMesh : public RenderBase::Mesh {
public:
    static float bevel;
    BrickMesh(const G3D::Vector3& size, int a, int b, int c, int d, int e, float f);
    void buildBevel(const G3D::Vector3& size, int a, int b, int c, int d, int e, float f);
    void buildFlat(const G3D::Vector3& size, int a, int b);
    static void computeBox(const G3D::Vector3& halfSize, G3D::AABox& b, G3D::AABox& a);
};

BrickMesh::BrickMesh(const G3D::Vector3& size, int a, int b, int c, int d, int e, float f)
{
    second = 1;
    if (c && d && e)
        buildBevel(size, a, b, c, d, e, f);
    else
        buildFlat(size, a, b);
    if (showBevels && !lowQuality) {
        G3D::Vector3 h = size * 0.5f - G3D::Vector3(bevel, bevel, bevel);
        computeBox(h, boxB, boxA);
    }
}
}
}
