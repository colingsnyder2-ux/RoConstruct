// from server: 100% by atomic.potato
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void*);

extern char g_cs[24];
extern int g_flag;
extern int g_a;
extern int g_b;
extern int g_c;
extern int g_d;
extern int g_e;
extern int g_f;

void sub_7f4929(void*);

void* getBody()
{
    if (!(g_flag & 1))
    {
        g_flag |= 1;
        InitializeCriticalSection(g_cs);
        g_a = 0;
        g_b = 0;
        g_c = 0;
        g_d = 0xb4;
        g_e = 0x20;
        g_f = 0x20;
        sub_7f4929((void*)0x98a310);
    }
    return g_cs;
}
