// from server: 100% by Yeetserama
struct FactoryProduct {
    FactoryProduct* construct();
};

extern "C" void __fastcall sub_600750(FactoryProduct* self);

FactoryProduct* FactoryProduct::construct() {
    sub_600750(this);
    *(int*)((char*)this + 0x00) = 0x7ba6ec;
    *(int*)((char*)this + 0x04) = 0x7ba6e4;
    *(int*)((char*)this + 0x10) = 0x7ba6dc;
    *(int*)((char*)this + 0x14) = 0x7ba6cc;
    *(int*)((char*)this + 0x2c) = 0x7ba6bc;
    *(int*)((char*)this + 0x44) = 0x7ba6ac;
    *(int*)((char*)this + 0x5c) = 0x7ba69c;
    *(int*)((char*)this + 0x74) = 0x7ba68c;
    *(int*)((char*)this + 0x8c) = 0x7ba67c;
    *(int*)((char*)this + 0xe8) = 0x7ba674;
    return this;
}
