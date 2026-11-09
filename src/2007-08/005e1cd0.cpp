// from server: 100% by colin
struct RBX_VMotorFeature_FactoryProduct {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    float field7C;
    float getValue();
};

extern "C" float __fastcall sub_624d80(int);

float RBX_VMotorFeature_FactoryProduct::getValue()
{
    int p = this->field1C;
    if (p != 0)
        return sub_624d80(p);
    return this->field7C;
}
