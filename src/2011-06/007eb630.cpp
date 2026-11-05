// from server: 80% by atomic.potato
struct Climbing
{
    int *func(int, int);
};

extern int *G1_func_007ec080(Climbing *, int, int);

int *Climbing::func(int a, int b)
{
    G1_func_007ec080(this, a, b);
    *(int *)this = 0xabeca8;
    *((int *)this + 1) = 0xabec9c;
    return (int *)this;
}
