// from server: 78% by atomic.potato
struct SpecialShape
{
};

int __cdecl f(int value)
{
    unsigned int masked = ((unsigned int)value) & 0x80000003u;
    if (masked != 0)
        return -1;

    value = (value - 24) >> 2;
    --value;
    if (value < 16)
        return value;
    return -1;
}
