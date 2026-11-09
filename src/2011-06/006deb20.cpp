// from server: 66% by atomic.potato
struct S
{
    int value0;
    int value1;
    int value2;
    int value3;
    int (*get)(int);
    int unused;
    int f(int *, int *);
};

int S::f(int *out, int *value)
{
    int *p = value ? value - 7 : 0;
    int *result = (int *)get(value0 + (int)p);
    out[0] = result[0];
    out[1] = result[1];
    out[2] = result[2];
    return (int)out;
}
