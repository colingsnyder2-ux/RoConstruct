// from server: 62% by atomic.potato
extern "C" void G1_func_00b22648(void *, const char *);

struct S
{
    char pad[64];
    char flag;
    S *f(const char *);
};

S *S::f(const char *)
{
    const char *name = flag ? "GrabRotateCursor" : "DragCursor";
    G1_func_00b22648(this, name);
    return this;
}
