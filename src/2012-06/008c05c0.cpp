// from server: 91% by atomic.potato
extern "C" void __cdecl Function9831F5(const char *);

int Function8C05C0()
{
    static int initialized = 0;
    static int value84 = 0;
    static int value88 = 0;

    if ((initialized & 1) != 0)
        return 0;

    initialized |= 1;
    value84 = 0;
    value88 = 0;
    Function9831F5("8csm");
    return 0;
}
