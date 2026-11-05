// from server: 45% by colin
struct FilteredSelection {
    char pad[0x100];
    int field_0x100;
    void construct();
};

extern "C" {
    void __stdcall sub_444E20();
    void __stdcall sub_541BF0();
    void __stdcall sub_77E698();
    void __stdcall sub_77E6AC();
}

void FilteredSelection::construct()
{
    sub_444E20();
    *(int*)((char*)this + 0xe8) = 0x7a9184;
    *(int*)((char*)this + 0x00) = 0x7a9364;
    *(int*)((char*)this + 0x04) = 0x7a935c;
    *(int*)((char*)this + 0x10) = 0x7a9354;
    *(int*)((char*)this + 0x14) = 0x7a9344;
    *(int*)((char*)this + 0x2c) = 0x7a9334;
    *(int*)((char*)this + 0x44) = 0x7a9324;
    *(int*)((char*)this + 0x5c) = 0x7a9314;
    *(int*)((char*)this + 0x74) = 0x7a9304;
    *(int*)((char*)this + 0x8c) = 0x7a92f4;
    *(int*)((char*)this + 0xe8) = 0x7a92ec;
    *(int*)((char*)this + 0xec) = 0;
    *(int*)((char*)this + 0xf0) = 0;
    *(int*)((char*)this + 0xf8) = 0;
    *(int*)((char*)this + 0xfc) = 0;
    *(int*)((char*)this + 0x100) = 0;
    sub_77E698();
    sub_541BF0();
    sub_77E6AC();
}
