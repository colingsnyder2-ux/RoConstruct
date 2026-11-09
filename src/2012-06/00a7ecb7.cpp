// from server: 18% by Intel
struct Vec4 { float x, y, z, w; };
struct Mat4 { float m[16]; };

Vec4* __stdcall func_00a7ecb7(Vec4* out, const Mat4* mat, const Vec4* vec) {
    float vx = vec->x, vy = vec->y, vz = vec->z, vw = vec->w;
    const float* m = mat->m;

    out->x = m[0] * vx + m[4] * vy + m[8] * vz + m[12] * vw;
    out->y = m[1] * vx + m[5] * vy + m[9] * vz + m[13] * vw;
    out->z = m[2] * vx + m[6] * vy + m[10] * vz + m[14] * vw;
    out->w = m[3] * vx + m[7] * vy + m[11] * vz + m[15] * vw;

    return out;
}
