// from server: 100% by colin
struct RBX_VBodyForce_FactoryProduct {
    RBX_VBodyForce_FactoryProduct* construct(int arg);
};

extern "C" void __stdcall sub_5edc00(int arg);

RBX_VBodyForce_FactoryProduct* RBX_VBodyForce_FactoryProduct::construct(int arg)
{
    sub_5edc00(arg);
    *(int*)((char*)this + 0x00) = 0x7bf5a4;
    *(int*)((char*)this + 0x04) = 0x7bf59c;
    *(int*)((char*)this + 0x10) = 0x7bf594;
    *(int*)((char*)this + 0x14) = 0x7bf584;
    *(int*)((char*)this + 0x2c) = 0x7bf574;
    *(int*)((char*)this + 0x44) = 0x7bf564;
    *(int*)((char*)this + 0x5c) = 0x7bf554;
    *(int*)((char*)this + 0x74) = 0x7bf544;
    *(int*)((char*)this + 0x8c) = 0x7bf534;
    *(int*)((char*)this + 0xe8) = 0x7bf51c;
    *(int*)((char*)this + 0xf0) = 0x7bf510;
    return this;
}
