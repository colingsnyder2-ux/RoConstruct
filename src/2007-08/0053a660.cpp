// from server: 100% by colin
struct BaseClass {
    void construct(int);
};

struct FactoryProduct : BaseClass {
    FactoryProduct(int);
};

FactoryProduct::FactoryProduct(int arg)
{
    BaseClass::construct(arg);
    *(int*)((char*)this + 0x00) = 0x793804;
    *(int*)((char*)this + 0x04) = 0x7937fc;
    *(int*)((char*)this + 0x10) = 0x7937f4;
    *(int*)((char*)this + 0x14) = 0x7937e4;
    *(int*)((char*)this + 0x2c) = 0x7937d4;
    *(int*)((char*)this + 0x44) = 0x7937c4;
    *(int*)((char*)this + 0x5c) = 0x7937b4;
    *(int*)((char*)this + 0x74) = 0x7937a4;
    *(int*)((char*)this + 0x8c) = 0x793794;
}
