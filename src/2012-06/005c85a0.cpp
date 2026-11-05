// from server: 68% by atomic.potato
struct S
{
};

int __cdecl f(unsigned int a, unsigned int b)
{
    unsigned int d;

    if (b == a)
        return 0;

    d = (b - a) & 0x00ffffffU;
    if (d >= 0x007fffffU)
        return 0;

    return 1;
}
