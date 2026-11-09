// from server: 100% by king_originala
extern const float initialValue;

struct Vector
{
    float x, y, z;
    Vector(float value);
    Vector(const Vector& other);
};

inline Vector::Vector(float value)
    : x(value), y(0.0f), z(value)
{
}

inline Vector::Vector(const Vector& other)
    : x(other.x), y(other.y), z(other.z)
{
}

Vector func_006663a0()
{
    static Vector value(initialValue);
    return value;
}
