// from server: 100% by colin
struct FactoryProduct {
    void construct();
    FactoryProduct();
};

extern void sub_005ddb70();

FactoryProduct::FactoryProduct()
{
    sub_005ddb70();
    *(int*)((char*)this + 0x00) = 0x7bcc64;
    *(int*)((char*)this + 0x04) = 0x7bcc58;
    *(int*)((char*)this + 0x10) = 0x7bcc50;
    *(int*)((char*)this + 0x14) = 0x7bcc40;
    *(int*)((char*)this + 0x2c) = 0x7bcc30;
    *(int*)((char*)this + 0x44) = 0x7bcc20;
    *(int*)((char*)this + 0x5c) = 0x7bcc10;
    *(int*)((char*)this + 0x74) = 0x7bcc00;
    *(int*)((char*)this + 0x8c) = 0x7bcbf0;
    *(int*)((char*)this + 0xe8) = 0x7bcbd8;
}
