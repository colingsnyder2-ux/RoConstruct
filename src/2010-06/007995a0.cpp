// from server: 100% by atomic.potato
extern int g_value;
extern "C" int __cdecl Function799370(int);
extern "C" int __cdecl Function799550(int);

int Function7995a0(int value)
{
    if (g_value <= 1)
        Function799550(value);
    else
        Function799370(value);
    return value;
}
