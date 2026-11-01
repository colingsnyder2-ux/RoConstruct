// from server: 100% by why2
struct CXTPCommandBar {
    char pad[0x178];
    int* field_178;
    void setValue(int value);
};

void CXTPCommandBar::setValue(int value) {
    int* p = field_178;
    p[6] = value;
}
