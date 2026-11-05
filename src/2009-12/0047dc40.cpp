// from server: 28% by atomic.potato
struct S
{
    void f(const float *p);
    float data[64];
};

void __thiscall S::f(const float *p)
{
    float *d = data + 63;
    int i;
    for (i = 0; i < 9; ++i)
        d[i] = p[i];
}
