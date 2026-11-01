// from server: 100% by king_originala
struct Vector3
{
    float x, y, z;
};

extern Vector3 scaleVector;
extern unsigned int scaleInitialized;
extern const float scaleY;
extern Vector3 zeroVector;
extern unsigned int zeroInitialized;

extern void __cdecl transformVector(
    Vector3* result, const Vector3* value, const Vector3* scale);
extern void __cdecl applyVector(void* object, const Vector3* value);

#pragma float_control(precise, off)

void __cdecl updateVector(void* object, const Vector3* source, Vector3* previous)
{
    Vector3 difference;
    Vector3 result;

    difference.x = source->x - previous->x;
    difference.y = source->y - previous->y;
    difference.z = source->z - previous->z;

    if (!(scaleInitialized & 1))
    {
        scaleInitialized |= 1;
        scaleVector.x = 1.0f;
        scaleVector.y = scaleY;
        scaleVector.z = 1.0f;
    }

    transformVector(&result, &difference, &scaleVector);

    if (!(zeroInitialized & 1))
    {
        zeroInitialized |= 1;
        zeroVector.x = 0.0f;
        zeroVector.y = 0.0f;
        zeroVector.z = 0.0f;
    }

    if (result.x != zeroVector.x ||
        result.y != zeroVector.y ||
        result.z != zeroVector.z)
    {
        applyVector(object, &result);
        previous->x = source->x;
        previous->y = source->y;
        previous->z = source->z;
    }
}
