// from server: 100% by atomic.potato
struct EventDesc
{
    int value;
    unsigned char update;

    unsigned char __thiscall f(unsigned char update);
};

unsigned char __thiscall EventDesc::f(unsigned char update)
{
    if (update)
    {
        if (value > 1)
        {
            value = value / 2;
            return 1;
        }
    }
    else
    {
        if (value < 0x10)
        {
            value += value;
            return 1;
        }
    }
    return 0;
}
