// from server: 100% by atomic.potato
extern "C" void __cdecl sub_80b15d(const char*);

unsigned int g_cca2a4;
int g_cca29c;
int g_cca2a0;

void function_005db4d0()
{
    if (!(g_cca2a4 & 1))
    {
        g_cca2a4 |= 1;
        g_cca29c = 0;
        g_cca2a0 = 0;
        sub_80b15d((const char*)0x00a35ae0);
    }
}
