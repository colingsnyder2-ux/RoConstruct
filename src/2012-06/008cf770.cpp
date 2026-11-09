// from server: 100% by Intel
struct FactoryProduct {
    void init();
};

extern "C" void __stdcall sub_8CCC30();

void FactoryProduct::init() {
    *(int*)this = 0xBE867C;
    *(int*)((char*)this + 4) = 0xBE8674;
    *(int*)((char*)this + 0x18) = 0xBE8668;
    *(int*)((char*)this + 0x1C) = 0xBE865C;
    *(int*)((char*)this + 0x80) = 0xBE860C;
    *(int*)((char*)this + 0x9C) = 0xBE85EC;
    *(int*)((char*)this + 0x114) = 0xBE85D0;
    sub_8CCC30();
}
