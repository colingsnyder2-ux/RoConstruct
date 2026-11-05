// from server: 100% by colin
struct CXTPCustomizeSheet_CCustomizeEdit
{
    char pad[0x168];
    int* field_0x168;
    int IsValid();
};

int CXTPCustomizeSheet_CCustomizeEdit::IsValid()
{
    int* p = field_0x168;
    if (p != 0 && p[8] != 0)
        return 1;
    return 0;
}
