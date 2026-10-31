// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};
}
namespace RBX {
class Geometry {
public:
    virtual ~Geometry();
    G3D::Vector3 gridSize;
    const G3D::Vector3& getGridSize() const { return gridSize; }
};
class Primitive {
public:
    char pad[0xe0];
    Geometry* geometry;
    Geometry* getGeometry() const { return geometry; }
};
class PartInstance {
public:
    char pad[0x118];
    Primitive* primitive;
    G3D::Vector3 getPartSizeUi() const;
};
G3D::Vector3 PartInstance::getPartSizeUi() const
{
    return primitive->getGeometry()->getGridSize();
}
}
