// from server: 100% by king_originala
struct Vec3 {
    float x, y, z;
};

struct Color4 {
    float r, g, b, a;
    Color4() {}
    Color4(float R, float G, float B, float A)
        : r(R), g(G), b(B), a(A) {}
    Color4(const Vec3& v, float A)
        : r(v.x), g(v.y), b(v.z), a(A) {}
};

extern const Vec3& __cdecl black();
extern const Vec3& __cdecl white();
extern int __cdecl style();

struct Renderer;
struct RenderTable {
    void* unused[10];
    void (__thiscall* outline)(Renderer*, const Color4&);
    void (__thiscall* fill)(Renderer*, const Color4&);
};

struct Renderer {
    RenderTable* table;
};

struct S {
    char padding[0x110];
    char textData[0x34];
    int selected;

    Color4 transform(const Color4&);
    Color4 transform(float, const Color4&);
    void drawText(Renderer*, const void*, const Color4&, int, int);
    void f(Renderer*);
};

void S::f(Renderer* renderer)
{
    {
        Color4 temporary;
        const Color4* color;
        if (selected) {
            static Color4 selectedColor(0.7f, 0.7f, 0.7f, 1.0f);
            color = &selectedColor;
        } else {
            const Vec3& v = white();
            temporary.r = v.x;
            temporary.g = v.y;
            temporary.b = v.z;
            temporary.a = 1.0f;
            color = &temporary;
        }
        renderer->table->fill(renderer, transform(*color));
    }
    renderer->table->outline(renderer, transform(1.0f, Color4(black(), 1.0f)));
    drawText(renderer, textData, Color4(black(), 1.0f), style(), 2);
}
