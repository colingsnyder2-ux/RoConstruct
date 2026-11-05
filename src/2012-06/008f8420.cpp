// from server: 50% by atomic.potato
extern "C" void __cdecl G_004015A0(int, int);
extern "C" void __cdecl G_009831F5(int);

extern int g_00E565A0;
extern int g_00E56598;
extern int g_00E5659C;

struct S {
    void f();
};

void S::f()
{
    *(int*)this = 0;
    G_004015A0(0x00E565D8, 0x008F80B0);
    if ((g_00E565A0 & 1) == 0)
    {
        g_00E565A0 |= 1;
        g_00E56598 = 0;
        g_00E5659C = 0;
        G_009831F5(0x00B20EF0);
    }
}
