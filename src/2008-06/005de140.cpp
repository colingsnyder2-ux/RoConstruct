// from server: 100% by king_originala
extern "C" double __cdecl acos(double);
#pragma intrinsic(acos)

extern const float negativeOne;
extern const float pi;

struct Vector3
{
    float x, y, z;
};

double __cdecl angleBetween(const Vector3& a, const Vector3& b)
{
    double dot = a.z * b.z + a.y * b.y + a.x * b.x;
    if (dot >= 1.0f)
        return 0.0f;
    if (dot <= negativeOne)
        return pi;
    return acos(dot);
}
