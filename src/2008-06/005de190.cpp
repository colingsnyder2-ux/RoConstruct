// from server: 100% by king_originala
extern "C" double __cdecl acos(double);
#pragma intrinsic(acos)

extern const float upperResult;
extern const float lowerResult;

struct S {
    float x;
    float y;
};

double __cdecl f(const S& v)
{
    if (v.y >= 1.0f)
        return upperResult;
    if (v.y <= -1.0f)
        return lowerResult;
    return acos(v.y);
}
