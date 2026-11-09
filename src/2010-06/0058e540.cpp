// from server: 45% by atomic.potato
struct S
{
    int pad[4];
    int data;
    int (*callback)(S *, double);

    int run(int *p, double *q);
};

int S::run(int *p, double *q)
{
    int *base = p ? p - 7 : 0;
    double v = *q;
    return callback(this, v);
}
