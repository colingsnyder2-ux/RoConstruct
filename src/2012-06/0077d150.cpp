// from server: 68% by atomic.potato
extern "C" void __cdecl f(void *);

static int g0;
static int g1;
static unsigned char g2;

void f(void *)
{
}

int main()
{
    if (!g2)
    {
        g2 = 1;
        g0 = 0;
        g1 = 0;
        f((void *)0x00b18da0);
    }
    return 0;
}
