// from server: 100% by atomic.potato
extern "C" void __stdcall sub_40c080(int);

struct VGuiImageButton {
    char pad_0000[0x14c];
    int field_0x14c;
    char pad_0150[0x44];
    unsigned char field_0x194;
    void setSomething(unsigned char value);
};

void VGuiImageButton::setSomething(unsigned char value) {
    if (this->field_0x194 != value) {
        this->field_0x194 = value;
        sub_40c080(0xb9855c);
        if (this->field_0x194 == 0) {
            this->field_0x14c = 0;
        }
    }
}
