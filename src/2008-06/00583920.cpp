// from server: 100% by king_originala
struct Vector
{
    float x, y, z;

    __forceinline Vector(double a, double b, double c) throw();
    __forceinline Vector(const Vector& v) throw();
    __forceinline Vector operator-() const throw();
};

__forceinline Vector::Vector(double a, double b, double c) throw()
    : x((float)a), y((float)b), z((float)c)
{
}

__forceinline Vector::Vector(const Vector& v) throw()
    : x(v.x), y(v.y), z(v.z)
{
}

__forceinline Vector Vector::operator-() const throw()
{
    return Vector(-(double)x, -(double)y, -(double)z);
}

extern const Vector& __cdecl getVector() throw();

struct Bounds
{
    Vector first;
    Vector second;

    __forceinline Bounds() throw();
};

__forceinline Bounds::Bounds() throw()
    : first(getVector()), second(-getVector())
{
}

Bounds* __cdecl getBounds()
{
    static Bounds bounds;
    return &bounds;
}
