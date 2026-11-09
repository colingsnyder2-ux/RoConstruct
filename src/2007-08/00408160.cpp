// from server: 50% by colin
struct ICreator {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
};

struct Creator : public ICreator {
    void* field0;
    Creator(const void* arg, int extra);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

Creator::Creator(const void* arg, int extra)
{
    field0 = 0;
    void* p = sub_62FEF6(0x14);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)((char*)p + 0) = (void*)0x785104;
        *(const void**)((char*)p + 0xc) = arg;
    } else {
        p = 0;
    }
    field0 = p;
}
