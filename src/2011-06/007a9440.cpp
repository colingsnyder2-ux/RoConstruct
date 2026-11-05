// from server: 96% by atomic.potato
struct S
{
    int *unused;
    int *p;
    int pad;
    void f();
};

extern "C" void __cdecl sub_7a92d0(int *, int);
extern "C" void __cdecl sub_80a058(int *);

void S::f()
{
    int *p = this->p;
    if (p)
    {
        sub_7a92d0(p, p[3]);
        sub_80a058(p);
    }
}
