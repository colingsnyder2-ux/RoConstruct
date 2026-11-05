// from server: 100% by king_originala
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct Vector2 {
    float x, y;
};

struct Vector3 {
    float x, y, z;
    Vector2* yz(Vector2* result) const;
};

Vector3* __cdecl normalize(Vector3* v, Vector3* result,
                          float unused, const Vector2* scale)
{
    Vector2 temporary;
    const Vector2* p = v->yz(&temporary);
    float reciprocal = 1.0f / (float)sqrt(p->x * p->x + p->y * p->y);
    float y = p->x * reciprocal;
    float z = p->y * reciprocal;

    v->y = scale->x * y;
    v->z = scale->y * z;

    result->x = 0.0f;
    result->y = y;
    result->z = z;
    return result;
}
