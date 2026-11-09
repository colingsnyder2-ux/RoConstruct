// from server: 41% by atomic.potato
struct S
{
    void __cdecl f(float *a, const int *b);
};

int g_mask[4];

void S::f(float *a, const int *b)
{
    a[0] = *(const float *)&b[0];
    a[1] = *(const float *)&b[1];
    *(int *)&a[2] = b[2] ^ g_mask[0];
}
