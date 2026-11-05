// from server: 75% by atomic.potato
extern "C" void __cdecl sub_7F4929(const void *);

unsigned char g_00B7B9AC;
int g_00B7B9A8;

void sub_463A90()
{
    if (!g_00B7B9AC)
    {
        g_00B7B9AC = 1;
        g_00B7B9A8 = 0;
        sub_7F4929((const void *)0x0097EAF0);
    }
}
