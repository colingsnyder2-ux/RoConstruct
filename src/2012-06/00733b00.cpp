// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __stdcall Target(DWORD);

void __stdcall Function(DWORD value)
{
    if (value == 0x00e4e9f8)
    {
        value = 0x00e33e28;
        Target(value);
    }
    else if (value == 0x00e4ea28)
    {
        value = 0x00e33e54;
        Target(value);
    }
}
