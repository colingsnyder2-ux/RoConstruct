// from server: 100% by atomic.potato
extern void G1_func_007aa380(void *, int);
extern void G1_func_0080a058(void *);

struct RightAngleRampPoly
{
};

void __cdecl f(void *arg)
{
    if (arg != 0)
    {
        G1_func_007aa380(arg, *(int *)((char *)arg + 12));
        G1_func_0080a058(arg);
    }
}
