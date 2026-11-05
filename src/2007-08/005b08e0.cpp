// from server: 100% by colin
struct RBX_VRotateV {
    void construct();
};

extern "C" void __fastcall sub_5B03F0();

void RBX_VRotateV::construct()
{
    *(int*)((char*)this + 0x00) = 0x7b67fc;
    *(int*)((char*)this + 0x04) = 0x7b67f4;
    *(int*)((char*)this + 0x10) = 0x7b67ec;
    *(int*)((char*)this + 0x14) = 0x7b67dc;
    *(int*)((char*)this + 0x2c) = 0x7b67cc;
    *(int*)((char*)this + 0x44) = 0x7b67bc;
    *(int*)((char*)this + 0x5c) = 0x7b67ac;
    *(int*)((char*)this + 0x74) = 0x7b679c;
    *(int*)((char*)this + 0x8c) = 0x7b678c;
    *(int*)((char*)this + 0xe8) = 0x7b6774;
    sub_5B03F0();
}
