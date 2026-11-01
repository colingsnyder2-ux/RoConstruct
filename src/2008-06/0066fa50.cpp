// from server: 100% by king_originala
struct Vec2 {
    float x, y;
};

struct Renderer {
    void draw(float ax, float ay, float bx, float by, unsigned color);
};

struct Context {
    char padding[20];
    Renderer* renderer;
};

struct Adorn {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int height();

    Context* context;
    void draw(const Vec2& a, const Vec2& b, unsigned color);
};

#pragma float_control(precise, off, push)

void Adorn::draw(const Vec2& a, const Vec2& b, unsigned color)
{
    Renderer* renderer = context->renderer;
    renderer->draw(a.x, float(height() - 1) - a.y,
                   b.x, float(height() - 1) - b.y, color);
}

#pragma float_control(pop)
