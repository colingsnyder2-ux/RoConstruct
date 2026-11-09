// from server: 100% by colin
struct FactoryProduct {
    char pad[0xfc];
    int field_fc;
    void setValue(int value);
};

void FactoryProduct::setValue(int value) {
    if (field_fc != value) {
        field_fc = value;
        extern void __stdcall sub_444710(int);
        sub_444710(0x8c6d28);
    }
}
