// from server: 100% by colin
struct RBX_VBodyForce_FactoryProduct {
    void construct();
};

extern "C" void __stdcall sub_5eb650();

void RBX_VBodyForce_FactoryProduct::construct()
{
    *(int*)((char*)this + 0x00) = 0x7be924;
    *(int*)((char*)this + 0x04) = 0x7be91c;
    *(int*)((char*)this + 0x10) = 0x7be914;
    *(int*)((char*)this + 0x14) = 0x7be904;
    *(int*)((char*)this + 0x2c) = 0x7be8f4;
    *(int*)((char*)this + 0x44) = 0x7be8e4;
    *(int*)((char*)this + 0x5c) = 0x7be8d4;
    *(int*)((char*)this + 0x74) = 0x7be8c4;
    *(int*)((char*)this + 0x8c) = 0x7be8b4;
    *(int*)((char*)this + 0xe8) = 0x7be89c;
    *(int*)((char*)this + 0xf0) = 0x7be890;
    sub_5eb650();
}
