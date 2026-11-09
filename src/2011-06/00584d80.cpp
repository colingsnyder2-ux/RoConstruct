// from server: 55% by atomic.potato
struct S
{
    int __cdecl f(int);
};

int S::f(int value)
{
    if ((unsigned int)value < 5)
        return value * 4 + 0x00CBA43C;
    return 0;
}
