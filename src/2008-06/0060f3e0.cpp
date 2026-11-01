// from server: 100% by king_originala
extern "C" double __cdecl fabs(double);
#pragma intrinsic(fabs)

struct Vector3 {
    float x, y, z;
};

struct S {
    Vector3 lower;
    Vector3 upper;
    int f(const Vector3& p);
};

int S::f(const Vector3& p)
{
    int result = 0;
    double d1 = fabs(p.y - upper.y);
    double d2 = fabs(p.z - upper.z);
    double d3 = fabs(p.x - lower.x);
    double d4 = fabs(p.y - lower.y);
    double d5 = fabs(p.z - lower.z);
    double minimum = fabs(p.x - upper.x);

    if (minimum > d1) {
        minimum = d1;
        result = 1;
    }
    if (d2 < minimum) {
        minimum = d2;
        result = 2;
    }
    if (d3 < minimum) {
        minimum = d3;
        result = 3;
    }
    if (d4 < minimum) {
        minimum = d4;
        result = 4;
    }
    if (d5 < minimum)
        result = 5;

    return result;
}
