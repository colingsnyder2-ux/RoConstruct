// from server: 91% by Intel
extern "C" void __cdecl sub_4015A0(void *, void *);
extern "C" void __cdecl Function9831F5(void *);

static unsigned int g_e1df6c;
static void *g_e1df64;
static void *g_e1df68;
static char g_b12c90;

void Function513510()
{
    sub_4015A0((void *)0x512b20, (void *)0xe1df78);
    if (!(g_e1df6c & 1))
    {
        g_e1df6c |= 1;
        g_e1df64 = 0;
        g_e1df68 = 0;
        Function9831F5(&g_b12c90);
    }
}
