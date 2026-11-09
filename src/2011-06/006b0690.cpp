// from server: 100% by atomic.potato
extern "C" void __stdcall sub_411f60(unsigned int);

struct BoundFuncDesc
{
    unsigned char padding[0x2f6];
    unsigned char value_2f6;
    void setValue(unsigned char value);
};

void BoundFuncDesc::setValue(unsigned char value)
{
    if (value_2f6 != value)
    {
        value_2f6 = value;
        sub_411f60(0xcd04a0);
    }
}
