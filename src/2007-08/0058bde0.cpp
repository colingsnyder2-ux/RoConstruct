// from server: 83% by colin
struct TypedStatsItem {
    char pad[0x0c];
    int field_c;
    char pad2[0x4c];
    void* vtable_5c;
    char pad3[0x14];
    void* vtable_74;
    char pad4[0x14];
    void* vtable_8c;
    char pad5[0x58];
    void* vtable_e8;
    void* construct();
};

extern "C" int __cdecl sub_58A7C0();

void* TypedStatsItem::construct() {
    vtable_5c = (void*)0x7af1bc;
    vtable_74 = (void*)0x7af1ac;
    vtable_8c = (void*)0x7af19c;
    vtable_e8 = (void*)0x7af190;
    field_c = sub_58A7C0();
    return this;
}
