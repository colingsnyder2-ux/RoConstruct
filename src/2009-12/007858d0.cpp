// from server: 34% by atomic.potato
struct Vec3 {
    float x, y, z;
};

struct S {
    char pad[4];
    Vec3 v;
    int __cdecl f(Vec3* out, float scale);
};

extern "C" void __cdecl sub_5f7330(Vec3* out, const Vec3* in);

int S::f(Vec3* out, float scale)
{
    Vec3 tmp;
    tmp.x = v.x * scale;
    tmp.y = v.y * scale;
    tmp.z = v.z * scale;
    sub_5f7330(out, &tmp);
    return (int)out;
}
