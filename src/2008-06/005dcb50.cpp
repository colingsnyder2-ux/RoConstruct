// from server: 100% by colin
// from server: 98% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

struct V2 {
    float x, y;
    V2(float _x, float _y) : x(_x), y(_y) {}
    V2 operator+(const V2& v) const { return V2(x + v.x, y + v.y); }
    V2 operator*(float s) const { return V2(s * x, s * y); }
};

struct Color {
    float r, g, b, a;
};

struct Rect {
    Vec2 low, high;
};

extern const float halfValue;
extern const double textSize;

extern "C" void __cdecl makeRect(Rect*, const Vec2*, const Vec2*);
extern "C" const Vec3& __cdecl zeroVector();
extern "C" const Vec3& __cdecl oneVector();

struct Renderer {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual Rect bounds() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void fillRect(const Rect&, const Color&) = 0;
    virtual void slot12() = 0;
    virtual void drawText(const Rect&, const void*, const V2&,
                          double, const Color&, const Color&,
                          int, int, int) = 0;
};

union Work {
    struct {
        Color background;
        Rect rectangle;
    } fill;
    struct {
        Color outline;
        Color foreground;
    } text;
};

struct S {
    char storage[0x140];
    void render(Renderer*);
};

void S::render(Renderer* renderer)
{
    Rect bounds = renderer->bounds();
    Rect area;
    area.low.x = bounds.low.x;
    area.low.y = bounds.low.y;
    area.high.x = bounds.high.x;
    area.high.y = bounds.high.y;

    V2 c = (V2(area.low.x, area.low.y) + V2(area.high.x, area.high.y)) * halfValue;

    Work work;
    work.fill.background.r = halfValue;
    work.fill.background.g = halfValue;
    work.fill.background.b = halfValue;
    work.fill.background.a = halfValue;

    makeRect(&work.fill.rectangle, &area.low, &area.high);
    renderer->fillRect(work.fill.rectangle, work.fill.background);

    const Vec3& zero = zeroVector();
    work.text.outline.r = zero.x;
    work.text.outline.g = zero.y;
    work.text.outline.b = zero.z;
    work.text.outline.a = 1.0f;

    const Vec3& one = oneVector();
    work.text.foreground.r = one.x;
    work.text.foreground.g = one.y;
    work.text.foreground.b = one.z;
    work.text.foreground.a = 1.0f;

    renderer->drawText(area, storage + 0x140, c, textSize,
                       work.text.foreground, work.text.outline, 2, 2, 0);
}
