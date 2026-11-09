// from server: 40% by atomic.potato
struct S
{
    int *field;
    void *f(int *out);
};

extern void *G1_func_004B1410(void *, int *);

void *S::f(int *out)
{
    int *p = field;
    if (p != 0)
    {
        G1_func_004B1410(p, out);
        return out;
    }
    out[0] = 0;
    out[1] = 0;
    return out;
}
