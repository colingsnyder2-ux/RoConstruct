// from server: 100% by EspClaude
// from server: 91% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector
{
    float x, y, z;

    Vector(float, float, float);
    Vector(const Vector&);
    bool operator!=(const Vector&) const;
    static const Vector& zero();
};

inline Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline Vector::Vector(const Vector& v)
    : x(v.x), y(v.y), z(v.z)
{
}

inline bool Vector::operator!=(const Vector& v) const
{
    return x != v.x || y != v.y || z != v.z;
}

inline const Vector& Vector::zero()
{
    static const Vector value(0.0f, 0.0f, 0.0f);
    return value;
}

struct Data
{
    unsigned int unused;
    unsigned int count;
};

extern void __cdecl calculate(
    Data*, const Vector*, const Vector*, Vector*, unsigned int);

Vector __cdecl reconstruct(
    Data* data, const Vector& target, unsigned int parameter)
{
    if (data->count == 0)
        return Vector::zero();

    Vector result(Vector::zero());
    if (target != Vector::zero())
        calculate(data, &Vector::zero(), &target, &result, parameter);

    return result;
}
