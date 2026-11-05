// from server: 66% by atomic.potato
extern "C" void __stdcall ConstructString(void *, const char *);

struct S
{
    int f(void *);
    void *member_1c;
};

int S::f(void *arg)
{
    const char *name = "DragCursor";
    if (*(int *)((char *)member_1c + 0x94) != 2)
        name = "GrabRotateCursor";
    ConstructString(arg, name);
    return (int)arg;
}
