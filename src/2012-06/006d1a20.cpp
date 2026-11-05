// from server: 100% by atomic.potato
extern "C" void G1_func_009831f5(const char *);

static unsigned long g_00e2f908;
static unsigned long g_00e2f900;
static unsigned long g_00e2f904;

void func_006d1a20()
{
    if (!(g_00e2f908 & 1))
    {
        g_00e2f908 |= 1;
        g_00e2f900 = 0;
        g_00e2f904 = 0;
        G1_func_009831f5((const char *)0x00b16a30);
    }
}
