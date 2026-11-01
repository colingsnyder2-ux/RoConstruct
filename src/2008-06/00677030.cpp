// from server: 100% by king_originala
extern const float colorComponent0;
extern const float colorComponent1;

struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c);
};

inline Vec3::Vec3(float a, float b, float c)
    : x(a), y(b), z(c) {}

struct Vec4 {
    float x, y, z, w;
};

extern const Vec3& __cdecl alternateColor();
extern void __cdecl draw(void*, void*, const Vec4&);

void __cdecl render(void* a, void* b, int mode)
{
    const Vec3* selected;
    if (mode == 0) {
        static const Vec3 color(colorComponent0, colorComponent1, 1.0f);
        selected = &color;
    } else {
        selected = &alternateColor();
    }

    Vec4 color;
    color.x = selected->x;
    color.y = selected->y;
    color.z = selected->z;
    color.w = 1.0f;
    draw(a, b, color);
}
