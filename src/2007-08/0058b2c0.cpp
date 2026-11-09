// from server: 0% by colin
struct EnumDescriptor {
    void construct();
};

struct EnumDesc {
    char pad[0xe8];
    int field_e8;
    int field_ec;
    int field_f0;
    char pad2[0x100 - 0xf4];
    float field_100;
    float field_104;
    float field_108;
    int field_10c;
    int field_110;
    double field_118;
    char field_120[0xc];
    char field_12c[0xc];
    void init();
};

extern "C" {
    void __stdcall sub_58ae50();
    void __stdcall sub_604e20();
    void __stdcall sub_4ffef0();
    void __stdcall sub_61dd70();
    void __stdcall sub_541bf0();
    void __stdcall sub_4931a0();
    void __stdcall sub_62fbd8();
    void __stdcall sub_588330();
    void __stdcall sub_62fc26();
    void __stdcall sub_412dc0();
    void __stdcall sub_630b9e();
    void __stdcall sub_62fc20();
    void __stdcall sub_5877d0();
    void __stdcall sub_77e698();
    void __stdcall sub_77e6ac();
}

void EnumDesc::init()
{
    sub_58ae50();
    field_e8 = 0x795b60;
    field_e8 = 0x7aec3c;
    field_ec = 0;
    field_f0 = 0;
    sub_604e20();
    field_100 = 1.0f;
    field_104 = *(float*)0x796468;
    field_108 = *(float*)0x796468;
    field_10c = 0;
    field_110 = 0;
    sub_4ffef0();
    field_118 = 0.0;
    sub_61dd70();
    sub_61dd70();
    sub_77e698();
    sub_541bf0();
    sub_77e6ac();
    if (*(char*)0x8c3341 == 0) {
        sub_4931a0();
        if (*(char*)(0 + 0xec) != 0) {
            sub_62fbd8();
            sub_588330();
            sub_62fc26();
            sub_588330();
            if (field_f0 < 0x40623) {
                sub_77e698();
                sub_412dc0();
                sub_630b9e();
            }
            sub_62fc20();
            sub_588330();
            sub_5877d0();
        }
    }
}
