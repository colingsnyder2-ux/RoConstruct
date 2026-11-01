// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Color4 {
public:
    float r, g, b, a;
    static const Color4& clear();
    Color4& operator=(const Color4& o) { r = o.r; g = o.g; b = o.b; a = o.a; return *this; }
};
}
namespace RBX {
namespace Layout { enum Style { VERTICAL, HORIZONTAL }; }
class TopMenuBar {
public:
    char pad[0xa0];
    G3D::Color4 backdropColor;  // 0xa0
    Layout::Style layoutStyle;  // 0xb0
    bool visible;               // 0xb4
private:
    void init();
};
void TopMenuBar::init()
{
    layoutStyle = Layout::VERTICAL;
    backdropColor = G3D::Color4::clear();
    visible = true;
}
}
