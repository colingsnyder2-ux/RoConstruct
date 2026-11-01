// from server: 100% by colin
struct RBX_VHopperBin_FactoryProduct {
    void* construct();
};

extern "C" void __fastcall sub_59d0d0(void*);

void* RBX_VHopperBin_FactoryProduct::construct()
{
    sub_59d0d0(this);
    *(int*)((char*)this + 0x00) = 0x7b2d9c;
    *(int*)((char*)this + 0x04) = 0x7b2d90;
    *(int*)((char*)this + 0x10) = 0x7b2d88;
    *(int*)((char*)this + 0x14) = 0x7b2d78;
    *(int*)((char*)this + 0x2c) = 0x7b2d68;
    *(int*)((char*)this + 0x44) = 0x7b2d58;
    *(int*)((char*)this + 0x5c) = 0x7b2d48;
    *(int*)((char*)this + 0x74) = 0x7b2d38;
    *(int*)((char*)this + 0x8c) = 0x7b2d28;
    *(int*)((char*)this + 0xe8) = 0x7b2d20;
    return this;
}
