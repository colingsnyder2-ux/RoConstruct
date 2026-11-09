// from server: 2% by atomic.potato
struct Vec2 {
    float x;
    float y;
    Vec2();
    Vec2(const Vec2&);
    Vec2& operator=(const Vec2&);
};

struct Vec3 {
    float x;
    float y;
    float z;
    Vec3();
    Vec3(const Vec3&);
    Vec3& operator=(const Vec3&);
};

struct Rect2D {
    float x0;
    float y0;
    float x1;
    float y1;
    Vec2 x0y0() const;
};

struct Mat4 {
    float m[16];
};

struct TorsoBuilder {
    char pad0[0x18];
    float x;
    float y;
    float z;
    void* p;
    void build(const Vec2& a, const Vec2& b, float f, char c, const Vec2& d, const Vec2& e, const Vec2& g, const Vec2& h);
};

extern "C" float g_9aea18;
extern "C" float g_9af2dc;
extern "C" float g_9b1610;
extern "C" float g_9b1624;

void __stdcall sub_71f710(Vec3* out, const Vec3* in);

Vec2 Rect2D::x0y0() const {
    Vec2 r;
    r.x = x0;
    r.y = y0;
    return r;
}
