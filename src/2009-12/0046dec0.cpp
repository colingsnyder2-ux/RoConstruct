// from server: 100% by atomic.potato
struct S_func_0046abe0
{
    int *f();
};

struct S_func_0046a8c0
{
    int f(int);
};

struct S_func_0046a890
{
    void f(int);
};

struct S
{
    void f(int);
};

void S::f(int)
{
    int *p = ((S_func_0046abe0 *)this)->f();
    if (((S_func_0046a8c0 *)p)->f(1))
        ((S_func_0046a890 *)p)->f(1);
}
