// from server: 49% by colin
struct ICreator {
    void* vtable;
};

struct Creator : ICreator {
    void* field4;
    void* field8;
    void* fieldC;
};

extern "C" void* __cdecl operator_new(unsigned int size);

struct FactoryProduct {
    ICreator* creator;
    FactoryProduct(int arg0, int arg1);
};

FactoryProduct::FactoryProduct(int arg0, int arg1) {
    creator = 0;
    Creator* c = (Creator*)operator_new(0x14);
    if (c) {
        c->field4 = (void*)1;
        c->field8 = (void*)1;
        c->vtable = (void*)0x79b08c;
        c->fieldC = (void*)arg0;
    } else {
        c = 0;
    }
    creator = c;
}
