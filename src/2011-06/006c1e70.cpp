// from server: 34% by atomic.potato
struct S
{
    void __cdecl f(int *p);
};

void S::f(int *p)
{
    p[0] = 0;
    p[1] = 0;
}
