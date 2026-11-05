// from server: 44% by atomic.potato
struct VVirtualUserBoundFuncDesc {
    void* vf0;
    void* vf4;
    char pad0[0x10];
    void* vf18;
    void* vf1c;
    char pad1[0x60];
    unsigned char flag80;
    char pad2[3];
    int field84;
    char pad3[0x80];
    int field110;
    char pad4[4];
    double field118;
};

extern "C" void __stdcall sub_8c7330();
extern "C" void* __stdcall sub_b22768(int, int);

void __stdcall init(VVirtualUserBoundFuncDesc* self);

void __stdcall init(VVirtualUserBoundFuncDesc* self)
{
    sub_8c7330();
    self->flag80 = 1;
    *(void**)self = (void*)0xbe6734;
    *(void**)((char*)self + 4) = (void*)0xbe6728;
    *(void**)((char*)self + 0x18) = (void*)0xbe671c;
    *(void**)((char*)self + 0x1c) = (void*)0xbe6710;
    self->field84 = 0;
    sub_b22768(3, 1);
    self->field110 = 0;
    self->field118 = 0.0;
}
