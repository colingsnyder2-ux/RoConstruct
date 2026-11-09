// from server: 37% by atomic.potato
struct S
{
};

void __cdecl f(float *a, int *b)
{
    a[0] = 0.0f;
    a[1] = 0.0f;
    float v = (float)b[1];
    if (b[0] != 0)
        a[1] = v;
    else
        a[0] = v;
}
