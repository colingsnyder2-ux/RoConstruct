// from server: 100% by colin
struct RBX_VHopperBin_FactoryProduct {
    char pad0[0x8c];
    int field_8c;
    char pad90[0x58];
    int field_e8;
    RBX_VHopperBin_FactoryProduct* ctor();
};

extern "C" void __fastcall sub_59f040(void*);

RBX_VHopperBin_FactoryProduct* RBX_VHopperBin_FactoryProduct::ctor()
{
    sub_59f040(this);
    *(int*)((char*)this + 0x00) = 0x7b2b2c;
    *(int*)((char*)this + 0x04) = 0x7b2b20;
    *(int*)((char*)this + 0x10) = 0x7b2b18;
    *(int*)((char*)this + 0x14) = 0x7b2b08;
    *(int*)((char*)this + 0x2c) = 0x7b2af8;
    *(int*)((char*)this + 0x44) = 0x7b2ae8;
    *(int*)((char*)this + 0x5c) = 0x7b2ad8;
    *(int*)((char*)this + 0x74) = 0x7b2ac8;
    *(int*)((char*)this + 0x8c) = 0x7b2ab8;
    *(int*)((char*)this + 0xe8) = 0x7b2ab0;
    return this;
}
