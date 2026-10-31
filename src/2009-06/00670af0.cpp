// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; }
};
}
namespace RBX {
class Extents {
public:
    G3D::Vector3 low, high;
    Extents& operator=(const Extents& o) { low = o.low; high = o.high; return *this; }
};
class Body {
public:
    void updatePV() const;
    int getStateIndex() const { updatePV(); return stateIndex; }
    char pad[0x98];
    int stateIndex;
};
class Primitive {
public:
    const Extents& getFastFuzzyExtents() const;
    Extents computeFuzzyExtents() const;
    char pad[0xc4];
    mutable Extents fuzzyExtents;
    mutable int fuzzyExtentsStateId;
    void* geometry;
    Body* body;
};
const Extents& Primitive::getFastFuzzyExtents() const
{
    if (fuzzyExtentsStateId != body->getStateIndex()) {
        fuzzyExtents = computeFuzzyExtents();
        fuzzyExtentsStateId = body->getStateIndex();
    }
    return fuzzyExtents;
}
}
