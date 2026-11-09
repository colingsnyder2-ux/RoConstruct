// from server: 100% by atomic.potato
extern "C" void __cdecl sub_80B15D(void*);

unsigned int g_cca2b8;
int g_cca2b0;
int g_cca2b4;

void sub_5DB850()
{
    if ((g_cca2b8 & 1) == 0)
    {
        g_cca2b8 |= 1;
        g_cca2b0 = 0;
        g_cca2b4 = 0;
        sub_80B15D((void*)0xA35AC0);
    }
}
