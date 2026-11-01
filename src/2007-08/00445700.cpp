// from server: 100% by colin
struct RBXBaseClass {
    void construct();
};

struct NonFactoryProduct : RBXBaseClass {
    void init();
};

void NonFactoryProduct::init()
{
    *(int*)0x8bafa4 = 0;
    *(int*)((char*)this + 0x00) = 0x78fcbc;
    *(int*)((char*)this + 0x04) = 0x78fcb4;
    *(int*)((char*)this + 0x10) = 0x78fcac;
    *(int*)((char*)this + 0x14) = 0x78fc9c;
    *(int*)((char*)this + 0x2c) = 0x78fc8c;
    *(int*)((char*)this + 0x44) = 0x78fc7c;
    *(int*)((char*)this + 0x5c) = 0x78fc6c;
    *(int*)((char*)this + 0x74) = 0x78fc5c;
    *(int*)((char*)this + 0x8c) = 0x78fc4c;
    construct();
}
