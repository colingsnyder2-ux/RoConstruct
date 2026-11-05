// from server: 100% by EspClaude
// roc 2009-06 0065c450  unit: RBX::PartInstance::legacyTraverseState
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class CoordinateFrame {
public:
    float m[12];
    CoordinateFrame operator*(const CoordinateFrame& other) const;
};
}
namespace RBX {
using G3D::CoordinateFrame;
class Primitive {
public:
    void setGridCorner(const CoordinateFrame& cf);
};
class PartInstance {
public:
    virtual void legacyTraverseState(const CoordinateFrame& parentState);
    char pad[0x94];
    CoordinateFrame* legacyOffset;   // 0x98
    char pad2[0x118 - 0x9c];
    Primitive* primitive;            // 0x118
};
void PartInstance::legacyTraverseState(const CoordinateFrame& parentState)
{
    CoordinateFrame gridCorner = parentState * *legacyOffset;
    primitive->setGridCorner(gridCorner);
}
}
