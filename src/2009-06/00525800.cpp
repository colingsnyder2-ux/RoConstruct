// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Color3 {
public:
    float r, g, b;
    Color3() {}
    Color3(const Color3& o) : r(o.r), g(o.g), b(o.b) {}
};
}
namespace RBX {
class Lighting {
public:
    virtual ~Lighting();
    char pad[0x1dc - 4];
    G3D::Color3 topAmbient;
    G3D::Color3 getAmbientTop() const;
};
G3D::Color3 Lighting::getAmbientTop() const { return topAmbient; }
}
