// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3();
    Vector3(const Vector3 &other);
};

inline Vector3::Vector3()
{
}

inline Vector3::Vector3(const Vector3 &other)
    : x(other.x), y(other.y), z(other.z)
{
}

typedef Vector3 &(__thiscall *Getter)(void *, Vector3 *);

struct S {
    char padding[8];
    Getter getter;
    int adjustment;
    int virtualOffset;
    Vector3 f(void *object);
};

Vector3 S::f(void *object)
{
    Vector3 temporary;
    char *base = object ? (char *)object - 20 : 0;
    return getter(base + 448 +
                  (*(int *)((char *)*(int **)(base + 448) + virtualOffset)
                   + adjustment), &temporary);
}
