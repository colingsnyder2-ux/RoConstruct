// from server: 100% by atomic.potato
struct S
{
    void f();
    int p0;
    int p1;
    int p2;
    int p3;
};

extern "C" void __cdecl sub_75bdf0(int, int);
extern "C" void __cdecl sub_7a799a(int);

void S::f()
{
    int p = p3;
    if (p != 0)
    {
        sub_75bdf0(p, *(int *)(p + 12));
        sub_7a799a(p);
    }
}
