// from server: 100% by colin
struct RBX_VBodyThrust_FactoryProduct {
    void construct();
};

extern "C" void __cdecl sub_5eb650();

void RBX_VBodyThrust_FactoryProduct::construct()
{
    *(int *)((char *)this + 0x00) = 0x7bea04;
    *(int *)((char *)this + 0x04) = 0x7be9fc;
    *(int *)((char *)this + 0x10) = 0x7be9f4;
    *(int *)((char *)this + 0x14) = 0x7be9e4;
    *(int *)((char *)this + 0x2c) = 0x7be9d4;
    *(int *)((char *)this + 0x44) = 0x7be9c4;
    *(int *)((char *)this + 0x5c) = 0x7be9b4;
    *(int *)((char *)this + 0x74) = 0x7be9a4;
    *(int *)((char *)this + 0x8c) = 0x7be994;
    *(int *)((char *)this + 0xe8) = 0x7be97c;
    *(int *)((char *)this + 0xf0) = 0x7be970;
    sub_5eb650();
}
