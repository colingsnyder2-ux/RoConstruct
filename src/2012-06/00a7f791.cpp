// from server: 23% by Intel
extern "C" int __cdecl sub_a7c112(float, float, float, float);

struct Vec3 { float x, y, z; };

Vec3* __stdcall func_00a7f791(Vec3* out, const Vec3* v, const float* m) {
    float t0 = v->x * m[0];
    float t1 = v->x * m[4];
    float t2 = v->x * m[8];
    float t3 = v->y * m[1];
    float t4 = v->y * m[5];
    float t5 = v->y * m[9];
    float t6 = v->z * m[2];
    float t7 = v->z * m[6];
    float t8 = v->z * m[10];

    float r0 = t0 + t3 + t6 + m[12];
    float r1 = t1 + t4 + t7 + m[13];
    float r2 = t2 + t5 + t8 + m[15];

    out->x = r0;
    out->y = r1;
    float w = r2;

    int res = sub_a7c112(1.0f, 1.0f, w, w);
    if (res == 0) {
        float inv = 1.0f / w;
        out->x *= inv;
        out->y *= inv;
    }
    return out;
}
