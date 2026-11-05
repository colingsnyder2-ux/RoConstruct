// from server: 100% by atomic.potato
struct S
{
    int pad[3];
    int *value;

    void f();
};

extern "C" void __cdecl f78b610(int *, int);
extern "C" void __cdecl f80a058(int *);

void S::f()
{
    int *p = value;
    if (p)
    {
        f78b610(p, p[3]);
        f80a058(p);
    }
}
