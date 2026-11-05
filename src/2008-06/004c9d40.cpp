// from server: 100% by king_originala
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct S {
    float x, y, z, w;
    void normalize();
};

void S::normalize()
{
    float inverse = 1.0f / (float)sqrt(x * x + y * y + z * z + w * w);
    x *= inverse;
    y *= inverse;
    z *= inverse;
    w *= inverse;
}
