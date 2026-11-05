// from server: 100% by colin
struct RBX_VCamera_FactoryProduct {
    char pad[0x18c];
    int field_18c;
    char pad2[0x194 - 0x18c - 4];
    int field_194;
    void method_599ae0(float);
    void method_599a00(float);
    void target(float);
};

void RBX_VCamera_FactoryProduct::target(float f) {
    if (field_194 != 0) {
        int v = field_18c;
        if (v == 4 || v == 1 || v == 3) {
            method_599ae0(f);
            return;
        }
    }
    method_599a00(f);
}
