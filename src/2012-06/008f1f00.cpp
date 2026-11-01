// from server: 46% by Intel
struct KernelJoint {
    void* vftable;
    char pad_4[24];
    void* field_1C;
    char pad_20[16];
    int field_30;

    void func_008f1f00();
};

extern "C" int __stdcall G1_func_005c9fe8(int, int);
extern "C" void __stdcall G1_func_00893d70();
extern "C" void __cdecl G1_func_00972290(int, int);
extern "C" int __cdecl G1_func_e5809c(int, int, int);

extern char G1_byte_00e31ab7;
extern char G1_byte_00e580b3;
extern int G1_dword_00e5809c;

void KernelJoint::func_008f1f00() {
    int vftable_init = 0xbeeef4;
    this->vftable = &vftable_init;
    int field1c_init = 0xbeeed8;
    this->field_1C = &field1c_init;

    if (G1_byte_00e580b3) {
        if (this->field_30) {
            if (G1_dword_00e5809c) {
                if (G1_func_e5809c(0x52, 0xbee9e0, 0xbeeec8)) {
                    goto LABEL_74;
                }
            }
            G1_func_00972290(0xbeee60, G1_byte_00e580b3);
        }
    }
LABEL_74:
    if (G1_byte_00e31ab7) {
        G1_func_005c9fe8(G1_byte_00e31ab7, 0xbeee4c);
    }
    int vftable_final = 0xbee948;
    this->vftable = &vftable_final;
    G1_func_00893d70();
}
