// from server: 100% by colin
struct RBX_VGameSettings_FactoryProduct {
    void construct();
};

extern "C" void __stdcall sub_5402B0();

void RBX_VGameSettings_FactoryProduct::construct()
{
    *(int*)0x8bdfac = 0;
    *(int*)((char*)this + 0x00) = 0x7b3184;
    *(int*)((char*)this + 0x04) = 0x7b317c;
    *(int*)((char*)this + 0x10) = 0x7b3174;
    *(int*)((char*)this + 0x14) = 0x7b3164;
    *(int*)((char*)this + 0x2c) = 0x7b3154;
    *(int*)((char*)this + 0x44) = 0x7b3144;
    *(int*)((char*)this + 0x5c) = 0x7b3134;
    *(int*)((char*)this + 0x74) = 0x7b3124;
    *(int*)((char*)this + 0x8c) = 0x7b3114;
    sub_5402B0();
}
