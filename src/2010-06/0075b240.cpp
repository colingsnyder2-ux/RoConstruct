// from server: 100% by atomic.potato
extern "C" void __cdecl sub_75b100(void *, int);
extern "C" void __cdecl sub_7a799a(void *);

struct S
{
    void f();
    char padding[12];
    void *field_0c;
};

void S::f()
{
    void *p = field_0c;
    if (p)
    {
        sub_75b100(p, *(int *)((char *)p + 12));
        sub_7a799a(p);
    }
}
