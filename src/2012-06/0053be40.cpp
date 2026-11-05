// from server: 100% by Intel
struct Player {
    char padding[0xE8];
    unsigned char field_E8;
    void method(unsigned char);
};

extern "C" void __stdcall sub_414DA0(unsigned int);

void Player::method(unsigned char arg) {
    if (arg != field_E8) {
        field_E8 = arg;
        sub_414DA0(0xE20F9C);
    }
}
