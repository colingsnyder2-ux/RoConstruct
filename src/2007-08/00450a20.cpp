// from server: 29% by tester
struct ICreator {
    virtual void v0();
    virtual void v1();
};

struct FactoryProductCreator : ICreator {
    void construct();
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl construct_creator(FactoryProductCreator* p);

void FactoryProductCreator::construct()
{
    FactoryProductCreator* p = (FactoryProductCreator*)operator_new(0x7c);
    if (p) {
        construct_creator(p);
    }
}
