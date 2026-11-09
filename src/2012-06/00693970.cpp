// from server: 46% by atomic.potato
struct S
{
    S* __cdecl f(int, int);
};

S* S::f(int a, int b)
{
    S* p = this;
    unsigned char z = 0;
    p->f(a, b);
    return p;
}
