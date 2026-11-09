// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
namespace G3D {
class Vector3 { public: float x, y, z; };
class CoordinateFrame;
class Color3 { public: float r, g, b; Color3() {} };
class Color4 {
public:
    float r, g, b, a;
    Color4(const Color3& c3, float a = 1.0) { r = c3.r; g = c3.g; b = c3.b; this->a = a; }
    Color4(const Color4& other) { r = other.r; g = other.g; b = other.b; a = other.a; }
};
}
namespace RBX {
class Primitive {
public:
    const G3D::CoordinateFrame& getCoordinateFrame() const;
};
class BrickColor {
public:
    G3D::Color3 color3() const;
};
class SurfaceData6 { char data[0x18]; public: ~SurfaceData6() {} };
class Surfaces {
public:
    SurfaceData6 surf6() const;
};
class PartData { public: int unk; G3D::Vector3 size; };
class Part {
public:
    Part(int type, const G3D::Vector3& size, G3D::Color4 color, const SurfaceData6& surfaces, const G3D::CoordinateFrame& cframe);
};
class PartInstance {
    char pad0[0x1dc];
    int partType;          // 0x1dc
    char pad1[4];
    BrickColor color;      // 0x1e4
    float transparency;    // 0x1e8
    char pad2[0x1f4 - 0x1ec];
    Surfaces surfaces;     // 0x1f4
    char pad3[0x228 - 0x1f5];
    Primitive primitive;   // 0x228
    char pad4[0x2c4 - 0x229];
    PartData* partData;    // 0x2c4
    char pad5[0x328 - 0x2c8];
    float localTransparencyModifier; // 0x328
public:
    float alpha() const { return 1.0f - (1.0f - transparency) * localTransparencyModifier; }
    G3D::Color3 getColor3() const { return color.color3(); }
    const G3D::Vector3& getPartSizeXml() const { return partData->size; }
    Part computePersistentPart() const;
};
Part PartInstance::computePersistentPart() const
{
    const G3D::CoordinateFrame& cframe = primitive.getCoordinateFrame();
    float transparency = 1.0f - alpha();
    return Part(partType, getPartSizeXml(), G3D::Color4(getColor3(), transparency), surfaces.surf6(), cframe);
}
}
