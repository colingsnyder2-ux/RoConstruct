// from server: 75% by atomic.potato
struct S
{
    int __cdecl f(unsigned int *result, unsigned int value, unsigned int count);
};

int S::f(unsigned int *result, unsigned int value, unsigned int count)
{
    if (0xffffffffU - value < count)
        return (int)0x80070057U;
    *result = value + count;
    return 0;
}
