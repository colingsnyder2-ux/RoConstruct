// from server: 100% by why2
struct DxUserInput {
    char pad[0x160];
    int field_160;
    int set(int value, unsigned char flag);
};

int DxUserInput::set(int value, unsigned char flag) {
    int result = flag ? value : 0;
    field_160 = result;
    return result;
}
