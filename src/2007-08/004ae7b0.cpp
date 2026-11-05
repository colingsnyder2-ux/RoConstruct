// from server: 49% by colin
struct ICreator {
    void* vtable;
};

struct Creator : ICreator {
    void* field4;
    void* field8;
    void* fieldC;
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

struct FactoryProduct {
    Creator* creator;
    FactoryProduct(int arg0, int arg1);
};

FactoryProduct::FactoryProduct(int arg0, int arg1)
{
    creator = 0;
    Creator* c = (Creator*)sub_62FEF6(0x14);
    if (c != 0) {
        c->field4 = (void*)1;
        c->field8 = (void*)1;
        c->vtable = (void*)0x79d844;
        c->fieldC = (void*)arg0;
    } else {
        c = 0;
    }
    creator = c;
}
