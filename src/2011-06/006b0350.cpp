// from server: 89% by atomic.potato
extern "C" void __stdcall sub_411f60(unsigned int);

struct BoundFuncDesc
{
    unsigned char padding[0x1c4];
    int value_1c4;
    void update(int value);

    virtual void refresh();
};

void BoundFuncDesc::update(int value)
{
    if (value_1c4 != value)
    {
        value_1c4 = value;
        sub_411f60(0xcd065c);
        refresh();
    }
}
