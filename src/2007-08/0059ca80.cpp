// from server: 100% by colin
struct FactoryProduct {
    void construct();
};

void FactoryProduct::construct()
{
    *(int*)((char*)this + 0x00) = 0x7b1a6c;
    *(int*)((char*)this + 0x04) = 0x7b1a64;
    *(int*)((char*)this + 0x10) = 0x7b1a5c;
    *(int*)((char*)this + 0x14) = 0x7b1a4c;
    *(int*)((char*)this + 0x2c) = 0x7b1a3c;
    *(int*)((char*)this + 0x44) = 0x7b1a2c;
    *(int*)((char*)this + 0x5c) = 0x7b1a1c;
    *(int*)((char*)this + 0x74) = 0x7b1a0c;
    *(int*)((char*)this + 0x8c) = 0x7b19fc;
    *(int*)((char*)this + 0xe8) = 0x7b19f4;
    extern void __stdcall sub_40cf60();
    sub_40cf60();
}
