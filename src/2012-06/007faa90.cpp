// from server: 99% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl sub_9831f5(const char *);

DWORD g_e4f474;
int g_e4f46c;
int g_e4f470;

extern "C" void __cdecl sub_7faa90()
{
    if (!(g_e4f474 & 1))
    {
        g_e4f474 |= 1;
        g_e4f46c = 0;
        g_e4f470 = 0;
        sub_9831f5("8csm");
    }
}
