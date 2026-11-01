// from server: 60% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __stdcall func_007f3c02(S *);

int S::f(int value)
{
    return func_007f3c02((S *)((char *)this + 0x58));
}
