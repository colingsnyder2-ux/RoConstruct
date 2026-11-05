// from server: 84% by atomic.potato
extern "C" void sym(void *);

struct S
{
    int *value;

    S();
    S *f(int *);
};

S::S()
{
}

S *S::f(int *p)
{
    sym(this);
    value = (int *)*p;
    ++*value;
    return this;
}
