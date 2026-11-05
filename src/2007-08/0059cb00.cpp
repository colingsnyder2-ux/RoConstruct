// from server: 100% by colin
struct RBX_VStarterPackService_FactoryProduct
{
    void construct();
};

extern void sub_0040CF60();

void RBX_VStarterPackService_FactoryProduct::construct()
{
    *(int*)((char*)this + 0x00) = 0x7b1b54;
    *(int*)((char*)this + 0x04) = 0x7b1b48;
    *(int*)((char*)this + 0x10) = 0x7b1b40;
    *(int*)((char*)this + 0x14) = 0x7b1b30;
    *(int*)((char*)this + 0x2c) = 0x7b1b20;
    *(int*)((char*)this + 0x44) = 0x7b1b10;
    *(int*)((char*)this + 0x5c) = 0x7b1b00;
    *(int*)((char*)this + 0x74) = 0x7b1af0;
    *(int*)((char*)this + 0x8c) = 0x7b1ae0;
    *(int*)((char*)this + 0xe8) = 0x7b1ad8;
    sub_0040CF60();
}
