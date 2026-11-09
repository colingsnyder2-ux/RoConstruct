// from server: 86% by atomic.potato
typedef unsigned char BYTE;

extern "C" void __cdecl f(const char *);

BYTE g_flag;
int g_value0;
int g_value1;

void f0042afb0()
{
    if (!(g_flag & 1))
    {
        g_flag |= 1;
        g_value0 = 0;
        g_value1 = 0;
        f("8csm");
    }
}
