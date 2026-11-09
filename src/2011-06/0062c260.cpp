// from server: 16% by atomic.potato
struct S
{
    int *a;
    int *b;
    S();
};

S::S()
{
    int *p = 0;
    int q = 0;
    a = p;
    b = &q;
}
