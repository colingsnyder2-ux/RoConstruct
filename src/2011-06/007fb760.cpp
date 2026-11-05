// from server: 100% by atomic.potato
extern int g_00c950a0;
extern "C" void G1_func_007fb4a0(void *);
extern "C" void G1_func_007fb710(void *);

void *func_007fb760(void *p)
{
    if (g_00c950a0 <= 1)
        G1_func_007fb4a0(p);
    else
        G1_func_007fb710(p);
    return p;
}
