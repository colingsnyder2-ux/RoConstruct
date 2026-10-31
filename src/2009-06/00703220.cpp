// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Color4 { public: float r,g,b,a; }; class RenderDevice; }
namespace RBX {
class DrawPrimitives { public: static void rawCylinderAlongX(float radius, float length, G3D::RenderDevice* rd, int slices); };
class Adorn {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void setColor(const G3D::Color4& c);
    virtual void cylinderAlongX(float radius, float length, const G3D::Color4& solidColor, const G3D::Color4& wireColor, int slices);
};
class AdornG3D : public Adorn {
public:
    G3D::RenderDevice* renderDevice;
    virtual void cylinderAlongX(float radius, float length, const G3D::Color4& solidColor, const G3D::Color4& wireColor, int slices);
};
void AdornG3D::cylinderAlongX(float radius, float length, const G3D::Color4& solidColor, const G3D::Color4& wireColor, int slices)
{
    setColor(solidColor);
    DrawPrimitives::rawCylinderAlongX(radius, length, renderDevice, slices);
}
}
