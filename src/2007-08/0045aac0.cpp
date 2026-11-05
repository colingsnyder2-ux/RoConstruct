// from server: 31% by colin
struct VCamera_FactoryProduct_Creator {
    void construct();
};

extern "C" void __stdcall sub_45AA70();
extern "C" void __stdcall sub_77E6A4();

void VCamera_FactoryProduct_Creator::construct()
{
    sub_45AA70();
    *(double*)((char*)this + 0xe8) = 0.0;
    *(int*)((char*)this + 0x00) = 0x7938bc;
    *(int*)((char*)this + 0x04) = 0x7938b4;
    *(int*)((char*)this + 0x10) = 0x7938ac;
    *(int*)((char*)this + 0x14) = 0x79389c;
    *(int*)((char*)this + 0x2c) = 0x79388c;
    *(int*)((char*)this + 0x44) = 0x79387c;
    *(int*)((char*)this + 0x5c) = 0x79386c;
    *(int*)((char*)this + 0x74) = 0x79385c;
    *(int*)((char*)this + 0x8c) = 0x79384c;
    sub_77E6A4();
}
