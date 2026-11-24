// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: G3D/Vector2.h already defines Vector2::clamp inline, which caused C2084.
// So this file uses a minimal local layout-compatible Vector2 (float x, y) in
// namespace G3D, and defines the out-of-line member with the same mangled name.
// INFERRED: the original was built with /fp:fast (no temporary float stores), so the
// pragma below reproduces that under the given flags.

#pragma float_control(precise, off)

namespace G3D {

class Vector2 {
public:
    float x;
    float y;

    Vector2() {}
    Vector2(float _x, float _y) : x(_x), y(_y) {}

    Vector2 clamp(const Vector2& lo, const Vector2& hi) const;
};

static inline float clampf(float val, float low, float hi) {
    if (val <= low) {
        return low;
    } else if (val >= hi) {
        return hi;
    } else {
        return val;
    }
}

Vector2 Vector2::clamp(const Vector2& lo, const Vector2& hi) const {
    return Vector2(clampf(x, lo.x, hi.x), clampf(y, lo.y, hi.y));
}

}
