// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl sub_9831F5(const void *);

static DWORD g_00E20110;
static DWORD g_00E20114;
static DWORD g_00E20118;

void f()
{
    if (!(g_00E20118 & 1))
    {
        g_00E20118 |= 1;
        g_00E20110 = 0;
        g_00E20114 = 0;
        sub_9831F5((const void *)0x00B12DC0);
    }
}
