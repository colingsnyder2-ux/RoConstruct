// from server: 89% by atomic.potato
typedef unsigned char BYTE;
typedef unsigned long DWORD;

extern "C" void __cdecl Function_009831F5(const void *);

static volatile DWORD g_flag;
static volatile DWORD g_value0;
static volatile DWORD g_value1;
static const char g_data[] = "8csm";

void Function_0077D650()
{
    if (!(g_flag & 1))
    {
        g_flag |= 1;
        g_value0 = 0;
        g_value1 = 0;
        Function_009831F5(g_data);
    }
}
