// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z;
    Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; } };
class Matrix3 { public: float elt[3][3];
    float* operator[](int iRow);
    const float* operator[](int iRow) const; };
}
namespace RBX {
namespace Reflection { class PropertyDescriptor { public: char pad[0x38]; }; }
class GlueJoint {
public:
    char pad[0xd0];
    G3D::Matrix3 facePoints;
    void setFacePoint(int i, const G3D::Vector3& v) { *reinterpret_cast<G3D::Vector3*>(facePoints[i]) = v; }
};
class Instance {
public:
    void raiseChanged(const Reflection::PropertyDescriptor& desc);
};
class Glue : public Instance {
public:
    char pad[0xac];
    GlueJoint* joint;
    GlueJoint* glueJoint() { return joint; }
    void setF1(const G3D::Vector3& value);
};
extern const Reflection::PropertyDescriptor prop_F1;
void Glue::setF1(const G3D::Vector3& value)
{
    glueJoint()->setFacePoint(1, value);
    raiseChanged(prop_F1);
}
}
