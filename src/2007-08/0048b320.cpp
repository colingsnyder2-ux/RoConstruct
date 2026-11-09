// from server: 31% by colin
struct RBXName;

struct ICreator {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
};

struct Creator : ICreator {
    void construct(RBXName* name);
};

struct FactoryProduct {
    Creator* creator;
    void FactoryProduct_ctor();
};

extern "C" void* __cdecl malloc(unsigned int size);

struct AllocHelper {
    void* operator new(unsigned int size);
};

void* AllocHelper::operator new(unsigned int size) {
    return malloc(size);
}

struct CreatorCtor {
    void ctor();
};

void Creator::construct(RBXName* name) {
    void* mem = malloc(0xf0);
    if (mem) {
        ((CreatorCtor*)mem)->ctor();
    }
    extern void FactoryProduct_setCreator(FactoryProduct* self, void* a, void* b);
    FactoryProduct_setCreator((FactoryProduct*)this, mem, name);
}

void FactoryProduct::FactoryProduct_ctor() {
    extern void FactoryProduct_setCreator(FactoryProduct* self, void* a, void* b);
    FactoryProduct_setCreator(this, 0, 0);
}
