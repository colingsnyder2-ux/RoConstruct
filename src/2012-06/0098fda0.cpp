// from server: 100% by tester
struct CPatchedControlComboBox {
    char m_pad[0x178];
    int m_field_16c;
    int method_637300();
};

extern "C" int __cdecl sub_6360f0(int);
extern "C" int __cdecl sub_630202(int);

int CPatchedControlComboBox::method_637300()
{
    return sub_630202(sub_6360f0(m_field_16c));
}
