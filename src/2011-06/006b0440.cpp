// from server: 100% by atomic.potato
extern "C" void __stdcall sub_411f60(unsigned int);

struct BoundFuncDesc
{
    unsigned char padding[0x1c8];
    int value_1c8;
    void setValue(int value);
};

void BoundFuncDesc::setValue(int value)
{
    if (value < 0)
        value = 0;
    else if (value > 1)
        value = 1;

    if (value_1c8 != value)
    {
        value_1c8 = value;
        sub_411f60(0xcd02e0);
    }
}
