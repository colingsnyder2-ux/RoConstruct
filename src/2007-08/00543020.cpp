// from server: 100% by colin
struct RBX_VDebugSettings_FactoryProduct {
    void construct();
};

extern "C" void __stdcall sub_005402B0();

void RBX_VDebugSettings_FactoryProduct::construct()
{
    *(int*)0x8baf44 = 0;
    *(int*)((char*)this + 0x00) = 0x7a68ac;
    *(int*)((char*)this + 0x04) = 0x7a68a4;
    *(int*)((char*)this + 0x10) = 0x7a689c;
    *(int*)((char*)this + 0x14) = 0x7a688c;
    *(int*)((char*)this + 0x2c) = 0x7a687c;
    *(int*)((char*)this + 0x44) = 0x7a686c;
    *(int*)((char*)this + 0x5c) = 0x7a685c;
    *(int*)((char*)this + 0x74) = 0x7a684c;
    *(int*)((char*)this + 0x8c) = 0x7a683c;
    sub_005402B0();
}
