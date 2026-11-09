// from server: 100% by atomic.potato
extern unsigned int g_00e1a988;
extern unsigned int g_00e1a980;
extern unsigned int g_00e1a984;
extern const char g_00b12870;

extern "C" void __cdecl func_009831f5(const char *);

void func_004a0d50()
{
    if (!(g_00e1a988 & 1))
    {
        g_00e1a988 |= 1;
        g_00e1a980 = 0;
        g_00e1a984 = 0;
        func_009831f5(&g_00b12870);
    }
}
