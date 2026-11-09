// from server: 14% by atomic.potato
struct Vec3 {
    float x;
    float y;
    float z;
};

Vec3* __fastcall minVec3(Vec3* out, void*, const Vec3* a, const Vec3* b, const Vec3* c)
{
    float z;
    if (b->z < a->z) {
        if (a->z < c->z)
            z = a->z;
        else
            z = c->z;
    } else {
        z = b->z;
    }

    float y;
    if (b->y < a->y) {
        if (a->y < c->y)
            y = a->y;
        else
            y = c->y;
    } else {
        y = b->y;
    }

    float x;
    if (b->x < a->x) {
        if (a->x < c->x)
            x = a->x;
        else
            x = c->x;
    } else {
        x = b->x;
    }

    out->x = x;
    out->y = y;
    out->z = z;
    return out;
}
