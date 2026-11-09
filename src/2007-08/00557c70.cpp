// from server: 100% by colin
struct RBX_DataModel {
    char pad[0xc];
    int field_0xc;
    char pad2[0x64 - 0x10];
    int field_0x64;
    void method(int a1, int a2, int a3);
};

extern "C" void __fastcall sub_57AB40(int);
extern "C" void __fastcall sub_57D9F0(int);
extern "C" void __fastcall sub_57B4C0(int);
extern "C" void __fastcall sub_5D9DA0(int);

void RBX_DataModel::method(int a1, int a2, int a3) {
    switch (a3) {
    case 0:
        if (a2 == 1) {
            sub_57B4C0(field_0xc);
        }
        sub_5D9DA0(field_0x64);
        break;
    case 1:
        sub_57D9F0(field_0xc);
        break;
    case 2:
        sub_57AB40(field_0xc);
        break;
    }
}
