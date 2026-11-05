// from server: 100% by atomic.potato
extern "C" void __cdecl sub_009831f5(void *);

unsigned int g_00e2f920;
int g_00e2f918;
int g_00e2f91c;
char g_00b16a90;

void func_006d1c70()
{
    if (!(g_00e2f920 & 1))
    {
        g_00e2f920 |= 1;
        g_00e2f918 = 0;
        g_00e2f91c = 0;
        sub_009831f5(&g_00b16a90);
    }
}
