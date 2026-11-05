// from server: 100% by Intel
struct Player {
    char padding[0xE8];
    unsigned char field_E8;
    void method();
};

extern "C" void __stdcall sub_414DA0(unsigned int);

void Player::method() {
    if (field_E8 != 1) {
        field_E8 = 1;
        sub_414DA0(0xE20F9C);
    }
}
