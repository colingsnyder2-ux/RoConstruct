// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 ContactManager getSlowHit 0060cd60 and getFastHit 0060d2d0 (inactive). Self-contained TU: the native Primitive/SpatialHash
// headers lack hitTest/realToHashGrid, so the minimal donor-context types below carry only what these bodies call.
#include <algorithm>
#include <math.h>

extern void alignedFree(void*);

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    float magnitude() const { return sqrtf(x * x + y * y + z * z); }
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
};
class Vector3int32 { public: int x, y, z; Vector3int32() {} Vector3int32(const Vector3int32& v) : x(v.x), y(v.y), z(v.z) {} };
template <class T>
class Array {
public:
    T* data;
    int num;
    int numAllocated;
    Array() { num = 0; numAllocated = 0; data = 0; }
    ~Array() { alignedFree(data); }
    void resize(int n, bool shrinkIfNecessary);
};
class Ray {
public:
    virtual void dummy();
    Vector3 origin;
    Vector3 direction;
    Ray unit() const;
    ~Ray() {}
};
}
using namespace G3D;

namespace RBX {
class Primitive;
class HitTestFilter
{
public:
    enum Result { STOP_TEST = 0, IGNORE_PRIM = 1, INCLUDE_PRIM = 2 };   // INFERRED: 0060cd60 switch (0 stop, 1 skipped, 2 default when no filter)
    virtual Result filterResult(const Primitive* p) const = 0;
};
class CoordinateFrame { public: float rot[9]; Vector3 translation; };   // INFERRED: translation at +0x24 (0060ce20)
class Primitive
{
public:
    virtual ~Primitive();
    virtual void v1();
    virtual void v2();
    virtual float getRadius() const;   // slot 3
    const CoordinateFrame& getCoordinateFrame() const;   // 005e82c0
    bool hitTest(const Ray& ray, Vector3& hit, bool& inside) const;   // 005e7f20
};
struct Extents {
    Vector3 low, high;
    Extents() {}
    Extents(const Extents& e) : low(e.low), high(e.high) {}
    bool fuzzyContains(const Vector3& point, float slop) const
    {
        return low.x - slop <= point.x && low.y - slop <= point.y && low.z - slop <= point.z && point.x <= high.x + slop &&
               point.y <= high.y + slop && point.z <= slop + high.z;
    }
};
class SpatialHash {
public:
    static Vector3int32 realToHashGrid(int level, const Vector3& v);
    static Extents hashGridToRealExtents(int level, const Vector3& v);
    void getPrimitivesInGrid(const Vector3int32& grid, Array<Primitive*>& found);
    bool getNextGrid(Vector3int32& grid, const Ray& ray, float maxDistance);
};
class ContactManager {
    SpatialHash* spatialHash;
    Primitive* getSlowHit(const Array<Primitive*>& found, const Ray& unitRay, const Array<const Primitive*>* ignore,
                          const HitTestFilter* filter, Vector3& hitPoint, float maxDistance, bool& hitSurface, bool& blocked) const;
public:
    Primitive* getFastHit(const Ray& ray, const Array<const Primitive*>* ignore, const HitTestFilter* filter,
                          Vector3& hitPoint, bool& hitSurface, bool& blocked) const;
};

Primitive* ContactManager::getFastHit(const Ray& ray, const Array<const Primitive*>* ignore, const HitTestFilter* filter,
                                      Vector3& hitPoint, bool& hitSurface, bool& blocked) const
{
    Array<Primitive*> found;

    Vector3int32 grid = SpatialHash::realToHashGrid(0, ray.origin);

    float length = ray.direction.magnitude();
    float maxDistance = std::min(5000.0f, length);

    Ray unitRay = ray.unit();

    do {
        found.resize(0, false);
        spatialHash->getPrimitivesInGrid(grid, found);

        Primitive* hit = getSlowHit(found, unitRay, ignore, filter, hitPoint, maxDistance, hitSurface, blocked);

        if (hit != 0) {
            Vector3 gridCenter((float)grid.x, (float)grid.y, (float)grid.z);
            Extents extents = SpatialHash::hashGridToRealExtents(0, gridCenter);

            if (extents.fuzzyContains(hitPoint, 0.001f)) {
                return hit;
            }
        }
    } while (spatialHash->getNextGrid(grid, unitRay, maxDistance));

    return 0;
}

static const Primitive* const* findIgnored(const Array<const Primitive*>& a, const Primitive* p)
{
    for (int i = 0; i < a.num; i++) {
        if (a.data[i] == p)
            return a.data + i;
    }
    return a.data + a.num;
}

// PARKED near miss (getSlowHit 0060cd60, 618 bytes against ~600): the target emits the found / not-found `find == end` compares as two separate
// tails and keeps the dx*Dx term of both dot products in the dx slot of the x87 stack; ~10 variants (index/pointer find helpers, dot term
// order and associativity, switch vs if) reproduce the call set, branches and constants but not that tail layout. Parked after three+ trials.
Primitive* ContactManager::getSlowHit(const Array<Primitive*>& found, const Ray& unitRay, const Array<const Primitive*>* ignore,
                                      const HitTestFilter* filter, Vector3& hitPoint, float maxDistance, bool& hitSurface, bool& blocked) const
{
    float stopDist = maxDistance;
    float bestDist = maxDistance;
    blocked = false;
    hitSurface = false;
    Primitive* best = 0;

    for (int i = 0; i < found.num; i++) {
        Primitive* p = found.data[i];
        bool notIgnored;
        if (ignore == 0)
            notIgnored = true;
        else
            notIgnored = findIgnored(*ignore, p) == ignore->data + ignore->num;
        HitTestFilter::Result r = filter ? filter->filterResult(p) : HitTestFilter::INCLUDE_PRIM;
        if (notIgnored && r != HitTestFilter::IGNORE_PRIM) {
            Vector3 c = p->getCoordinateFrame().translation;
            float radius = p->getRadius();
            Vector3 d = c - unitRay.origin;
            float t = unitRay.direction.x * d.x + (d.y * unitRay.direction.y + d.z * unitRay.direction.z);
            Vector3 closest = unitRay.origin + unitRay.direction * t;
            if ((c - closest).magnitude() <= radius) {
                Vector3 hit(0, 0, 0);
                bool ins;
                if (p->hitTest(unitRay, hit, ins)) {
                    Vector3 e = hit - unitRay.origin;
                    float tt = unitRay.direction.x * e.x + (e.y * unitRay.direction.y + e.z * unitRay.direction.z);
                    if (tt > 0.0f) {
                        switch (r) {
                        case HitTestFilter::STOP_TEST:
                            if (tt < stopDist) {
                                stopDist = tt;
                                blocked = true;
                            }
                            break;
                        case HitTestFilter::INCLUDE_PRIM:
                            if (tt < bestDist) {
                                bestDist = tt;
                                hitSurface = ins;
                                hitPoint = hit;
                                best = p;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    if (blocked && best && stopDist > bestDist)
        blocked = false;
    return best;
}
}
