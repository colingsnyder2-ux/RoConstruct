// from server: 100% by colin
// from server: 96% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast

namespace std {
template <class T> inline const T& min(const T& l, const T& r) { return r < l ? r : l; }
template <class T> inline const T& max(const T& l, const T& r) { return l < r ? r : l; }
}

namespace G3D {
template <class T> inline T min(const T& x, const T& y) { return std::min<T>(x, y); }
template <class T> inline T max(const T& x, const T& y) { return std::max<T>(x, y); }

class Vector3 {
public:
    float x, y, z;
    inline Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    inline Vector3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
    inline Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    inline Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    inline float dot(const Vector3& v) const { float r = x * v.x; r += y * v.y; r += z * v.z; return r; }
};
}

namespace RBX {
class Face {
public:
    G3D::Vector3 c0, c1, c2, c3;
    const G3D::Vector3& operator[](int i) const { return (&c0)[i]; }
    void minMax(const G3D::Vector3& point, const G3D::Vector3& normal, float& min, float& max) const;
};

void Face::minMax(const G3D::Vector3& point, const G3D::Vector3& normal, float& min, float& max) const
{
    min = 1.0e10;
    max = -1.0e10;
    for (int i = 0; i < 4; ++i)
    {
        const G3D::Vector3& v = (*this)[i];
        float temp = (v - point).dot(normal);
        min = G3D::min(min, temp);
        max = G3D::max(max, temp);
    }
}
}
