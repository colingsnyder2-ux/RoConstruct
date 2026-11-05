// from server: 91% by atomic.potato
extern "C" int __cdecl f6432d0();
struct S426ba0;
extern "C" void f426ba0(S426ba0 *, void *);

struct S
{
    int value;
    int f(int);
};

struct S426ba0
{
    int value;
};

int S::f(int x)
{
    static int counter;
    ++counter;
    value = f6432d0();
    f426ba0((S426ba0 *)((char *)this + 4), (void *)x);
    return (int)this;
}
