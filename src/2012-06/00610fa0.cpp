// from server: 13% by atomic.potato
struct V2 { float x, y; };
struct V3 { float x, y, z; };

extern "C" {
    float g_b4c440;
    float g_b53ac8;
    float g_b62770;
    float g_b82674;
}

struct Src {
    float x, y;
    V2 xy(V2* out) const;
};

V2 Src::xy(V2* out) const {
    out->x = x;
    out->y = y;
    return *out;
}

struct V3Src {
    float x, y, z;
    V2 xy(V2* out) const;
};

V2 V3Src::xy(V2* out) const {
    out->x = x;
    out->y = y;
    return *out;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

extern "C" void __cdecl sub_8276a0(Vec3* out, const Vec3* a, const Vec3* b);

struct PBBBuilder {
    char pad0[4];
    void* field4;
    char pad8[0x10];
    float f18;
    float f1c;
    float f20;
    void build(
        const V3Src* a,
        const V3Src* b,
        const V3Src* c,
        const V3Src* d,
        float f1,
        float f2,
        float f3,
        char flag1,
        char flag2,
        char flag3,
        float f4,
        float f5,
        float f6);
};

void PBBBuilder::build(
    const V3Src* a,
    const V3Src* b,
    const V3Src* c,
    const V3Src* d,
    float f1,
    float f2,
    float f3,
    char flag1,
    char flag2,
    char flag3,
    float f4,
    float f5,
    float f6)
{
    V2 t0, t1, t2, t3;
    a->xy(&t0);
    b->xy(&t1);
    float dx = t1.x - t0.x;
    float dy = t1.y - t0.y;
    c->xy(&t2);
    d->xy(&t3);
    float sx = t2.x + t3.x;
    float sy = t2.y + t3.y;

    Vec3 v0, v1;
    sub_8276a0(&v0, (const Vec3*)&t0, (const Vec3*)&t1);
    v1.x = sx;
    v1.y = sy;
    v1.z = 0.0f;

    float g1 = g_b4c440;
    float g2 = g_b82674;

    Vec3 p0, p1, p2, p3;
    p0.x = t0.x;
    p0.y = t0.y;
    p0.z = 0.0f;
    p1.x = t1.x;
    p1.y = t1.y;
    p1.z = 0.0f;
    p2.x = t2.x;
    p2.y = t2.y;
    p2.z = 0.0f;
    p3.x = t3.x;
    p3.y = t3.y;
    p3.z = 0.0f;

    float ax = p0.x;
    if (ax > g_b53ac8) ax -= g2;
    else ax += g2;
    p0.x = ax;
    p1.x = p1.x - g2;

    if (flag1) {
        p0.z = (f1 / f4) * ax;
    } else {
        p0.z = f1;
    }
    if (flag2) {
        p1.z = (f2 / f5) * p1.x;
    } else {
        p1.z = f2;
    }
    if (flag3) {
        p2.x = t0.x;
        p2.y = t0.y;
    }

    Vec3 r0, r1, r2, r3;
    sub_8276a0(&r0, &p0, &p1);
    r1.x = f18 + r0.x;
    r1.y = f1c + r0.y;
    r1.z = f20 + r0.z;
    sub_8276a0(&r2, &p2, &p3);
    r3.x = r2.x;
    r3.y = r2.y;
    r3.z = r2.z;
    sub_8276a0(&r3, &p2, &p3);
    r3.x = r2.x;
    r3.y = r2.y;
    r3.z = r2.z;
    r3.z = r3.z * g_b62770;
    r3.y = r3.y * g_b62770;

    void** vt = *(void***)field4;
    void (*fn)(void*, Vec3*) = (void (*)(void*, Vec3*))vt[4];
    fn(field4, &r1);
}
