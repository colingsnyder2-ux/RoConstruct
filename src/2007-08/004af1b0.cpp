// from server: 50% by colin
struct ICreator {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
};

struct Creator : ICreator {
    void* ptr;
    Creator(const void* arg0, const void* arg1);
};

void* __cdecl sub_62fef6(unsigned int size);

Creator::Creator(const void* arg0, const void* arg1)
{
    ptr = 0;
    void* p = sub_62fef6(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x79d8b4;
        *(const void**)((char*)p + 0xc) = arg0;
    } else {
        p = 0;
    }
    ptr = p;
}
