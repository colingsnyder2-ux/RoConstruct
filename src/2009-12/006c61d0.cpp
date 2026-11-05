// from server: 62% by atomic.potato
typedef unsigned char byte;
typedef unsigned int DWORD;

extern "C" void __stdcall target(DWORD);

volatile byte g_initialized = 0;
volatile DWORD g_current = 0;
volatile DWORD g_value = 0;

void __stdcall target(DWORD value)
{
    DWORD selected;

    if (g_initialized != 0)
        selected = value;
    else
        selected = 0;

    if (selected == g_current)
        return;

    g_current = selected;
    value = 0x00b9230c;
    target(value);
}
