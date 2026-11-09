// from server: 50% by colin
struct ICreator {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
};

struct Creator : ICreator {
    int field0;
    Creator(int arg0, int arg1);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

Creator::Creator(int arg0, int arg1) {
    field0 = 0;
    void* p = sub_62FEF6(0x14);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(int*)p = 0x79b9d8;
        *(int*)((char*)p + 0xc) = arg0;
    } else {
        p = 0;
    }
    field0 = (int)p;
}
