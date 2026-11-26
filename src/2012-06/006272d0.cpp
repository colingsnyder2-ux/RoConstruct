// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
namespace G3D {
class Vector2 {
public:
    float x, y;
    Vector2(float _x, float _y) : x(_x), y(_y) {}
    static const Vector2& one();
};
const Vector2& Vector2::one() {
    static const Vector2 v(1.0f, 1.0f);
    return v;
}
}