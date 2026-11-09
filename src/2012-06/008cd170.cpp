// from server: 61% by atomic.potato
struct BodyMover
{
    int f();
};

struct VTable
{
    void (__thiscall *fn)(void *, void *, char *);
};

extern VTable *g_table;

int BodyMover::f()
{
    char flag = 1;
    char *p = 0;
    if (this)
        p = (char *)this + 0x1c;
    g_table->fn(g_table, p, &flag);
    return 0;
}
