// from server: 50% by colin
struct ICreator {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
};

struct Creator : ICreator {
    void* field0;
    Creator(const void* arg, int arg2);
};

extern "C" void* __cdecl operator_new(unsigned int size);

Creator::Creator(const void* arg, int arg2)
{
    field0 = 0;
    void* p = operator_new(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x787aa8;
        *(const void**)((char*)p + 0xc) = arg;
    } else {
        p = 0;
    }
    field0 = p;
}
