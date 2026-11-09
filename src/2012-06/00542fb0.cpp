// from server: 67% by atomic.potato
struct S
{
    int f();
};

struct V
{
    void (__thiscall *g)(void *);
};

extern V *g_00E20704;

int S::f()
{
    void *p = *(void **)((char *)this + 0x1ac);
    if (p)
        g_00E20704->g((char *)p + 0x1c);
    return 0;
}
