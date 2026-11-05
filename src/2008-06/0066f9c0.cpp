// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Rect
{
    float x, y, z, w;
};

struct Renderer
{
    void draw(int mode, float x, float y, float z, float w, unsigned int color);
};

struct Context
{
    char padding[20];
    Renderer* renderer;
};

struct S
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int height();

    Context* context;

    void draw(const Rect* rect, unsigned int unused, unsigned int color);
};

void S::draw(const Rect* rect, unsigned int unused, unsigned int color)
{
    float w = rect->w;
    float z = rect->z;
    float y = rect->y;
    float x = rect->x;
    Renderer* renderer = context->renderer;
    renderer->draw(2, x, (height() - 1) - y,
                   z, (height() - 1) - w, color);
}
