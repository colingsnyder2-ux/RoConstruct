// from server: 50% by colin
struct ICreator {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
};

struct Creator : ICreator {
    void* field0;
    Creator(void* arg0, void* arg1);
};

extern "C" void* __cdecl operator_new(unsigned int size);

Creator::Creator(void* arg0, void* arg1) {
    field0 = 0;
    void* p = operator_new(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x79b0a8;
        *(void**)((char*)p + 0xc) = arg0;
    } else {
        p = 0;
    }
    field0 = p;
}
