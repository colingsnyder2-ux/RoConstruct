// from server: 100% by colin
struct BaseClass {
    void construct();
};

struct FactoryProduct : BaseClass {
    FactoryProduct();
};

FactoryProduct::FactoryProduct()
{
    construct();
    *(int*)((char*)this + 0x00) = 0x7bcb8c;
    *(int*)((char*)this + 0x04) = 0x7bcb80;
    *(int*)((char*)this + 0x10) = 0x7bcb78;
    *(int*)((char*)this + 0x14) = 0x7bcb68;
    *(int*)((char*)this + 0x2c) = 0x7bcb58;
    *(int*)((char*)this + 0x44) = 0x7bcb48;
    *(int*)((char*)this + 0x5c) = 0x7bcb38;
    *(int*)((char*)this + 0x74) = 0x7bcb28;
    *(int*)((char*)this + 0x8c) = 0x7bcb18;
    *(int*)((char*)this + 0xe8) = 0x7bcb00;
}
