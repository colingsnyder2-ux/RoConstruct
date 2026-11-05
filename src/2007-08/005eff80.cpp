// from server: 100% by colin
struct RBX_VMessage_FactoryProduct {
    void* construct(int arg);
};

extern "C" void __stdcall sub_5EFE40(int arg);

void* RBX_VMessage_FactoryProduct::construct(int arg) {
    sub_5EFE40(arg);
    *(int*)((char*)this + 0x00) = 0x7bffc4;
    *(int*)((char*)this + 0x04) = 0x7bffbc;
    *(int*)((char*)this + 0x10) = 0x7bffb4;
    *(int*)((char*)this + 0x14) = 0x7bffa4;
    *(int*)((char*)this + 0x2c) = 0x7bff94;
    *(int*)((char*)this + 0x44) = 0x7bff84;
    *(int*)((char*)this + 0x5c) = 0x7bff74;
    *(int*)((char*)this + 0x74) = 0x7bff64;
    *(int*)((char*)this + 0x8c) = 0x7bff54;
    return this;
}
