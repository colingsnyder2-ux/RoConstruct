// from server: 100% by atomic.potato
typedef unsigned char byte;
typedef unsigned long DWORD;

extern "C" void __cdecl Function_009831F5(const void *);

static DWORD g_flag_00E1DF94;
static DWORD g_value_00E1DF8C;
static DWORD g_value_00E1DF90;
static const unsigned char g_data_00B12CE0[] = { 0x33, 0xc0, 0xb9, 0x90, 0xdf };

void Function_00516520()
{
    if ((g_flag_00E1DF94 & 1) == 0)
    {
        g_flag_00E1DF94 |= 1;
        g_value_00E1DF8C = 0;
        g_value_00E1DF90 = 0;
        Function_009831F5(g_data_00B12CE0);
    }
}
