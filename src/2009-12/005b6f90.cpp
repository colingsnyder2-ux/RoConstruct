// from server: 18% by atomic.potato
struct Vec2 { float x; float y; };
struct Vec3 { float x; float y; float z; };

struct Rect2D {
    float x0, y0, x1, y1;
    Vec2 x0y0() const;
};

struct Mat3 {
    float m[12];
};

struct HeadBuilder {
    char pad0[4];
    void* ptr4;
    char pad8[0x10];
    float f18;
    float f1c;
    float f20;
    void build(Rect2D* r, Vec3* v, int a, int b, int c, int d, int e, int f);
};

extern "C" void __stdcall sub_71f760(float* out, float* in);
extern "C" void __stdcall sub_5f6cf0(float* out, float* a, float* b);

extern float g_9aea18;
extern float g_9af2dc;

Vec2 Rect2D::x0y0() const {
    Vec2 v;
    v.x = x0;
    v.y = y0;
    return v;
}

void HeadBuilder::build(Rect2D* r, Vec3* v, int a, int b, int c, int d, int e, int f) {
    Vec2 p0 = r->x0y0();
    Vec2 p1 = ((Rect2D*)ptr4)->x0y0();
    float dx = p1.x - p0.x;
    float dy = p1.y - p0.y;

    Vec2 q0 = r->x0y0();
    Vec2 q1 = ((Rect2D*)ptr4)->x0y0();
    float sx = q0.x + q1.x;
    float sy = q0.y + q1.y;

    float tmp[2];
    sub_5f6cf0(tmp, &sx, &sy);

    float m[12];
    m[0] = tmp[0];
    m[1] = tmp[1];
    m[2] = 0.0f;
    m[3] = 0.0f;
    m[4] = 0.0f;
    m[5] = 0.0f;
    m[6] = 0.0f;
    m[7] = 0.0f;
    m[8] = 0.0f;
    m[9] = 0.0f;
    m[10] = 0.0f;
    m[11] = 0.0f;

    float vx = v->x;
    float vy = v->y;
    float vz = v->z;

    float out[2];
    sub_5f6cf0(out, &vx, &vy);

    m[0] = vx;
    m[1] = vy;
    m[2] = vz;
    m[3] = 0.0f;
    m[4] = 0.0f;
    m[5] = 0.0f;
    m[6] = g_9aea18;
    m[7] = g_9aea18;
    m[8] = 0.0f;
    m[9] = 0.0f;
    m[10] = 0.0f;
    m[11] = 0.0f;

    m[6] = out[0];
    m[7] = out[1];
    m[8] = 0.0f;
    m[9] = 0.0f;
    m[10] = 0.0f;
    m[11] = 0.0f;

    void (*fn)(float*, float*, float*) = *(void(**)(float*, float*, float*))((char*)this + 0xac);
    fn(m, &vx, &vy);

    if (*(char*)((char*)this + 0xbc)) {
        m[6] = v->x;
        m[7] = v->y;
    }

    float r1[2];
    sub_71f760(r1, m);

    float r2[2];
    r2[0] = f18 + r1[0];
    r2[1] = f1c + r1[1];
    float r2z = f20 + 0.0f;

    float r3[2];
    sub_71f760(r3, r2);

    m[6] = r3[0];
    m[7] = r3[1];
    m[8] = r2z;

    float r4[2];
    sub_71f760(r4, m);

    m[6] = r4[0];
    m[7] = r4[1];
    m[8] = r2z;

    float scale = g_9af2dc;
    m[6] = m[6] * scale;
    m[7] = m[7] * scale;

    void* obj = ptr4;
    void** vtbl = *(void***)obj;
    void (*fn2)(void*, float*) = (void(*)(void*, float*))vtbl[4];
    fn2(obj, m);
}
