// from server: 100% by atomic.potato
struct S
{
    int padding[3];
    int *p;

    void f();
};

extern "C" void __cdecl sub_7a9b00(int *, int);
extern "C" void __cdecl sub_80a058(int *);

void S::f()
{
    int *p = this->p;
    if (p != 0)
    {
        sub_7a9b00(p, p[3]);
        sub_80a058(p);
    }
}
