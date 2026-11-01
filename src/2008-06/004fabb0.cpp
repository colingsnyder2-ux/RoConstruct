// from server: 100% by king_originala
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct Vec3 {
    float x, y, z;
};

void __cdecl normalizeAndScale(Vec3* value, Vec3* unit, void*, const volatile Vec3* scale)
{
    float inverseLength = 1.0f / (float)sqrt(
        value->x * value->x +
        value->y * value->y +
        value->z * value->z);

    float x = value->x * inverseLength;
    float y = value->y * inverseLength;
    float z = value->z * inverseLength;

    unit->x = x;
    unit->y = y;
    unit->z = z;

    float scaledX = x * scale->x;
    float scaledY = y * scale->y;
    float scaledZ = z * scale->z;

    value->x = scaledX;
    value->y = scaledY;
    value->z = scaledZ;
}
