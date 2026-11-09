// from server: 100% by atomic.potato
typedef unsigned char byte;

extern "C" void __cdecl Function80B15D(const char *);

int g_cd5d5c;
int g_cd5d54;
int g_cd5d58;

void Function007CB8B0()
{
    if (!(g_cd5d5c & 1))
    {
        g_cd5d5c |= 1;
        g_cd5d54 = 0;
        g_cd5d58 = 0;
        Function80B15D((const char *)0x00a3f970);
    }
}
