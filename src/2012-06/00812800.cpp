// from server: 80% by Intel
extern char g_0_bc6954, g_0_bc671c, g_4_bc6710, g_18_bc6704, g_1c_bc66f8, g_80_bc66cc;
extern "C" void base_811a80(void*);

struct VMotor_FactoryProduct {
    void* f_0;
    void* f_4;
    char pad_8[20];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    char pad_84[76];
    void* f_ac;
    void init();
};

void VMotor_FactoryProduct::init() {
    f_ac = &g_0_bc6954;
    f_0 = &g_0_bc671c;
    f_4 = &g_4_bc6710;
    f_18 = &g_18_bc6704;
    f_1c = &g_1c_bc66f8;
    f_80 = &g_80_bc66cc;
    base_811a80(this);
}
