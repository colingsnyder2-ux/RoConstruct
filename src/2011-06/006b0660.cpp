// from server: 72% by atomic.potato
extern "C" void __stdcall sub_411f60(unsigned int);

struct BoundFuncDesc
{
    unsigned char padding[0x1ec];
    float value_1ec;
    void setValue(float value);
};

void BoundFuncDesc::setValue(float value)
{
    if (value != value_1ec)
    {
        value_1ec = value;
        sub_411f60(0xcd0188);
    }
}
