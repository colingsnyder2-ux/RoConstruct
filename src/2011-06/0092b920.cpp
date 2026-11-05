// from server: 100% by atomic.potato
typedef unsigned char byte;

static byte g_00D1F0E0;
static int g_00D1F0E4;

void f0092b920()
{
    if ((g_00D1F0E4 & 1) == 0)
    {
        g_00D1F0E4 |= 1;
        g_00D1F0E0 = 0;
    }
}
