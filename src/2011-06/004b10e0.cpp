// from server: 100% by atomic.potato
extern "C" void VConfiguration_FactoryProduct_Creator();

struct Creator
{
    int value0;
    int value4;
    int pad0[4];
    int value18;
    int value1c;
    void Create();
};

void Creator::Create()
{
    value0 = 0xa772cc;
    value4 = 0xa772c0;
    value18 = 0xa772b4;
    value1c = 0xa772a8;
    VConfiguration_FactoryProduct_Creator();
}
