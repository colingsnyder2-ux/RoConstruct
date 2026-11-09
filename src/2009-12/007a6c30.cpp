// from server: 38% by atomic.potato
struct S
{
    float pad0[9];
    float f1;
    float f2;
    float f3;
    S *f(S *p);
};

S *S::f(S *p)
{
    p->f1 = f1;
    p->f2 = f2;
    p->f3 = f3;
    return p;
}
