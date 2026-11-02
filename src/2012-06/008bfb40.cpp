// from server: 65% by Intel
struct Clump {
    char pad_0[0x8];
    char field_8;
    char pad_9[0x77];
    float field_80;
    float field_84;
    float field_88;
    float field_8c;
    float field_90;
    float field_94;
    float field_98;
    float field_9c;
    float field_a0;
    float field_a4;
    float field_a8;
    float field_ac;
    float field_b0;

    void sub_8BFB40();
};

extern "C" int __stdcall sub_B7DCCC(int, int, int);
extern "C" void __cdecl sub_972290(int, int);

void Clump::sub_8BFB40() {
    if (*(char*)0xE580B3) {
        if (this->field_8) {
            int (__stdcall *func)(int, int, int) = *(int (__stdcall**)(int, int, int))0xE5809C;
            if (func) {
                if (func(0xBE5940, 0xB7DCCC, 0x54)) {
                    return;
                }
            }
            sub_972290(*(unsigned char*)0xE580B3, 0xBE5990);
        }
    }
    float val = this->field_80;
    this->field_84 = 0.0f;
    this->field_88 = val;
    this->field_8c = 0.0f;
    this->field_90 = 0.0f;
    this->field_94 = 0.0f;
    this->field_98 = 0.0f;
    this->field_9c = 0.0f;
    this->field_a0 = 0.0f;
    this->field_a4 = 0.0f;
    this->field_a8 = 0.0f;
    this->field_ac = 0.0f;
    this->field_b0 = 0.0f;
}
