// from server: 100% by colin
struct BaseClass {
    BaseClass(int);
};

struct FactoryProduct : BaseClass {
    FactoryProduct(int);
};

FactoryProduct::FactoryProduct(int arg) : BaseClass(arg)
{
    *(int*)((char*)this + 0x00) = 0x7b7484;
    *(int*)((char*)this + 0x04) = 0x7b747c;
    *(int*)((char*)this + 0x10) = 0x7b7474;
    *(int*)((char*)this + 0x14) = 0x7b7464;
    *(int*)((char*)this + 0x2c) = 0x7b7454;
    *(int*)((char*)this + 0x44) = 0x7b7444;
    *(int*)((char*)this + 0x5c) = 0x7b7434;
    *(int*)((char*)this + 0x74) = 0x7b7424;
    *(int*)((char*)this + 0x8c) = 0x7b7414;
    *(int*)((char*)this + 0xe8) = 0x7b73fc;
}
