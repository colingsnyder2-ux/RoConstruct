// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl sub_4015A0(const void *, const void *);
extern "C" void __cdecl sub_9831F5(const void *);

static DWORD g_00E20110;
static DWORD g_00E20114;
static DWORD g_00E20118;

struct S
{
    void *f();
};

void *S::f()
{
    sub_4015A0((const void *)0x00E2011C, (const void *)0x0052E4F0);
    if (!(g_00E20118 & 1))
    {
        g_00E20118 |= 1;
        g_00E20110 = 0;
        g_00E20114 = 0;
        sub_9831F5((const void *)0x00B12DC0);
    }
    return (void *)0x00E20110;
}
