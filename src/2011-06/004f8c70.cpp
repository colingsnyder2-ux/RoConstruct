// from server: 69% by atomic.potato
struct S
{
    int value;
    void __cdecl f(void *, void *);
};

extern "C" void __cdecl sub_4f0920(void *, void *);
extern "C" void __cdecl sub_4f7330(void *);

void S::f(void *a, void *b)
{
    void *p;
    sub_4f0920(&p, a);
    if (value != 0)
        sub_4f7330(&p);
}
