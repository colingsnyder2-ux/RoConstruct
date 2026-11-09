// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector2 { volatile float x, y; Vector2(const Vector2& o) : x(o.x), y(o.y) {} };
Vector2 func_004672e0(const Vector2& v, int amount)
{
    Vector2 result = v;
    float x = v.x;
    result.x += (x > 0.0f ? 1.0f : (x < 0.0f ? -1.0f : 0.0f)) * amount;
    float y = v.y;
    result.y += (y > 0.0f ? 1.0f : (y < 0.0f ? -1.0f : 0.0f)) * amount;
    return result;
}
