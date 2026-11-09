// from server: 100% by colin
struct RBX_VRotateP_FactoryProduct {
    RBX_VRotateP_FactoryProduct* construct(int arg);
};

extern "C" void __stdcall sub_5B1A20(int arg);

RBX_VRotateP_FactoryProduct* RBX_VRotateP_FactoryProduct::construct(int arg) {
    sub_5B1A20(arg);
    *(int*)((char*)this + 0x00) = 0x7b76f4;
    *(int*)((char*)this + 0x04) = 0x7b76ec;
    *(int*)((char*)this + 0x10) = 0x7b76e4;
    *(int*)((char*)this + 0x14) = 0x7b76d4;
    *(int*)((char*)this + 0x2c) = 0x7b76c4;
    *(int*)((char*)this + 0x44) = 0x7b76b4;
    *(int*)((char*)this + 0x5c) = 0x7b76a4;
    *(int*)((char*)this + 0x74) = 0x7b7694;
    *(int*)((char*)this + 0x8c) = 0x7b7684;
    *(int*)((char*)this + 0xe8) = 0x7b766c;
    return this;
}
