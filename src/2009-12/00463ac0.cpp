// from server: 100% by atomic.potato
extern "C" void __cdecl sub_7f4929(const char *);

unsigned long g_b7b9b8;
unsigned long g_b7b9b0;
unsigned long g_b7b9b4;
char g_97ead0[4];

void sub_463ac0()
{
    if (!(g_b7b9b8 & 1))
    {
        g_b7b9b8 |= 1;
        g_b7b9b0 = 0;
        g_b7b9b4 = 0;
        sub_7f4929(g_97ead0);
    }
}
