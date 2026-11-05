// from server: 25% by atomic.potato
struct Vec2 { float x; float y; };

struct GuiBase {
    virtual void getRect(Vec2* out);
    short field4;
    short field6;
};

struct Rect { float x0; float y0; float x1; float y1; };

void GuiBase::getRect(Vec2* out) {
    Vec2 a;
    Vec2 b;
    this->getRect(&a);
    float ax = a.x;
    float ay = a.y;
    float bx = b.x;
    float by = b.y;
    float w = (float)this->field4 + a.y;
    float h = (float)this->field6 + b.y;
    out->x = 0.0f;
    out->y = 0.0f;
    float v0 = ax;
    float v1 = w;
    float v2 = bx;
    float v3 = h;
    float r0 = (ax > bx) ? bx : ax;
    float r1 = (h > w) ? w : h;
    float r2 = (bx > ax) ? ax : bx;
    float r3 = (w > h) ? h : w;
    out->x = r0;
    out->y = r1;
    out->x = r2;
    out->y = r3;
}
