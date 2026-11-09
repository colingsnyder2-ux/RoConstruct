// from server: 25% by atomic.potato
struct S
{
    int *value;
    S();
    S *f(int **p);
};

S::S()
{
}

S *S::f(int **p)
{
    S *q = this;
    q->value = *p;
    ++*q->value;
    return q;
}
