// from server: 29% by Intel
struct Vec4 {
    float x, y, z, w;
};

extern "C" int __cdecl helper(float, float);

int __stdcall func_00a7ed7b(Vec4* out, const Vec4* in) {
    float t = in->x * in->x + in->y * in->y + in->z * in->z + in->w * in->w;
    extern const float flt_C2DB98;
    int cmp = helper(t, flt_C2DB98);
    if (cmp) {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
        out->w = 0.0f;
    } else {
        float inv = 1.0f / t;
        out->x = -in->x * inv;
        out->y = -in->y * inv;
        out->z = -in->z * inv;
        out->w = in->w;
    }
    return reinterpret_cast<int>(out);
}
