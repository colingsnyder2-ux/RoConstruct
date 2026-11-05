// from server: 92% by Intel
struct VBasicPartInstance {
    int vfptr;
    int field_4;
    char pad_8[20];
    int field_18;
    int field_1C;
    char pad_20[96];
    int field_80;
    int field_84;
    char pad_88[12];
    int field_90;
    char pad_94[8];
    int field_9C;
    char pad_A0[20];
    int field_B4;
    char pad_B8[20];
    int field_C8;

    void FactoryProduct();
};

extern "C" void __stdcall sub_7B45A0();

void VBasicPartInstance::FactoryProduct() {
    int v84 = this->field_84;
    this->vfptr = 0xBB8E3C;
    this->field_4 = 0xBB8E30;
    this->field_18 = 0xBB8E24;
    this->field_1C = 0xBB8E18;
    this->field_80 = 0xBB8E10;
    this->field_90 = 0xBB8DF8;
    this->field_9C = 0xBB8DCC;
    this->field_B4 = 0xBB8DA0;
    this->field_C8 = 0xBB8D98;
    int edx = *(int*)(v84 + 4);
    *(int*)(edx + (int)this + 0x84) = 0xBB8D90;
    int eax = this->field_84;
    eax = *(int*)(eax + 4);
    edx = eax - 0x248;
    *(int*)(eax + (int)this + 0x80) = edx;
    sub_7B45A0();
}
