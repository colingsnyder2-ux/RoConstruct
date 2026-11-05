// from server: 50% by atomic.potato
extern "C" void __cdecl Call49C0F0(void *, void *);

struct S
{
    int unused[45];
    void *field_b4;
    int f(void *);
};

int S::f(void *out)
{
    if (field_b4 != 0)
    {
        Call49C0F0(field_b4, out);
        return (int)out;
    }

    *(int *)out = 0;
    *((int *)out + 1) = 0;
    return 0;
}
