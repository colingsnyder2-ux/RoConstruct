// from server: 100% by atomic.potato
struct FactoryProduct
{
    int value0;
    int value1;
    int value2;
    int value3;
    int value4;
    int value5;
    int value6;
    int value7;

    void initialize();
};

extern "C" void FactoryProductTarget();

void FactoryProduct::initialize()
{
    value0 = 0x9d7ffc;
    value1 = 0x9d7ff0;
    value6 = 0x9d7fe4;
    value7 = 0x9d7fdc;
    FactoryProductTarget();
}
