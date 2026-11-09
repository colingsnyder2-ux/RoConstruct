// from server: 71% by tajop
struct FlagBase {
    char pad0[0xc];
    int field_c;
    char pad1[0x168 - 0x10];
    void* field_168;
    char pad2[0x220 - 0x16c];
    void* field_220;
    FlagBase(int);
    ~FlagBase();
};

struct Flag : FlagBase {
    Flag(int);
};

int sub_591230();

Flag::Flag(int flag)
    : FlagBase((flag != 0 ? (field_168 = (void*)0x7bb71c, field_220 = (void*)0x7a4ccc, 0) : 0))
{
    *(int*)((char*)this + 0x00) = 0x7bd61c;
    *(int*)((char*)this + 0x04) = 0x7bd610;
    *(int*)((char*)this + 0x10) = 0x7bd608;
    *(int*)((char*)this + 0x14) = 0x7bd5f8;
    *(int*)((char*)this + 0x2c) = 0x7bd5e8;
    *(int*)((char*)this + 0x44) = 0x7bd5d8;
    *(int*)((char*)this + 0x5c) = 0x7bd5c8;
    *(int*)((char*)this + 0x74) = 0x7bd5b8;
    *(int*)((char*)this + 0x8c) = 0x7bd5a8;
    *(int*)((char*)this + 0xe8) = 0x7bd5a0;
    *(int*)((char*)this + 0x158) = 0x7bd588;
    int v = *(int*)((char*)field_168 + 4);
    *(int*)((char*)this + v + 0x168) = 0x7bd580;
    int w = *(int*)((char*)field_168 + 4);
    *(int*)((char*)this + w + 0x164) = w - 0xb8;
    field_c = sub_591230();
}
