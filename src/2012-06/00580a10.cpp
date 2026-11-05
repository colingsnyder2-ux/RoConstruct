// from server: 58% by atomic.potato
struct S
{
    S& f(int);
};

S& S::f(int a)
{
    this->f(a);
    if (a & 1)
    {
        S* p = (S*)((char*)this - 4);
        p->f(a);
    }
    return *this;
}
