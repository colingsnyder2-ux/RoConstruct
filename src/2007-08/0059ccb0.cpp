// from server: 100% by colin
struct Base {
    void construct();
};

struct FactoryProduct : Base {
    FactoryProduct* init();
};

FactoryProduct* FactoryProduct::init() {
    construct();
    *(int*)((char*)this + 0x00) = 0x7b1c3c;
    *(int*)((char*)this + 0x04) = 0x7b1c30;
    *(int*)((char*)this + 0x10) = 0x7b1c28;
    *(int*)((char*)this + 0x14) = 0x7b1c18;
    *(int*)((char*)this + 0x2c) = 0x7b1c08;
    *(int*)((char*)this + 0x44) = 0x7b1bf8;
    *(int*)((char*)this + 0x5c) = 0x7b1be8;
    *(int*)((char*)this + 0x74) = 0x7b1bd8;
    *(int*)((char*)this + 0x8c) = 0x7b1bc8;
    *(int*)((char*)this + 0xe8) = 0x7b1bc0;
    return this;
}
