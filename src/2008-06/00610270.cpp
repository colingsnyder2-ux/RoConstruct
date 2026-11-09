// from server: 100% by king_originala
struct Vector3
{
    float x, y, z;
    Vector3();
    Vector3(float a, float b, float c);
};

__forceinline Vector3::Vector3()
{
}

__forceinline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

extern void __cdecl transform(const void*, Vector3*);
extern void __cdecl multiply(Vector3*, const Vector3*, const Vector3*);

void __cdecl f(const void* source, Vector3* vector, Vector3* output)
{
    transform(source, vector);

    Vector3 result;
    Vector3 sum(
        vector->x + output->x,
        vector->y + output->y,
        vector->z + output->z);

    static Vector3 scale(1.0f, 0.1f, 1.0f);
    multiply(&result, &sum, &scale);

    output->x = result.x;
    output->y = result.y;
    output->z = result.z;
}
