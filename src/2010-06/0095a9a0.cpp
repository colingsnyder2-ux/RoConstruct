// from server: 33% by atomic.potato
struct Vec2 {
    float x;
    float y;
};

struct Vec3 {
    float x;
    float y;
    float z;
    Vec2 yz() const;
};

struct PBBBuilder {
    char pad0[4];
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    void func(const Vec3* a, const Vec2* b);
};

extern "C" double sqrt(double);

Vec2 Vec3::yz() const {
    Vec2 r;
    r.x = y;
    r.y = z;
    return r;
}

void PBBBuilder::func(const Vec3* a, const Vec2* b) {
    Vec2 t = a->yz();
    float len = t.x * t.x + t.y * t.y;
    float inv = 1.0f / (float)sqrt(len);
    float nx = t.x * inv;
    float ny = t.y * inv;
    f4 = b->x * nx;
    f8 = b->y * ny;
    fc = 0.0f;
    f10 = nx;
    f14 = ny;
}
