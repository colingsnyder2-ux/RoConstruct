// from server: 84% by atomic.potato
struct S
{
    int f();
    int m0;
    int m8;
    int m20;
};

extern "C" void __stdcall sub_561a30(int *);

int S::f()
{
    sub_561a30(&m8);
    m0 = -1;
    m20 = -1;
    return (int)this;
}
