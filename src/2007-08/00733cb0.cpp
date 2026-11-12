// from server: 100% by EspClaude
// roc 2007-08 00733cb0  unit: G3D::Sky  size: 227 bytes
// Resize Array<Vector4> star (+0x38, num +0x3c) and Array<float> starIntensity
// (+0x44), then refill both from the top index down (G3D Sky star init shape).
#include <stdlib.h>

namespace G3D {

template<class T> class Array
{
public:
    T*  data;          // +0
    int num;           // +4
    int numAllocated;  // +8
    void resize(int n, bool shrinkIfNecessary = true);   // 0x507190 / 0x47c7d0
    int size() const { return num; }
    T& operator[](int n) { return data[n]; }
};

class Vector3
{
public:
    float x, y, z;
    static Vector3 random();       // 0x50f560, cdecl, hidden return pointer
};

class Vector4
{
public:
    float x, y, z, w;
    Vector4() {}
    Vector4(const Vector3& v, float _w) : x(v.x), y(v.y), z(v.z), w(_w) {}
    Vector4& operator=(const Vector4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; }
};

inline float uniformRandom(float low = 0.0f, float hi = 1.0f)
{
    return (hi - low) * float(::rand()) / float(RAND_MAX) + low;
}

inline double square(double x) { return x * x; }

class Sky
{
    char pad00[0x38];
    Array<Vector4> star;           // +0x38
    Array<float>   starIntensity;  // +0x44
public:
    void setNumStars(int n);
};

void Sky::setNumStars(int n)
{
    if (n == star.size())
        return;
    star.resize(n);
    starIntensity.resize(star.size());
    for (int i = star.size() - 1; i >= 0; --i) {
        star[i] = Vector4(Vector3::random(), 0);
        starIntensity[i] = square(uniformRandom()) + .3f;
    }
}

}
