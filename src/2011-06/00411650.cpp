// from server: 100% by atomic.potato
struct FactoryProductCreator
{
    void *product;
    unsigned char initialized;
    FactoryProductCreator(void *value);
};

extern "C" void __cdecl InitializeFactoryProduct();

FactoryProductCreator::FactoryProductCreator(void *value)
{
    product = value;
    initialized = 0;
    InitializeFactoryProduct();
}
