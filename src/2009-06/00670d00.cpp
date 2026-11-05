// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
};
class Ray {
public:
    Vector3 origin, direction;
    virtual ~Ray() {}
};
class CoordinateFrame {
public:
    Ray toObjectSpace(const Ray& r) const;
    Vector3 pointToWorldSpace(const Vector3& v) const;
};
}
namespace RBX {
class PV { public: G3D::CoordinateFrame position; };
class Body {
public:
    char pad[0x9c];
    PV pv;
    void updatePV();
    const PV& getPV() { updatePV(); return pv; }
};
class Geometry {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual bool hitTest(const G3D::Ray& rayInMe, G3D::Vector3& localHitPoint, bool& inside);
};
class Primitive {
public:
    char pad[0xe0];
    Geometry* geometry;
    Body* body;
    bool hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint, bool& inside);
};
bool Primitive::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint, bool& inside)
{
    G3D::Ray localRay = body->getPV().position.toObjectSpace(worldRay);
    G3D::Vector3 localHitPoint;
    if (geometry->hitTest(localRay, localHitPoint, inside))
    {
        worldHitPoint = body->getPV().position.pointToWorldSpace(localHitPoint);
        return true;
    }
    else return false;
}
}
