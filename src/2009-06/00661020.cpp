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
    bool operator!=(const Vector3& r) const { return x != r.x || y != r.y || z != r.z; }
    Vector3 xxx() const;
};
class Matrix3 { public: float elt[3][3]; };
class CoordinateFrame { public: Matrix3 rotation; Vector3 translation; };
}
namespace RBX {
using G3D::Vector3;
using G3D::CoordinateFrame;
namespace Reflection { class PropertyDescriptor; }
class Geometry { public: virtual ~Geometry(); Vector3 gridSize; const Vector3& getGridSize() const { return gridSize; } };
class Primitive {
public:
    char pad[0xe0];
    Geometry* geometry;
    Geometry* getGeometry() const { return geometry; }
    CoordinateFrame getGridCorner() const;
    void setGridSize(const Vector3&);
    void setGridCorner(const CoordinateFrame&);
};
class PartInstance {
public:
    virtual ~PartInstance();
    char pad0[0x98 - 4];
    int legacyOffset;
    char pad1[0x118 - 0x9c];
    Primitive* primitive;
    char pad2[0x1d8 - 0x11c];
    bool dirty;
    char pad3[0x1ec - 0x1d9];
    bool flag;
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21();
    virtual bool hasThreeDimensionalSize();
    const Vector3& getPartSizeXml() const { return primitive->getGeometry()->getGridSize(); }
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
    void setPartSizeXml(const Vector3& rbxSize);
    static const Reflection::PropertyDescriptor prop_Size;
    static const Reflection::PropertyDescriptor prop_SizeUi;
};
void PartInstance::setPartSizeXml(const Vector3& rbxSize) {
    if (rbxSize != getPartSizeXml()) {
        Vector3 newRbxSize = hasThreeDimensionalSize() ? rbxSize : rbxSize.xxx();
        if (legacyOffset) {
            CoordinateFrame oldCorner = primitive->getGridCorner();
            primitive->setGridSize(newRbxSize);
            primitive->setGridCorner(oldCorner);
        } else {
            primitive->setGridSize(newRbxSize);
        }
        raisePropertyChanged(prop_Size);
        raisePropertyChanged(prop_SizeUi);
        dirty = true;
        flag = false;
    }
}
}
