// from server: 34% by atomic.potato
struct S {
    int **field;
    int f(void *, void *);
};

int S::f(void *a, void *b)
{
    void **p;
    p = (void **)((char *)this + 0x1c);
    return ((int *)p[0])[3];
}
