// from server: 34% by tester
struct Vec2 {
    float x;
    float y;
};

struct Vec3 {
    float x;
    float y;
    float z;
    Vec2 xy() const;
};

Vec2 Vec3::xy() const {
    Vec2 r;
    r.x = x;
    r.y = y;
    return r;
}

struct HeadBuilder {
    void __cdecl normalizeXY(Vec3* v);
};

void HeadBuilder::normalizeXY(Vec3* v) {
    float ax = v->x;
    float ay = v->y;
    float f = ax < 0.0f ? -ax : ax;
    float g = ay < 0.0f ? -ay : ay;
    float s;
    if (f >= g) {
        if (ay == 0.0f) {
            s = 0.0f;
        } else {
            Vec2 t = v->xy();
            s = ay / (float)(t.x * t.y + t.x * t.y);
        }
    } else {
        if (ax == 0.0f) {
            s = 0.0f;
        } else {
            Vec2 t = v->xy();
            s = ax / (float)(t.x * t.x + t.y * t.y);
        }
    }
    v->x = v->x * s;
    v->y = v->y * s;
}
