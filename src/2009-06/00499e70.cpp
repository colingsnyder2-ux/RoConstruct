// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace Ogre {
typedef float Real;
class Vector3 {
public:
    Real x, y, z;
    Vector3() {}
    Vector3(const Vector3& r) : x(r.x), y(r.y), z(r.z) {}
    Vector3& operator=(const Vector3& r) { x = r.x; y = r.y; z = r.z; return *this; }
};
class AxisAlignedBox {
public:
    enum Extent { EXTENT_NULL, EXTENT_FINITE, EXTENT_INFINITE };
protected:
    Vector3 mMinimum;
    Vector3 mMaximum;
    Extent mExtent;
    mutable Vector3* mpCorners;
public:
    AxisAlignedBox() : mpCorners(0) { mExtent = EXTENT_NULL; }
    AxisAlignedBox(const Vector3& min, const Vector3& max) : mpCorners(0) { setExtents(min, max); }
    ~AxisAlignedBox() { if (mpCorners) delete[] mpCorners; }
    AxisAlignedBox(Real mx, Real my, Real mz, Real Mx, Real My, Real Mz) : mpCorners(0) { setExtents(mx, my, mz, Mx, My, Mz); }
    void setExtents(Real mx, Real my, Real mz, Real Mx, Real My, Real Mz) { mExtent = EXTENT_FINITE; mMinimum.x = mx; mMinimum.y = my; mMinimum.z = mz; mMaximum.x = Mx; mMaximum.y = My; mMaximum.z = Mz; }
    void setExtents(const Vector3& min, const Vector3& max) { mExtent = EXTENT_FINITE; mMinimum = min; mMaximum = max; }
};
}
namespace G3D {
class Vector3 { public: float x, y, z; };
class AABox {
    Vector3 lo, hi;
public:
    const Vector3& low() const { return lo; }
    const Vector3& high() const { return hi; }
};
}
namespace RBX {
const Ogre::Vector3& convert(const G3D::Vector3& v) { return reinterpret_cast<const Ogre::Vector3&>(v); }
Ogre::AxisAlignedBox convert(const G3D::AABox& b)
{
    return Ogre::AxisAlignedBox(b.low().x, b.low().y, b.low().z, b.high().x, b.high().y, b.high().z);
}
}
