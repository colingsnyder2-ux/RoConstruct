// from server: 100% by atomic.potato
extern "C" void __stdcall sub_411f60(unsigned int);

struct BoundFuncDesc
{
    unsigned char padding[0x1a0];
    int field_1a0;
    unsigned char padding2[0x44];
    unsigned char value_1e8;
    void setValue(unsigned char value);
};

void BoundFuncDesc::setValue(unsigned char value)
{
    if (value_1e8 != value)
    {
        value_1e8 = value;
        sub_411f60(0xcd0430);
        if (value_1e8 == 0)
        {
            field_1a0 = 0;
        }
    }
}
