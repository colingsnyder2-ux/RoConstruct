// from server: 100% by atomic.potato
typedef unsigned char BYTE;

extern "C" void __cdecl sub_9831F5(const char *);

int g_E50714;
int g_E5070C;
int g_E50710;

void function_00817740()
{
    if (g_E50714 & 1)
        return;

    g_E50714 |= 1;
    g_E5070C = 0;
    g_E50710 = 0;
    sub_9831F5((const char *)0x00b1e5a0);
}
