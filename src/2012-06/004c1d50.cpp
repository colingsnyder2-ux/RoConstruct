// from server: 61% by atomic.potato
extern "C" void __cdecl sub_743e60(int *, int *);

int g_00e1c2a0;

struct S
{
    S *f();
};

S *S::f()
{
    int value = 0;
    value = g_00e1c2a0;
    ++g_00e1c2a0;
    sub_743e60((int *)this, &value);
    return this;
}
