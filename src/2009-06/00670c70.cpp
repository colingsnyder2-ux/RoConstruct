// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { struct Vector3 { float x, y, z; Vector3(const Vector3& o):x(o.x),y(o.y),z(o.z){} }; }
namespace RBX {
class Primitive;
class Geometry {
public:
    enum GeometryType { GEOMETRY_NONE };
    virtual void slot0();
    virtual ~Geometry();
    virtual GeometryType getGeometryType() const;
    const G3D::Vector3& getGridSize() const { return gridSize; }
    G3D::Vector3 gridSize;
};
class World { public: void onPrimitiveGeometryTypeChanged(Primitive* p); };
struct DirtyFlag { bool dirty; void setDirty() { dirty = true; } };
class Primitive {
public:
    char pad0[0xc0];
    World* world;
    char pad1[0x1c];
    Geometry* geometry;
    char pad2[0x50];
    DirtyFlag JointK;
    char pad3[0x13];
    bool exeFlag2009;
    static Geometry* newGeometry(Geometry::GeometryType t);
    void setGridSize(const G3D::Vector3& v);
    void setPrimitiveType(Geometry::GeometryType geometryType);
};
void Primitive::setPrimitiveType(Geometry::GeometryType geometryType)
{
    if (geometry->getGeometryType() != geometryType)
    {
        G3D::Vector3 oldSize = geometry->getGridSize();
        if (geometry)
            delete geometry;
        geometry = newGeometry(geometryType);
        if (world)
            world->onPrimitiveGeometryTypeChanged(this);
        setGridSize(oldSize);
        JointK.setDirty();
        exeFlag2009 = false;
    }
}
}
