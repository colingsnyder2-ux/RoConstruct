// from server: 68% by atomic.potato
extern "C" void __stdcall sub_411f60(unsigned int);

struct BoundFuncDesc
{
    unsigned char padding[0x1a0];
    int field_1a0;
    unsigned char padding2[0x45];
    unsigned char value_1e9;
    void setValue(unsigned char value);
};

void BoundFuncDesc::setValue(unsigned char value)
{
    if (value_1e9 != value)
    {
        sub_411f60(0xcd02c0);
        value_1e9 = value;
        if (value_1e9 == 0)
        {
            field_1a0 = 0;
        }
    }
}
