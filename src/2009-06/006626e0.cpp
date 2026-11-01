// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector2 {
    float x, y;
    Vector2() {}
    Vector2(float a, float b) : x(a), y(b) {}
    Vector2 operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
    Vector2 operator*(float s) const { return Vector2(x * s, y * s); }
};
struct Rect2D {
    Vector2 low, high;
    Vector2 anchor(int xAlign, int yAlign) const;
};
Vector2 Rect2D::anchor(int xAlign, int yAlign) const
{
Vector2 r = (high + low) * 0.5f; switch (xAlign) { case 2: r.x = low.x; break; case 3: r.x = high.x; break; }
switch (yAlign) { case 0: r.y = low.y; break; case 1: r.y = high.y; break; }
return r;
}
