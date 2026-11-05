// from server: 100% by Intel
struct ViewRbxGfx {
    char padding[32];
    unsigned char field_20;
    unsigned char getAndClearField20();
};

unsigned char ViewRbxGfx::getAndClearField20() {
    unsigned char result = field_20;
    field_20 = 0;
    return result;
}
