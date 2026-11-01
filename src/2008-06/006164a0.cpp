// from server: 100% by king_originala
struct Rect {
    float x0, y0, x1, y1;
    Rect(const Rect&);
};

struct Vector3 {
    float x, y, z;
};

struct Color {
    float r, g, b, a;
};

extern Rect __cdecl makeRect(float, float, float, float);
extern const Vector3& __cdecl getColor();
extern const float depth;

struct Renderer {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void draw(const Rect&, float, const Color&);
};

struct S {
    char padding[0x26];
    short x0, y0, x1, y1;
    void draw(Renderer*);
};

void S::draw(Renderer* renderer)
{
    Rect rect = makeRect((float)x0, (float)y0, (float)x1, (float)y1);
    const Vector3& rgb = getColor();
    Color color = { rgb.x, rgb.y, rgb.z, 1.0f };
    renderer->draw(rect, depth, color);
}
