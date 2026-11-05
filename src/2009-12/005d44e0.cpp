// from server: 47% by atomic.potato
struct G3DPart {
    void* vfptr;          // 0x00
    int field_04;         // 0x04
    void* field_08;       // 0x08
    int field_0c;         // 0x0c
    int field_10;         // 0x10
    int field_14;         // 0x14
    int field_18;         // 0x18
    int field_1c;         // 0x1c
    char pad_20[0x20];    // 0x20
    char pad_40[0x20];    // 0x40
    int field_60;         // 0x60
    G3DPart();
};

extern "C" void* __cdecl sub_5EA2C0(unsigned int, unsigned int);
extern "C" void __cdecl sub_5EAFC0(void*, int, void*, unsigned int);
extern "C" void __fastcall sub_5D1D00(void*, void*, void*);
extern "C" void __fastcall sub_5D1C80(void*, void*, void*);

G3DPart::G3DPart()
{
    vfptr = (void*)0x9c11a0;
    field_0c = 0xa;
    field_04 = 0;
    field_08 = sub_5EA2C0(0x28, 0x10);
    sub_5EAFC0(field_08, 0, 0, (unsigned int)(field_0c * 4));
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
    sub_5D1D00((char*)this + 0x20, (char*)this + 0x21, (char*)this + 0x22);
    sub_5D1C80((char*)this + 0x40, (char*)this + 0x41, (char*)this + 0x42);
    field_60 = 0;
}
