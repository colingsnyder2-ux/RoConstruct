// from server: 100% by atomic.potato
struct S
{
    char pad[12];
    int *p;

    void f();
};

extern "C" void __cdecl Function_007aa380(int *, int);
extern "C" void __cdecl Function_0080a058(int *);

void S::f()
{
    int *p = this->p;
    if (p != 0)
    {
        Function_007aa380(p, p[3]);
        Function_0080a058(p);
    }
}
