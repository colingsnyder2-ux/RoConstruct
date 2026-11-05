// from server: 17% by atomic.potato
extern "C" float __cdecl helper(float, float);

struct S {
    float f(float a, float b, float c, float d, float e, float f);
};

float S::f(float a, float b, float c, float d, float e, float f)
{
    float t = f * f;
    float u = f + f;
    float v = t * 0.0f;
    float w = u - v + 0.0f;
    float x = t - v;
    float y = t - w;
    float z = w - t;
    float r0 = z * a + y * b + x * c + w * d;
    float r1 = z * a + y * b + x * c + w * d;
    float r2 = z * a + y * b + x * c + w * d;
    float r3 = z * a + y * b + x * c + w * d;
    return r0 + r1 + r2 + r3;
}
