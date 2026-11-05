// from server: 36% by atomic.potato
struct S
{
    int f(void *);
    int *vtable;
    int pad[17];
};

int S::f(void *arg)
{
    int *p = (int *)arg;
    int code = p[2];

    if (code == 0x7f || code == 0x1b)
    {
        int *q = (int *)((char *)this + 0x48);
        return ((int (__thiscall *)(int *))q[0])(q);
    }

    return 0;
}
