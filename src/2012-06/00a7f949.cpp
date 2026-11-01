// from server: 24% by Intel
extern "C" int __stdcall sub_a7c112(float, float, float, float);

struct Vec3 {
    float x, y, z;
};

struct Mat4x4 {
    float m[4][4];
};

Vec3* __stdcall func_00a7f949(Vec3* out, const Vec3* v, const Mat4x4* m) {
    float tx = v->x * m->m[0][0] + v->y * m->m[1][0] + v->z * m->m[2][0] + m->m[3][0];
    float ty = v->x * m->m[0][1] + v->y * m->m[1][1] + v->z * m->m[2][1] + m->m[3][1];
    float tz = v->x * m->m[0][2] + v->y * m->m[1][2] + v->z * m->m[2][2] + m->m[3][2];
    float tw = v->x * m->m[0][3] + v->y * m->m[1][3] + v->z * m->m[2][3] + m->m[3][3];

    out->x = tx;
    out->y = ty;
    out->z = tz;

    int r = sub_a7c112(1.0f, 1.0f, 1.0f, tw);
    if (r != 0) {
        float inv_w = 1.0f / tw;
        out->x = tx * inv_w;
        out->y = ty * inv_w;
        out->z = tz * inv_w;
    }
    return out;
}
