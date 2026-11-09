// from server: 100% by atomic.potato
struct Tool {
    int field_0;
    int field_4;
    char pad[0x18 - 8];
    int field_18;
    int field_1c;
    char pad2[0x94 - 0x20];
    int field_94;
    void init();
};

extern "C" void __fastcall sub_5f65e0(Tool*);

void Tool::init()
{
    field_0 = 0xa3007c;
    field_4 = 0xa30070;
    field_18 = 0xa30064;
    field_1c = 0xa30058;
    field_94 = 0xa30050;
    sub_5f65e0(this);
}
