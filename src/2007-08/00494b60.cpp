// from server: 50% by colin
struct ICreator {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
};

struct Creator : ICreator {
    int field0;
    int field4;
    int field8;
    int fieldC;
    Creator(int arg);
};

extern "C" void* __cdecl sub_62fef6(unsigned int size);

Creator::Creator(int arg) {
    field0 = 0;
    void* p = sub_62fef6(0x10);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(int*)p = 0x79b808;
        *(int*)((char*)p + 0xc) = arg;
    } else {
        p = 0;
    }
    field0 = (int)p;
}
