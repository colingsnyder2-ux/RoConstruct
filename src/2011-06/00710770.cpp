// from server: 100% by atomic.potato
extern "C" void G1_func_00710450(void *, void *, int);

struct S
{
    void __cdecl f(void *, int);
};

void S::f(void *a, int b)
{
    if (b != 4)
    {
        G1_func_00710450(this, a, b);
        return;
    }

    *(int *)a = 0x00C81298;
    *((unsigned char *)a + 4) = 0;
    *((unsigned char *)a + 5) = 0;
}
