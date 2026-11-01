// from server: 100% by colin
struct FactoryProduct {
    void construct();
};

extern "C" void __stdcall sub_5B03F0();

void FactoryProduct::construct()
{
    *(int*)((char*)this + 0x00) = 0x7b658c;
    *(int*)((char*)this + 0x04) = 0x7b6584;
    *(int*)((char*)this + 0x10) = 0x7b657c;
    *(int*)((char*)this + 0x14) = 0x7b656c;
    *(int*)((char*)this + 0x2c) = 0x7b655c;
    *(int*)((char*)this + 0x44) = 0x7b654c;
    *(int*)((char*)this + 0x5c) = 0x7b653c;
    *(int*)((char*)this + 0x74) = 0x7b652c;
    *(int*)((char*)this + 0x8c) = 0x7b651c;
    *(int*)((char*)this + 0xe8) = 0x7b6504;
    sub_5B03F0();
}
