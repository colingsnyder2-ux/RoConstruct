// from server: 50% by atomic.potato
struct S
{
    float __cdecl f(float const *, float const *);
};

float S::f(float const *a, float const *b)
{
    float x = a[0] - b[0];
    float y = a[1] - b[1];
    float z = b[2];
    return (z * x + z * y) / y;
}
