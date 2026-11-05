// from server: 100% by atomic.potato
struct Vec3 { float x, y, z; };

extern Vec3* func_004fb620(void*);

Vec3* func_004fbe90(Vec3* out, void* src)
{
    Vec3* v = func_004fb620(src);
    out->x = v->x;
    out->y = v->y;
    out->z = v->z;
    return out;
}
