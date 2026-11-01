// from server: 100% by colin
struct RBX_AutoJoint {
    void construct();
};

extern "C" void __stdcall sub_5b03f0();

void RBX_AutoJoint::construct()
{
    *(int*)((char*)this + 0x00) = 0x7b631c;
    *(int*)((char*)this + 0x04) = 0x7b6314;
    *(int*)((char*)this + 0x10) = 0x7b630c;
    *(int*)((char*)this + 0x14) = 0x7b62fc;
    *(int*)((char*)this + 0x2c) = 0x7b62ec;
    *(int*)((char*)this + 0x44) = 0x7b62dc;
    *(int*)((char*)this + 0x5c) = 0x7b62cc;
    *(int*)((char*)this + 0x74) = 0x7b62bc;
    *(int*)((char*)this + 0x8c) = 0x7b62ac;
    *(int*)((char*)this + 0xe8) = 0x7b6294;
    sub_5b03f0();
}
