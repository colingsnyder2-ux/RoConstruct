// from server: 100% by tester
extern "C" void __cdecl sub_9831F5(void*);

int g_0E20150;
int g_0E20154;
int g_0E20158;

void sub_52FE80()
{
    if ((g_0E20158 & 1) == 0)
    {
        g_0E20158 |= 1;
        g_0E20150 = 0;
        g_0E20154 = 0;
        sub_9831F5((void*)0x00B12E20);
    }
}
