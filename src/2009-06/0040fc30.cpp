// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector2 {
public:
    float x, y;
    Vector2() {}
    Vector2(const Vector2& o) : x(o.x), y(o.y) {}
};
}
namespace RBX {
class GuiRoot {
public:
    virtual ~GuiRoot();
private:
    char pad[0x98 - 4];
    G3D::Vector2 canvasSize;
    virtual G3D::Vector2 getSize() const;
};
G3D::Vector2 GuiRoot::getSize() const { return canvasSize; }
}
