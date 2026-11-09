// from server: 100% by king_originala
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct S {
    float x, y;
    float normalize(float tolerance);
};

float S::normalize(float tolerance) {
    double length = sqrt(x * x + y * y);
    if (length > tolerance) {
        double inverse = 1.0 / length;
        x = (float)(x * inverse);
        y = (float)(y * inverse);
        return (float)length;
    }
    return 0.0f;
}
