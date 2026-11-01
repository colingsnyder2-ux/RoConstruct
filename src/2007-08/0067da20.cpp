// from server: 100% by colin
struct CXTPControlRadioButton {
    CXTPControlRadioButton* Construct();
    int field0;
    char pad[0x1c];
    int field20;
    char pad2[0xd4];
    int fieldF8;
};

extern "C" void __fastcall sub_6ca460(CXTPControlRadioButton* p);

CXTPControlRadioButton* CXTPControlRadioButton::Construct() {
    sub_6ca460(this);
    field0 = 0x7ce744;
    field20 = 0x7ce6e4;
    fieldF8 = 0xb;
    return this;
}
