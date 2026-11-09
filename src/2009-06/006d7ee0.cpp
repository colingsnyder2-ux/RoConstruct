// from server: 100% by EspClaude
// roc 2009-06 006d7ee0  RBX::MultiJoint::MultiJoint (2009 Joint has 2nd vptr @0x20)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class CoordinateFrame; }
namespace RBX {
class Primitive;
class IPipelined {
public:
    virtual ~IPipelined();
    char pad[0x1c];
};
class Edge {
public:
    virtual void putInKernel();
};
class Joint : public IPipelined, public Edge {
protected:
    Joint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& c0, const G3D::CoordinateFrame& c1);
    ~Joint();
};
class MultiJoint : public Joint {
    void init(int numBreaking) throw();
protected:
    MultiJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0, const G3D::CoordinateFrame& jointCoord1, int numBreaking);
    ~MultiJoint();
};
MultiJoint::MultiJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0, const G3D::CoordinateFrame& jointCoord1, int numBreaking)
    : Joint(p0, p1, jointCoord0, jointCoord1)
{
    init(numBreaking);
}
}
