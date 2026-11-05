// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D {
class Color3 {
public:
    float r, g, b;
    Color3() {}
    Color3(float r, float g, float b) : r(r), g(g), b(b) {}
    Color3& operator=(const Color3& o) { r = o.r; g = o.g; b = o.b; return *this; }
};
}
namespace RBX {
class Assembly {
public:
    static const G3D::Color3& debugColor(int i);
};
const G3D::Color3& Assembly::debugColor(int i)
{
    static G3D::Color3 colors[16];
    static bool initialized = false;
    if (!initialized) {
        colors[0] = G3D::Color3(0.0f, 0.0f, 0.0f);
        colors[1] = G3D::Color3(87 / 255.0f, 87 / 255.0f, 87 / 255.0f);
        colors[2] = G3D::Color3(173 / 255.0f, 35 / 255.0f, 35 / 255.0f);
        colors[3] = G3D::Color3(42 / 255.0f, 75 / 255.0f, 215 / 255.0f);
        colors[4] = G3D::Color3(29 / 255.0f, 105 / 255.0f, 20 / 255.0f);
        colors[5] = G3D::Color3(129 / 255.0f, 74 / 255.0f, 25 / 255.0f);
        colors[6] = G3D::Color3(129 / 255.0f, 38 / 255.0f, 192 / 255.0f);
        colors[7] = G3D::Color3(160 / 255.0f, 160 / 255.0f, 160 / 255.0f);
        colors[8] = G3D::Color3(129 / 255.0f, 197 / 255.0f, 22 / 255.0f);
        colors[9] = G3D::Color3(157 / 255.0f, 175 / 255.0f, 255 / 255.0f);
        colors[10] = G3D::Color3(41 / 255.0f, 208 / 255.0f, 208 / 255.0f);
        colors[11] = G3D::Color3(255 / 255.0f, 146 / 255.0f, 51 / 255.0f);
        colors[12] = G3D::Color3(255 / 255.0f, 238 / 255.0f, 51 / 255.0f);
        colors[13] = G3D::Color3(233 / 255.0f, 222 / 255.0f, 187 / 255.0f);
        colors[14] = G3D::Color3(255 / 255.0f, 205 / 255.0f, 243 / 255.0f);
        colors[15] = G3D::Color3(255 / 255.0f, 255 / 255.0f, 255 / 255.0f);
        initialized = true;
    }
    return colors[i % 16];
}
}
