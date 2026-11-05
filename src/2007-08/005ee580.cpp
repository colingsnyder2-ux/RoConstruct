// from server: 100% by colin
struct BaseClass {
    BaseClass(int);
};

struct FactoryProduct : BaseClass {
    FactoryProduct(int);
};

FactoryProduct::FactoryProduct(int arg) : BaseClass(arg) {
    *(int*)((char*)this + 0x00) = 0x7bf3e4;
    *(int*)((char*)this + 0x04) = 0x7bf3dc;
    *(int*)((char*)this + 0x10) = 0x7bf3d4;
    *(int*)((char*)this + 0x14) = 0x7bf3c4;
    *(int*)((char*)this + 0x2c) = 0x7bf3b4;
    *(int*)((char*)this + 0x44) = 0x7bf3a4;
    *(int*)((char*)this + 0x5c) = 0x7bf394;
    *(int*)((char*)this + 0x74) = 0x7bf384;
    *(int*)((char*)this + 0x8c) = 0x7bf374;
    *(int*)((char*)this + 0xe8) = 0x7bf35c;
    *(int*)((char*)this + 0xf0) = 0x7bf350;
}
