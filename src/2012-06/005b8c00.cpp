// from server: 91% by atomic.potato
extern "C" void G1_func_009831f5(const char *);

int func_005b8c00()
{
    static int initialized = 0;
    static int value1 = 0;
    static int value2 = 0;

    if ((initialized & 1) != 0)
        return 0;

    initialized |= 1;
    value1 = 0;
    value2 = 0;
    G1_func_009831f5("8csm");
    return 0;
}
