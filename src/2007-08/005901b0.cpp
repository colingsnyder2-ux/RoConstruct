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
    *(int*)((char*)this + 0x00) = 0x7af944;
    *(int*)((char*)this + 0x04) = 0x7af938;
    *(int*)((char*)this + 0x10) = 0x7af930;
    *(int*)((char*)this + 0x14) = 0x7af920;
    *(int*)((char*)this + 0x2c) = 0x7af910;
    *(int*)((char*)this + 0x44) = 0x7af900;
    *(int*)((char*)this + 0x5c) = 0x7af8f0;
    *(int*)((char*)this + 0x74) = 0x7af8e0;
    *(int*)((char*)this + 0x8c) = 0x7af8d0;
    *(int*)((char*)this + 0xe8) = 0x7af8b8;
}
