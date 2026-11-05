// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct CPatchedControlComboBox {
    char pad[0x178];
    int field_178;
    int getSomething();
    int finalize(int);
};

extern "C" int __cdecl helper_6a6e90(int);
extern "C" int __cdecl helper_6a0c26(int);

int CPatchedControlComboBox::getSomething() {
    return helper_6a0c26(helper_6a6e90(field_178));
}
