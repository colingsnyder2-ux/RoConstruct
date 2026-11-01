// from server: 100% by tester
struct S
{
    int *vtable;
    int value;
    int (__thiscall *get)(int *);
    int offset;
    int f(float *out, int *arg);
};

int S::f(float *out, int *arg)
{
    int *p = arg ? (int *)((char *)arg - 20) : 0;
    int *value = (int *)(get((int *)(offset + (int)p)));
    out[0] = ((float *)value)[0];
    out[1] = ((float *)value)[1];
    out[2] = ((float *)value)[2];
    return (int)out;
}
