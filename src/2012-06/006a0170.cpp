// from server: 58% by atomic.potato
struct S
{
    void f(int);
    int *p;
};

extern void G1_func_0069f4b0(int *);

void S::f(int value)
{
    int *p = this->p;
    if (value)
        G1_func_0069f4b0(p + value - 0x1c);
    else
        G1_func_0069f4b0(p);
}
