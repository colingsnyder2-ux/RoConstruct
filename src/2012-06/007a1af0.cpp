// from server: 82% by atomic.potato
extern "C" void __cdecl Function_009831f5(const char *);

int Function_007a1af0()
{
    static int initialized = 0;
    static int value_00e4a490 = 0;
    static int value_00e4a494 = 0;

    if ((initialized & 1) == 0)
    {
        initialized |= 1;
        value_00e4a490 = 0;
        value_00e4a494 = 0;
        Function_009831f5("8csm");
    }

    return 1;
}
