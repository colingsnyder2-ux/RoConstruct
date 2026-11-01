// from server: 100% by colin
struct RBX_VBodyPosition_FactoryProduct {
    void construct();
};

extern "C" void __stdcall tail_call_5eb650();

void RBX_VBodyPosition_FactoryProduct::construct()
{
    *(int*)((char*)this + 0x00) = 0x7beae4;
    *(int*)((char*)this + 0x04) = 0x7beadc;
    *(int*)((char*)this + 0x10) = 0x7bead4;
    *(int*)((char*)this + 0x14) = 0x7beac4;
    *(int*)((char*)this + 0x2c) = 0x7beab4;
    *(int*)((char*)this + 0x44) = 0x7beaa4;
    *(int*)((char*)this + 0x5c) = 0x7bea94;
    *(int*)((char*)this + 0x74) = 0x7bea84;
    *(int*)((char*)this + 0x8c) = 0x7bea74;
    *(int*)((char*)this + 0xe8) = 0x7bea5c;
    *(int*)((char*)this + 0xf0) = 0x7bea50;
    tail_call_5eb650();
}
