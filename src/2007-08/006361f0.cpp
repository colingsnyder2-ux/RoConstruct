// from server: 100% by colin
struct CXTPControlComboBoxPopupBar {
    void sub_636100();
    int field_0;
    char pad_4[0x50];
    int field_54;
    char pad_58[0x4];
    int field_5c;
    char pad_60[0x60];
    int field_c0;
    int field_c4;
    char pad_c8[0x24];
    int field_ec;
    char pad_f0[0xc];
    int field_fc;
    CXTPControlComboBoxPopupBar* construct();
};

CXTPControlComboBoxPopupBar* CXTPControlComboBoxPopupBar::construct() {
    sub_636100();
    field_c4 = 0;
    field_c0 = 0;
    field_ec = 0;
    field_0 = 0x7c59fc;
    field_54 = 0x7c59ec;
    field_5c = 0x7c598c;
    field_fc = 6;
    return this;
}
