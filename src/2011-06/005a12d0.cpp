// from server: 100% by atomic.potato
extern int g_00CBD044;
extern int g_00CBD03C;
extern int g_00CBD040;
extern int g_00A35150;

extern "C" void __cdecl sub_0080B15D(const int&);

void Function_005A12D0()
{
    if ((g_00CBD044 & 1) == 0)
    {
        g_00CBD044 |= 1;
        g_00CBD03C = 0;
        g_00CBD040 = 0;
        sub_0080B15D(g_00A35150);
    }
}
