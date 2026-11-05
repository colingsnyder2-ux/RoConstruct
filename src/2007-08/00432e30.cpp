// from server: 47% by colin
struct ICreator {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

struct Creator : ICreator {
    void* field0;
    Creator(const void* arg);
};

Creator::Creator(const void* arg)
{
    field0 = 0;
    void* p = sub_62FEF6(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(int*)((char*)p + 0) = 0x78bacc;
        *(const void**)((char*)p + 0xc) = arg;
    } else {
        p = 0;
    }
    field0 = p;
}
