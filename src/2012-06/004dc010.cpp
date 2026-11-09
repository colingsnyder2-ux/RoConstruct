// from server: 38% by atomic.potato
struct ManualObject {
    char pad0[0x10];
    char pad10[0x10];
    int field20;
    int field24;
    char field28;
    char pad29[3];
    int field2c;
    int field30;
    char pad34[0x10];
    char field44[0x10];
    ManualObject();
};

extern "C" void __stdcall sub_7219d0();
extern "C" void __stdcall sub_b22f6c();
extern "C" void __stdcall sub_b2327c();

ManualObject::ManualObject()
{
    sub_7219d0();
    field20 = 0;
    field24 = 4;
    field28 = 1;
    field2c = 0;
    field30 = 0;
    sub_7219d0();
    sub_b22f6c();
    sub_b2327c();
}
