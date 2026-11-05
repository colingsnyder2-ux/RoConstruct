// from server: 96% by atomic.potato
struct S
{
    void f();
    void *p0;
    void *p1;
    void *p2;
};

extern "C" void __cdecl sub_78b160(void *, int);
extern "C" void __cdecl sub_80a058(void *);

void S::f()
{
    void *p = p2;
    if (p != 0)
    {
        sub_78b160(p, *(int *)((char *)p + 12));
        sub_80a058(p);
    }
}
