// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc 2008-06 00610580  (agentH rewrite)

struct Vector3
{
    float x, y, z;
    Vector3() {}
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3 operator+(const Vector3& o) const { return Vector3(x + o.x, y + o.y, z + o.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    bool operator==(const Vector3& o) const { return x == o.x && y == o.y && z == o.z; }
};

extern const float half;
extern const float scaleY;
extern Vector3 adjustment;
extern unsigned int adjustmentInitialized;

extern void __cdecl transformVector(
    Vector3* result, const Vector3* value, const Vector3* scale);
extern bool __cdecl testVector(Vector3* result, void* context);
extern Vector3* __cdecl multiplyVector(
    Vector3* result, const Vector3* value, const Vector3* scale);

void __cdecl subdivideVector(
    Vector3* result,
    const Vector3* start,
    const Vector3* end,
    const Vector3* scale,
    void* context)
{
    transformVector(result, end, scale);
    if (!testVector(result, context))
        return;

    Vector3 average = (*start + *end) * 0.51f;

    if (!(adjustmentInitialized & 1))
    {
        adjustmentInitialized |= 1;
        adjustment.x = 1.0f;
        adjustment.y = scaleY;
        adjustment.z = 1.0f;
    }

    Vector3 midpoint;
    multiplyVector(&midpoint, &average, &adjustment);

    transformVector(result, &midpoint, scale);
    bool accepted = testVector(result, context);

    if (midpoint == *end)
    {
        if (accepted)
            transformVector(result, start, scale);
    }
    else if (accepted)
    {
        subdivideVector(result, start, &midpoint, scale, context);
    }
    else
    {
        subdivideVector(result, &midpoint, end, scale, context);
    }
}
