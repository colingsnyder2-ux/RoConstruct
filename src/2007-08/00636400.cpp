// from server: 100% by colin
struct CPatchedControlComboBox {
    int getValue();
    char pad[0x194];
    int field_194;
    int field_198;
};

int CPatchedControlComboBox::getValue() {
    return field_198 + field_194 + 5;
}
