// from server: 100% by king_originala
struct Vec3 {
    float x, y, z;
};

extern int scaleBase;
extern void __cdecl transform(Vec3*, const Vec3*);

Vec3* __cdecl buildVector(Vec3* result, int shift, const Vec3* value)
{
    double scale = 1.0 / (scaleBase << shift);
    Vec3 scaled;
    scaled.x = (float)(value->x * scale);
    scaled.y = (float)(value->y * scale);
    scaled.z = (float)(value->z * scale);
    transform(result, &scaled);
    return result;
}
