// from server: 100% by atomic.potato
struct RBX_TextBox {
    char pad[0x248];
    int field_248;
    void sub_411f60(const char*);
    void set(int);
};

void RBX_TextBox::set(int v) {
    if (field_248 != v) {
        field_248 = v;
        sub_411f60((const char*)0xcd104c);
        sub_411f60((const char*)0xcd1164);
    }
}
