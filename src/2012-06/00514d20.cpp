// from server: 35% by tester
struct RbxMegaCluster {
    void dtor();
    char pad[0x1c];
    int field1c;
    char pad2[0x24];
    int field40;
    int field44;
    char pad3[0xc];
    int field54;
    int field58;
    int field5c;
};

extern "C" void __stdcall sub_428a60(int);
extern "C" void __stdcall sub_4cc010(int);
extern "C" void __stdcall sub_673ce0(int);
extern "C" void __stdcall sub_982114(int);

void RbxMegaCluster::dtor()
{
    *(int*)this = 0xb6e4f8;
    if (field54 != 0) {
        sub_982114(field54);
    }
    field54 = 0;
    field58 = 0;
    field5c = 0;
    sub_428a60((int)(this) + 0x44);
    sub_428a60((int)(this) + 0x40);
    sub_4cc010((int)(this) + 0x1c);
    sub_673ce0((int)(this));
}
