// from server: 100% by colin
struct FactoryProduct {
    void construct();
    FactoryProduct* init();
};

FactoryProduct* FactoryProduct::init()
{
    construct();
    *(int*)((char*)this + 0) = 0x7b271c;
    *(int*)((char*)this + 4) = 0x7b2710;
    *(int*)((char*)this + 0x10) = 0x7b2708;
    *(int*)((char*)this + 0x14) = 0x7b26f8;
    *(int*)((char*)this + 0x2c) = 0x7b26e8;
    *(int*)((char*)this + 0x44) = 0x7b26d8;
    *(int*)((char*)this + 0x5c) = 0x7b26c8;
    *(int*)((char*)this + 0x74) = 0x7b26b8;
    *(int*)((char*)this + 0x8c) = 0x7b26a8;
    *(int*)((char*)this + 0xe8) = 0x7b26a0;
    return this;
}
