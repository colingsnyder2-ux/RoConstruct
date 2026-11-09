// from server: 100% by colin
struct CXTPCustomizeSheet {
    void sub_62FEEA(int);
    int sub_63096A(int, int);
    void sub_6302EC();
    int sub_675880();
    char pad[0x94];
    int field_94;
    void func_00675950();
};

void CXTPCustomizeSheet::func_00675950()
{
    sub_62FEEA(1);
    int v = sub_63096A(0x69, field_94);
    ((CXTPCustomizeSheet *)v)->sub_6302EC();
    int r = sub_675880();
    *(int *)(*(int *)(r + 0x74) + 0x28) = field_94;
}
