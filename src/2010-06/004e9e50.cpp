// from server: 63% by atomic.potato
extern "C" void __cdecl sub_4e1f30(void *, void *);
extern "C" void __cdecl sub_4e87a0(void *);

struct S
{
    void __cdecl f(void *);
};

void __cdecl S::f(void *arg)
{
    char temporary[12];
    sub_4e1f30(arg, temporary);
    if (*(int *)((char *)arg + 4) != 0)
        sub_4e87a0(temporary);
}
