// from server: 100% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl sub_00762960(const char *, const char *, const char *);

static DWORD g_00cbb2b8;
static const char *g_00cbb2a4;
static const char *g_00cbb2b4;

int sub_00618170(const char *p)
{
    const char *a;
    if (g_00cbb2b8 >= 0x10)
        a = g_00cbb2a4;
    else
        a = (const char *)&g_00cbb2a4;
    sub_00762960(p, a, g_00cbb2b4);
    return 1;
}
