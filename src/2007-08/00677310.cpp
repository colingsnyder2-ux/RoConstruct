// from server: 100% by colin
struct CXTPCustomizeCommandsPage {
    int field0;
    char pad[0x1c];
    int field20;
    char pad2[0xd0];
    int fieldd4;
    char pad3[0x20];
    int fieldf8;
    CXTPCustomizeCommandsPage* construct();
};

extern "C" void __fastcall sub_6ca460(CXTPCustomizeCommandsPage* self);

CXTPCustomizeCommandsPage* CXTPCustomizeCommandsPage::construct() {
    sub_6ca460(this);
    *(int*)this = 0x7cd10c;
    *(int*)((char*)this + 0x20) = 0x7cd0ac;
    *(int*)((char*)this + 0xf8) = 1;
    *(int*)((char*)this + 0xd4) = 0x5a;
    return this;
}
