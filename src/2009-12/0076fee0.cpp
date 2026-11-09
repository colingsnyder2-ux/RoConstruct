// from server: 68% by atomic.potato
extern "C" void __stdcall sub_40c080(int);

struct VGuiImageButton {
    char pad[0x14c];
    int field_0x14c;
    char pad2[0x195 - 0x150];
    unsigned char field_0x195;
    void setSomething(unsigned char value);
};

void VGuiImageButton::setSomething(unsigned char value) {
    if (this->field_0x195 != value) {
        sub_40c080(0xb983f0);
        this->field_0x195 = value;
        if (this->field_0x195 == 0) {
            this->field_0x14c = 0;
        }
    }
}
