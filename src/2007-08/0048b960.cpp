// from server: 49% by colin
struct ICreator {
    void* vtable;
};

struct Creator : ICreator {
    void* field_4;
    void* field_8;
    void* field_c;
};

struct FactoryProduct {
    Creator* creator;
    FactoryProduct(int arg0, int arg1);
};

extern "C" void* __cdecl operator_new(unsigned int size);

FactoryProduct::FactoryProduct(int arg0, int arg1)
{
    creator = 0;
    Creator* c = (Creator*)operator_new(0x14);
    if (c) {
        c->vtable = (void*)0x79b038;
        c->field_4 = (void*)1;
        c->field_8 = (void*)1;
        c->field_c = (void*)arg0;
    } else {
        c = 0;
    }
    creator = c;
}
