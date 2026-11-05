// from server: 49% by colin
struct ICreator {
    void* vtable;
};

struct Creator : ICreator {
    void* field4;
    void* field8;
    void* fieldC;
};

struct FactoryProduct {
    Creator* creator;
    FactoryProduct(int arg0, int arg1);
};

extern "C" void* __cdecl operator_new(unsigned int size);

FactoryProduct::FactoryProduct(int arg0, int arg1) {
    this->creator = 0;
    Creator* c = (Creator*)operator_new(0x14);
    if (c != 0) {
        c->field4 = (void*)1;
        c->field8 = (void*)1;
        c->vtable = (void*)0x78e3d4;
        c->fieldC = (void*)arg0;
    } else {
        c = 0;
    }
    this->creator = c;
}
