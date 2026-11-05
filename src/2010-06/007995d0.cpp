// from server: 59% by atomic.potato
extern int g_value;
extern "C" int __cdecl Function799370(int);
extern "C" int __cdecl Function799550(int);

int Function7995d0(int value, int mode)
{
    if (mode == 1)
    {
        if (g_value <= 1)
            Function799370(value);
        else
            Function799550(value);
    }
    else if (mode == 2)
    {
        Function799370(value);
    }
    else
    {
        Function799550(value);
    }
    return value;
}
