// from server: 47% by atomic.potato
struct S
{
    void __cdecl f(unsigned int *a, const unsigned int *b);
};

unsigned int g_mask[4];

void S::f(unsigned int *a, const unsigned int *b)
{
    a[0] = b[0];
    a[1] = b[1] ^ g_mask[0];
    a[2] = b[2];
}
