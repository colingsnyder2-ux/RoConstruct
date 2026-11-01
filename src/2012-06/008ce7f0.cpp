// from server: 100% by Intel
struct VBodyPositionFactoryProduct {
    void initialize();
};

extern "C" void __stdcall sub_8CCC30();

void VBodyPositionFactoryProduct::initialize() {
    *(int*)this = 0xBE8994;
    *(int*)((char*)this + 4) = 0xBE898C;
    *(int*)((char*)this + 0x18) = 0xBE8980;
    *(int*)((char*)this + 0x1C) = 0xBE8974;
    *(int*)((char*)this + 0x80) = 0xBE8924;
    *(int*)((char*)this + 0x9C) = 0xBE8904;
    *(int*)((char*)this + 0x114) = 0xBE88E8;
    sub_8CCC30();
}
