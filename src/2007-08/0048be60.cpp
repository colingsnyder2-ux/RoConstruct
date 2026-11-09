// from server: 49% by colin
struct ICreator {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
};

struct CreatorImpl {
    int field0;
    int field4;
    int field8;
    int fieldC;
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

struct FactoryProductCreator {
    ICreator* field0;
    FactoryProductCreator(int arg0, int arg1);
};

FactoryProductCreator::FactoryProductCreator(int arg0, int arg1)
{
    this->field0 = 0;
    CreatorImpl* p = (CreatorImpl*)sub_62FEF6(0x14);
    if (p != 0) {
        p->field4 = 1;
        p->field8 = 1;
        p->field0 = 0x79b070;
        p->fieldC = arg0;
    } else {
        p = 0;
    }
    this->field0 = (ICreator*)p;
}
