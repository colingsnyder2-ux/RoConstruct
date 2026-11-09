// from server: 93% by atomic.potato
extern "C" void __cdecl sub_00521e20(void *, void *, unsigned int);

struct S
{
    void f(void *);
};

void S::f(void *arg)
{
    sub_00521e20(arg, (void *)0x00a7f018, 0xc84);
}
