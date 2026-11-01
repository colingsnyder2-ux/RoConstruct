// from server: 100% by colin
struct VDecalFactoryProduct {
    char pad[0xe8];
    int field_e8;
    VDecalFactoryProduct();
};

extern "C" void __fastcall sub_5b8de0(VDecalFactoryProduct* self);

VDecalFactoryProduct::VDecalFactoryProduct()
{
    sub_5b8de0(this);
    *(int*)((char*)this + 0x00) = 0x7b8ca4;
    *(int*)((char*)this + 0x04) = 0x7b8c9c;
    *(int*)((char*)this + 0x10) = 0x7b8c94;
    *(int*)((char*)this + 0x14) = 0x7b8c84;
    *(int*)((char*)this + 0x2c) = 0x7b8c74;
    *(int*)((char*)this + 0x44) = 0x7b8c64;
    *(int*)((char*)this + 0x5c) = 0x7b8c54;
    *(int*)((char*)this + 0x74) = 0x7b8c44;
    *(int*)((char*)this + 0x8c) = 0x7b8c34;
    *(int*)((char*)this + 0xe8) = 5;
}
