// from server: 7% by atomic.potato
struct Vec2 { float x; float y; };
struct Vec3 { float x; float y; float z; };

struct Rect2D {
    Vec2 x0y0() const;
};

struct Src {
    Vec2 v;
};

struct Builder {
    char pad0[4];
    void* field4;
    char pad8[0x10];
    float f18;
    float f1c;
    float f20;
    void method(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, char);
};

Vec2 Rect2D::x0y0() const {
    Vec2 r;
    r.x = *(float*)this;
    r.y = *((float*)this + 1);
    return r;
}

extern float g_9aea18;
extern float g_9af2dc;

void Builder::method(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, float a13, float a14, float a15, float a16, float a17, float a18, float a19, char flag) {
    Vec2 p1 = ((Rect2D*)&a1)->x0y0();
    Vec2 p2 = ((Rect2D*)&a2)->x0y0();
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;

    Vec2 p3 = ((Rect2D*)&a3)->x0y0();
    Vec2 p4 = ((Rect2D*)&a4)->x0y0();
    float sx = p3.x + p4.x;
    float sy = p3.y + p4.y;

    Vec3 v;
    v.x = dx;
    v.y = dy;
    v.z = 0.0f;

    Vec3 w;
    w.x = sx;
    w.y = sy;
    w.z = 0.0f;

    float f38, f3c;
    if (a5 > 0.0f) {
        f38 = a5 - a6;
    } else {
        f38 = a6 + a5;
    }
    if (a7 > 0.0f) {
        f3c = a7 - a6;
    } else {
        f3c = a6 + a7;
    }

    Vec3 pos;
    pos.x = a8;
    pos.y = a9;
    pos.z = a10;

    if (flag) {
        pos.x = a11;
        pos.y = a12;
    }

    Vec3 tmp;
    tmp.x = f38;
    tmp.y = f3c;
    tmp.z = 0.0f;
    Vec3 out;
    out.x = tmp.x;
    out.y = tmp.y;
    out.z = tmp.z;

    Vec3 v2;
    v2.x = this->f18 + out.x;
    v2.y = this->f1c + out.y;
    v2.z = this->f20 + out.z;

    Vec3 v3;
    v3.x = out.x;
    v3.y = out.y;
    v3.z = out.z;

    Vec3 v4;
    v4.x = out.x;
    v4.y = out.y;
    v4.z = out.z;

    Vec3 v5;
    v5.x = out.x;
    v5.y = out.y;
    v5.z = out.z;

    v5.z = v5.z * g_9af2dc;
    v5.y = v5.y * g_9af2dc;

    void** vt = *(void***)this->field4;
    void (*fn)(void*, Vec3*) = (void (*)(void*, Vec3*))vt[4];
    fn(this->field4, &v5);
}
