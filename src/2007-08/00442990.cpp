// from server: 100% by colin
struct RBXImage {
    void* vftable;
    void* field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    unsigned char field1C;
    unsigned char field1D;
    char pad1E[2];
    int field20;
    RBXImage* destroy(int);
};

extern "C" int (__stdcall *DeleteObject)(void*);
extern "C" void __cdecl sub_62FC62(void*);

RBXImage* RBXImage::destroy(int flags) {
    void* p = field4;
    vftable = (void*)0x78f588;
    if (p != 0) {
        field4 = 0;
        field8 = 0;
        fieldC = 0;
        field10 = 0;
        field18 = 0;
        field14 = 0;
        field20 = -1;
        field1D = 0;
        field1C = 0;
        DeleteObject(p);
    }
    if (flags & 1) {
        sub_62FC62(this);
    }
    return this;
}
