// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Vector3 {
    float x, y, z;
    Vector3(float a = 0.0f, float c = 0.0f, float b = 0.0f);
    Vector3(const Vector3& v);
    Vector3 operator/(float scale) const;
};

__forceinline Vector3::Vector3(float a, float c, float b)
    : x(a), y(b), z(c)
{
}

__forceinline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

extern bool __cdecl readVector(void* state, int index, Vector3* value);
extern float __cdecl readNumber(void* state, int index);
extern Vector3* __cdecl checkVector(void* state, int index, const char* type);
extern void __cdecl pushVector(void* state, Vector3 value);
extern const char* vectorType;

int __cdecl divide(void* state)
{
    Vector3 a;
    if (readVector(state, 1, &a)) {
        Vector3 b;
        if (readVector(state, 2, &b)) {
            pushVector(state, Vector3(a.x / b.x, a.z / b.z, a.y / b.y));
        } else {
            pushVector(state, a / readNumber(state, 2));
        }
    } else {
        const Vector3* value = checkVector(state, 2, vectorType);
        a.x = value->x;
        a.y = value->y;
        a.z = value->z;
        float scale = readNumber(state, 1);
        pushVector(state, Vector3(scale / a.x, scale / a.z, scale / a.y));
    }
    return 1;
}
