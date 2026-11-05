// from server: 50% by colin
struct ICreator {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
};

struct Creator : ICreator {
    void* ptr;
    Creator(const void* name, int extra);
};

extern "C" void* __cdecl operator_new(unsigned int size);

Creator::Creator(const void* name, int extra)
{
    ptr = 0;
    void* mem = operator_new(0x14);
    if (mem) {
        *(int*)((char*)mem + 4) = 1;
        *(int*)((char*)mem + 8) = 1;
        *(void**)mem = (void*)0x79d898;
        *(const void**)((char*)mem + 0xc) = name;
    } else {
        mem = 0;
    }
    ptr = mem;
}
