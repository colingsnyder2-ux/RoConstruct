// from server: 98% by Intel
struct DialogChoice {
    int vfptr;
    int vfptr2;
    char pad_8[0x10];
    int field_18;
    int field_1C;
    char pad_20[0x60];
    int field_80;
    int field_84;
    char pad_88[0x8];
    int field_90;
    char pad_94[0x8];
    int field_9C;
    char pad_A0[0x14];
    int field_B4;
    char pad_B8[0x10];
    int field_C8;

    int sub_8CA4E0();
};

extern "C" void __stdcall sub_7587e0();

int DialogChoice::sub_8CA4E0() {
    int eax = this->field_84;
    this->vfptr = 0xBE6EF4;
    this->vfptr2 = 0xBE6EEC;
    this->field_18 = 0xBE6EE0;
    this->field_1C = 0xBE6ED4;
    this->field_80 = 0xBE6ECC;
    this->field_90 = 0xBE6EB4;
    this->field_9C = 0xBE6E88;
    this->field_B4 = 0xBE6E5C;
    this->field_C8 = 0xBE6E54;
    int edx = *(int*)(eax + 4);
    *(int*)(edx + (int)this + 0x84) = 0xBE6E4C;
    eax = this->field_84;
    eax = *(int*)(eax + 4);
    edx = eax - 0x240;
    *(int*)(eax + (int)this + 0x80) = edx;
    sub_7587e0();
    return 0;
}
