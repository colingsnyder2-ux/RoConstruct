// from server: 45% by Intel
extern "C" int __stdcall sub_972290(int, int);
extern "C" int __stdcall sub_E5809C(int, int, int);

struct HumanoidStage {
    int field_A0;
    int data[1];

    void sub_964B00(int index, int* src);
};

void HumanoidStage::sub_964B00(int index, int* src) {
    int v2 = index;
    if (*(char*)0xE580B3) {
        if (v2 >= this->field_A0) {
            int v3 = *(int*)0xE5809C;
            if (v3) {
                if (sub_E5809C(0x27, 0xBDB2B8, 0xBDB3F4)) {
                    return;
                }
            }
            sub_972290(*(char*)0xE580B3, 0xC07418);
        }
        if (*(char*)0xE580B3) {
            if (this->field_A0 > 0x28) {
                int v4 = *(int*)0xE5809C;
                if (v4) {
                    if (sub_E5809C(0x28, 0xBDB2B8, 0xBDB37C)) {
                        return;
                    }
                }
                sub_972290(*(char*)0xE580B3, 0xC073A8);
            }
        }
    }
    this->data[v2] = *src;
}
