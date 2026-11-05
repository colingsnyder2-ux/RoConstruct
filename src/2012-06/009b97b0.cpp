// from server: 27% by atomic.potato
struct S
{
    int f(void *, void *);
};

int S::f(void *a, void *b)
{
    (void)a;
    (void)b;
    return b != 0;
}
