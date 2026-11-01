// from server: 100% by colin
extern "C" void* (__cdecl *malloc)(unsigned int size);

struct BoundFuncDesc {
    void* field0;
    unsigned int field4;
    void* field8;
    void* fieldC;
    unsigned char field10;
    char field11;
    void* construct(unsigned int size);
};

void* BoundFuncDesc::construct(unsigned int size) {
    field0 = 0;
    field8 = 0;
    if ((int)size <= 0x100) {
        fieldC = (char*)this + 0x11;
        field4 = 0x800;
    } else {
        fieldC = malloc(size);
        field4 = size * 8;
    }
    field10 = 1;
    return this;
}
