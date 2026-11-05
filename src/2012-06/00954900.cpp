// from server: 64% by atomic.potato
struct S
{
    char pad[0x4c];
    char flag;
    int f(const char *);
};

extern "C" int __stdcall G1_func_00B22648(void *, const char *);

int S::f(const char *arg)
{
    const char *name = flag ? "DragCursor" : "GrabRotateCursor";
    G1_func_00B22648((void *)this, name);
    return (int)this;
}
