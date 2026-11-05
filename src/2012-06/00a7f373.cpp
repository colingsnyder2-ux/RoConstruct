// from server: 57% by atomic.potato
struct Vec4 {
    float x, y, z, w;
};

void __stdcall func_00a7f373(Vec4* out, const Vec4* a, const Vec4* b) {
    out->x = b->x;
    out->y = b->y;
    out->z = b->z;
    out->w = -(a->y * b->y + a->z * b->z + a->x * b->x);
}
