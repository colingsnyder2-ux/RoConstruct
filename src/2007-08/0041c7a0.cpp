// from server: 32% by colin
struct ICreator {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
};

struct Creator : ICreator {
    void construct(void* arg);
};

struct FactoryProduct {
    void* field0;
    char pad[0x29c - 4];
    void init(Creator* creator, void* arg);
};

extern "C" void* __cdecl malloc(unsigned int size);
extern "C" void __stdcall sub_578ED0(void* p, int flag);

void FactoryProduct::init(Creator* creator, void* arg)
{
    void* mem = malloc(0x29c);
    void* obj;
    if (mem) {
        sub_578ED0(mem, 1);
        obj = mem;
    } else {
        obj = 0;
    }
    creator->construct(obj);
}
