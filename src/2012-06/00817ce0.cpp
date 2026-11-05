// from server: 89% by atomic.potato
extern "C" void __cdecl Function9831F5(const char *);

volatile unsigned long GlobalE50724;
volatile unsigned long GlobalE5071C;
volatile unsigned long GlobalE50720;

void Function817CE0()
{
    if (GlobalE50724 & 1)
        return;

    GlobalE50724 |= 1;
    GlobalE5071C = 0;
    GlobalE50720 = 0;
    Function9831F5("8csm");
}
