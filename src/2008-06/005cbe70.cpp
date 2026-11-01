// from server: 100% by colin
#pragma float_control(precise, off)

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

struct Vector2 {
    float x;
    float y;

    Vector2(const float& a, const float& b) : x(a), y(b) {}
    Vector2 __thiscall operator/(float divisor) const;
    Vector2 __thiscall direction() const;
};

Vector2 Vector2::direction() const {
    float squaredLength = x * x + y * y;
    if (squaredLength != 1.0f)
        return *this / (float)sqrt(squaredLength);
    return Vector2(x, y);
}
