// from server: 81% by tester
// roc 2012-06 00814a10  unit: RBX::VWeld::?$FactoryProduct  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00814a10

extern "C" int __stdcall sub_983448(int, int, int, int, int);
extern "C" void __stdcall sub_414da0();

struct S {
    char pad[0xa8];
    int field_a8;
    void f(int);
};

void S::f(int arg) {
    int a = sub_983448(field_a8, 0, 0xdc2d44, 0xddba3c, 0);
    int b = sub_983448(field_a8, 0, 0xdc2d44, 0xddbb24, 0);
    if (a != 0) {
        if (arg != *(int*)(a + 0x94)) {
            *(int*)(a + 0x94) = arg;
            sub_414da0();
        }
    } else if (b != 0) {
        if (arg != *(int*)(b + 0xfc)) {
            *(int*)(b + 0xfc) = arg;
            sub_414da0();
        }
    }
}
