// from server: 100% by king_originala
struct Vec2 {
    float x;
    float y;
};

struct Source {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual Vec2 get();
};

struct S {
    char padding0[0x20];
    Source* source;
    char padding1[0x0C];
    float x;
    float y;

    Vec2 f();
};

Vec2 S::f()
{
    if (x == 0.0f && y == 0.0f && source) {
        Vec2 value = source->get();
        x = value.x;
        y = value.y;
    }

    Vec2 result;
    result.x = x;
    result.y = y;
    return result;
}
