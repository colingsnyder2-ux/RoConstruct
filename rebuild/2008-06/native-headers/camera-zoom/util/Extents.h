#pragma once
// >>> native-status (generated) -- do not edit >>>
// Extents | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 344d4239 | roc native-status --write
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Plane.h>
#include <G3D/GCamera.h>
#include "util/NormalId.h"
#include "util/Vector3int32.h"
namespace RBX {
class Extents {
    G3D::Vector3 low, high;
public:
    Extents(const Vector3int32& a, const Vector3int32& b): low(a.toVector3()), high(b.toVector3()) {}
    Extents(const G3D::Vector3& a, const G3D::Vector3& b): low(a), high(b) {}
    Extents(): low(G3D::Vector3::inf()), high(-G3D::Vector3::inf()) {}
    bool operator==(const Extents&) const; bool operator!=(const Extents&) const;
    Extents& operator=(const Extents& o) { low=o.low; high=o.high; return *this; }
    const G3D::Vector3& min() const { return low; } const G3D::Vector3& max() const { return high; }
    G3D::Vector3 getCorner(int) const; G3D::Vector3 size() const { return high-low; }
    G3D::Vector3 center() const { return (high+low)*0.5f; }
    G3D::Vector3 bottomCenter() const { G3D::Vector3 v=(low+high)*0.5f; v.y=low.y; return v; }
    G3D::Vector3 topCenter() const { G3D::Vector3 v=(low+high)*0.5f; v.y=high.y; return v; }
    float longestSide() const; float volume() const; float areaXZ() const;
    Extents toWorldSpace(const G3D::CoordinateFrame&); Extents express(const G3D::CoordinateFrame&, const G3D::CoordinateFrame&);
    G3D::Vector3 faceCenter(NormalId) const; void getFaceCorners(NormalId,G3D::Vector3&,G3D::Vector3&,G3D::Vector3&,G3D::Vector3&) const;
    G3D::Plane getPlane(NormalId) const; G3D::Vector3 clip(const G3D::Vector3& v) const { return v.clamp(low,high); }
    G3D::Vector3 clamp(const Extents&) const; NormalId closestFace(const G3D::Vector3&);
    __declspec(noalias) void unionWith(const Extents&); void shift(const G3D::Vector3&);
    void scale(float s) { low*=s; high*=s; } void expand(float f) { low-=G3D::Vector3(f,f,f); high+=G3D::Vector3(f,f,f); }
    G3D::Vector3& operator[](int); const G3D::Vector3& operator[](int) const; operator G3D::Vector3*(); operator const G3D::Vector3*() const;
    bool contains(const G3D::Vector3&) const; bool overlapsOrTouches(const Extents&) const; bool fuzzyContains(const G3D::Vector3&,float) const;
    bool containedByFrustum(const G3D::GCamera::Frustum&) const; bool partiallyContainedByFrustum(const G3D::GCamera::Frustum&) const; bool separatedByMoreThan(const Extents&,float) const;
private: static float epsilon();
public:
    static Extents fromCenterCorner(const G3D::Vector3& c,const G3D::Vector3& r) { return Extents(c-r,c+r); }
    static Extents fromCenterRadius(const G3D::Vector3&,float); static Extents vv(const G3D::Vector3&,const G3D::Vector3&);
    static bool overlapsOrTouches(const Extents&,const Extents&); static const Extents& zero(); static const Extents& unit();
    static const Extents& infiniteExtents(); static const Extents& negativeInfiniteExtents();
}; }
