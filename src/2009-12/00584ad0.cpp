// from server: 2% by atomic.potato
struct Vec2
{
    float x;
    float y;
};

struct Vec3
{
    float x;
    float y;
    float z;
};

struct Mat4
{
    float m[16];
};

struct Rect2D
{
    float x0;
    float y0;
    float x1;
    float y1;
    Vec2 x0y0(Vec2* out) const;
};

Vec2 Rect2D::x0y0(Vec2* out) const
{
    out->x = x0;
    out->y = y0;
    return *out;
}
