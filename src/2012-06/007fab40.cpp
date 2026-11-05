// from server: 91% by atomic.potato
typedef unsigned char BYTE;
typedef unsigned long DWORD;

extern "C" void __cdecl Function9831F5(const char *);

volatile DWORD gE4F498;
volatile DWORD gE4F490;
volatile DWORD gE4F494;

void Function007FAB40()
{
    if (!(gE4F498 & 0xFF))
    {
        gE4F498 |= 1;
        gE4F490 = 0;
        gE4F494 = 0;
        Function9831F5("8csm");
    }
}
