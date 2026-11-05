// from server: 49% by colin
struct ICreator {
    void* vtable;
};

struct CreatorImpl {
    void* vtable;
    int refcount1;
    int refcount2;
    void* arg;
};

struct FactoryProduct {
    void* ptr;
    FactoryProduct(int arg, int arg2);
};

extern "C" void* __cdecl operator_new(unsigned int size);

FactoryProduct::FactoryProduct(int arg, int arg2)
{
    ptr = 0;
    CreatorImpl* c = (CreatorImpl*)operator_new(0x14);
    if (c) {
        c->refcount1 = 1;
        c->refcount2 = 1;
        c->vtable = (void*)0x79afe4;
        c->arg = (void*)arg;
    } else {
        c = 0;
    }
    ptr = c;
}
