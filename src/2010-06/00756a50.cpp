// from server: 100% by atomic.potato
struct S
{
    char pad[12];
    int *p;

    void f();
};

extern "C" void __cdecl f1(int *, int);
extern "C" void __cdecl f2(int *);

void S::f()
{
    int *p = this->p;
    if (p)
    {
        f1(p, *reinterpret_cast<int *>(reinterpret_cast<char *>(p) + 12));
        f2(p);
    }
}
