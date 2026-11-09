// from server: 45% by atomic.potato
struct CylinderBuilder
{
    void f(float *out, int value);
};

void CylinderBuilder::f(float *out, int value)
{
    out[0] = 0.0f;
    int n = value >= 0 ? 6 : 2;
    ((int *)out)[1] = n;
    ((int *)out)[2] = n;
}
