// from server: 100% by tester
struct CPatchedControlComboBox {
    char pad[0x178];
    int field_0x178;
    int getValue();
};

extern "C" int __cdecl sub_71B420(int);
extern "C" int __cdecl sub_718FC6(int);

int CPatchedControlComboBox::getValue() {
    return sub_718FC6(sub_71B420(field_0x178));
}
