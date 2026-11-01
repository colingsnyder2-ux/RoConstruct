// from server: 33% by Intel
struct VHopperBinFactoryProduct {
    VHopperBinFactoryProduct* construct();
};

extern "C" void __fastcall base_construct(void*);
extern "C" int __cdecl sub_52C7D0();
extern int dword_E48ABC;

VHopperBinFactoryProduct* VHopperBinFactoryProduct::construct() {
    base_construct(this);
    *(int*)this = 0xBA031C;
    *(int*)((char*)this + 4) = 0xBA0314;
    *(int*)((char*)this + 0x18) = 0xBA0308;
    *(int*)((char*)this + 0x1C) = 0xBA02FC;
    *(int*)((char*)this + 0x80) = 0xBA02F4;
    int result = sub_52C7D0();
    *(int*)((char*)this + 0x28) = result;
    ++dword_E48ABC;
    return this;
}
