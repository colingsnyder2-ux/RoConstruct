// from server: 100% by tester
struct RBX_VMotorFeature_FactoryProduct {
    char pad0[8];
    RBX_VMotorFeature_FactoryProduct* field8;
    char padC[0x10];
    char* field1C;
    char* field20;
    void func_005e1cf0();
};

void RBX_VMotorFeature_FactoryProduct::func_005e1cf0()
{
    if (field8 != 0) {
        field8->func_005e1cf0();
    } else {
        if (field20 != 0) {
            field20[4] = 1;
        }
    }
    if (field1C != 0) {
        field1C[4] = 1;
    }
}
