// from server: 66% by atomic.potato
struct RBX_TextBox {
    char pad[0x228];
    int field_228;
    void sub_6cb5a0(int);
};

extern "C" void __stdcall sub_411f60(void*, void*);

void RBX_TextBox::sub_6cb5a0(int a) {
    if (field_228 != a) {
        sub_411f60((void*)0xcd11d8, this);
        field_228 = a;
        sub_411f60((void*)0xcd1164, this);
    }
}
