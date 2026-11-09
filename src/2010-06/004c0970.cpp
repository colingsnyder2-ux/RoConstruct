// from server: 100% by atomic.potato
struct S_func_004c0970
{
    int f();
};

extern "C" char sub_004d58c0(S_func_004c0970 *, int);

int S_func_004c0970::f()
{
    if (*((int *)((char *)this + 0x128)) == 0)
    {
        if (sub_004d58c0(this, 1) == 0)
            return 0;
    }
    return 1;
}
