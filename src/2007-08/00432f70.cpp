// from server: 35% by TrollStein
struct ICreator {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
};

struct Creator : ICreator {
    void construct(int, int);
};

extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __stdcall sub_583300(void*, int);

struct FactoryProduct {
    Creator* creator;
    void __cdecl init(Creator* c);
};

void FactoryProduct::init(Creator* c)
{
    Creator* p = (Creator*)malloc(0x180);
    if (p) {
        sub_583300(p, 1);
    } else {
        p = 0;
    }
    this->creator = p;
    c->construct((int)this->creator, 0);
}
