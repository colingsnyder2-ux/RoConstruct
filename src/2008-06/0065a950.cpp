// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Extents;
class Vector3int32 {
public:
    int x, y, z;
    Vector3int32() : x(0), y(0), z(0) {}
    bool operator==(const Vector3int32& o) const { return x == o.x && y == o.y && z == o.z; }
    bool operator!=(const Vector3int32& o) const { return !(*this == o); }
};
class ExtentsInt32 {
public:
    Vector3int32 low, high;
    bool overlapsOrTouches(const ExtentsInt32& o) const {
        return low.x <= o.high.x && low.y <= o.high.y && low.z <= o.high.z
            && high.y >= o.low.y && high.x >= o.low.x && high.z >= o.low.z;
    }
    static ExtentsInt32 __cdecl unionOf(const ExtentsInt32& a, const ExtentsInt32& b);
};
class Clump { public: char pad[0x20]; unsigned short level; };
class Primitive {
public:
    char pad[0x64];
    Clump* clump;
    ExtentsInt32 spatialExtents;
};
class SpatialHash {
public:
    static __declspec(noalias) void __cdecl computeMinMax(int level, const Extents& extents, Vector3int32& min, Vector3int32& max);
    void changeMinMax(int level, Primitive* p, const ExtentsInt32& change, const ExtentsInt32& oldBox, const ExtentsInt32& newBox);
    void updateContacts(Primitive* p);
    void primitiveExtentsChanged(Primitive* p, const Extents& fuzzyExtents);
};
void SpatialHash::primitiveExtentsChanged(Primitive* p, const Extents& fuzzyExtents)
{
    int level = p->clump->level;
    Vector3int32 newMin;
    Vector3int32 newMax;
    computeMinMax(level, fuzzyExtents, newMin, newMax);
    if (newMin != p->spatialExtents.low || newMax != p->spatialExtents.high) {
        ExtentsInt32 oldBox = p->spatialExtents;
        p->spatialExtents.low = newMin;
        p->spatialExtents.high = newMax;
        const ExtentsInt32& newBox = p->spatialExtents;
        if (oldBox.overlapsOrTouches(newBox)) {
            ExtentsInt32 unionBox = ExtentsInt32::unionOf(oldBox, newBox);
            changeMinMax(level, p, unionBox, oldBox, newBox);
            updateContacts(p);
        } else {
            changeMinMax(level, p, oldBox, oldBox, newBox);
            updateContacts(p);
            changeMinMax(level, p, newBox, oldBox, newBox);
        }
    }
}
}
