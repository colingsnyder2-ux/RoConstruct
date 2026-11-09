// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
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
class HitTestFilter;
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
public:
    Primitive* getSlowHit(const Array<Primitive*>& found, const Ray& unitRay, const Array<const Primitive*>* ignore,
                          const HitTestFilter* filter, Vector3& hitPoint, float maxDistance, bool& hitSurface, bool& blocked) const;
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
}
