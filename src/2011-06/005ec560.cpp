// from server: 64% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int a)
{
    S* p = (S*)((char*)this - 12);
    p->f(a);
    if (a & 1)
        delete p;
    return (int)p;
}
