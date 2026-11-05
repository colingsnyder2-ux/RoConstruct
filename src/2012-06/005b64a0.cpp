// from server: 24% by atomic.potato
struct S
{
    S *f(int);
    S *g(int);
};

S *S::g(int value)
{
    int local = 0;
    unsigned char flag = 0;
    return this->f(local);
}
