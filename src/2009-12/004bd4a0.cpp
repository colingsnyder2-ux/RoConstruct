// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
template<class T>
inline const T& minimum(const T& a, const T& b)
{
    return b < a ? b : a;
}

template<class T>
inline const T& maximum(const T& a, const T& b)
{
    return b < a ? a : b;
}

struct Vector
{
    int x, y, z;
    Vector(const int&, const int&, const int&);
};

inline Vector::Vector(const int& a, const int& b, const int& c)
    : x(a), y(b), z(c)
{
}

inline Vector minimum(const Vector& a, const Vector& b)
{
    return Vector(minimum(a.x, b.x),
                  minimum(a.y, b.y),
                  minimum(a.z, b.z));
}

inline Vector maximum(const Vector& a, const Vector& b)
{
    return Vector(b.x < a.x ? a.x : b.x, b.y < a.y ? a.y : b.y, b.z < a.z ? a.z : b.z);
}

struct Bounds
{
    Vector lower, upper;
    Bounds(const Vector&, const Vector&);
};

inline Bounds::Bounds(const Vector& a, const Vector& b)
    : lower(a), upper(b)
{
}

Bounds intersect(const Bounds& a, const Bounds& b)
{
    return Bounds(minimum(b.lower, a.lower),
                  maximum(a.upper, b.upper));
}