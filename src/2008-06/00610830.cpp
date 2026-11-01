// from server: 100% by king_originala
struct Vector
{
    float x, y, z;

    __forceinline Vector(float a, float b, float c);
    __forceinline Vector(const Vector& other);
    __forceinline Vector& operator=(const Vector& other);
};

__forceinline Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

__forceinline Vector::Vector(const Vector& other)
    : x(other.x), y(other.y), z(other.z)
{
}

__forceinline Vector& Vector::operator=(const Vector& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

struct Contact
{
    unsigned int reserved;
    unsigned int count;
};

extern const float offset;
extern const float scale;

extern Vector __cdecl scaleVector(const Vector&, float);
extern void __cdecl prepareContact(Contact*, const Vector&);
extern bool __cdecl testContact(Contact*, const void*);
extern void __cdecl solveContactA(Contact*, Vector&, const void*);
extern void __cdecl solveContactB(Contact*, Vector&, const void*);

Vector __cdecl computeContact(Contact* contact, const Vector& position,
                              const void* other)
{
    if (contact->count == 0)
    {
        static const Vector zero(0.0f, 0.0f, 0.0f);
        return zero;
    }

    Vector result(position.x, position.y - offset, position.z);
    result = scaleVector(result, scale);
    prepareContact(contact, result);

    if (testContact(contact, other))
        solveContactA(contact, result, other);
    else
        solveContactB(contact, result, other);

    return result;
}
