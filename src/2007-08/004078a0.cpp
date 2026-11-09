// from server: 24% by colin
extern "C" void* __stdcall malloc(unsigned int size);

struct ICreator {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
};

struct Creator : public ICreator {
    void construct(int flag);
};

struct FactoryProduct {
    void init(Creator* creator, int flag);
};

void FactoryProduct::init(Creator* creator, int flag)
{
    Creator* c = (Creator*)malloc(0x244);
    if (c) {
        c->construct(1);
    } else {
        c = 0;
    }
    this->init(c, flag);
}
