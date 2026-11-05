// from server: 100% by king_originala
extern "C" double __cdecl acos(double);
#pragma intrinsic(acos)
#pragma float_control(precise, off)

extern const float tolerance;
extern const float fullTurn;

struct S {
    float x, y;
    float normalize(float tolerance);
};

float __cdecl angle(const S& value)
{
    S v;
    v.x = value.x;
    v.y = value.y;
    v.normalize(tolerance);

    float result = (float)acos(v.x);
    if (v.y < 0.0f)
        result = fullTurn - result;
    return result;
}
