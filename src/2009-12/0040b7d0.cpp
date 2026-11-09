// from server: 100% by atomic.potato
struct VEventsFactoryProduct
{
    int value0;
    int value4;
    int value8;
    int valueC;
    int value10;
    int value14;
    int value18;
    int value1C;

    void set();
};

extern "C" void __stdcall sub_40acb0();

void VEventsFactoryProduct::set()
{
    value0 = 0x9a033c;
    value4 = 0x9a0334;
    value18 = 0x9a0328;
    value1C = 0x9a0320;
    sub_40acb0();
}
