// from server: 95% by atomic.potato
extern void G1_func_0040c080(void *);

struct S
{
    int padding[112];
    int value;
    void f(int);
};

void S::f(int v)
{
    if (value == v)
        return;
    value = v;
    G1_func_0040c080((void *)0x00b970d0);
}
