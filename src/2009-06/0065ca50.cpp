// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_77de328cdef9da31.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/g3dmath.h>
#include <G3D/CoordinateFrame.h>
#include <cmath>
namespace RBX {
class Geometry { public: int pad; G3D::Vector3 gridSize; };
class Primitive {
public:
    char pad[0xe0];
    Geometry* geometry;
    const G3D::CoordinateFrame& getCoordinateFrame() const;
    Geometry* getGeometry() const { return geometry; }
};
static inline float snapOffset(float v) { return v - G3D::iRound(std::floor(v)); }
class PartInstance {
public:
    char pad[0x118];
    Primitive* primitive;
    G3D::CoordinateFrame f() const;
};
G3D::CoordinateFrame PartInstance::f() const
{
    G3D::Vector3 half = primitive->getGeometry()->gridSize * 0.5f;
    G3D::Vector3 offset; offset.y = -half.y; offset.x = snapOffset(half.x); offset.z = snapOffset(half.z);
    G3D::CoordinateFrame cf(G3D::Matrix3::identity(), offset);
    Primitive* p = primitive;
    return p->getCoordinateFrame() * cf;
}
}
