// from server: 49% by colin
struct ICreator {
    void* vtable;
};

struct Creator : public ICreator {
    int field4;
    int field8;
    int fieldC;
};

extern "C" void* __cdecl operator_new(unsigned int size);

struct FactoryProduct {
    Creator* creator;
    FactoryProduct(int arg0, int arg1);
};

FactoryProduct::FactoryProduct(int arg0, int arg1) {
    creator = 0;
    Creator* c = (Creator*)operator_new(0x14);
    if (c) {
        c->field4 = 1;
        c->field8 = 1;
        c->vtable = (void*)0x785094;
        c->fieldC = arg0;
    } else {
        c = 0;
    }
    creator = c;
}
