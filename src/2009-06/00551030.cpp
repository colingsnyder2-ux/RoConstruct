// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Vector2 { float x, y; };
struct Rect { float x, y, z, w, h; };
extern const float kEps;
struct Scaler {
    float sx, sy;
    bool scaleX, scaleY;
    void apply(Rect& r, const Vector2& size, int unused);
};
void Scaler::apply(Rect& r, const Vector2& size, int)
{
    if (r.x > 0.0f) r.x -= kEps; else r.x += kEps;
    if (r.y > 0.0f) r.y -= kEps; else r.y += kEps;
    r.w = scaleX ? (r.x / size.x) * sx : sx;
    r.h = scaleY ? (sy / size.y) * r.y : sy;
}
