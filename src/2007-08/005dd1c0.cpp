// from server: 48% by colin
struct FactoryProduct {
    char pad0[0xfc];
    int field_fc;
    int field_100;
    int field_104;
    int field_108;
    int field_10c;
    char field_110;
    char field_114;
    void construct();
};

extern "C" void* __cdecl sub_62fef6(unsigned int);
extern "C" void __cdecl sub_5b4450();
extern "C" void __cdecl sub_5dd060();
extern "C" void __cdecl sub_541bf0();

extern "C" void* __stdcall sub_77e698(const char*);
extern "C" void __stdcall sub_77e6ac(void*);

void FactoryProduct::construct() {
    void* p = sub_62fef6(0x94);
    if (p != 0) {
        sub_5b4450();
    } else {
        p = 0;
    }
    sub_5dd060();
    *(int*)((char*)this + 0) = 0x7bc29c;
    *(int*)((char*)this + 4) = 0x7bc290;
    *(int*)((char*)this + 0x10) = 0x7bc288;
    *(int*)((char*)this + 0x14) = 0x7bc278;
    *(int*)((char*)this + 0x2c) = 0x7bc268;
    *(int*)((char*)this + 0x44) = 0x7bc258;
    *(int*)((char*)this + 0x5c) = 0x7bc248;
    *(int*)((char*)this + 0x74) = 0x7bc238;
    *(int*)((char*)this + 0x8c) = 0x7bc228;
    *(int*)((char*)this + 0xe8) = 0x7bc210;
    field_fc = 0;
    field_100 = 0;
    field_108 = 0;
    field_10c = 0;
    field_110 = 0;
    field_114 = 0;
    char buf[0x1c];
    sub_77e698("VelocityMotor");
    sub_541bf0();
    sub_77e6ac(buf);
}
