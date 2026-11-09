// from server: 100% by why2
struct CFont {
    char pad[0x8c];
    int field_8c;
    char pad2[0x94 - 0x8c - 4];
    int field_94;
    int get();
};

int CFont::get() {
    if (field_94 == 2)
        return 0xa4b310;
    return field_8c;
}
