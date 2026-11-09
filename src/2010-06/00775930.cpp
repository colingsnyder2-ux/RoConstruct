// from server: 93% by atomic.potato


struct S
{
    int *vptr;
    int value;
    char padding[204];
    int field;
    S *f(void *, void *);
void sub_716910(void *, void *);
};

S *S::f(void *a, void *b)
{
    sub_716910(a, b);
    *vptr = 0xA529DC;
    field = 0;
    return this;
}
