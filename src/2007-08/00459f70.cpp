// from server: 55% by colin
struct ICreator {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    virtual void unknown4();
};

struct Creator : ICreator {
    void* field4;
    void* field8;
    void* fieldC;
    Creator(void* arg, int unused);
};

extern "C" void* __cdecl operator_new(unsigned int size);

Creator::Creator(void* arg, int unused)
{
    this->field4 = 0;
    this->field8 = 0;
    this->fieldC = 0;
    void* p = operator_new(0x14);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)((char*)p) = (void*)0x793698;
        *(void**)((char*)p + 0xc) = arg;
    } else {
        p = 0;
    }
    *(void**)this = p;
}
